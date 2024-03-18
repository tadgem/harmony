#pragma once

#include "Core/TypeDef.h"
#include "bgfx/bgfx.h"
#include "glm.hpp"
#include "glm/gtc/quaternion.hpp"
#include <string>

namespace glm {
    inline void to_json(harmony::Json &j, const glm::vec2 &v) {
        j = harmony::Json{{"x", v.x},
                           {"y", v.y}};
    }

    inline void from_json(const harmony::Json &j, glm::vec2 &v) {
        j.at("x").get_to(v.x);
        j.at("y").get_to(v.y);
    }

    inline void to_json(harmony::Json &j, const glm::vec3 &v) {
        j = harmony::Json{{"x", v.x},
                           {"y", v.y},
                           {"z", v.z}};
    }

    inline void from_json(const harmony::Json &j, glm::vec3 &v) {
        j.at("x").get_to(v.x);
        j.at("y").get_to(v.y);
        j.at("z").get_to(v.z);
    }

    inline void to_json(harmony::Json &j, const glm::vec4 &v) {
        j = harmony::Json{{"x", v.x},
                           {"y", v.y},
                           {"z", v.z},
                           {"w", v.w}};
    }

    inline void from_json(const harmony::Json &j, glm::vec4 &v) {
        j.at("x").get_to(v.x);
        j.at("y").get_to(v.y);
        j.at("z").get_to(v.z);
        j.at("w").get_to(v.w);
    }

    inline void to_json(harmony::Json &j, const glm::mat3 &v) {
        j = harmony::Json{
                {"0", v[0]},
                {"1", v[1]},
                {"2", v[2]},
                {"3", v[3]},
                {"4", v[4]},
                {"5", v[5]},
                {"6", v[6]},
                {"7", v[7]},
                {"8", v[8]},
        };
    }

    inline void from_json(const harmony::Json &j, glm::mat3 &v) {
        j.at("0").get_to(v[0]);
        j.at("1").get_to(v[1]);
        j.at("2").get_to(v[2]);
        j.at("3").get_to(v[3]);
        j.at("4").get_to(v[4]);
        j.at("5").get_to(v[5]);
        j.at("6").get_to(v[6]);
        j.at("7").get_to(v[7]);
        j.at("8").get_to(v[8]);
    }

    inline void to_json(harmony::Json &j, const glm::mat4 &v) {
        j = harmony::Json{
                {"row0", v[0]},
                {"row1", v[1]},
                {"row2", v[2]},
                {"row3", v[3]}};
    }

    inline void from_json(const harmony::Json &j, glm::mat4 &v) {
        j.at("row0").get_to(v[0]);
        j.at("row1").get_to(v[1]);
        j.at("row2").get_to(v[2]);
        j.at("row3").get_to(v[3]);
    }

    inline void to_json(harmony::Json &j, const glm::quat &v) {
        j = harmony::Json{{"x", v.x},
                           {"y", v.y},
                           {"z", v.z},
                           {"w", v.w}};
    }

    inline void from_json(const harmony::Json &j, glm::quat &v) {
        j.at("x").get_to(v.x);
        j.at("y").get_to(v.y);
        j.at("z").get_to(v.z);
        j.at("w").get_to(v.w);
    }
} // namespace glm
namespace harmony {
    struct ShaderUniform {
        bgfx::UniformHandle BgfxHandle{UINT16_MAX};
        String Name;
        bgfx::UniformType::Enum Type;
        uint16_t ArraySize;

        bool Valid();

        bool operator<(const ShaderUniform &o) const {
            return BgfxHandle.idx < o.BgfxHandle.idx;
        }

        bool operator==(const ShaderUniform &o) const {
            return BgfxHandle.idx == o.BgfxHandle.idx && Type == o.Type;
        }

        bool operator!=(const ShaderUniform &o) const {
            return BgfxHandle.idx != o.BgfxHandle.idx || Type != o.Type;
        }

        operator bgfx::UniformHandle &() {
            return BgfxHandle;
        }

        operator bgfx::UniformHandle() const {
            return BgfxHandle;
        }

        NLOHMANN_DEFINE_TYPE_INTRUSIVE(ShaderUniform, Name, Type)
    };
} // namespace harmony