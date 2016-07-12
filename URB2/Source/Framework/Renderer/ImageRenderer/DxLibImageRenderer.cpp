#include "DxLibImageRenderer.h"

void framework::DxLibImageRenderer::drawSimpleBox(const util::Vector2 & centerPosition, int width, int height, float angleDeg){
	DrawBox(centerPosition.getIntX() - width/2,
			centerPosition.getIntX() + width/2,
			centerPosition.getIntX() - height/2,
			centerPosition.getIntX() + height/2,
			GetColor(0, 255, 128),
			TRUE
		);
}
