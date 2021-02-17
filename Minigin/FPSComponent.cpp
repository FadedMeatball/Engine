#include "MiniginPCH.h"
#include "FPSComponent.h"
#include "ResourceManager.h"
#include "TextObject.h"

dae::FPSComponent::FPSComponent()
	: BaseComponent(Transform())
	, m_FPS(60.f)
{
}

void dae::FPSComponent::Update(float const dt)
{
	m_FPS = 1.f / dt;
}

void dae::FPSComponent::Render() const
{
}

int dae::FPSComponent::GetFPS() const
{
	return static_cast<int>(m_FPS);
}
