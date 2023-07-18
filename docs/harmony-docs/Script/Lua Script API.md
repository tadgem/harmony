# Packages
## **Time**
##### Methods
-  `time.GetFrameTime()` : Returns time elapsed in milliseconds since last frame, scaled by the global time-scale. 
-  `time.GetFrameTimeUnscaled() `: Returns time elapsed in milliseconds since last frame, unaffected by global timescale.
-  `time.GetTimescale` : Returns the global time-scale (float)
-  `time.SetTimescale` : Set the global time-scale

## Maths.
##### Types
- `vec2`
	- `x` : `float`
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
##### Methods
// TODO : Can we reimplement maths functions as operators?

## Input
##### Types
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
- `GamePadStick`
	- `LS`
	- `RS`
- `GamePadTrigger`
	- `RT`
	- `LT`
- `MouseButton`
	- `Left`
	- `Right`
	- `Middle`
- `Key` :  Keys of the keyboard, if one is missing reach out to Liam.

##### Methods
- `GetGamepadButton(GamepadButton)` : `bool` : returns true if the specified button is pressed.
- 
- Debug