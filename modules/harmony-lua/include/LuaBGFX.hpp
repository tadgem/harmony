#pragma once

#include "sol/sol.hpp"
#include "bgfx/bgfx.h"

static void bind_bgfx(sol::state& state)
{
	sol::table bgfx = state.create_named_table("bgfx");
	
	bgfx.new_usertype<bgfx::UniformHandle>("UniformHandle", "idx", &bgfx::UniformHandle::idx);
	bgfx.new_usertype<bgfx::ShaderHandle>("ShaderHandle", "idx", &bgfx::ShaderHandle::idx);
	bgfx.new_usertype<bgfx::ProgramHandle>("ProgramHandle", "idx", &bgfx::ProgramHandle::idx);
	bgfx.new_usertype<bgfx::TextureHandle>("TextureHandle", "idx", &bgfx::TextureHandle::idx);
	bgfx.new_usertype<bgfx::FrameBufferHandle>("FrameBufferHandle", "idx", &bgfx::FrameBufferHandle::idx);
	bgfx.new_usertype<bgfx::VertexBufferHandle>("VertexBufferHandle", "idx", &bgfx::VertexBufferHandle::idx);
	bgfx.new_usertype<bgfx::IndexBufferHandle>("IndexBufferHandle", "idx", &bgfx::IndexBufferHandle::idx);
	bgfx.new_usertype<bgfx::DynamicVertexBufferHandle>("DynamicVertexBufferHandle", "idx", &bgfx::DynamicVertexBufferHandle::idx);
	bgfx.new_usertype<bgfx::DynamicIndexBufferHandle>("DynamicIndexBufferHandle", "idx", &bgfx::DynamicIndexBufferHandle::idx);
	bgfx.new_usertype<bgfx::VertexLayoutHandle>("VertexLayoutHandle", "idx", &bgfx::VertexLayoutHandle::idx);

}