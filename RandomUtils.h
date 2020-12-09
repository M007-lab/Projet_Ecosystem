#ifndef RANDUTILS_H
#define RANDUTILS_H

#include <vector>
#include "RandGenerator.h"

template <typename T>
// initialize a population of n elements
std::vector<T> init_n_elements(std::vector<T> list,std::vector<double> weight,int number)
{
    // Vérification des arguments
    if(list.size() != weight.size() && number > 0 )
        throw std::invalid_argument("Size error");
    std::vector<T>  randomlist;
    for(int i=0;i<number;++i)
    {
        randomlist.push_back(random_weighted(list,weight));
    }
    return randomlist;
};

template <typename T>

// Pour titer un élément au hasard dans une liste, en respectant les poids dans weight si sum(weight) = 1
// Aucune garantie si sum(weight) != 1
// Méthode qui va être utilisée pour ajouter au hasard une bestiole au cours de la simulation
T random_element(std::vector<T> list,std::vector<double> weight)
{
    // Vérification des arguments
    if(list.size() != weight.size())
        throw std::invalid_argument("Size error");


    // On doit avoir sum(weight) = 1 !!!!
    int n = 1000; //precision max 10e-3
    std::vector<T> randomlist;

    //On commence par remplir randomlist avec n*weight_x pour chaque x dans list
    for(unsigned int i=0;i<list.size();i++)
    {
        if(weight[i]>0)
        {
            for(int j=0;j<n*weight[i];++j)
            {
                randomlist.push_back(list[i]);
            }
        }
    }
    Rand_int rd(0,randomlist.size());
    return randomlist[rd()];
};

#endif