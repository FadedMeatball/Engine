#include "MiniginPCH.h"
#include "BaseComponent.h"

dae::BaseComponent::BaseComponent(const dae::Transform& transform)
	: m_Transform{transform}
{
}

dae::Transform dae::BaseComponent::GetTransform() const
{
	return m_Transform;
}


void dae::BaseComponent::SetTransform(const dae::Transform& transform)
{
	m_Transform = transform;
}
