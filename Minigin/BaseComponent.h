#pragma once
#include "Transform.h"

namespace dae
{
	class BaseComponent
	{
	public:
		BaseComponent(const Transform& transform);
		BaseComponent(const BaseComponent& other) = delete;
		BaseComponent(BaseComponent&& other) = delete;
		BaseComponent& operator=(const BaseComponent& other) = delete;
		BaseComponent& operator=(BaseComponent&& other) = delete;
		virtual ~BaseComponent() = default;

		virtual void Update(float dt) = 0;
		virtual void Render() const = 0;

		Transform GetTransform() const;
		void SetTransform(const Transform& transform);

	protected:
		Transform m_Transform;
	};
}