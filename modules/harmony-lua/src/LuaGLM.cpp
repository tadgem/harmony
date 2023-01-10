#include "LuaGLM.hpp"
#include "glm.hpp"
#include "glm/detail/type_mat3x3.hpp"

void harmony::InitGLM(sol::state& state)
{
	sol::table glm = state.create_named_table("nvg");
	auto vec2type = glm.new_usertype<glm::vec2>("vec2", "x", &glm::vec2::x, "y",&glm::vec2::y);
	auto vec3type = glm.new_usertype<glm::vec3>("vec3", "x", &glm::vec3::x, "y", &glm::vec3::y, "z", &glm::vec3::z);
	auto vec4type = glm.new_usertype<glm::vec4>("vec4", "x", &glm::vec4::x, "y", &glm::vec4::y, "z", &glm::vec4::z, "z", &glm::vec4::w);
	
}
