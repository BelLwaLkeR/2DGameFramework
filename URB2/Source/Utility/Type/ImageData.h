#pragma once
#include <vector>
#include <string>
#include <Source/Utility/SmartPtr.h>
#include <Source/Utility/DxLibUtility/DxLibImageTypename.h>

namespace util {
	class ImageData{
	public:
		ImageData();
		ImageData(util::WeakPtr<util::Vector2> pPosition, const std::string& imageName, const Vector2& oneImageSize = {0, 0}, int imageNum = 0);
		vertex_t*	getVertexPointer()			const;
		const util::image_t& getTexture()		const;
		const util::image_t& getNormalMap()		const;
		const util::image_t& getReflectionMap()	const;
		const util::Vector2& getSize()			const;
		const util::Vector2& getPosition()		const;

	private:
		void setup();
		void reloadVertex() const;

		util::WeakPtr<util::Vector2>	m_pPosition;
		util::Vector2					m_Size;
		std::vector<util::image_t>		m_Texture;
		std::vector<util::image_t>		m_NormalMap;
		std::vector<util::image_t>		m_ReflectionMap;
		mutable std::array<vertex_t, 6>	m_Vertex;
	};
}