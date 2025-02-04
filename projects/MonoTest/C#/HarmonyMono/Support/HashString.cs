﻿

namespace Harmony.Support
{
    public class HashString
    {
        private readonly ulong _value;

        public HashString(string input)
        {
            _value = Hash(input);
        }

        private static ulong Hash(string input)
        {
            ulong r = 0;
            for(int i = 0; i < input.Length; i++)
            {
                char c = input[i];
                r ^= 397u * c;
            }
            return r;
        }

        public bool Equals(HashString other)
        {
            return _value == other._value;
        }

        public override bool Equals(object obj)
        {
            if(obj is HashString h) 
            {
                return this == h;
            }
            return false;
        }

        public override int GetHashCode()
        {
            return base.GetHashCode();
        }

        public override string ToString()
        {
            return $"{_value}";
        }

        public static bool operator == (HashString lhs, HashString rhs)
        {
            return lhs.Equals(rhs);
        }

        public static bool operator !=(HashString lhs, HashString rhs)
        {
            return !lhs.Equals(rhs);
        }

    }
}
