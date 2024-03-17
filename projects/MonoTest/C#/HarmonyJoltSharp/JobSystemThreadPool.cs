// Copyright © Amer Koleci and Contributors.
// Licensed under the MIT License (MIT). See LICENSE in the repository root for more information.

using static HarmonyJoltSharp.JoltApi;

namespace HarmonyJoltSharp
{

    public sealed class JobSystemThreadPool : JobSystem
    {
        public JobSystemThreadPool(int maxJobs, int maxBarriers, int inNumThreads = -1)
            : base(JPH_JobSystemThreadPool_Create((uint)maxJobs, (uint)maxBarriers, inNumThreads))
        {
        }
    }
}