/*
 *   Newtonic - Graphics for Physics
 *   Copyright (C) 2019 Luca "ekardnam" Bertozzi <luca.bertozzi11@studio.unibo.it>
 *
 *   This program is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef _MESH_RENDERER_H
#define _MESH_RENDERER_H


#include <memory>
#include <string>

#include "behaviour.h"

#include "mesh_shader.h"

 namespace Newtonic
 {

   class Mesh;
   class Assets;
   class Camera;
   class Transform;

   class MeshRenderer : public Behaviour
   {
     std::string m_meshName;
     std::string m_shaderName;

     std::weak_ptr<Mesh> m_wpMesh;
     std::weak_ptr<MeshShader> m_wpShader;

     std::weak_ptr<Camera> m_wpCamera;
     std::weak_ptr<Transform> m_wpActorTransform;

   public:
    MeshRenderer(std::string meshName, std::string shaderName) :
      m_meshName(meshName),
      m_shaderName(shaderName)
    {};

     void Init() override;
     void Update(float dt) override {};
     void Render() override;
   };

 }

#endif // _MESH_RENDERER_H
