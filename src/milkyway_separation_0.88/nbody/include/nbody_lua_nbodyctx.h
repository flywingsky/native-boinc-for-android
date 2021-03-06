/*
Copyright (C) 2011  Matthew Arsenault

This file is part of Milkway@Home.

Milkyway@Home is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Milkyway@Home is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Milkyway@Home.  If not, see <http://www.gnu.org/licenses/>.
*/

#if !defined(_NBODY_LUA_TYPES_H_INSIDE_) && !defined(NBODY_LUA_TYPES_COMPILATION)
  #error "Only nbody_lua_types.h can be included directly."
#endif

#ifndef _NBODY_LUA_NBODYCTX_H_
#define _NBODY_LUA_NBODYCTX_H_

#include <lua.h>
#include "nbody_types.h"

int pushNBodyCtx(lua_State* luaSt, const NBodyCtx* ctx);
NBodyCtx* checkNBodyCtx(lua_State* luaSt, int idx);
NBodyCtx* toNBodyCtx(lua_State* luaSt, int idx);
NBodyCtx* expectNBodyCtx(lua_State* luaSt, int idx);
int registerNBodyCtx(lua_State* luaSt);

criterion_t readCriterion(lua_State* luaSt, const char* name);

#endif /* _NBODY_LUA_NBODYCTX_H_ */

