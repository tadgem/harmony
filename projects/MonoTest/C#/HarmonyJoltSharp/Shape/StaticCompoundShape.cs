// Copyright © Amer Koleci and Contributors.
// Licensed under the MIT License (MIT). See LICENSE in the repository root for more information.
using System;
using static HarmonyJoltSharp.JoltApi;

namespace HarmonyJoltSharp
{

    public sealed class StaticCompoundShapeSettings : CompoundShapeShapeSettings
    {
        public StaticCompoundShapeSettings()
            : base(JPH_StaticCompoundShapeSettings_Create())
        {
        }
    }

    public sealed class StaticCompoundShape : CompoundShape
    {
        internal StaticCompoundShape(IntPtr handle)
            : base(handle)
        {
        }
    }
}