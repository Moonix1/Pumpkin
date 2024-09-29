#include "pheader.hpp"
#include "Layer.hpp"

namespace Pumpkin {
    Layer::Layer(const std::string &debugName)
        : m_DebugName(debugName) {}
        
    Layer::~Layer() {
        
    }
}