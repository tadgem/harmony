#include "Core/Input.h"
#include "Core/Program.h"
#include "Core/Log.hpp"
void harmony::Input::UpdateMouseScroll(float val)
{
	p_MouseState.PreviousFrameScroll = p_MouseState.CurrentFrameScroll;
	p_MouseState.CurrentFrameScroll = val;
}
void harmony::Input::UpdateMousePosition(glm::vec2 mousePosition)
{
	p_MouseState.PreviousFrameMouseLocation = p_MouseState.CurrentFrameMouseLocation;
	p_MouseState.CurrentFrameMouseLocation = mousePosition;

	glm::vec2 currentVelocity = p_MouseState.CurrentFrameMouseLocation - p_MouseState.PreviousFrameMouseLocation;
	currentVelocity.x /= Program::p_WindowWidth;
	currentVelocity.y /= Program::p_WindowHeight;

	p_MouseState.PreviousFrameMouseVelocity = p_MouseState.CurrentFrameMouseVelocity;
	p_MouseState.CurrentFrameMouseVelocity = currentVelocity;
}

void harmony::Input::UpdateMouseButton(Mouse::Button button, bool active)
{
	p_MouseState.PreviousFrameButtonState[button] = p_MouseState.CurrentFrameButtonState[button];
	p_MouseState.CurrentFrameButtonState[button] = active;
}

void harmony::Input::UpdateKey(Key key, bool active)
{
	p_KeyboardState.PreviousFrameKeyState[key] = p_KeyboardState.CurrentFrameKeyState[key];
	p_KeyboardState.CurrentFrameKeyState[key] = active;
}

void harmony::Input::UpdateGamepadButton(int gamepadIndex, Gamepad::Button button, bool active)
{
	if (gamepadIndex >= g_NumGamepads)
	{
		harmony::log::error("Supplied gamepad index : {} but the maximum index is {}", gamepadIndex, g_NumGamepads - 1);
		return;
	}
	p_GamepadStates[gamepadIndex].PreviousFrameButtonState[button] 
		= p_GamepadStates[gamepadIndex].CurrentFrameButtonState[button];

	p_GamepadStates[gamepadIndex].CurrentFrameButtonState[button] = active;
}

void harmony::Input::UpdateGamepadTrigger(int gamepadIndex, Gamepad::Trigger trigger, float value)
{
	if (gamepadIndex >= g_NumGamepads)
	{
		harmony::log::error("Supplied gamepad index : {} but the maximum index is {}", gamepadIndex, g_NumGamepads - 1);
		return;
	}

	p_GamepadStates[gamepadIndex].PreviousFrameTriggerState[trigger]
		= p_GamepadStates[gamepadIndex].CurrentFrameTriggerState[trigger];

	p_GamepadStates[gamepadIndex].CurrentFrameTriggerState[trigger] = value;
}

void harmony::Input::UpdateGamepadStick(int gamepadIndex, Gamepad::Stick stick, glm::vec2 value)
{
	if (gamepadIndex >= g_NumGamepads)
	{
		harmony::log::error("Supplied gamepad index : {} but the maximum index is {}", gamepadIndex, g_NumGamepads - 1);
		return;
	}

	p_GamepadStates[gamepadIndex].PreviousFrameStickState[stick]
		= p_GamepadStates[gamepadIndex].CurrentFrameStickState[stick];

	p_GamepadStates[gamepadIndex].CurrentFrameStickState[stick] = value;
}

void harmony::Input::OnControllerConnected(uint8_t index)
{
	return;
}

void harmony::Input::OnControllerDisconnected(uint8_t index)
{
}

glm::vec2 harmony::Input::GetMousePosition()
{
	return p_MouseState.CurrentFrameMouseLocation;
}

glm::vec2 harmony::Input::GetMousePositionLastFrame()
{
	return p_MouseState.PreviousFrameMouseLocation;
}

glm::vec2 harmony::Input::GetMouseVelocity()
{
	return p_MouseState.CurrentFrameMouseVelocity;
}

