#ifndef GRAFMACIERZ_HPP
#define GRAFMACIERZ_HPP

#include <vector>
#include <iostream>
#include "Krawedz.hpp"

template <typename T>
class GrafMacierz {
public:
    GrafMacierz(int V);
    void dodajKrawedz(int u, int v, T waga);
    const std::vector<std::vector<T>>& pobierzMacierzSasiedztwa() const;
    void wyswietl() const;

private:
    int V;
    std::vector<std::vector<T>> macierzSasiedztwa;
};

#include "GrafMacierz.tpp"

#endif // GRAFMACIERZ_HPP
