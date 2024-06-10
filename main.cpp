#include <iostream>
#include "Test.hpp"

int main() {
    while (true) {
        int V, iteracje;
        double gestosc;
        char choice;

        std::cout << "Podaj liczbe wierzcholkow: ";
        std::cin >> V;
        std::cout << "Podaj gestosc (0.0 - 1.0): ";
        std::cin >> gestosc;
        std::cout << "Podaj liczbe iteracji: ";
        std::cin >> iteracje;

        //std::cout << "Wierzcholki: " << V << ", Gestosc: " << gestosc << ", Iteracje: " << iteracje << "\n";

        std::vector<Krawedz<int>> mstLista = testKruskalDlaGrafLista(V, gestosc, iteracje);
        wyswietlMST(mstLista);

        std::vector<Krawedz<int>> mstMacierz = testKruskalDlaGrafMacierz(V, gestosc, iteracje);
        wyswietlMST(mstMacierz);

        std::cout << "Nacisnij '0', aby zakonczyc, lub inny klawisz, aby kontynuowac...\n";
        std::cin.ignore();
        std::cin.get(choice);
        if (choice == '0') {
            break;
        }
    }

    return 0;
}
