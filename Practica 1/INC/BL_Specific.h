#ifndef BL_SPECIFIC_H_
#define _BL_SPECIFIC_H_

#include <random>
#include <cmath>
#include <utility>
#include <individuo.h>
#include <muestra.h>
#include <clasificador.h>

using namespace std;

vector<individuo::value_type> generarVecino(vector<individuo::value_type> W, const unsigned int &i, const unsigned int &seed);
pair<vector<individuo::value_type>, pair<float, float>> BusquedaLocalAprendizaje(const muestra &training, const muestra &test, const unsigned int & seed);

#endif
