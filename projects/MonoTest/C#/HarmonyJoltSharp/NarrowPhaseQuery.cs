// Copyright © Amer Koleci and Contributors.
// Licensed under the MIT License (MIT). See LICENSE in the repository root for more information.
using System;
using System.Numerics;
using static HarmonyJoltSharp.JoltApi;

namespace HarmonyJoltSharp
{

    public readonly struct NarrowPhaseQuery : IEquatable<NarrowPhaseQuery>
    {
        public NarrowPhaseQuery(IntPtr handle) { Handle = handle; }
        public IntPtr Handle { get; }
        public bool IsNull => Handle == IntPtr.Zero;
        public static NarrowPhaseQuery Null => new NarrowPhaseQuery(IntPtr.Zero);
        public static implicit operator NarrowPhaseQuery(IntPtr handle) => new NarrowPhaseQuery(handle);
        public static bool operator ==(NarrowPhaseQuery left, NarrowPhaseQuery right) => left.Handle == right.Handle;
        public static bool operator !=(NarrowPhaseQuery left, NarrowPhaseQuery right) => left.Handle != right.Handle;
        public static bool operator ==(NarrowPhaseQuery left, IntPtr right) => left.Handle == right;
        public static bool operator !=(NarrowPhaseQuery left, IntPtr right) => left.Handle != right;
        public bool Equals(NarrowPhaseQuery other) => Handle == other.Handle;

        /// <inheritdoc/>
        public override bool Equals(object obj) => obj is NarrowPhaseQuery handle && Equals(handle);

        /// <inheritdoc/>
        public override int GetHashCode() => Handle.GetHashCode();

        public bool CastRay(in Double3 origin, in Vector3 direction, ref RayCastResult hit, BroadPhaseLayerFilter broadPhaseFilter,
            ObjectLayerFilter objectLayerFilter, BodyFilter bodyFilter)
        {
            Bool32 result = JPH_NarrowPhaseQuery_CastRay(Handle, origin, direction, ref hit, broadPhaseFilter.Handle, objectLayerFilter.Handle, bodyFilter.Handle);
            return result;
        }
    }
}