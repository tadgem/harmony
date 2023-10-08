// Copyright © Amer Koleci and Contributors.
// Licensed under the MIT License (MIT). See LICENSE in the repository root for more information.
using System;
using System.Numerics;
using static HarmonyJoltSharp.JoltApi;

namespace HarmonyJoltSharp
{

    public readonly struct MotionProperties : IEquatable<MotionProperties>
    {
        public MotionProperties(IntPtr handle) { Handle = handle; }
        public IntPtr Handle { get; }
        public bool IsNull => Handle == IntPtr.Zero;
        public bool IsNotNull => Handle != IntPtr.Zero;
        public static MotionProperties Null => new MotionProperties(IntPtr.Zero);
        public static implicit operator MotionProperties(IntPtr handle) => new MotionProperties(handle);
        public static bool operator ==(MotionProperties left, MotionProperties right) => left.Handle == right.Handle;
        public static bool operator !=(MotionProperties left, MotionProperties right) => left.Handle != right.Handle;
        public static bool operator ==(MotionProperties left, IntPtr right) => left.Handle == right;
        public static bool operator !=(MotionProperties left, IntPtr right) => left.Handle != right;
        public bool Equals(MotionProperties other) => Handle == other.Handle;

        /// <inheritdoc/>
        public override bool Equals(object obj) => obj is MotionProperties handle && Equals(handle);

        /// <inheritdoc/>
        public override int GetHashCode() => Handle.GetHashCode();

        public float LinearDamping
        {
            get => JPH_MotionProperties_GetLinearDamping(Handle);
            set => JPH_MotionProperties_SetLinearDamping(Handle, value);
        }

        public float AngularDamping
        {
            get => JPH_MotionProperties_GetAngularDamping(Handle);
            set => JPH_MotionProperties_SetAngularDamping(Handle, value);
        }

        public float InverseMassUnchecked
        {
            get => JPH_MotionProperties_GetInverseMassUnchecked(Handle);
        }

        public void SetMassProperties(AllowedDOFs allowedDOFs, in MassProperties massProperties)
        {
            //JPH_MotionProperties_SetMassProperties(Handle, allowedDOFs, massProperties.Handle);
        }
    }
}