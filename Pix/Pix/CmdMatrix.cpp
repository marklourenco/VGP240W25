#include "CmdMatrix.h"
#include "MatrixStack.h"
#include "VariableCache.h"

const float gDegToRad = 3.1416f / 180.0f;
bool CmdPushTranslation::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 3)
	{
		return false;
	}
	
	VariableCache* vc = VariableCache::Get();
	float x = vc->GetFloat(params[0]);
	float y = vc->GetFloat(params[1]);
	float z = vc->GetFloat(params[2]);
	MatrixStack::Get()->PushTranslation({x, y, z});
	return true;
}

bool CmdPushRotationX::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}
	
	VariableCache* vc = VariableCache::Get();
	float degree = vc->GetFloat(params[0]);
	MatrixStack::Get()->PushRotationX(degree * gDegToRad);
	return true;
}

bool CmdPushRotationY::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	float degree = vc->GetFloat(params[0]);
	MatrixStack::Get()->PushRotationY(degree * gDegToRad);
	return true;
}

bool CmdPushRotationZ::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	float degree = vc->GetFloat(params[0]);
	MatrixStack::Get()->PushRotationZ(degree * gDegToRad);
	return true;
}

bool CmdPushScaling::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 3)
	{
		return false;
	}
	
	VariableCache* vc = VariableCache::Get();
	float x = vc->GetFloat(params[0]);
	float y = vc->GetFloat(params[1]);
	float z = vc->GetFloat(params[2]);
	MatrixStack::Get()->PushScaling({x, y, z});
	return true;
}

bool CmdPopMatrix::Execute(const std::vector<std::string>& params)
{
	MatrixStack::Get()->PopMatrix();
	return true;
}