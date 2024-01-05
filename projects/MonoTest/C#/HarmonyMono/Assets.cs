using System;
using System.Runtime.CompilerServices;

namespace Harmony
{
    struct AssetHandle
    {
        string  Path;
        uint    Index;
        ulong   TypeHash; 
    }

    public static class AssetMethods
    {
        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static AssetHandle[] GetAssetsAtPath(string path);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static Texture GetTextureAsset(AssetHandle handle);

        [MethodImpl(MethodImplOptions.InternalCall)]
        internal extern static Mesh GetMeshAsset(AssetHandle handle);
    }
}
