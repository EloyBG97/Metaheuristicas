#ifndef _SPECIFIC_GENETIC_H_
#define _SPECIFIC_GENETIC_H_

#include <clasificador.h>
#include <utility>
#include <set>
#include <common_gmetic.h>

using namespace std;

individuo_genetico AGG_BLX(const muestra &Tr, const muestra &Ts, const unsigned int & seed);
individuo_genetico AGG_CA(const muestra &Tr, const muestra &Ts, const unsigned int & seed);
individuo_genetico AGE_BLX(const muestra &Tr, const muestra &Ts, const unsigned int & seed);
individuo_genetico AGE_CA(const muestra &Tr, const muestra &Ts, const unsigned int & seed);

#endif
