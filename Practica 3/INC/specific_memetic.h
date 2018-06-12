#ifndef _SPECIFIC_MEMETIC_H_
#define _SPECIFIC_MEMETIC_H_

#include <clasificador.h>
#include <utility>
#include <set>
#include <BLmemetic_Specific.h>
#include <common_gmetic.h>

using namespace std;


template<unsigned int Generation, unsigned int Percent, bool Mejorado = false>
individuo_genetico AM(const muestra &Tr, const unsigned int & seed);


#include <specific_memetic.hxx>
#endif
