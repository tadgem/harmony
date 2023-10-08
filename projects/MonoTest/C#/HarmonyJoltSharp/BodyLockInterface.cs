// Copyright © Amer Koleci and Contributors.
// Licensed under the MIT License (MIT). See LICENSE in the repository root for more information.
using System;
using static HarmonyJoltSharp.JoltApi;

namespace HarmonyJoltSharp
{

    public readonly struct BodyLockInterface : IEquatable<BodyLockInterface>
    {
        public BodyLockInterface(IntPtr handle) { Handle = handle; }
        public IntPtr Handle { get; }
        public bool IsNull => Handle == IntPtr.Zero;
        public static BodyLockInterface Null => new BodyLockInterface(IntPtr.Zero);
        public static implicit operator BodyLockInterface(IntPtr handle) => new BodyLockInterface(handle);
        public static bool operator ==(BodyLockInterface left, BodyLockInterface right) => left.Handle == right.Handle;
        public static bool operator !=(BodyLockInterface left, BodyLockInterface right) => left.Handle != right.Handle;
        public static bool operator ==(BodyLockInterface left, IntPtr right) => left.Handle == right;
        public static bool operator !=(BodyLockInterface left, IntPtr right) => left.Handle != right;
        public bool Equals(BodyLockInterface other) => Handle == other.Handle;

        /// <inheritdoc/>
        public override bool Equals(object obj) => obj is BodyLockInterface handle && Equals(handle);

        /// <inheritdoc/>
        public override int GetHashCode() => Handle.GetHashCode();

        public void LockRead(in BodyID bodyID, out BodyLockRead @lock)
        {
            JPH_BodyLockInterface_LockRead(Handle, bodyID, out @lock);
        }

        public void UnlockRead(in BodyLockRead @lock)
        {
            JPH_BodyLockInterface_UnlockRead(Handle, in @lock);
        }

        public void LockWrite(in BodyID bodyID, out BodyLockWrite @lock)
        {
            JPH_BodyLockInterface_LockWrite(Handle, bodyID, out @lock);
        }

        public void UnlockWrite(in BodyLockWrite @lock)
        {
            JPH_BodyLockInterface_UnlockWrite(Handle, in @lock);
        }
    }
}