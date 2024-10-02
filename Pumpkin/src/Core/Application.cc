#include "Application.hpp"
#include "Defines.hpp"

#include "Input.hpp"

#include <glad/glad.h>
#include "Renderer/Renderer.hpp"

namespace Pumpkin {

    Application *Application::s_Instance = nullptr;

    Application::Application() {
        PUMPKIN_CORE_ASSERT(s_Instance, "Application already exists!");
        s_Instance = this;
        m_Window = std::unique_ptr<Window>(Window::Create());
        m_Window->SetEventCallback(PUMPKIN_BIND_EVENT_FN(Application::OnEvent));

        m_ImGuiLayer = new ImGuiLayer();

        PushOverlay(m_ImGuiLayer);

        m_TriangleVA.reset(VertexArray::Create());

        float vertices[3 * 7] = {
            -0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
             0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
             0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f,
        };
        
        std::shared_ptr<VertexBuffer> triangleVB;
        triangleVB.reset(VertexBuffer::Create(vertices, sizeof(vertices)));
        BufferLayout triangleLayout = {
            { ShaderDataType::Float3, "a_Position" },
            { ShaderDataType::Float4, "a_Color" }
        };
        triangleVB->SetLayout(triangleLayout);
        m_TriangleVA->AddVertexBuffer(triangleVB);

        uint32_t tIndices[3] = {0, 1, 2};
        std::shared_ptr<IndexBuffer> triangleIB;
        triangleIB.reset(IndexBuffer::Create(tIndices, sizeof(tIndices) / sizeof(uint32_t)));
        m_TriangleVA->SetIndexBuffer(triangleIB);

        m_SquareVA.reset(VertexArray::Create());

        float sVertices[3 * 4] = {
            -0.75f, -0.75f, 0.0f,
             0.75f, -0.75f, 0.0f,
             0.75f,  0.75f, 0.0f,
            -0.75f,  0.75f, 0.0f,
        };

        std::shared_ptr<VertexBuffer> squareVB;
        squareVB.reset(VertexBuffer::Create(sVertices, sizeof(sVertices)));
        BufferLayout squareVBLayout = {
            { ShaderDataType::Float3, "a_Position" },
        };
        squareVB->SetLayout(squareVBLayout);
        m_SquareVA->AddVertexBuffer(squareVB);
        
        uint32_t sIndices[6] = {0, 1, 2, 2, 3, 0};
        std::shared_ptr<IndexBuffer> squareIB;
        squareIB.reset(IndexBuffer::Create(sIndices, sizeof(sIndices) / sizeof(uint32_t)));
        m_SquareVA->SetIndexBuffer(squareIB);

        m_TriangleShader.reset(new Shader("../Shaders/test.vert", "../Shaders/test.frag"));
        m_SquareShader.reset(new Shader("../Shaders/square.vert", "../Shaders/square.frag"));
    }

    Application::~Application() {}

    void Application::OnEvent(Event &event) {
        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<WindowCloseEvent>(
            PUMPKIN_BIND_EVENT_FN(Application::OnWindowClose));

        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
            (*--it)->OnEvent(event);
            if (event.handled)
            break;
        }
    }

    void Application::PushLayer(Layer *layer) {
        m_LayerStack.PushLayer(layer);
        layer->OnAttach();
    }

    void Application::PushOverlay(Layer *overlay) {
        m_LayerStack.PushOverlay(overlay);
        overlay->OnAttach();
    }

    bool Application::OnWindowClose(WindowCloseEvent &event) {
        m_Running = false;
        return true;
    }

    void Application::Run() {
        while (m_Running) {
            RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
            RenderCommand::Clear();

            Renderer::BeginScene();

            m_SquareShader->Bind();
            Renderer::Submit(m_SquareVA);

            m_TriangleShader->Bind();
            Renderer::Submit(m_TriangleVA);
            
            Renderer::EndScene();

            for (Layer *layer : m_LayerStack)
            layer->OnUpdate();

            m_ImGuiLayer->Begin();
            for (Layer *layer : m_LayerStack)
            layer->OnImGuiRender();
            m_ImGuiLayer->End();

            m_Window->OnUpdate();
        }
    }

} // namespace Pumpkin
