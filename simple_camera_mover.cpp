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

 #include "simple_camera_mover.h"

 #include "engine.h"
 #include "scene.h"
 #include "camera.h"
 #include "input.h"
 #include "transform.h"
 #include "actor.h"

 namespace Newtonic
 {
   std::shared_ptr<Actor> MakeSimpleCameraMover()
   {
     auto scm = std::make_shared<Actor>();
     scm->AddBehaviour(std::make_shared<SimpleCameraMoverBehaviour>());
     return scm;
   }

   void SimpleCameraMoverBehaviour::Init()
   {
     m_pScene = GetActor()->GetScene();
     m_wpCamera = m_pScene->GetCamera();
     m_pInput = g_engine->GetInputManager();
   }

   void SimpleCameraMoverBehaviour::Update(float dt)
   {
     Transform *pTransform = m_wpCamera.lock()->GetTransform();
     if (m_pInput->IsKeyDown(25)) pTransform->Move(glm::vec3(0.0, 0.0, 1.0) * dt);
     if (m_pInput->IsKeyDown(39)) pTransform->Move(glm::vec3(0.0, 0.0, -1.0) * dt);
     if (m_pInput->IsKeyDown(38)) pTransform->Move(glm::vec3(-1.0, 0.0, 0.0) * dt);
     if (m_pInput->IsKeyDown(40)) pTransform->Move(glm::vec3(1.0, 0.0, 0.0) * dt);
     if (m_pInput->IsKeyDown(24)) pTransform->Move(glm::vec3(0.0, 1.0, 0.0) * dt);
     if (m_pInput->IsKeyDown(26)) pTransform->Move(glm::vec3(0.0, -1.0, 0.0) * dt);

     int h = m_pInput->GetAxis(HORIZONTAL), v = m_pInput->GetAxis(VERTICAL);
     pTransform->Rotate(glm::vec3(-v, h, 0) * dt);
   }

 }
