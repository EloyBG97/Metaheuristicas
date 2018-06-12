#ifndef BLMEMETIC_SPECIFIC_H_
#define _BLMEMETIC_SPECIFIC_H_

#include <random>
#include <cmath>
#include <utility>
#include <individuo.h>
#include <muestra.h>
#include <clasificador.h>
#include <BL_Specific.h>

using namespace std;

pair<vector<individuo::value_type>, pair<float, float>> BusquedaLocalAprendizaje(vector<individuo::value_type> solucion, const muestra &training, const unsigned int & seed, unsigned int &n_ejecuciones);

#endif
