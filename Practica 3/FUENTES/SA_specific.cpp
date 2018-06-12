#include <SA_specific.h>

pair<vector<individuo::value_type>, pair<float, float>> SimulatedAnneling(const muestra &training, const unsigned int & seed) {
    static default_random_engine generator(seed);
    static uniform_real_distribution<typename individuo::value_type> distribution(0,1);

    vector<typename individuo::value_type> solucion(training.getIndividuo(0).getSize());
    vector<typename individuo::value_type> bestSolution, solucion_aux;

    const unsigned int MAX_EJECUCIONES = 1500;
    const unsigned int MAX_VECINOS = 10 * solucion.size();
    const unsigned int MAX_EXITOS = 0.1 * MAX_VECINOS;
    const unsigned int M = MAX_EJECUCIONES / (MAX_VECINOS * MAX_VECINOS);
    const float MU = 0.3;

    unsigned int vecinos_generados = 0, vecinos_exitos = 0;



    pair<float, float>  coste_solucion_p, coste_solucion_aux_p, coste_best_solution_p;

    float Tstart = 0, Tfinal = 0.003, T;
    float coste_solucion, coste_solucion_aux, coste_best_solution, dif_coste;
   

    typename individuo::size_type i;
    unsigned int n_ejecuciones =  0;

    //INICIALIZAR LA SOLUCION JUNTO CON LA TEMPERATURA
    while (Tstart <= Tfinal) {
        for(i = 0; i < solucion.size();++i) {
            solucion[i] = distribution(generator);
        }

        coste_solucion_p = fObjetivo(solucion, training);
        coste_solucion = 0.5 * (coste_solucion_p.first + coste_solucion_p.second);

        Tstart = (MU * coste_solucion) / -log(MU);
    }

    bestSolution = solucion;
    coste_best_solution_p = coste_solucion_p;
    coste_best_solution = coste_solucion;

    T = Tstart;

    const float BETA = (Tstart - Tfinal) / (M * Tstart * Tfinal);


    do {
      vecinos_generados = 0;
      vecinos_exitos = 0;
      
        while(vecinos_generados < MAX_VECINOS && vecinos_exitos < MAX_EXITOS) {
            solucion_aux = generarVecino(solucion, vecinos_generados % solucion.size(), seed);

            coste_solucion_aux_p = fObjetivo(solucion_aux, training);
            coste_solucion_aux = 0.5 * (coste_solucion_aux_p.first + coste_solucion_aux_p.second);

            dif_coste = coste_solucion_aux - coste_solucion;

            if(dif_coste < 0 || distribution(generator) <= (-dif_coste / T)) {
                solucion = solucion_aux;
                coste_solucion_p = coste_solucion_aux_p;
                coste_solucion = coste_solucion_aux;

                if(coste_solucion > coste_best_solution) {
                    bestSolution = solucion;
                    coste_best_solution_p = coste_solucion_p;
                    coste_best_solution = coste_solucion;
                }
                
                ++vecinos_exitos;
            } 

            ++vecinos_generados; 
        }

        T =  T / (1 + BETA * T);

    } while (T > Tfinal);

    return pair<vector<individuo::value_type>, pair<float, float>>(bestSolution, coste_best_solution_p);
}

