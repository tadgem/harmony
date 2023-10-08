// Copyright © Amer Koleci and Contributors.
// Licensed under the MIT License (MIT). See LICENSE in the repository root for more information.

using System;
using System.Numerics;
using static HarmonyJoltSharp.JoltApi;

namespace HarmonyJoltSharp
{

    public class DistanceConstraintSettings : TwoBodyConstraintSettings
    {
        internal DistanceConstraintSettings(IntPtr handle)
            : base(handle)
        {
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="DistanceConstraintSettings" /> class.
        /// </summary>
        ~DistanceConstraintSettings() => Dispose(isDisposing: false);

        public Vector3 Point1
        {
            get
            {
                JPH_DistanceConstraintSettings_GetPoint1(Handle, out Vector3 value);
                return value;
            }
            set
            {
                JPH_DistanceConstraintSettings_SetPoint1(Handle, value);
            }
        }

        public Vector3 Point2
        {
            get
            {
                JPH_DistanceConstraintSettings_GetPoint2(Handle, out Vector3 value);
                return value;
            }
            set
            {
                JPH_DistanceConstraintSettings_SetPoint2(Handle, value);
            }
        }

        public override TwoBodyConstraint CreateConstraint(in Body body1, in Body body2)
        {
            return new DistanceConstraint(JPH_DistanceConstraintSettings_CreateConstraint(Handle, body1.Handle, body2.Handle));
        }
    }

    public class DistanceConstraint : TwoBodyConstraint
    {
        internal DistanceConstraint(IntPtr handle)
            : base(handle)
        {
        }

        /// <summary>
        /// Finalizes an instance of the <see cref="DistanceConstraint" /> class.
        /// </summary>
        ~DistanceConstraint() => Dispose(isDisposing: false);
    }
}