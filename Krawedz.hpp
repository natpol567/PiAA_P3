#ifndef KRAWEDZ_HPP
#define KRAWEDZ_HPP

template <typename T>
struct Krawedz {
    int zrodlo, cel;
    T waga;

    Krawedz(int z, int c, T w) : zrodlo(z), cel(c), waga(w) {}

    bool operator<(const Krawedz& inna) const {
        return waga < inna.waga;
    }
};

#endif // KRAWEDZ_HPP
