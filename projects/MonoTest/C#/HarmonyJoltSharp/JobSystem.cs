// Copyright © Amer Koleci and Contributors.
// Licensed under the MIT License (MIT). See LICENSE in the repository root for more information.
using System;
using static HarmonyJoltSharp.JoltApi;

namespace HarmonyJoltSharp
{

    public abstract class JobSystem : NativeObject
    {
        public JobSystem(IntPtr handle)
            : base(handle)
        {
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="JobSystem" /> class.
        /// </summary>
        ~JobSystem() => Dispose(disposing: false);

        protected override void Dispose(bool disposing)
        {
            if (disposing)
            {
                JPH_JobSystem_Destroy(Handle);
            }
        }
    }
}