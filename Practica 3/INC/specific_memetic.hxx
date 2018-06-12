#include <chrono>

using namespace std;

using namespace std::chrono;
template<unsigned int Generation, unsigned int Percent, bool Mejorado>
	individuo_genetico AM(const muestra &Tr, const unsigned int & seed) {

	default_random_engine probabilidad_genetico(seed);

	uniform_real_distribution<float> distribution(0, 1);

	individuo_genetico hijo;

	unsigned int n_generation = 0;
	const float Pcm = 0.7;
	const unsigned int M = 10;
	const unsigned int N_EJECUCIONES = 15000;
	unsigned int  n_ejecuciones = 0, n_ejecuciones_aux;
	const unsigned int N_CRUCES = Pcm * M;

	poblacion_genetico population(M);
	poblacion_genetico remplazo(M);
	vector<unsigned int> idx_padres;
	vector<unsigned int> aux2;
	pair<individuo_genetico*, individuo_genetico*> couple;
	pair<individuo_genetico, individuo_genetico> hijos;
	poblacion_genetico::iterator it;

	high_resolution_clock::time_point t1_start_population, t2_start_population;



	bool muta;



	population = StartPopulation(Tr, M, seed);
	n_ejecuciones += M;

	do {

		if(n_generation % Generation == 0) {
			if(Mejorado) {
				aux2.resize(population.size());

				for(unsigned int i = 0; i < aux2.size(); ++i)
					aux2[i] = i;

				sort(aux2.begin(), aux2.end(), [&](unsigned int idx1, unsigned int idx2) {
					float coste1 = population[idx1].second.first + population[idx1].second.second,
			  		coste2 = population[idx2].second.first + population[idx2].second.second;

					return coste1 < coste2;
				});

				aux2.resize((Percent * (float) M)/100);
			}

			if(!Mejorado)
				aux2 = ElegirAleatorios(population, M * ((float) Percent / 100), seed);


			for(unsigned int i = 0; i < aux2.size(); ++i) {
				hijo = BusquedaLocalAprendizaje(population[aux2[i]].first, Tr, seed, n_ejecuciones_aux);
				population[aux2[i]] = hijo;
				n_ejecuciones += n_ejecuciones_aux;
			}
		}

		/**/

		idx_padres = Seleccionar(population, M, seed);

		for(unsigned int i = 0; i < N_CRUCES; i+=2) {
				couple.first = &population[idx_padres[i]];
				couple.second = &population[idx_padres[i + 1]];

				hijos = CruceBLX(couple, Tr, seed);
				n_ejecuciones += 2;

				remplazo[i] = hijos.first;
				remplazo[i+1] = hijos.second;

		}

		for(unsigned int i = N_CRUCES;  i < M; ++i) {
			remplazo[i] = population[idx_padres[i]];
		}

		for(unsigned int i = 0;  i < M; ++i) {
			muta = Mutacion(remplazo[i], Tr, seed);
			n_ejecuciones += muta;
		}


		RemplazoGeneracional(population, remplazo);
		++n_generation;
	} while(n_ejecuciones < N_EJECUCIONES);

	return *population.begin();
}
