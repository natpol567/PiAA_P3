#ifndef GRAFLISTA_HPP
#define GRAFLISTA_HPP

#include <vector>
#include <iostream>
#include "Krawedz.hpp"

template <typename T>
class GrafLista {
public:
    GrafLista(int V);
    void dodajKrawedz(int u, int v, T waga);
    const std::vector<std::vector<Krawedz<T>>>& pobierzListeSasiedztwa() const;
    void wyswietl() const;

private:
    int V;
    std::vector<std::vector<Krawedz<T>>> listaSasiedztwa;
};

#include "GrafLista.tpp"

#endif // GRAFLISTA_HPP
