#ifndef TEST_HPP
#define TEST_HPP

#include <vector>
#include "Krawedz.hpp"
#include "GrafLista.hpp"
#include "GrafMacierz.hpp"
#include "Kruskal.hpp"

void generujGraf(int V, double gestosc, GrafLista<int>& grafLista, GrafMacierz<int>& grafMacierz);
std::vector<Krawedz<int>> testKruskalDlaGrafLista(int V, double gestosc, int iteracje);
std::vector<Krawedz<int>> testKruskalDlaGrafMacierz(int V, double gestosc, int iteracje);
void wyswietlMST(const std::vector<Krawedz<int>>& mst);

#endif // TEST_HPP
