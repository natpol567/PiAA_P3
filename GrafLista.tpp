#ifndef GRAFLISTA_TPP
#define GRAFLISTA_TPP

#include "GrafLista.hpp"

template <typename T>
GrafLista<T>::GrafLista(int V) : V(V), listaSasiedztwa(V) {}

template <typename T>
void GrafLista<T>::dodajKrawedz(int u, int v, T waga) {
    listaSasiedztwa[u].emplace_back(u, v, waga);
    listaSasiedztwa[v].emplace_back(v, u, waga); // Dla grafu nieskierowanego
}

template <typename T>
const std::vector<std::vector<Krawedz<T>>>& GrafLista<T>::pobierzListeSasiedztwa() const {
    return listaSasiedztwa;
}



template <typename T>
void GrafLista<T>::wyswietl() const {
    std::cout << "Lista sasiedztwa:\n";
    for (int i = 0; i < V; ++i) {
        std::cout << i << ":";
        for (const auto& krawedz : listaSasiedztwa[i]) {
            std::cout << " -> " << krawedz.cel << " (" << krawedz.waga << ")";
        }
        std::cout << "\n";
    }
}

#endif // GRAFLISTA_TPP
