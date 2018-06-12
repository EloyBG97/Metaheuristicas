#ifndef _COMMON_GMETIC_H_
#define _COMMON_GMETIC_H_

#include <clasificador.h>
#include <utility>
#include <vector>
#include <algorithm>

using namespace std;

double fRand(double fMin, double fMax);

typedef pair<vector<individuo::value_type>, pair<float, float>> individuo_genetico;
typedef vector<individuo_genetico>  poblacion_genetico;


poblacion_genetico StartPopulation(const muestra &Tr, const unsigned int M, const unsigned int & seed);

//Seleccion
vector<unsigned int> Seleccionar(const poblacion_genetico & P, const unsigned int & N, const unsigned int & seed);
//pair<unsigned int, unsigned int> SeleccionarEstacionario(const poblacion_genetico & P, const unsigned int & seed);


//Torneo Binario
unsigned int torneoBinario(const poblacion_genetico &P, const unsigned int & seed);

//Cruce
pair<individuo_genetico,individuo_genetico> CruceBLX(const pair<individuo_genetico*, individuo_genetico*> & C, const muestra &Tr, const unsigned int & seed);
individuo_genetico CruceMean(const pair<individuo_genetico*, individuo_genetico*> & C, const muestra &Tr);

//Mutacion
bool Mutacion(individuo_genetico & I, const muestra & Tr, const unsigned int & seed);

void RemplazoGeneracional(poblacion_genetico & P, poblacion_genetico & R);
void RemplazoEstacionario(poblacion_genetico & P, poblacion_genetico & R);

vector<unsigned int> ElegirAleatorios(const vector<individuo_genetico> & P, const  unsigned int & N, const unsigned int & seed);


#endif