glm::vec2 harmony::Input::GetMouseVelocityLastFrame()
{
	return p_MouseState.PreviousFrameMouseVelocity;
}

bool harmony::Input::GetMouseButton(Mouse::Button button)
{
	return p_MouseState.CurrentFrameButtonState[button];
}

bool harmony::Input::GetMouseButtonJustPressed(Mouse::Button button)
{
	return p_MouseState.CurrentFrameButtonState[button] && !p_MouseState.PreviousFrameButtonState[button];
}

bool harmony::Input::GetMouseButtonJustReleased(Mouse::Button button)
{
	return !p_MouseState.CurrentFrameButtonState[button] && p_MouseState.PreviousFrameButtonState[button];
}

bool harmony::Input::GetKey(Key key)
{
	return p_KeyboardState.CurrentFrameKeyState[key];
}

bool harmony::Input::GetKeyJustPressed(Key key)
{
	return p_KeyboardState.CurrentFrameKeyState[key] && !p_KeyboardState.PreviousFrameKeyState[key];
}

bool harmony::Input::GetKeyJustReleased(Key key)
{
	return !p_KeyboardState.CurrentFrameKeyState[key] && p_KeyboardState.PreviousFrameKeyState[key];
}

bool harmony::Input::GetGamepadButton(int gamepadIndex, Gamepad::Button button)
{
	if (gamepadIndex >= g_NumGamepads)
	{
		harmony::log::error("Attempting to retrieve gamepad state for index greater than number supported by harmony : ", gamepadIndex + 1);
		return false;
	}
	return p_GamepadStates[gamepadIndex].CurrentFrameButtonState[button];
}

bool harmony::Input::GetGamepadButtonJustPressed(int gamepadIndex, Gamepad::Button button)
{
	if (gamepadIndex >= g_NumGamepads)
	{
		harmony::log::error("Attempting to retrieve gamepad state for index greater than number supported by harmony : ", gamepadIndex + 1);
		return false;
	}
	return p_GamepadStates[gamepadIndex].CurrentFrameButtonState[button] && !p_GamepadStates[gamepadIndex].PreviousFrameButtonState[button];
}

bool harmony::Input::GetGamepadButtonJustReleased(int gamepadIndex, Gamepad::Button button)
{
	if (gamepadIndex >= g_NumGamepads)
	{
		harmony::log::error("Attempting to retrieve gamepad state for index greater than number supported by harmony : ", gamepadIndex + 1);
		return false;
	}
	return !p_GamepadStates[gamepadIndex].CurrentFrameButtonState[button] && p_GamepadStates[gamepadIndex].PreviousFrameButtonState[button];
}

float harmony::Input::GetGamepadTrigger(int gamepadIndex, Gamepad::Trigger trigger)
{
	if (gamepadIndex >= g_NumGamepads)
	{
		harmony::log::error("Attempting to retrieve gamepad state for index greater than number supported by harmony : ", gamepadIndex + 1);
		return 0.0f;
	}
	return p_GamepadStates[gamepadIndex].CurrentFrameTriggerState[trigger];
}

glm::vec2 harmony::Input::GetGamepadStick(int gamepadIndex, Gamepad::Stick stick)
{
	if (gamepadIndex >= g_NumGamepads)
	{
		harmony::log::error("Attempting to retrieve gamepad state for index greater than number supported by harmony : " , gamepadIndex + 1);
		return glm::vec2();
	}
	return p_GamepadStates[gamepadIndex].CurrentFrameStickState[stick];
}

