#include "DrawComponent.h"
#include <Source/Framework/Task/TaskManager.h>
#include <Source/Framework/Entity/Entity.h>
#include <Source/Framework/Device/Renderer/ImageRenderer/ImageRenderer.h>

framework::DrawComponent::DrawComponent(){
}

framework::DrawComponent::~DrawComponent(){

}

void framework::DrawComponent::setup(util::WeakPtr<Entity> pEntity, util::WeakPtr<util::Vector2> pPosition){
	Component::setup(pEntity, pPosition);
	setupImage(m_ImageParameters);
}

void framework::DrawComponent::setupImage(ImageParameters imageParameters){
	loadImage();
}

void framework::DrawComponent::loadImage(){
	m_pImageData = util::makeShared<util::ImageData>(m_pPosition, m_ImageParameters.imageName, m_ImageParameters.oneImageSize, m_ImageParameters.imageNum);
}

void framework::DrawComponent::draw(){
	ImageRenderer::drawImage(m_pImageData);
}

void framework::DrawComponent::active() {
	util::WeakPtr<DrawComponent> drawTask = m_pEntity->getComponentCast<DrawComponent>(this);
	SGLT_TASK_MANAGER->addDrawTask(m_ImageParameters.layer, drawTask);
}

void framework::DrawComponent::deActive() {
	util::WeakPtr<DrawComponent> drawTask = m_pEntity->getComponentCast<DrawComponent>(this);
	SGLT_TASK_MANAGER->removeDrawTask(m_ImageParameters.layer, drawTask);
}
