#include <iostream>

struct Punkt {
    double x;
    double y;
};

void inicjuj_punkt(Punkt *p){
    p->x = (std::rand() % 10000) / 50.0 - 100;
    p->y = (std::rand() % 10000) / 50.0 - 100;
}

void inicjuj_punkty(Punkt *punkty, int ile){
    for (int i=0; i<ile; i++){
        inicjuj_punkt(&punkty[i]);
    }
}

int sprawdz_os(Punkt *p){
    if (p->y == 0) return 0; // oś X
    if (p->x == 0) return 1; // oś Y
    return -1;
}

int sprawdz_cwiartke(Punkt *p){
    if (p->x > 0 && p->y > 0) return 0; // I ćwiartka
    if (p->x < 0 && p->y > 0) return 1; // II ćwiartka
    if (p->x < 0 && p->y < 0) return 2; // III ćwiartka
    if (p->x > 0 && p->y < 0) return 3; // IV ćwiartka
    return -1;
}

void zlicz_punkty_na_oic(Punkt *punkty, int ile, int *osie, int *cwiartki)
{
    for (int i=0; i<ile; i++){
        int ktora_os = sprawdz_os(&punkty[i]);
        if (ktora_os != -1){
            osie[ktora_os]++;
            continue;
        }
        int ktora_cw = sprawdz_cwiartke(&punkty[i]);
        if (ktora_cw != -1){
            cwiartki[ktora_cw]++;
        }
    }
}

int main(){
    const int N = 100;
    int licznik_cwiartki[4] = {0, 0, 0, 0};
    int licznik_osi[2] = {0, 0};
    std::srand(1);
    Punkt punkty[N];

    inicjuj_punkty(punkty, N);
    zlicz_punkty_na_oic(punkty, N, licznik_osi, licznik_cwiartki);

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
