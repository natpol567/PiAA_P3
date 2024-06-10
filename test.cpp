#include "Test.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <set>

void generujGraf(int V, double gestosc, GrafLista<int>& grafLista, GrafMacierz<int>& grafMacierz) {
    std::srand(std::time(nullptr));

    int maxEdges = V * (V - 1) / 2;
    int numEdges = static_cast<int>(gestosc * maxEdges);
    std::set<std::pair<int, int>> krawedzieSet;

    for (int i = 1; i < V; ++i) {
        int u = i;
        int v = std::rand() % i;
        krawedzieSet.insert(std::minmax(u, v));
        int waga = std::rand() % 100 + 1;
        grafLista.dodajKrawedz(u, v, waga);
        grafMacierz.dodajKrawedz(u, v, waga);
    }

    while (krawedzieSet.size() < numEdges) {
        int u = std::rand() % V;
        int v = std::rand() % V;
        if (u != v && krawedzieSet.find(std::minmax(u, v)) == krawedzieSet.end()) {
            krawedzieSet.insert(std::minmax(u, v));
            int waga = std::rand() % 100 + 1;
            grafLista.dodajKrawedz(u, v, waga);
            grafMacierz.dodajKrawedz(u, v, waga);
        }
    }
}

std::vector<Krawedz<int>> testKruskalDlaGrafLista(int V, double gestosc, int iteracje) {
    double sumaCzasu = 0.0;
    std::vector<Krawedz<int>> mst;

    for (int i = 0; i < iteracje; ++i) {
        GrafLista<int> graf(V);
        GrafMacierz<int> grafMacierz(V);
        generujGraf(V, gestosc, graf, grafMacierz);
        graf.wyswietl();

        auto start = std::chrono::high_resolution_clock::now();
        Kruskal<int> kruskal;
        mst = kruskal.znajdzMSTZListy(graf, V);
        auto end = std::chrono::high_resolution_clock::now();
        sumaCzasu += std::chrono::duration<double, std::milli>(end - start).count();
    }

    double sredniCzas = sumaCzasu / iteracje;
    std::cout << "Sredni czas (Lista Sasiedztwa): " << sredniCzas << " ms" << std::endl;

    return mst;
}

std::vector<Krawedz<int>> testKruskalDlaGrafMacierz(int V, double gestosc, int iteracje) {
    double sumaCzasu = 0.0;
    std::vector<Krawedz<int>> mst;

    for (int i = 0; i < iteracje; ++i) {
        GrafLista<int> grafLista(V);
        GrafMacierz<int> graf(V);
        generujGraf(V, gestosc, grafLista, graf);
        graf.wyswietl();

        auto start = std::chrono::high_resolution_clock::now();
        Kruskal<int> kruskal;
        mst = kruskal.znajdzMSTZMacierzy(graf, V);
        auto end = std::chrono::high_resolution_clock::now();
        sumaCzasu += std::chrono::duration<double, std::milli>(end - start).count();
    }

    double sredniCzas = sumaCzasu / iteracje;
    std::cout << "Sredni czas (Macierz Sasiedztwa): " << sredniCzas << " ms" << std::endl;

    return mst;
}

void wyswietlMST(const std::vector<Krawedz<int>>& mst) {
    std::cout << "Minimalne Drzewo Rozpinajace (MST):\n";
    for (const auto& krawedz : mst) {
        std::cout << krawedz.zrodlo << " -- " << krawedz.cel << " == " << krawedz.waga << "\n";
    }
}
