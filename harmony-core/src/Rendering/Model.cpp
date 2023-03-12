#include "Rendering/Model.h"

uint32_t harmony::ModelHandle::p_Counter = 0;

harmony::ModelHandle harmony::ModelHandle::CreateNew()
{
	p_Counter++;
	ModelHandle handle{ p_Counter };
	return handle;
}

harmony::Model::Model(const String& name) :Asset(AssetHandle{name, 0, GetTypeHash<Model>()}),  m_Name(name)
{
}