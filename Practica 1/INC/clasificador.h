#ifndef _CLASIFICADOR_H_
#define _CLASIFICADOR_H_

#include <muestra.h>
#include <vector>
#include <individuo.h>
#include <utility>

using namespace std;

pair<float, float> fObjetivo(const vector<individuo::value_type>&W, const muestra &training);
float tasaClas(const vector<individuo::value_type>&W, const muestra &training);
float tasaRed(const vector<individuo::value_type>&W, const float &tasa);
muestra::size_type validacionTraining(const vector<individuo::value_type>&W, const muestra &training);
muestra::size_type validacionTest(const vector<individuo::value_type>&W, const muestra &training, const muestra &test);
bool clasifica(const vector<individuo::value_type>&W, const muestra &conocimiento, const individuo &I);
individuo::value_type distanciaIndividuos(const individuo &I1, const individuo &I2, const vector<individuo::value_type>&W);

#endif