#include "Model.h"

void Model::Load(const std::string& fileName)
{
    mFileName = fileName;

    std::vector<Vector3> positions;
    std::vector<uint32_t> positionIndices;

    FILE* file = nullptr;
    fopen_s(&file, fileName.c_str(), "r");
    if (file == nullptr)
    {
        char buffer[128];
        sprintf_s(buffer, "Can't open model file %s", fileName.c_str());
        MessageBoxA(nullptr, buffer, "Model Error", MB_OK | MB_ICONEXCLAMATION);
        return;
    }
    // read the file
    while (true)
    {
        char buffer[128];
        int result = fscanf_s(file, "%s", buffer, (uint32_t)std::size(buffer));
        if (result == EOF)
        {
            break;
        }
        if (strcmp(buffer, "v") == 0)
        {
            float x, y, z = 0.0f;
            fscanf_s(file, "%f %f %f", &x, &y, &z);
            positions.push_back({ x, y, z });
        }
        else if (strcmp(buffer, "%f") == 0)
        {
            uint32_t v[3];
            if (fscanf_s(file, "%d//%*d %d//%*d %d//%*d\n", &v[0], &v[1], &v[2]) != 3)
            {
                char error[128];
                sprintf_s(error, "Unexpected format for %s", fileName.c_str());
                MessageBoxA(nullptr, error, "Model Error", MB_OK | MB_ICONEXCLAMATION);
                return;
            }
            for (uint32_t i = 0; i < 3; ++i)
            {
                positionIndices.push_back(v[i]);
            }
        }
    }
    fclose(file);

    mVertices.resize(positionIndices.size());
    for (size_t i = 0; i < positionIndices.size(); ++i)
    {
        mVertices[i].pos = positions[positionIndices[i] - 1];
        mVertices[i].color = X::Colors::White;
    }
}

const std::string& Model::GetFileName() const
{
    return mFileName;
}

const Vertex& Model::GetVertex(uint32_t index) const
{
    return mVertices[index];
}

uint32_t Model::GetVertexCount() const
{
    return mVertices.size();
}
