# Zadanie

W istniejącym kodzie klasy `Tablica` zaimplementować metodę `void zmien_rozmiar(int n)`

Przykład:
```
int main(){
    Tablica tab{20};

    tab.ustaw(3, 1999);

    tab.zmien_rozmiar(10);

    tab.wyswietl();
}
```

Ma wyświetlić tablicę z elementami od 0 do 9.

Stworzyć metody pomocnicze:
- `wypelnij(int wartosc)` - wypełnia całą tablicę daną wartością
- `wypelnij_zakres(int od, int do, int wartość)` - wypełnia zakres komórek daną wartością
