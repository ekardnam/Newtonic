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

#include "input.h"

#include "util.h"
#include "core.h"

namespace Newtonic
{
  bool Input::s_keyStatuses[HIGHEST_KEY_CODE];
  
  void Input::SetKeyStatus(unsigned int keyCode, bool status)
  {
    NW_WRAP_DEBUG(Core::GetCoreLogger().Debug(FormatString("Key: %i status: %i", keyCode, status)));
    s_keyStatuses[keyCode] = status;
  }

  bool Input::IsKeyDown(unsigned int keyCode) { return s_keyStatuses[keyCode]; }
}
