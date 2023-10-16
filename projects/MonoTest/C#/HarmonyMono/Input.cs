using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace Harmony
{
    public static class Input
    {
        public enum GamepadButton
        {
            ButtonInvalid = -1,
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

        public enum GamepadStick
        {
            StickInvalid = -1,
            LS,
            RS
        };
        public enum GamepadTrigger
        {
            Invalid = -1,
            LT,
            RT
        };
        public enum MouseButton
        {
            Invalid = -1,
            Left,
            Middle,
            Right,
            Extra1,
            Extra2,
            Extra3
        };
        public enum Key
        {
            KeyInvalid = -1,
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
            HomeKey,
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
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static Vector2 GetMousePosition();
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static Vector2 GetMousePositionLastFrame();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static Vector2 GetMouseVelocity();
        
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static Vector2 GetMouseVelocityLastFrame();

        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static bool GetMouseButton(MouseButton button);
        [MethodImpl(MethodImplOptions.InternalCall)]
        public extern static bool GetMouseButtonJustPressed(MouseButton button);
        [MethodImpl(MethodImplOptions.InternalCall)] 
        public extern static bool GetMouseButtonJustReleased(MouseButton button);
        
        [MethodImpl(MethodImplOptions.InternalCall)] 
        public extern static bool GetKeyButton(Key key);
    
        [MethodImpl(MethodImplOptions.InternalCall)] 
        public extern static bool GetKeyButtonJustPressed(Key key);
    
        [MethodImpl(MethodImplOptions.InternalCall)] 
        public extern static bool GetKeyButtonJustReleased(Key key);
        
        [MethodImpl(MethodImplOptions.InternalCall)] 
        public extern static bool GetGamepadButton(int gamepadIndex, GamepadButton button);
        [MethodImpl(MethodImplOptions.InternalCall)] 
        public extern static bool GetGamepadButtonJustPressed(int gamepadIndex, GamepadButton button);
        [MethodImpl(MethodImplOptions.InternalCall)] 
        public extern static bool GetGamepadButtonJustReleased(int gamepadIndex, GamepadButton button);
        [MethodImpl(MethodImplOptions.InternalCall)] 
        public extern static float GetGamepadTrigger(int gamepadIndex, GamepadTrigger trigger);
        [MethodImpl(MethodImplOptions.InternalCall)] 
        public extern static Vector2 GetGamepadStick(int gamepadIndex, GamepadStick stick);
    }
}
