#pragma once
#include <Source/Framework/Component/DrawComponent.h>


namespace component {
	class DrawRectangle: public framework::DrawComponent
	{
	public:
		DrawRectangle();
		~DrawRectangle();
		virtual void draw() override;
	private:

	};
}
