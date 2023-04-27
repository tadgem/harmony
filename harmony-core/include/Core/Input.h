#pragma once
// TODO when need arises, revisit input, potentially as a program component
// Singletons are not great.
#include <map>
#include <vector>
#include "glm/glm.hpp"
#include "SDL.h"

namespace harmony {

    namespace Gamepad {
        enum class Button {
            Invalid = -1,
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
            Start,
            LS,
            RS
        };

        enum class Stick {
            Invalid = -1,
            LS,
            RS
        };

        enum class Trigger {
            Invalid = -1,
            LT,
            RT
        };

    };
    namespace Mouse {
        enum class Button {
            Invalid = -1,
            Left,
            Middle,
            Right,
            Extra1,
            Extra2,
            Extra3
        };

    };

    enum class Key {
        Invalid = -1,
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
        Right,
        Escape

    };

    struct GamepadState {
        std::map<Gamepad::Button, bool> CurrentFrameButtonState;
        std::map<Gamepad::Button, bool> PreviousFrameButtonState;

        std::map<Gamepad::Trigger, float> CurrentFrameTriggerState;
        std::map<Gamepad::Trigger, float> PreviousFrameTriggerState;

        std::map<Gamepad::Stick, glm::vec2> CurrentFrameStickState;
        std::map<Gamepad::Stick, glm::vec2> PreviousFrameStickState;
    };

    struct MouseState {
        std::map<Mouse::Button, bool> CurrentFrameButtonState;
        std::map<Mouse::Button, bool> PreviousFrameButtonState;

        float CurrentFrameScroll;
        float PreviousFrameScroll;

        glm::vec2 CurrentFrameMouseLocation;
        glm::vec2 PreviousFrameMouseLocation;

        glm::vec2 CurrentFrameMouseVelocity;
        glm::vec2 PreviousFrameMouseVelocity;
    };

    struct KeyboardState {
        std::map<Key, bool> CurrentFrameKeyState;
        std::map<Key, bool> PreviousFrameKeyState;
    };

    class Input {
    public:
        static void UpdateMouseScroll(float val);

        static void UpdateMousePosition(glm::vec2 mousePosition);

        static void UpdateMouseButton(Mouse::Button button, bool active);

        static void UpdateKey(Key key, bool active);

        static void UpdateGamepadButton(int gamepadIndex, Gamepad::Button button, bool active);

        static void UpdateGamepadTrigger(int gamepadIndex, Gamepad::Trigger trigger, float value);

        static void UpdateGamepadStick(int gamepadIndex, Gamepad::Stick stick, glm::vec2 value);

        static void OnControllerConnected(uint8_t index);

        static void OnControllerDisconnected(uint8_t index);

        static glm::vec2 GetMousePosition();

        static glm::vec2 GetMousePositionLastFrame();

        static glm::vec2 GetMouseVelocity();

        static glm::vec2 GetMouseVelocityLastFrame();

        static bool GetMouseButton(Mouse::Button button);

        static bool GetMouseButtonJustPressed(Mouse::Button button);

        static bool GetMouseButtonJustReleased(Mouse::Button button);

        static bool GetKey(Key key);

        static bool GetKeyJustPressed(Key key);

        static bool GetKeyJustReleased(Key key);

        static bool GetGamepadButton(int gamepadIndex, Gamepad::Button button);

        static bool GetGamepadButtonJustPressed(int gamepadIndex, Gamepad::Button button);

        static bool GetGamepadButtonJustReleased(int gamepadIndex, Gamepad::Button button);

        static float GetGamepadTrigger(int gamepadIndex, Gamepad::Trigger trigger);

        static glm::vec2 GetGamepadStick(int gamepadIndex, Gamepad::Stick stick);

        static Key GetKeyFromSDLKeycode(SDL_Keycode keyCode);

        static Mouse::Button GetMouseButtonFromSDLKeycode(SDL_KeyCode keyCode);

        static void Init();

        static void PostFrame();

        static const uint8_t g_NumGamepads = 4;
    private:

        inline static KeyboardState p_KeyboardState;
        inline static MouseState p_MouseState;
        inline static std::vector<GamepadState> p_GamepadStates;
    };
};