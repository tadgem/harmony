// Copyright © Amer Koleci and Contributors.
// Licensed under the MIT License (MIT). See LICENSE in the repository root for more information.

using System;
using static HarmonyJoltSharp.JoltApi;

namespace HarmonyJoltSharp
{

    public abstract class ConstraintSettings : NativeObject
    {
        protected ConstraintSettings()
        {
        }

        protected ConstraintSettings(IntPtr handle)
            : base(handle)
        {
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="ConstraintSettings" /> class.
        /// </summary>
        ~ConstraintSettings() => Dispose(isDisposing: false);

        protected override void Dispose(bool isDisposing)
        {
            if (isDisposing)
            {
                JPH_ConstraintSettings_Destroy(Handle);
            }
        }
    }

    public abstract class Constraint : NativeObject
    {
        protected Constraint(IntPtr handle)
            : base(handle)
        {
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="Constraint" /> class.
        /// </summary>
        ~Constraint() => Dispose(isDisposing: false);

        protected override void Dispose(bool isDisposing)
        {
            if (isDisposing)
            {
                JPH_Constraint_Destroy(Handle);
            }
        }

        // TODO: Handle type of settings here stuff here
        public IntPtr ConstraintSettings
        {
            get => JPH_Constraint_GetConstraintSettings(Handle);
        }

        public bool Enabled
        {
            get => JPH_Constraint_GetEnabled(Handle);
            set => JPH_Constraint_SetEnabled(Handle, value);
        }
    }
}