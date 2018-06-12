#include <DE_specific.h>

using namespace std;

pair<vector<individuo::value_type>, pair<float, float>> DERand1(const muestra &training, const unsigned int & seed) {
    static default_random_engine generator(seed);
	uniform_real_distribution<double> distribution(0 ,1);

    const unsigned int SIZE_POPULATION = 50;
    const float F = 0.5;
    const float CR = 0.5;
    poblacion_genetico population = StartPopulation(training, SIZE_POPULATION, seed);
    individuo_genetico hijo;
    vector<unsigned int> parents;
    unsigned int nEjecuciones = 0;
    unsigned int aux;
    vector<unsigned int> idx_population(SIZE_POPULATION);

    hijo.first.resize(population[0].first.size());

    do {
        for(unsigned int i = 0; i < SIZE_POPULATION; ++i) {

            parents = ElegirAleatorios(population, 3, seed);

            for(unsigned int j = 0; j < population[i].first.size(); ++j) {
                if(distribution(generator) < CR) {
                    hijo.first[j] = population[parents[0]].first[j] + F * (population[parents[1]].first[j] - population[parents[2]].first[j]);
                }

                else{
                    hijo.first[j] = population[i].first[j];
                }
            }

            hijo.second = fObjetivo(hijo.first, training);
            ++nEjecuciones;

            if(population[i].second < hijo.second)
                population[i] = hijo;

        }

    } while (nEjecuciones < 15000);

   	for(unsigned i = 0; i < SIZE_POPULATION; ++i) {
		idx_population[i] = i;
	}
	
	sort(idx_population.begin(), idx_population.end(), [&](unsigned int idx1, unsigned int idx2) {
		float coste1 = population[idx1].second.first + population[idx1].second.second, 
			  coste2 = population[idx2].second.first + population[idx2].second.second;

		return coste1 > coste2;
	});

	return population[idx_population[0]];
}


pair<vector<individuo::value_type>, pair<float, float>> DECurrentBest1(const muestra &training, const unsigned int & seed){
    static default_random_engine generator(seed);
	uniform_real_distribution<double> distribution(0 ,1);

    const unsigned int SIZE_POPULATION = 50;
    const float F = 0.5;
    const float CR = 0.5;
    poblacion_genetico population = StartPopulation(training, SIZE_POPULATION, seed);
    individuo_genetico hijo;
    vector<unsigned int> parents;
    unsigned int nEjecuciones = 0;
    unsigned int aux;
    vector<unsigned int> idx_population(SIZE_POPULATION);

    hijo.first.resize(population[0].first.size());

    do {
        for(unsigned int i = 0; i < SIZE_POPULATION; ++i) {

            for(unsigned j = 0; j < SIZE_POPULATION; ++j) {
                idx_population[j] = j;
            }
            
            sort(idx_population.begin(), idx_population.end(), [&](unsigned int idx1, unsigned int idx2) {
                float coste1 = population[idx1].second.first + population[idx1].second.second, 
                    coste2 = population[idx2].second.first + population[idx2].second.second;

                return coste1 > coste2;
            });


            parents = ElegirAleatorios(population, 2, seed);

            for(unsigned int j = 0; j < population[i].first.size(); ++j) {
                if(distribution(generator) < CR) {
                    hijo.first[j] = population[i].first[j] + F * (population[idx_population[0]].first[j] - population[i].first[j]) + F * (population[parents[0]].first[j] - population[parents[1]].first[j]);
                }

                else{
                    hijo.first[j] = population[i].first[j];
                }
            }

            hijo.second = fObjetivo(hijo.first, training);
            ++nEjecuciones;

            if(population[i].second < hijo.second)
                population[i] = hijo;

        }

    } while (nEjecuciones < 15000);

   	for(unsigned i = 0; i < SIZE_POPULATION; ++i) {
		idx_population[i] = i;
	}
	
	sort(idx_population.begin(), idx_population.end(), [&](unsigned int idx1, unsigned int idx2) {
		float coste1 = population[idx1].second.first + population[idx1].second.second, 
			  coste2 = population[idx2].second.first + population[idx2].second.second;

		return coste1 > coste2;
	});

	return population[idx_population[0]];
}
