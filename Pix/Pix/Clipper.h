#pragma once

#include "Vertex.h"

class Clipper
{
public:
	static Clipper* Get();

	void OnNewFrame();

	bool ClipPoint(const Vertex& v);
	bool ClipLine(const Vertex& a, const Vertex& b);

	bool IsClipping() const;
	void SetClipping(bool clip);

private:
	bool mClipping = false;
};