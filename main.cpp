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

// main.cpp is used for fast tests, it has no use in the final library

#include <stdio.h>
#include <memory>
#include <glm/glm.hpp>

#include "engine.h"
#include "mesh.h"
#include "actor.h"
#include "scene.h"
#include "mesh_renderer.h"
#include "assets.h"
#include "message_bus.h"
#include "common.h"

int main(int argc, char **argv)
{
    puts("Newtonic testing");

    Newtonic::Engine engine;
    engine.Init();
    engine.OpenWindow("Newtonic", Newtonic::Viewport(512, 512));

    engine.Loop();
    return 0;
}
