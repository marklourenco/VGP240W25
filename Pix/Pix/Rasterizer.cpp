#include "Rasterizer.h"

Rasterizer* Rasterizer::Get()
{
	static Rasterizer sInstance;
	return &sInstance;
}

void Rasterizer::SetColor(X::Color color)
{
	mColor = color;
}

void Rasterizer::DrawPoint(int x, int y)
{
	X::DrawPixel(x, y, mColor);
}

void Rasterizer::DrawPoint(const Vertex& vertex)
{
	SetColor(vertex.color);
	DrawPoint(static_cast<int>(vertex.pos.x), static_cast<int>(vertex.pos.y));
}