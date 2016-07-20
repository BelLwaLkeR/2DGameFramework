
#pragma once
#include <vector>
#include <Source/Framework/Component/Component.h>
#include <Source/Framework/Renderer/ImageRenderer/eDrawLayer.h>
#include <Source/Framework/Renderer/ImageRenderer/Shader/IPixelShader.h>
#include <Source/Utility/Type/Vector2.h>

namespace framework {
	struct ImageParameters {
		eDrawLayer		layer;
		std::string		imageName;
		util::Vector2	oneImageSize;
		int				imageNum;

		ImageParameters():
			layer(eDrawLayer::UI),
			imageName(""),
			oneImageSize({ 0, 0 }),
			imageNum(0){}

		ImageParameters(eDrawLayer layer, const std::string& imageName, const util::Vector2& oneImageSize, int imageNum):
			layer(layer),
			imageName(imageName),
			oneImageSize(oneImageSize),
			imageNum(imageNum) {}
	};


	class DrawComponent: public Component{
	public:
		DrawComponent();
		~DrawComponent();
		virtual void draw();

	protected:
		ImageParameters						m_ImageParameters;
		util::SharedPtr<util::ImageData>	m_pImageData;
		void active()	override;
		void deActive()	override;

	private:

		void setup(util::WeakPtr<Entity> pEntity, util::WeakPtr<util::Vector2> pPosition) override;
		void setupImage(ImageParameters imageParameters);
		void loadImage();
	};
}