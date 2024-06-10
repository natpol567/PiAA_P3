#ifndef KRUSKAL_HPP
#define KRUSKAL_HPP

#include <vector>
#include <algorithm>
#include "Krawedz.hpp"
#include "GrafLista.hpp"
#include "GrafMacierz.hpp"

template <typename T>
class Kruskal {
public:
    std::vector<Krawedz<T>> znajdzMSTZListy(const GrafLista<T>& graf, int V);
    std::vector<Krawedz<T>> znajdzMSTZMacierzy(const GrafMacierz<T>& graf, int V);

private:
    int znajdzRodzica(int v, std::vector<int>& rodzic);
    void polaczZbiory(int u, int v, std::vector<int>& rodzic, std::vector<int>& ranga);
};

#include "Kruskal.tpp"

#endif // KRUSKAL_HPP
