/* Copyright 2010 Matthew Arsenault, Travis Desell, Boleslaw
Szymanski, Heidi Newberg, Carlos Varela, Malik Magdon-Ismail and
Rensselaer Polytechnic Institute.

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

#ifndef _R_POINTS_H_
#define _R_POINTS_H_

#include "separation_types.h"
#include "separation_constants.h"
#include "coordinates.h"
#include "milkyway_extra.h"


#ifdef __cplusplus
extern "C" {
#endif

real calcG(real coords);
real calcReffXrRp3(real coords, real gPrime);

void setRPoints(const AstronomyParameters* ap,
                const StreamGauss sg,
                unsigned int n_convolve,
                real coords,
                RPoints* r_pts);

void setSplitRPoints(const AstronomyParameters* ap,
                     const StreamGauss sg,
                     unsigned int n_convolve,
                     real gPrime,
                     real* RESTRICT r_points,
                     real* RESTRICT qw_r3_N);

RPoints* precalculateRPts(const AstronomyParameters* ap,
                          const IntegralArea* ia,
                          const StreamGauss sg,
                          RConsts** rc_out,
                          int transpose);

#ifdef __cplusplus
}
#endif

#endif /* _R_POINTS_H_ */

