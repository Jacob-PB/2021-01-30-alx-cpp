#include <iostream>

struct Punkt {
    double x;
    double y;
};

void inicjuj_punkt(Punkt *p){
    p->x = std::rand() % 21 - 10;
    p->y = std::rand() % 21 - 10;
}

void inicjuj_punkty(Punkt *punkty, int ile){
    for (int i=0; i<ile; i++){
        inicjuj_punkt(&punkty[i]);
    }
}

int main(){
    const int N = 100;
    int licznik_cwiartki[4] = {0, 0, 0, 0};
    int licznik_osi[2] = {0, 0};
    std::srand(1);
    Punkt punkty[N];

    inicjuj_punkty(punkty, N);

    for (int i=0; i<N; i++){
        if (punkty[i].y == 0 ) licznik_osi[0]++; // oś X
        if (punkty[i].x == 0 ) licznik_osi[1]++; // oś Y

        if (punkty[i].y == 0 || punkty[i].x == 0) continue;

        if (punkty[i].x > 0 && punkty[i].y > 0) licznik_cwiartki[0]++; // I ćwiartka
        if (punkty[i].x < 0 && punkty[i].y > 0) licznik_cwiartki[1]++; // II ćwiartka
        if (punkty[i].x < 0 && punkty[i].y < 0) licznik_cwiartki[2]++; // III ćwiartka
        if (punkty[i].x > 0 && punkty[i].y < 0) licznik_cwiartki[3]++; // IV ćwiartka
    }

    for (int i=0; i<N; i++){
        std::cout << i << ": " << punkty[i].x << ", " << punkty[i].y << "\n";
    }

    for (int i=0; i<4; i++){
        std::cout << "ćwiartka " << (i + 1) << ": " << licznik_cwiartki[i] << "\n";
    }
    std::cout << "oś X: " << licznik_osi[0] << "\n";
    std::cout << "oś Y: " << licznik_osi[1] << "\n";

    return 0;
}
