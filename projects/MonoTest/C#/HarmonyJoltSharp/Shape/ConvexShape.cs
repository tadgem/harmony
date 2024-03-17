// Copyright © Amer Koleci and Contributors.
// Licensed under the MIT License (MIT). See LICENSE in the repository root for more information.

using static HarmonyJoltSharp.JoltApi;
using System;
namespace HarmonyJoltSharp
{

    public abstract class ConvexShapeSettings : ShapeSettings
    {
        protected ConvexShapeSettings()
        {
        }

        internal ConvexShapeSettings(IntPtr handle)
            : base(handle)
        {
        }

        public float Density
        {
            get => JPH_ConvexShapeSettings_GetDensity(Handle);
            set => JPH_ConvexShapeSettings_SetDensity(Handle, value);
        }
    }

    public abstract class ConvexShape : Shape
    {
        internal ConvexShape(IntPtr handle)
            : base(handle)
        {
        }

        public float Density
        {
            get => JPH_ConvexShape_GetDensity(Handle);
            set => JPH_ConvexShape_SetDensity(Handle, value);
        }
    }
}