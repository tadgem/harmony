# harmony
## A cross platform engine focussed on being fun to use and easy to extend. 
### Development Status : pre-alpha (all features unless stated otherwise are WIP)

I started this project in March / April 2022. After having spent years working on games, I wanted to create my own engine that was free of the frustrations of other engines, its plain old C++, no fancy scripting variants ala unreal and no required paid membership to edit the source ala unity. If you know C++, you should be able to jump in to this with minimal effort. Each game using harmony has full access to the engine source and can extend the engine using C++ or the Scripting framework. Big heavy feature you don't want / need in your game? take it out, each feature has been designed to be as modular as possible, meaning if you want to take out a system, its usually just a single line of code.  The renderer introduces a stack based approach which allows for modularity when constructing render pipelines.

#### Features :

+ Editor + Runtime applications
+ ECS Design
+ Modular Design for Engine Components + Game Systems. 
+ Serialization infrastructure using JSON.
+ "Pipeline Stack" renderer architecture, which allows reuse of shared data and abstraction of resource generation.
+ ShaderDataSource architecture which allows data binding code for shaders to be reused. 
+ Lua scripting support (LuaJIT + Lua available through use of a CMake option)
+ Jolt Physics Integration
+ Arbitrary model loading (Thanks to assimp)
+ Shader hot reload

#### Help wanted!
If you feel like you can contribute to the engine your input is wanted! please reach out for more info about getting setup with the project.