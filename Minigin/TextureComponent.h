#pragma once
#include "BaseComponent.h"
#include <memory>

namespace dae
{
	class Texture2D;
	class TextureComponent final : public BaseComponent
	{
	public:
		TextureComponent(const Transform& transform);
		TextureComponent(const Transform& transform, const std::shared_ptr<Texture2D>& texture);
		TextureComponent(const TextureComponent& other) = delete;
		TextureComponent(TextureComponent&& other) = delete;
		TextureComponent& operator=(const TextureComponent& other) = delete;
		TextureComponent& operator=(TextureComponent&& other) = delete;
		virtual ~TextureComponent() = default;

		virtual void Update(float dt) override;
		virtual void Render() const override;

		std::shared_ptr<Texture2D> GetTexture() const;
		void SetTexture(const std::string& fileName);
		void SetTexture(const std::shared_ptr<Texture2D>& texture);
		
	private:
		std::shared_ptr<Texture2D> m_Texture;
	};
}