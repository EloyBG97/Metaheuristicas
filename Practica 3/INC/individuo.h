/**
* @file individuo.h
* @author Eloy Bedia García
* @date 24 de Marzo de 2018
**/

#ifndef _INDIVIDUO_H_
#define _INDIVIDUO_H_

#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>

using namespace std;

/**! Clase conjunto
*!individuo::individuo, getResult, getQuality,  getSize.
* Tipos individuo::value_type, individuo::size_type
* Descripción
* Es un caso concreto
*/

class individuo {
  public:

    /**
    * @brief Es el tipo con el que se manejaran todas las caracteristicas del individuo
    **/
    typedef float value_type;

    /**
    * @brief Es el tipo con el que se manejara la cantidad de caracteristicas que tenga el individuo
    **/
    typedef unsigned short size_type;

    /**
    *@brief Inicializa un individuo vacio (sin caracteristicas)
    **/
    individuo();

    /**
    * @brief Borra todas las caracteristicas del individuo.
    */
    ~individuo();

    /**
    * @brief Se crea un individuo con @a nQualities desde la cadena
    * de caracteres @a data
    * @param [in] data Es la cadena de caracteres que contiene las caracteristicas
    * del individuo
    * @param [in] nQualities Es el núemro de caracteristicas que tiene el individuo
    **/
    individuo(const string &data, const size_type &nQualities);

    /**
    @brief Crea un individuo que es copia exacta del individuo @a I
    @param [in] I Individuo desde el cual se hará la copia
    **/
    individuo(const individuo &I);

    /**
    @brief Asigna el valor del individuo  @a i a otro individuo
    @param [in] i Individuo del cual se asignará su valor a otro individuo
    @return Devuelve un individuo exactamente igual que @a i
    **/
    individuo &operator=(const individuo &i);

    /**
    * @brief Compara las caracteristicas del individuo con @a I para comprobar si son iguales o no
    * @param [in] I Individuo de referencia para comparar
    * @return Devuelve TRUE n caso de igualdad y FALSE en caso contrario.
    **/
    bool operator== (const individuo &I) const;

    /**
    * @brief Consulta si es un caso positivo o negativo.
    * @result TRUE si es un caso positivo y FALSE si es un caso negativo
    **/
    bool getResult() const;

    /**
    * @brief Consulta la caracteristicas @a n del individuo
    * @param [in] n El número de caracteristica a consultar
    * @pre Existe la caracteristica número @a n del individuo
    * @return Devuelve la caracteristica en cuestion
    **/
    const value_type &getQuality(const size_type &n) const;
    value_type &getQuality(const size_type &n);

    /**
    * @brief Consulta el número de caracteristicas del individuo
    * @return Devuelve El numero d caracteristicas del individuo
    **/
    size_type getSize() const;

 private:

    /**
    @brief Aribuo que distingue entre un caso positivo y negativo
    **/
    bool result;

    /**
    * @brief Conjunto de caracteristicas de un Individuo
    **/
    vector<value_type> qualities;

};

#endif
