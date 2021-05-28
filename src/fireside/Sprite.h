#pragma once

#include "Material.h"

namespace fireside 
{
	class Sprite 
	{
	public:
		Sprite() : m_SpriteTexture(nullptr), m_SpriteMat(nullptr) { }
		Sprite(Material* mat) : m_SpriteMat(mat), m_SpriteTexture(nullptr) { }
		Sprite(Material* mat, Texture* tex) : m_SpriteMat(mat), m_SpriteTexture(tex) { }

		~Sprite();
	private:
		Texture* m_SpriteTexture;
		Material* m_SpriteMat;
	};
}