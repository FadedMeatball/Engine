#include "MiniginPCH.h"
#include "GameObject.h"
#include "BaseComponent.h"
#include <algorithm>

void dae::GameObject::Update(float dt)
{
	std::for_each(m_Components.cbegin(), m_Components.cend(), [dt](const std::shared_ptr<BaseComponent>& comp)
	{
		comp->Update(dt);
	});

}

void dae::GameObject::Render() const
{
	std::for_each(m_Components.cbegin(), m_Components.cend(), [](const std::shared_ptr<BaseComponent>& comp)
	{
		comp->Render();
	});
}

//void dae::GameObject::Render() const
//{
//	const auto pos = m_Transform.GetPosition();
//	Renderer::GetInstance().RenderTexture(*m_Texture, pos.x, pos.y);
//}
//
//void dae::GameObject::SetTexture(const std::string& filename)
//{
//	m_Texture = ResourceManager::GetInstance().LoadTexture(filename);
//}

void dae::GameObject::SetPosition(float x, float y)
{
	m_Transform.SetPosition(x, y, 0.0f);
}

void dae::GameObject::AddComponent(const std::shared_ptr<BaseComponent>& component)
{
	const auto cit{std::find(m_Components.cbegin(), m_Components.cend(), component)};
	if (cit == m_Components.cend())
		m_Components.push_back(component);
}
