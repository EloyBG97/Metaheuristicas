#ifndef _ILS_SPECIFIC_H_
#define _ILS_SPECIFIC_H_

#include <vector>
#include<individuo.h>
#include <random>
#include <algorithm>
#include <clasificador.h>

using namespace std;

vector<individuo::value_type> generarVecinoFuerte(vector<individuo::value_type> W, const unsigned int &t, const unsigned int &seed);
pair<vector<individuo::value_type>, pair<float, float>> iterativeLocalSearch(const muestra &training, const unsigned int & seed);
pair<vector<individuo::value_type>, pair<float, float>> LocalSearch(const vector<individuo::value_type> &W, const muestra &training, const unsigned int & seed);
vector<individuo::value_type> generarVecino(vector<individuo::value_type> W, const unsigned int &i, const unsigned int &seed);

#endif