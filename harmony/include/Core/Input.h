#pragma once
// TODO when need arises, revisit input, potentially as a program component
// Singletons are not great.
#include <map>
#include <vector>
#include "glm/glm.hpp"
#include "SDL.h"
namespace harmony {

	namespace Gamepad
	{
		enum Button
		{
			FaceNorth,
			FaceSouth,
			FaceEast,
			FaceWest,
			Up,
			Down,
			Left,
			Right,
			RightBumper,
			LeftBumper,
			Home,
			Select,
			Start
		};

		enum Stick
		{
			LS,
			RS
		};

		enum Trigger
		{
			LT,
			RT
		};

	};
	namespace Mouse
	{
		enum Button
		{
			Left,
			Middle,
			Right,
			Extra1,
			Extra2,
			Extra3
		};

	};

	enum Key
	{
		A,
		B,
		C,
		D,
		E,
		F,
		G,
		H,
		I,
		J,
		K,
		L,
		M,
		N,
		O,
		P,
		Q,
		R,
		S,
		T,
		U,
		V,
		W,
		X,
		Y,
		Z,
		Zero,
		One,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Minus,
		Underscore,
		Equals,
		Plus,
		Backspace,
		Enter,
		Space,
		Tab,
		CapsLock,
		Tilde,
		LeftShift,
		LeftControl,
		LeftAlt,
		RightShift,
		RightControl,
		RightAlt,
		F1,
		F2,
		F3,
		F4,
		F5,
		F6,
		F7,
		F8,
		F9,
		F10,
		F11,
		F12,
		Insert,
		Home,
		PageUp,
		PageDown,
		Delete,
		End,
		Up,
		Down,
		Left,
		Right

	};

	struct GamepadState
	{
		std::map<Gamepad::Button, bool> CurrentFrameButtonState;
		std::map<Gamepad::Button, bool> PreviousFrameButtonState;

		std::map<Gamepad::Trigger, float> CurrentFrameTriggerState;
		std::map<Gamepad::Trigger, float> PreviousFrameTriggerState;

		std::map<Gamepad::Stick, glm::vec2> CurrentFrameStickState;
		std::map<Gamepad::Stick, glm::vec2> PreviousFrameStickState;
	};

	struct MouseState
	{
		std::map<Mouse::Button, bool> CurrentFrameButtonState;
		std::map<Mouse::Button, bool> PreviousFrameButtonState;

		float CurrentFrameScroll;
		float PreviousFrameScroll;

		glm::vec2 CurrentFrameMouseLocation;
		glm::vec2 PreviousFrameMouseLocation;
	};

	struct KeyboardState
	{
		std::map<Key, bool> CurrentFrameKeyState;
		std::map<Key, bool> PreviousFrameKeyState;
	};

	class Input
	{
	public:
		void UpdateMouseScroll(float val);
		void UpdateMousePosition(glm::vec2 mousePosition);
		void UpdateMouseButton(Mouse::Button button, bool active);

		void UpdateKey(Key key, bool active);

		void UpdateGamepadButton(int gamepadIndex, Gamepad::Button button, bool active);
		void UpdateGamepadTrigger(int gamepadIndex, Gamepad::Trigger trigger, float value);
		void UpdateGamepadStick(int gamepadIndex, Gamepad::Stick stick, glm::vec2 value);

		void		OnControllerConnected(uint8_t index);
		void		OnControllerDisconnected(uint8_t index);

		glm::vec2	GetMousePosition();
		glm::vec2	GetMousePositionLastFrame();

		bool		GetMouseButton(Mouse::Button button);
		bool		GetMouseButtonJustPressed(Mouse::Button button);
		bool		GetMouseButtonJustReleased(Mouse::Button button);

		bool GetKey(Key key);
		bool GetKeyJustPressed(Key key);
		bool GetKeyJustReleased(Key key);

		bool GetGamepadButton(int gamepadIndex, Gamepad::Button button);
		bool GetGamepadButtonJustPressed(int gamepadIndex, Gamepad::Button button);
		bool GetGamepadButtonJustReleased(int gamepadIndex, Gamepad::Button button);

		float GetGamepadTrigger(int gamepadIndex, Gamepad::Trigger trigger);
		glm::vec2 GetGamepadStick(int gamepadIndex, Gamepad::Stick stick);

		static Key GetKeyFromSDLKeycode(SDL_Keycode keyCode);
		static Mouse::Button GetMouseButtonFromSDLKeycode(SDL_KeyCode keyCode);

		void PostFrame();
		static Input* Get();
		~Input();
		const uint8_t g_NumGamepads = 4;
	private:
		Input();
		inline static Input* p_Instance = nullptr;
		
		KeyboardState p_KeyboardState;
		MouseState p_MouseState;
		std::vector<GamepadState> p_GamepadStates;
	};
};