harmony::Key harmony::Input::GetKeyFromSDLKeycode(SDL_Keycode keyCode)
{
	if (keyCode >= SDLK_0 && keyCode <= SDLK_9)
	{
		int diff = keyCode - SDLK_0;
		return static_cast<Key>(Key::Zero + diff);
	}

	if (keyCode >= SDLK_a && keyCode <= SDLK_z)
	{
		int diff = keyCode - SDLK_a;
		return static_cast<Key>(Key::A + diff);
	}

	if (keyCode >= SDLK_F1 && keyCode <= SDLK_F12)
	{
		int diff = keyCode - SDLK_F1;
		return static_cast<Key>(Key::F1 + diff);
	}

	switch (keyCode)
	{
	case SDLK_MINUS:
		return Key::Minus;
	case SDLK_UNDERSCORE:
		return Key::Underscore;
	case SDLK_EQUALS:
		return Key::Equals;
	case SDLK_PLUS:
		return Key::Plus;
	case SDLK_BACKSPACE:
		return Key::Backspace;
	case SDLK_RETURN:
		return Key::Enter;
	case SDLK_SPACE:
		return Key::Space;
	case SDLK_TAB:
		return Key::Tab;
	case SDLK_CAPSLOCK:
		return Key::CapsLock;
	case SDLK_LSHIFT:
		return Key::LeftShift;
	case SDLK_LCTRL:
		return Key::LeftControl;
	case SDLK_LALT:
		return Key::LeftAlt;
	case SDLK_RSHIFT:
		return Key::RightShift;
	case SDLK_RCTRL:
		return Key::RightControl;
	case SDLK_RALT:	
		return Key::RightAlt;
	case SDLK_INSERT:
		return Key::Insert;
	case SDLK_HOME:
		return Key::Home;
	case SDLK_PAGEUP:
		return Key::PageUp;
	case SDLK_PAGEDOWN:
		return Key::PageDown;
	case SDLK_DELETE:
		return Key::Delete;
	case SDLK_END:
		return Key::End;
	case SDLK_UP:
		return Key::Up;
	case SDLK_DOWN:
		return Key::Down;
	case SDLK_LEFT:
		return Key::Left;
	case SDLK_RIGHT:
		return Key::Right;
	default:
		harmony::log::error("Unknown key passed.");
		return Key::End;
	}
	
}

void harmony::Input::PostFrame()
{
	for (int button = Gamepad::Button::FaceNorth; button != Gamepad::Button::Start; button++)
	{
		Gamepad::Button padButton = static_cast<Gamepad::Button>(button);
		for (int pad = 0; pad < g_NumGamepads; pad++)
		{
			bool activeCurrentFrame = p_GamepadStates[pad].CurrentFrameButtonState[padButton];
			bool activePreviousFrame = p_GamepadStates[pad].PreviousFrameButtonState[padButton];
			bool updatedThisFrame = activeCurrentFrame != activePreviousFrame;
			if (updatedThisFrame)
			{
				p_GamepadStates[pad].PreviousFrameButtonState[padButton] = activeCurrentFrame;
			}
		}
	}

	for (int button = Gamepad::Trigger::LT; button != Gamepad::Trigger::RT; button++)
	{
		Gamepad::Trigger padButton = static_cast<Gamepad::Trigger>(button);
		for (int pad = 0; pad < g_NumGamepads; pad++)
		{
			float valueCurrentFrame = p_GamepadStates[pad].CurrentFrameTriggerState[padButton];
			float valuePreviousFrame = p_GamepadStates[pad].PreviousFrameTriggerState[padButton];
			
			float diff = std::abs(valueCurrentFrame - valuePreviousFrame);
			if (diff > 0.001f)
			{
				p_GamepadStates[pad].PreviousFrameTriggerState[padButton] = valueCurrentFrame;
			}
		}
	}

	for (int button = Gamepad::Stick::LS; button != Gamepad::Stick::RS; button++)
	{
		Gamepad::Stick padButton = static_cast<Gamepad::Stick>(button);
		for (int pad = 0; pad < g_NumGamepads; pad++)
		{
			glm::vec2 valueCurrentFrame = p_GamepadStates[pad].CurrentFrameStickState[padButton];
			glm::vec2 valuePreviousFrame = p_GamepadStates[pad].PreviousFrameStickState[padButton];
			bool updatedThisFrame = valueCurrentFrame != valuePreviousFrame;
		
			if (updatedThisFrame)
			{
				p_GamepadStates[pad].PreviousFrameStickState[padButton] = valueCurrentFrame;
			}
		}
	}

	for (int button = Key::A ; button != Key::Right; button++)
	{
		Key padButton = static_cast<Key>(button);
		for (int pad = 0; pad < g_NumGamepads; pad++)
		{
			bool activeCurrentFrame = p_KeyboardState.CurrentFrameKeyState[padButton];
			bool activePreviousFrame = p_KeyboardState.PreviousFrameKeyState[padButton];
			bool updatedThisFrame = activeCurrentFrame != activePreviousFrame;
			if (updatedThisFrame)
			{
				p_KeyboardState.PreviousFrameKeyState[padButton] = activeCurrentFrame;
			}
		}
	}

	for (int button = Mouse::Button::Left; button != Mouse::Button::Extra3; button++)
	{
		Mouse::Button mouseButton = static_cast<Mouse::Button>(button);
		bool activeCurrentFrame = p_MouseState.CurrentFrameButtonState[mouseButton];
		bool activePreviousFrame = p_MouseState.PreviousFrameButtonState[mouseButton];
		bool updatedThisFrame = activeCurrentFrame != activePreviousFrame;
		if (updatedThisFrame)
		{
			p_MouseState.PreviousFrameButtonState[mouseButton] = activeCurrentFrame;
		}
	}

}

