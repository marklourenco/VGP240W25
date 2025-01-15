#include "PrimitivesManager.h"
#include "Rasterizer.h"

PrimitivesManager* PrimitivesManager::Get()
{
	static PrimitivesManager sInstance;
	return &sInstance;
}
PrimitivesManager::PrimitivesManager()
{

}

bool PrimitivesManager::BeginDraw(Topology topology)
{
	mTopology = topology;
	mDrawBegin = true;
	mVertexBuffer.clear();
	return true;
}
void PrimitivesManager::AddVertex(const Vertex& vertex)
{
	if (mDrawBegin)
	{
		mVertexBuffer.push_back(vertex);
	}
}
bool PrimitivesManager::EndDraw()
{
	if (!mDrawBegin)
	{
		return false;
	}

	switch (mTopology)
	{
	case Topology::Point:
		for (size_t i = 0; i < mVertexBuffer.size(); i++)
		{
			// Rasterize 
			Rasterizer::Get()->DrawPoint(mVertexBuffer[i]);
		}
		break;
	case Topology::Line:
		break;
	case Topology::Triangle:
		break;
	default:
		break;
	}

	mDrawBegin = false;

	return true;
}
