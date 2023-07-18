# Time
### Types

### Methods
- `time.GetFrameTime()` : `float` : Returns time elapsed in milliseconds since last frame, scaled by the global time-scale. 
- `time.GetFrameTimeUnscaled() `: `float` : Returns time elapsed in milliseconds since last frame, unaffected by global timescale.
- `time.GetTimescale()` : `float` : Returns the global time-scale (float)
- `time.SetTimescale()` : `void` : Set the global time-scale

# Maths
### Types
- `vec2`
	- `x`:  `float`
	- `y`:  `float`
- `vec3`
	- `x`: `float`
	- `y`: `float`
	- `z`: `float`
- `vec4`
	- `x`: `float`
	- `y`: `float`
	- `z`: `float`
	- `w`: `float`
	
### Methods
// TODO : Can we reimplement maths functions as operators?

# Input
### Types
- `GamePadButton` : `enum`
	- `FaceNorth`
	- `FaceEast`
	- `FaceSouth`
	- `FaceWest`
	- `Up`
	- `Right`
	- `Down`
	- `Left`
	- `RB`
	- `LB`
	- `Home`
	- `Back`
	- `Start`
- `GamePadStick` : `enum`
	- `LS`
	- `RS`
- `GamePadTrigger` : `enum`
	- `RT`
	- `LT`
- `MouseButton` : `enum`
	- `Left`
	- `Right`
	- `Middle`
- `Key` : `enum`  
	- `Keys of the keyboard, A, B, C, D, End, PgUp, LeftAlt etc. if one is missing reach out to Liam.`
	
### Methods
- `GetGamepadButton(GamepadButton)` : `bool` : returns true if the specified button is pressed.
- `GetGamepadButtonJustPressed(GamepadButton)` : `bool` : returns true if the specific button was pressed this frame.
- `GetGamepadButtonJustReleased(GamepadButton)` : `bool` : returns true if the specific button was released this frame.
- `GetGamepadTrigger(GamepadTrigger)` : `float` : Return the current state of the specified trigger (in range 0 - 1)
- `GetGamepadStick(GamepadStick)` : `vec2` : Return the current state of the specified stick (each axis in range 0 - 1)

- `GetKey(Key)` : `bool` : Returns true if the specified key is pressed
- `GetKeyJustPressed(Key)` : `bool` : Returns true if the specified key was pressed this frame.
- `GetKeyJustReleased(Key)` : `bool` : Returns true if the specified key was released this frame.

- `GetMousePosition()` : `vec2` : Returns position in screen space of the mouse cursor
- `GetMousePositionLastFrame()` : `vec2` : Returns position in screen space of the mouse cursor for the previous frame.
- `GetMouseVelocity()` : `vec2` : Returns unit vector representing direction of mouse movement.
- `GetMouseVelocityLastFrame()` : `vec2` : Returns unit vector representing direction of mouse movement for the previous frame.

- `GetMouseButton(MouseButton)` : `bool` : Returns true if the specified Mouse Button is pressed
- `GetMouseButtonJustPressed(MouseButton)` : `bool` : Returns true if the specified Mouse Button was pressed this frame.
- `GetMouseButtonJustReleased(MouseButton)` : `bool` : Returns true if the specified Mouse Button was released this frame.

# Rendering
### Types
- `View`
- `Renderer`
- `Shader`
- `PipelineStageRenderer`

### Methods
- `GetRenderer()` : `Renderer` : Returns the program renderer.
- `GetView(String)` : `View` : Try to find a view, given a name.
- `GetViewEntity(View)` : `Entity` : Try to find the view's entity, if one exists.
- `GetShader(String)` : `Shader` : Try to find a shader, given a name.

# ECS
### Types
- `EntityHandle` : N.B. entt handle for an entity
- `Entity` : N.B. Harmony implementation of an entity.
- `Scene`
- `Registry` : N.B. entt::registry
- `Transform`
- `Mesh`
- `Material`
- `Camera`
- `CameraComponent`
- `DirectionalLight`
- `PointLigjht`
- `SpotLight`

### Methods
- `LoadScene(String)` : `void` : Try to open a scene at a specified path.
- `OpenScene(Number)` : `void` : Try to open a scene at a given index (the order in which your scenes are serialized in yourgame.harmonyproj)
- `GetForegroundScene()` : `Scene` : Try to return the foreground scene, if one exists.
- `GetEntity()` : `Entity` : Get the entity that this script is attached to (Behavioural scripts only)

# Debug
### Types

### Methods
- `DrawLine(vec3 start, vec3 end)` : `void` : Draws a line (Editor only) from point A to point B.
- `DrawSphere(vec3 pos, float radius)` : `void` : Draw a sphere at `pos` with a radius `radius`.
- `SetColor(float r,float g,float b, float a)` : `void` : Set the colour for the current debug drawable.

- 