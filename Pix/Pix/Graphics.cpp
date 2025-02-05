#include "Graphics.h"

#include "Viewport.h"
#include "Clipper.h"
#include "MatrixStack.h"

void Graphics::NewFrame()
{
	Viewport::Get()->OnNewFrame();
	Clipper::Get()->OnNewFrame();
	MatrixStack::Get()->OnNewFrame();
}