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

#ifndef _ACTOR_H
#define _ACTOR_H

#include <vector>
#include <memory>

#include "transform.h"

 namespace Newtonic
 {
   class Behaviour;
   class Scene;

   class Actor
   {
     Scene * m_scene;
     std::shared_ptr<Transform> m_transform;
     std::vector<std::shared_ptr<Behaviour>> m_behaviours;

   public:
     Actor()
     {
       m_transform = std::make_unique<Transform>();
     }

     Scene * GetScene() const
     {
       return m_scene;
     }

     void SetScene(Scene * scene)
     {
       m_scene = scene;
     }

     void AddBehaviour(std::shared_ptr<Behaviour> && behaviour);

     std::weak_ptr<Transform> GetTransform() const
     {
       return m_transform;
     }

     template <typename T>
     std::weak_ptr<T> GetBehaviour() const
     {
       for (auto & behaviour : m_behaviours)
       {
         auto pDownCasted = std::dynamic_pointer_cast<T>(behaviour);
         if (pDownCasted.get() != nullptr)
         {
           return pDownCasted;
         }
       }

       return std::weak_ptr<T>();
     }

     std::weak_ptr<Transform> GetTransform()
     {
       return m_transform;
     }

     void Init();
     void Render();
     void Update();
   };
 }

#endif // _ACTOR_H
