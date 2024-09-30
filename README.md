# Pumpkin Engine
<br>\<br>

A little learning project that is written in c++ \
based off of [Hazel Game Engine](https://github.com/TheCherno/Hazel)

<br>\<br>

> [!WARNING]
> THIS ENGINE IS IN EARLY DEVELOPMENT EXPECT BUGS \
> OR THINGS NOT WORKING PROPERLY.

<br>\<br>

## Support

| Linux       | Supported |
| ----------- | ----------- |
| Wayland     | WIP |
| X11         | Yes |

<br>/<br>

| Windows     | Fully Supported |
| ----------- | --------------- |

<br>/<br>

## Installation
Clone the repository make sure you have the `--recursive` flag
    
    $ git clone --recursive https://github.com/Moonix1/Pumpkin-Engine
  
Next enter the repo destination, then build with cmake \
Ninja is recommended as the Generator but you can use VS or other

    $ cmake -G Ninja -B bin
    $ cmake --build bin