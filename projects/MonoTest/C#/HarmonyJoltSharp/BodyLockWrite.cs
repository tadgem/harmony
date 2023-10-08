// Copyright © Amer Koleci and Contributors.
// Licensed under the MIT License (MIT). See LICENSE in the repository root for more information.

using System;

namespace HarmonyJoltSharp
{

    public readonly struct BodyLockWrite
    {
        public readonly BodyLockInterface LockInterface;
        public readonly IntPtr Mutex; /* JPH_SharedMutex */
        public readonly Body Body;
    }
}