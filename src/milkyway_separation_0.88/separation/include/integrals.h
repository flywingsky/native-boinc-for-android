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

#ifndef _INTEGRALS_H_
#define _INTEGRALS_H_


#include "separation_types.h"
#include "evaluation_state.h"
#include "milkyway_util.h"

#ifdef __cplusplus
extern "C" {
#endif

LBTrig lb_trig(LB lb);

int integrate(const AstronomyParameters* ap,
              const IntegralArea* ia,
              const StreamConstants* sc,
              const StreamGauss sg,
              EvaluationState* es,
              const CLRequest* clr);

#ifdef ANDROID
LBTrigIntFp lb_trig_intfp(LB lb);

int integrateIntFp(const AstronomyParameters* ap,
              const IntegralArea* ia,
              const StreamConstantsIntFp* sc,
              const StreamGauss sg,
              EvaluationState* es,
              const CLRequest* clr);
#endif

void separationIntegralApplyCorrection(EvaluationState* es);

#ifdef __cplusplus
}
#endif

#endif /* _INTEGRALS_H_ */

