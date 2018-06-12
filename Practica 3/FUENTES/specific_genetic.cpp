#include<specific_genetic.h>

#include <chrono>


using namespace std;
using namespace std::chrono;

using namespace std;

//Cruce BLX / Generacional
individuo_genetico AGG_BLX(const muestra &Tr, const unsigned int & seed) {
	const size_t M = 30;
	const float Pc = 0.7;

	const unsigned N_CRUCES = Pc * M;
	const unsigned int N_EJECUCIONES = 15000;

	poblacion_genetico population(M);
	poblacion_genetico remplazo(M);
	vector<unsigned int> idx_padres;
	vector<unsigned int> idx_population(M);

	unsigned int i;

	pair<individuo_genetico*, individuo_genetico*> couple;
	pair<individuo_genetico, individuo_genetico> hijos;



	bool muta;


	unsigned int  n_ejecuciones = 0;

	population = StartPopulation(Tr, M, seed);
	n_ejecuciones += M;

	do {

		idx_padres = Seleccionar(population, M, seed);
		
		for(i = 0; i < N_CRUCES; i+=2) {
				couple.first = &population[idx_padres[i]];
				couple.second = &population[idx_padres[i + 1]];

				hijos = CruceBLX(couple, Tr, seed);

				n_ejecuciones += 2;

				remplazo[i] = hijos.first;
				remplazo[i+1] = hijos.second;

		}

		for(i = N_CRUCES;  i < M; ++i) {
			remplazo[i] = population[idx_padres[i]];
		}

		for(i = 0;  i < M; ++i) {
			muta = Mutacion(remplazo[i], Tr, seed);
			n_ejecuciones += muta;
		}

		RemplazoGeneracional(population, remplazo);
		
	} while(n_ejecuciones < N_EJECUCIONES);


	for(i = 0; i < M; ++i) {
		idx_population[i] = i;
	}
	
	sort(idx_population.begin(), idx_population.end(), [&](unsigned int idx1, unsigned int idx2) {
		float coste1 = population[idx1].second.first + population[idx1].second.second, 
			  coste2 = population[idx2].second.first + population[idx2].second.second;

		return coste1 > coste2;
	});

	return population[idx_population[0]];
}

//Cruce Mean / Generacional
individuo_genetico AGG_CA(const muestra &Tr, const unsigned int & seed) {
	const size_t M = 30;
	const float Pc = 0.7;

	const unsigned n_cruces = Pc * M;
	const unsigned int N_EJECUCIONES = 15000;

	poblacion_genetico population(M);
	vector<unsigned int> idx_population(M);
	poblacion_genetico remplazo(M);
	vector<unsigned int> idx_padres;
	pair<individuo_genetico*, individuo_genetico*> couple;
	individuo_genetico hijos;

	unsigned int i;


	typename vector<pair<individuo_genetico, individuo_genetico>>::iterator it;
	typename poblacion_genetico::iterator padres_it;


	bool muta;


	unsigned int  n_ejecuciones = 0;


	population = StartPopulation(Tr, M, seed);
	n_ejecuciones += M;
	do {
		idx_padres = Seleccionar(population, M, seed);

		for(i = 0; i < n_cruces; ++i) {
			couple.first = &population[idx_padres[i]];
			couple.second = &population[idx_padres[i + 1]];

			hijos = CruceMean(couple, Tr);
			n_ejecuciones += 1;

			remplazo[i] = hijos;
		}

		for(i = n_cruces;  i < M; ++i) {
			remplazo[i] = population[idx_padres[i]];
		}

		for(i = 0;  i < M; ++i) {
			muta = Mutacion(remplazo[i], Tr, seed);
			n_ejecuciones += muta;
		}


		RemplazoGeneracional(population, remplazo);

	} while(n_ejecuciones < N_EJECUCIONES);

	for(i = 0; i < M; ++i) {
		idx_population[i] = i;
	}
	
	sort(idx_population.begin(), idx_population.end(), [&](unsigned int idx1, unsigned int idx2) {
		float coste1 = population[idx1].second.first + population[idx1].second.second, 
			  coste2 = population[idx2].second.first + population[idx2].second.second;

		return coste1 > coste2;
	});

	return population[idx_population[0]];
}


//Cruce BLX / Estacionario
individuo_genetico AGE_BLX(const muestra &Tr, const unsigned int & seed) {
	const size_t M = 30;
	const unsigned int N_EJECUCIONES = 15000;
	unsigned int n_ejecuciones = 0;

	vector<individuo_genetico> population;
	vector<unsigned int> idx_population(M);
	vector<individuo_genetico> remplazo(2);
	vector<unsigned int> idx_padres;
	pair<individuo_genetico, individuo_genetico> hijos;
	pair<individuo_genetico*, individuo_genetico*> couple;
	bool muta;

	unsigned int i;




	population = StartPopulation(Tr, M, seed);
	n_ejecuciones += M;
	do {
		idx_padres = Seleccionar(population, 2, seed);



		couple.first = &population[idx_padres[0]];
		couple.second = &population[idx_padres[1]];

		hijos = CruceBLX(couple, Tr, seed);
		n_ejecuciones += 2;

		muta = Mutacion(hijos.first, Tr, seed);
		n_ejecuciones += (muta)?1:0;

		muta = Mutacion(hijos.second, Tr, seed);
		n_ejecuciones += (muta)?1:0;

		remplazo[0] = hijos.first;
		remplazo[1] = hijos.second;
	


		RemplazoEstacionario(population, remplazo);


	} while(n_ejecuciones < N_EJECUCIONES);


	for(i = 0; i < M; ++i) {
		idx_population[i] = i;
	}
	
	sort(idx_population.begin(), idx_population.end(), [&](unsigned int idx1, unsigned int idx2) {
		float coste1 = population[idx1].second.first + population[idx1].second.second, 
			  coste2 = population[idx2].second.first + population[idx2].second.second;

		return coste1 > coste2;
	});

	return population[idx_population[0]];
}

//Cruce Mean / Estacionario
individuo_genetico AGE_CA(const muestra &Tr, const unsigned int & seed) {

	const size_t M = 30;
	const unsigned int N_EJECUCIONES = 15000;
	unsigned int  n_ejecuciones = 0;

	vector<individuo_genetico> population;
	vector<unsigned int> idx_population(M);
	vector<individuo_genetico> remplazo(1);
	vector<unsigned int> idx_padres;
	pair<individuo_genetico*, individuo_genetico*> couple;
	individuo_genetico hijo;
	bool muta;

	unsigned int i;


	population = StartPopulation(Tr, M, seed);
	n_ejecuciones += M;

	do {
		idx_padres = Seleccionar(population, 2, seed);



		couple.first = &population[idx_padres[0]];
		couple.second = &population[idx_padres[1]];
		
		hijo = CruceMean(couple, Tr);
		++n_ejecuciones;


		muta = Mutacion(hijo, Tr, seed);
		n_ejecuciones += muta;


		remplazo[0] = hijo;
	


		RemplazoEstacionario(population, remplazo);
	} while(n_ejecuciones < N_EJECUCIONES);
	
	for(i = 0; i < M; ++i) {
		idx_population[i] = i;
	}
	
	sort(idx_population.begin(), idx_population.end(), [&](unsigned int idx1, unsigned int idx2) {
		float coste1 = population[idx1].second.first + population[idx1].second.second, 
			  coste2 = population[idx2].second.first + population[idx2].second.second;

		return coste1 > coste2;
	});

	return population[idx_population[0]];
}
