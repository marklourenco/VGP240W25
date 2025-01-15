#pragma once

#include <XEngine.h>
#include "Vertex.h"

class Rasterizer
{
public:
	static Rasterizer* Get();

public:
	void SetColor(X::Color color);

	void DrawPoint(int x, int y);
	void DrawPoint(const Vertex& vertex);

private:
	X::Color mColor = X::Colors::White;
};