#ifndef GRAFMACIERZ_TPP
#define GRAFMACIERZ_TPP

#include "GrafMacierz.hpp"

template <typename T>
GrafMacierz<T>::GrafMacierz(int V) : V(V), macierzSasiedztwa(V, std::vector<T>(V, 0)) {}

template <typename T>
void GrafMacierz<T>::dodajKrawedz(int u, int v, T waga) {
    macierzSasiedztwa[u][v] = waga;
    macierzSasiedztwa[v][u] = waga; // Dla grafu nieskierowanego
}

template <typename T>
const std::vector<std::vector<T>>& GrafMacierz<T>::pobierzMacierzSasiedztwa() const {
    return macierzSasiedztwa;
}



template <typename T>
void GrafMacierz<T>::wyswietl() const {
    std::cout << "Macierz sasiedztwa:\n";
    for (const auto& wiersz : macierzSasiedztwa) {
        for (const auto& wartosc : wiersz) {
            std::cout << wartosc << " ";
        }
        std::cout << "\n";
    }
}

#endif // GRAFMACIERZ_TPP
