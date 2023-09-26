using System;

namespace Harmony
{
    /// <summary>
    /// ID must match entt entity index.
    /// </summary>
    public struct Entity
    {
        public Entity(uint id)
        {
            ID = id;
        }

        public readonly uint ID;
        public static implicit operator uint (Entity entity) { return entity.ID; }

        public override string ToString()
        {
            return $"{ID}";
        }
    }

    public interface IComponent{}

    public interface INativeComponent : IComponent {}

    public interface IScriptComponent : IComponent {}

    public static class ECS
    {

        public static T GetComponent<T> (Entity entity) where T : IComponent
        {
            // is T a built in component
            // is T a C# defined component
            return default;
        }

        public static void SomeExtension (this Entity e)
        {

        }
    }
}
