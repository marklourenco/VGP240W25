#include "Clipper.h"
#include "Viewport.h"

Clipper* Clipper::Get()
{
	static Clipper sInstance;
	return &sInstance;
}

void Clipper::OnNewFrame()
{
	mClipping = false;
}

bool Clipper::ClipPoint(const Vertex& v)
{
	if (!mClipping)
	{
		return false;
	}
	
	float minX = Viewport::Get()->GetMinX();
	float maxX = Viewport::Get()->GetMaxX();
	float minY = Viewport::Get()->GetMinY();
	float maxY = Viewport::Get()->GetMaxY();
	return v.pos.x < minX || v.pos.x > maxX
		|| v.pos.y < maxY || v.pos.y > maxY;
}

bool Clipper::ClipLine(const Vertex& a, const Vertex& b)
{
	return false;
}

bool Clipper::IsClipping() const
{
	return mClipping;
}

void Clipper::SetClipping(bool clip)
{
	mClipping = clip;
}
