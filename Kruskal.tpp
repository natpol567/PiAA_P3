#ifndef KRUSKAL_TPP
#define KRUSKAL_TPP

#include "Kruskal.hpp"

template <typename T>
int Kruskal<T>::znajdzRodzica(int v, std::vector<int>& rodzic) {
    if (v != rodzic[v])
        rodzic[v] = znajdzRodzica(rodzic[v], rodzic);
    return rodzic[v];
}

template <typename T>
void Kruskal<T>::polaczZbiory(int u, int v, std::vector<int>& rodzic, std::vector<int>& ranga) {
    int korzenU = znajdzRodzica(u, rodzic);
    int korzenV = znajdzRodzica(v, rodzic);
    if (ranga[korzenU] < ranga[korzenV])
        rodzic[korzenU] = korzenV;
    else if (ranga[korzenU] > ranga[korzenV])
        rodzic[korzenV] = korzenU;
    else {
        rodzic[korzenV] = korzenU;
        ranga[korzenU]++;
    }
}

template <typename T>
std::vector<Krawedz<T>> Kruskal<T>::znajdzMSTZListy(const GrafLista<T>& graf, int V) {
    std::vector<Krawedz<T>> krawedzie;
    std::vector<int> rodzic(V);
    std::vector<int> ranga(V, 0);

    for (int i = 0; i < V; ++i)
        rodzic[i] = i;

    for (int u = 0; u < V; ++u) {
        for (const auto& k : graf.pobierzListeSasiedztwa()[u]) {
            if (u < k.cel) {
                krawedzie.push_back(k);
            }
        }
    }

    std::sort(krawedzie.begin(), krawedzie.end());

    std::vector<Krawedz<T>> mst;
    for (const auto& k : krawedzie) {
        int u = k.zrodlo;
        int v = k.cel;
        if (znajdzRodzica(u, rodzic) != znajdzRodzica(v, rodzic)) {
            mst.push_back(k);
            polaczZbiory(u, v, rodzic, ranga);
        }
    }

    return mst;
}

template <typename T>
std::vector<Krawedz<T>> Kruskal<T>::znajdzMSTZMacierzy(const GrafMacierz<T>& graf, int V) {
    std::vector<Krawedz<T>> krawedzie;
    std::vector<int> rodzic(V);
    std::vector<int> ranga(V, 0);

    for (int i = 0; i < V; ++i)
        rodzic[i] = i;

    for (int u = 0; u < V; ++u) {
        for (int v = u + 1; v < V; ++v) {
            if (graf.pobierzMacierzSasiedztwa()[u][v] != 0) {
                krawedzie.emplace_back(u, v, graf.pobierzMacierzSasiedztwa()[u][v]);
            }
        }
    }

    std::sort(krawedzie.begin(), krawedzie.end());

    std::vector<Krawedz<T>> mst;
    for (const auto& k : krawedzie) {
        int u = k.zrodlo;
        int v = k.cel;
        if (znajdzRodzica(u, rodzic) != znajdzRodzica(v, rodzic)) {
            mst.push_back(k);
            polaczZbiory(u, v, rodzic, ranga);
        }
    }

    return mst;
}

#endif // KRUSKAL_TPP
