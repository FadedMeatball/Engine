#pragma once
#include "Transform.h"
#include "SceneObject.h"
#include <vector>
#include <memory>

namespace dae
{
	class BaseComponent;
	class GameObject final : public SceneObject
	{
	public:
		GameObject() = default;
		virtual ~GameObject() = default;
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;
		
		void Update(float dt) override;
		void Render() const override;
		
		void SetPosition(float x, float y);

		void AddComponent(const std::shared_ptr<BaseComponent>& component);

	private:
		std::vector<std::shared_ptr<BaseComponent>> m_Components;
		Transform m_Transform;
	};
}
