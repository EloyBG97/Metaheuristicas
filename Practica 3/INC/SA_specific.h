#ifndef SA_SPECIFIC_H_
#define SA_SPECIFIC_H_

#include <BL_Specific.h>
#include <utility>
#include <individuo.h>
#include <muestra.h>
#include <clasificador.h>

using namespace std;

pair<vector<individuo::value_type>, pair<float, float>> SimulatedAnneling(const muestra &training, const unsigned int & seed);


#endif
