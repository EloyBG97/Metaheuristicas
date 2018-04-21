#ifndef _RELIEF_SPECIFIC_H_
#define _RELIEF_SPECIFIC_H_

#include <individuo.h>
#include <muestra.h>
#include <clasificador.h>
#include <utility>

individuo Enemigo(const individuo &i1, const muestra &training);
individuo Amigo(const individuo &i1,  const muestra &training);
pair<vector<individuo::value_type>, pair<float, float>> reliefAprendizaje(const muestra &training, const muestra &test);


#endif
