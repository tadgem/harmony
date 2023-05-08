![harmony logo](banner.jpg)
# harmony
## Moddable and friendly cross platform game engine. 

Game engine with core focus on being fun to use and highly customizable. All software used to build harmony is open source, and can be substitued with whatever systems you see fit using the ECS infrastructure provided by the engine. Rendering is handled using `bgfx` with input/windowing/events etc. handled by `SDL2`

#### Features :

+ Editor + Runtime applications (WIP)
+ ECS Design
+ Modular Design for Engine Components + Game Systems. 
+ Serialization infrastructure using JSON. (WIP)
+ GraphScript : in engine visual scripting language
+ Pipeline Graph renderer architecture, which allows reuse of shared data and abstraction of resource generation.
+ ShaderDataSource architecture which allows data binding code for shaders to be reused. 
+ Lua scripting support (LuaJIT + Lua available through use of a CMake option) (WIP)
+ Jolt Physics Integration (WIP)
+ Arbitrary model loading (WIP)
+ Shader hot reload