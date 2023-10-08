// Copyright © Amer Koleci and Contributors.
// Licensed under the MIT License (MIT). See LICENSE in the repository root for more information.

using System;
using System.Numerics;
using static HarmonyJoltSharp.JoltApi;

namespace HarmonyJoltSharp
{

    public sealed class SliderConstraintSettings : TwoBodyConstraintSettings
    {
        public SliderConstraintSettings()
            : base(JPH_SliderConstraintSettings_Create())
        {
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="SliderConstraintSettings" /> class.
        /// </summary>
        ~SliderConstraintSettings() => Dispose(isDisposing: false);

        public override TwoBodyConstraint CreateConstraint(in Body body1, in Body body2)
        {
            return new SliderConstraint(JPH_SliderConstraintSettings_CreateConstraint(Handle, body1.Handle, body2.Handle));
        }

        public void SetSliderAxis(in Vector3 axis)
        {
            JPH_SliderConstraintSettings_SetSliderAxis(Handle, in axis);
        }
    }

    public sealed class SliderConstraint : TwoBodyConstraint
    {
        internal SliderConstraint(IntPtr handle)
            : base(handle)
        {
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="SliderConstraint" /> class.
        /// </summary>
        ~SliderConstraint() => Dispose(isDisposing: false);
    }
}