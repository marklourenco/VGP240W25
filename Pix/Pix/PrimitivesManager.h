#pragma once

#include "Vertex.h"

enum class Topology
{
	Point,
	Line,
	Triangle
};

enum class CullMode
{
	None, // no face culling
	Back, // call items facing away from the camera
	Front // cull items facing towards the camera
};

class PrimitivesManager
{
	// Everyone has access
public:
	static PrimitivesManager* Get();

	void OnNewFrame();
	void SetCullMode(CullMode mode);

	bool BeginDraw(Topology topology, bool applyTransform = false);
	void AddVertex(const Vertex& vertex);
	bool EndDraw();

	// Only this class can see
private:
	PrimitivesManager();

	std::vector<Vertex> mVertexBuffer;
	Topology mTopology = Topology::Point;
	CullMode mCullMode = CullMode::Back;
	bool mDrawBegin = false;
	bool mApplyTransform = false;
};

