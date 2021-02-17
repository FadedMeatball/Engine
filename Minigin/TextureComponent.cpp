#include "MiniginPCH.h"
#include "TextureComponent.h"
#include "Renderer.h"
#include "ResourceManager.h"

dae::TextureComponent::TextureComponent(const Transform& transform)
	: BaseComponent(transform)
{
	m_Texture = nullptr;
}

dae::TextureComponent::TextureComponent(const Transform& transform, const std::shared_ptr<Texture2D>& texture)
	: BaseComponent(transform)
	, m_Texture(texture)
{
}

void dae::TextureComponent::Update(float /*dt*/)
{
}

void dae::TextureComponent::Render() const
{
	const auto pos = m_Transform.GetPosition();
	Renderer::GetInstance().RenderTexture(*m_Texture, pos.x, pos.y);
}

std::shared_ptr<dae::Texture2D> dae::TextureComponent::GetTexture() const
{
	return m_Texture;
}

void dae::TextureComponent::SetTexture(const std::string& fileName)
{
	m_Texture = ResourceManager::GetInstance().LoadTexture(fileName);
}

void dae::TextureComponent::SetTexture(const std::shared_ptr<Texture2D>& texture)
{
	m_Texture = texture;
}

