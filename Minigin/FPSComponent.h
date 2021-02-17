#pragma once
#include "BaseComponent.h"
#include <memory>

namespace dae
{
	class TextObject;
	class Font;
	class FPSComponent final : public BaseComponent
	{
	public:
		FPSComponent();
		FPSComponent(const FPSComponent& other) = delete;
		FPSComponent(FPSComponent&& other) = delete;
		FPSComponent& operator=(const FPSComponent& other) = delete;
		FPSComponent& operator=(FPSComponent&& other) = delete;
		virtual ~FPSComponent() = default;

		virtual void Update(float dt) override;
		virtual void Render() const override;
		
		int GetFPS() const;

	private:
		float m_FPS;
	};
}