void harmony::Input::Init()
{
	for (int i = 0; i < g_NumGamepads; i++)
	{
		p_GamepadStates.emplace_back(GamepadState());
	}

	for (int button = Gamepad::Button::FaceNorth; button != Gamepad::Button::Start; button++)
	{
		Gamepad::Button padButton = static_cast<Gamepad::Button>(button);
		for (int pad = 0; pad < g_NumGamepads; pad++)
		{
			p_GamepadStates[pad].CurrentFrameButtonState.emplace(padButton, false);
			p_GamepadStates[pad].PreviousFrameButtonState.emplace(padButton, false);
		}
	}

	for (int trigger = Gamepad::Trigger::LT; trigger != Gamepad::Trigger::RT; trigger++)
	{
		Gamepad::Trigger padTrigger = static_cast<Gamepad::Trigger>(trigger);
		for (int pad = 0; pad < g_NumGamepads; pad++)
		{
			p_GamepadStates[pad].CurrentFrameTriggerState.emplace(padTrigger, 0.0f);
			p_GamepadStates[pad].PreviousFrameTriggerState.emplace(padTrigger, 0.0f);
		}
	}

	for (int stick = Gamepad::Stick::LS; stick != Gamepad::Stick::RS; stick++)
	{
		Gamepad::Stick padStick = static_cast<Gamepad::Stick>(stick);
		for (int pad = 0; pad < g_NumGamepads; pad++)
		{
			p_GamepadStates[pad].CurrentFrameStickState.emplace(padStick, glm::vec2(0.0));
			p_GamepadStates[pad].PreviousFrameStickState.emplace(padStick, glm::vec2(0.0));
		}
	}

	for (int button = Key::A; button != Key::Right; button++)
	{
		Key key= static_cast<Key>(button);
		p_KeyboardState.CurrentFrameKeyState.emplace(key, false);
		p_KeyboardState.PreviousFrameKeyState.emplace(key, false);
	}

	p_MouseState.CurrentFrameMouseLocation = glm::vec2(0.0);
	p_MouseState.PreviousFrameMouseLocation = glm::vec2(0.0);

	for (int button = Mouse::Button::Left; button != Mouse::Button::Extra3; button++)
	{
		Mouse::Button mouseButton = static_cast<Mouse::Button>(button);
		p_MouseState.CurrentFrameButtonState.emplace(mouseButton, false);
		p_MouseState.PreviousFrameButtonState.emplace(mouseButton, false);
	}
}