#include "Rendering/Model.h"

uint32_t harmony::ModelHandle::p_Counter = 0;

harmony::ModelHandle harmony::ModelHandle::CreateNew()
{
	p_Counter++;
	ModelHandle handle{ p_Counter };
	return handle;
}

harmony::Model::Model(const std::string& name) :Asset(GetTypeHash<Model>()), m_Handle(ModelHandle::CreateNew()), m_Name(name)
{
}