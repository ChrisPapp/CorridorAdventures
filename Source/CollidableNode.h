#pragma once

#include "GeometryNode.h"

class CollidableNode : public GeometryNode
{
    public:

        CollidableNode(void);
        ~CollidableNode(void);

        CollidableNode(const CollidableNode &) = default;
        CollidableNode(CollidableNode &&) = default;
        CollidableNode& operator=(const CollidableNode&) = default;
        CollidableNode& operator=(CollidableNode&&) = default;

        void Init(GeometricMesh* mesh) override;
        bool intersectRay(const glm::vec3 & pOrigin, const glm::vec3 & pDir, float& pIsectDistconst, const glm::mat4& pWorldMatrix = glm::mat4(1.f), float pTmax = 1.e+15f, float pTmin = 0.f);

    protected:

        // Empty

    private:

        typedef GeometryNode super;

        struct triangle { glm::vec3 v0, v1, v2; };

        std::vector<triangle> triangles;
};