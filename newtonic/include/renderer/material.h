/*
 *   Newtonic
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

#pragma once

#include "texture.h"
#include "shader.h"
#include "../materialdefinition.h"
#include "../serialization.h"
#include "../asset.h"

namespace Newtonic
{
  class Material
  {
  public:
    Material();
    Material(const MaterialDefinition & info);

    void Instantiate(const MaterialDefinition & info);

    void SetFloat(const std::string & name, float v);
    void SetVector2(const std::string & name, const Vector2 & v);
    void SetVector3(const std::string & name, const Vector3 & v);
    void SetVector4(const std::string & name, const Vector4 & v);
    void SetMatrix4(const std::string & name, const Matrix4 & v);
    void SetTexture(const std::string & name, const std::string & v);

    void Bind() const;
    void Unbind() const;

    ASSET_CLASS(AssetType::Material)

  private:
    std::unordered_map<std::string, std::unique_ptr<Uniform>> m_uniforms;

    std::shared_ptr<Shader> m_shader;
    mutable std::unordered_map<std::string, std::shared_ptr<Texture>> m_textures;
  };
}
