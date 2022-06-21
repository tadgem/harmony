#include "Core/Input.h"
#include "Core/Log.hpp"
void harmony::Input::UpdateMousePosition(glm::vec2 mousePosition)
{
	p_MouseState.PreviousFrameMouseLocation = p_MouseState.CurrentFrameMouseLocation;
	p_MouseState.CurrentFrameMouseLocation = mousePosition;
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

glm::vec2 harmony::Input::GetMousePosition()
{
	return p_MouseState.CurrentFrameMouseLocation;
}

glm::vec2 harmony::Input::GetMousePositionLastFrame()
{
	return p_MouseState.PreviousFrameMouseLocation;
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

harmony::Input* harmony::Input::Get()
{
	if (p_Instance == nullptr)
	{
		p_Instance = new Input();
	}
	return p_Instance;
}

harmony::Input::Input()
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

harmony::Input::~Input()
{
	if (p_Instance)
	{
		delete p_Instance;
	}
}
