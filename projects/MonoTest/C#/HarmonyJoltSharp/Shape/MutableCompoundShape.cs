// Copyright © Amer Koleci and Contributors.
// Licensed under the MIT License (MIT). See LICENSE in the repository root for more information.
using System;
using static HarmonyJoltSharp.JoltApi;

namespace HarmonyJoltSharp
{

    public sealed class MutableCompoundShapeSettings : CompoundShapeShapeSettings
    {
        public MutableCompoundShapeSettings()
            : base(JPH_MutableCompoundShapeSettings_Create())
        {
        }
    }

    public sealed class MutableCompoundShape : CompoundShape
    {
        internal MutableCompoundShape(IntPtr handle)
            : base(handle)
        {
        }
    }
}