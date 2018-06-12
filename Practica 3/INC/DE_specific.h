#ifndef _DE_SPECIFIC_H_
#define _DE_SPECIFIC_H_

#include<common_gmetic.h>

pair<vector<individuo::value_type>, pair<float, float>> DERand1(const muestra &training, const unsigned int & seed);
pair<vector<individuo::value_type>, pair<float, float>> DECurrentBest1(const muestra &training, const unsigned int & seed);

#endif