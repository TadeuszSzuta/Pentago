#include <iostream>
using namespace std;
//Deklaracje używanych funkcji
string wczytajNazwyGraczy(string gracze[]); //Wczytuje nazwy graczy
void wczytaniePredefPlanszy(int runda, int plansza[][6], int cwiartkaQ[][3], int cwiartkaW[][3], int cwiartkaA[][3], int cwiartkaS[][3]);// Obsługuje pentago na predefiniowanej planszy
void obrotCwiartki(int plansza[][6], int cwiartkaQ[][3], int cwiartkaW[][3], int cwiartkaA[][3], int cwiartkaS[][3]); //Odpowiada za obbracanie ćwiartek w pentago
void zapiszPlansze(int plansza[][6], int cwiartkaQ[][3], int cwiartkaW[][3], int cwiartkaA[][3], int cwiartkaS[][3]); //Odpowiada za przepisywanie ćwiartek(3x3) do planszy(6x6)
void ruchGracza(int runda, string gracze[], int plansza[][6], int cwiartkaQ[][3], int cwiartkaW[][3], int cwiartkaA[][3], int cwiartkaS[][3]); //Odpowiada za wpisywanie danych podanych przez użytkownika w odpowiednie ćwiartki planszy
void wyrysujPlansze(int plansza[][6]); // Odpowiada za narysowanie w konsoli planszy znaków do kółko i krzyżyk i pentago
void zerowaniePlanszy(int plansza[][6], int cwiartkaQ[][3], int cwiartkaW[][3], int cwiartkaA[][3], int cwiartkaS[][3]); //Przy uruchomieniu każdej gry czyści planszę i ćwiartki, przygotowując je do innych gier
void MenuGlowne(string gracze[], int plansza[][6], int cwiartkaQ[][3], int cwiartkaW[][3], int cwiartkaA[][3], int cwiartkaS[][3]); //Odpowiada za wyświetlanie menu i wybór gier i funkcji zmiany nazwy graczy
void graKiK(string gracze[], int plansza[][6], int cwiartkaQ[][3], int cwiartkaW[][3], int cwiartkaA[][3], int cwiartkaS[][3]); // Odpowiada za obsługę gry w kółko i krzyżyk
void graPentago(string gracze[], int plansza[][6], int cwiartkaQ[][3], int cwiartkaW[][3], int cwiartkaA[][3], int cwiartkaS[][3]); // Odpowiada za obsługę gry w pentago
void predefPentago(string gracze[], int plansza[][6], int cwiartkaQ[][3], int cwiartkaW[][3], int cwiartkaA[][3], int cwiartkaS[][3]); // Odpowiada za obsługę gry w pentago na predefiniowanej planszy

string wczytajNazwyGraczy(string gracze[]) { //Funckja prosi użytkownika o podanie nazwy gracza 1 i gracza 2, nazwy umieszczone są w tablicy gracze

    cout << "Prosze podac nazwe pierwszego gracza: ";
    cin >> gracze[0];
    cout << endl;

    cout << "Prosze podac nazwe drugiego gracza: ";
    cin >> gracze[1];

    system("CLS");
    return gracze[0];
}

void MenuGlowne(string gracze[], int plansza[][6], int cwiartkaQ[][3], int cwiartkaW[][3], int cwiartkaA[][3], int cwiartkaS[][3]) { //Funkcja wyświetla menu i prosi użytkownika o wybranie jednej z podanych opcji. W razie orzymania nieprawidłowych danych prosi użytkownika o ponowne wprowadzenie danych
    char wyborMenu;

    cout << endl << "gracz 1: " << gracze[0] << endl;
    cout << "gracz 2: " << gracze[1] << endl << endl;
    cout << "                Menu" << endl;
    cout << "-----------------------------------" << endl;
    cout << "1. Gra w kolko i krzyzyk" << endl;
    cout << "2. Gra w pentago" << endl;
    cout << "3. Predefioniowana plansza Pentago" << endl;
    cout << "4. Zmiana nazw graczy" << endl;
    cout << endl << "Prosze wybrac jedna z opcji widocznych powyzej: ";

    cin >> wyborMenu;

    switch (wyborMenu) {
    case '1': {
        system("CLS");
        graKiK(gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
    }
            break;

    case '2': {
        system("CLS");
        graPentago(gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);

    }
            break;

    case '3': {
        system("CLS");
        predefPentago(gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
    }
            break;

    case '4': {
        system("CLS");
        wczytajNazwyGraczy(gracze);
        MenuGlowne(gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
    }
            break;

    default: {
        system("CLS");
        cout << endl << "!!!NIE WYBRANO PRAWIDLOWEJ OPCJI!!!" << endl << endl;
        MenuGlowne(gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
    }
           break;

    }

}

void graKiK(string gracze[], int plansza[][6], int cwiartkaQ[][3], int cwiartkaW[][3], int cwiartkaA[][3], int cwiartkaS[][3]) { // Funckja odpowiada za wyświetlanie i działanie gry w kółko i krzyżyk. Po uruchomieniu przygotowywane są zmienne runda, wygrana oraz czyszczone są ćwiartki i plansza do gry;
    int runda = 1;
    bool wygrana = false;

    zerowaniePlanszy(plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);

    while ((runda <= 36) || (wygrana != false)) {

        wyrysujPlansze(plansza);
        ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
        zapiszPlansze(plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);

        runda++;
        system("CLS");

        //Warunek wygranej w KiK
        if (((plansza[0][0] != 0) && (plansza[0][0] == plansza[1][1]) && (plansza[1][1] == plansza[2][2]) && (plansza[2][2] == plansza[3][3]) && (plansza[3][3] == plansza[4][4]) && (plansza[4][4] == plansza[5][5])) ||
            ((plansza[0][5] != 0) && (plansza[0][5] == plansza[1][4]) && (plansza[1][4] == plansza[2][3]) && (plansza[2][3] == plansza[3][2]) && (plansza[3][2] == plansza[4][1]) && (plansza[4][1] == plansza[5][0])) ||

            ((plansza[0][0] != 0) && (plansza[0][0] == plansza[0][1]) && (plansza[0][1] == plansza[0][2]) && (plansza[0][2] == plansza[0][3]) && (plansza[0][3] == plansza[0][4]) && (plansza[0][4] == plansza[0][5])) ||
            ((plansza[1][0] != 0) && (plansza[1][0] == plansza[1][1]) && (plansza[1][1] == plansza[1][2]) && (plansza[1][2] == plansza[1][3]) && (plansza[1][3] == plansza[1][4]) && (plansza[1][4] == plansza[1][5])) ||
            ((plansza[2][0] != 0) && (plansza[2][0] == plansza[2][1]) && (plansza[2][1] == plansza[2][2]) && (plansza[2][2] == plansza[2][3]) && (plansza[2][3] == plansza[2][4]) && (plansza[2][4] == plansza[2][5])) ||
            ((plansza[3][0] != 0) && (plansza[3][0] == plansza[3][1]) && (plansza[3][1] == plansza[3][2]) && (plansza[3][2] == plansza[3][3]) && (plansza[3][3] == plansza[3][4]) && (plansza[3][4] == plansza[3][5])) ||
            ((plansza[4][0] != 0) && (plansza[4][0] == plansza[4][1]) && (plansza[4][1] == plansza[4][2]) && (plansza[4][2] == plansza[4][3]) && (plansza[4][3] == plansza[4][4]) && (plansza[4][4] == plansza[4][5])) ||
            ((plansza[5][0] != 0) && (plansza[5][0] == plansza[5][1]) && (plansza[5][1] == plansza[5][2]) && (plansza[5][2] == plansza[5][3]) && (plansza[5][3] == plansza[5][4]) && (plansza[5][4] == plansza[5][5])) ||

            ((plansza[0][0] != 0) && (plansza[0][0] == plansza[1][0]) && (plansza[1][0] == plansza[2][0]) && (plansza[2][0] == plansza[3][0]) && (plansza[3][0] == plansza[4][0]) && (plansza[4][0] == plansza[5][0])) ||
            ((plansza[0][1] != 0) && (plansza[0][1] == plansza[1][1]) && (plansza[1][1] == plansza[2][1]) && (plansza[2][1] == plansza[3][1]) && (plansza[3][1] == plansza[4][1]) && (plansza[4][1] == plansza[5][1])) ||
            ((plansza[0][2] != 0) && (plansza[0][2] == plansza[1][2]) && (plansza[1][2] == plansza[2][2]) && (plansza[2][2] == plansza[3][2]) && (plansza[3][2] == plansza[4][2]) && (plansza[4][2] == plansza[5][2])) ||
            ((plansza[0][3] != 0) && (plansza[0][3] == plansza[1][3]) && (plansza[1][3] == plansza[2][3]) && (plansza[2][3] == plansza[3][3]) && (plansza[3][3] == plansza[4][3]) && (plansza[4][3] == plansza[5][3])) ||
            ((plansza[0][4] != 0) && (plansza[0][4] == plansza[1][4]) && (plansza[1][4] == plansza[2][4]) && (plansza[2][4] == plansza[3][4]) && (plansza[3][4] == plansza[4][4]) && (plansza[4][4] == plansza[5][4])) ||
            ((plansza[0][5] != 0) && (plansza[0][5] == plansza[1][5]) && (plansza[1][5] == plansza[2][5]) && (plansza[2][5] == plansza[3][5]) && (plansza[3][5] == plansza[4][5]) && (plansza[4][5] == plansza[5][5]))

            ) {
            wygrana = true;
            system("CLS");
            cout << "Wygral gracz: ";
            if ((runda - 1) % 2 == 1) {
                cout << gracze[0];
            }
            else if (runda % 2 == 0) {
                cout << gracze[1];
            }
            cout << endl;

            MenuGlowne(gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
        }

    }
    cout << " Rozgrywka zakonczyla sie remisem" << endl;
    MenuGlowne(gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);

}

void graPentago(string gracze[], int plansza[][6], int cwiartkaQ[][3], int cwiartkaW[][3], int cwiartkaA[][3], int cwiartkaS[][3]) { //Funkcja odpowiada za wyświetlanie i działanie gry w pentago. Podobnie jak w graKiK przygotowywane są zmienne i czyszczona jest plansza z ćwiartkami. Dodatkowo poza umieszczaniem pionka na planszy, użytkownik wybiera i obraca jedną z ćwiartek planszy

    int runda = 1;
    bool wygrana = false;

    zerowaniePlanszy(plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);

    while ((runda <= 36) || (wygrana != false)) {

        wyrysujPlansze(plansza);
        ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
        zapiszPlansze(plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
        system("CLS");
        wyrysujPlansze(plansza);
        obrotCwiartki(plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
        zapiszPlansze(plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);

        runda++;
        system("CLS");

        if (// Warunek wygranej w Pentago
            ((1 == plansza[0][0]) && (plansza[0][0] == plansza[0][1]) && (plansza[0][1] == plansza[0][2]) && (plansza[0][2] == plansza[0][3]) && (plansza[0][3] == plansza[0][4])) ||
            ((1 == plansza[1][0]) && (plansza[1][0] == plansza[1][1]) && (plansza[1][1] == plansza[1][2]) && (plansza[1][2] == plansza[1][3]) && (plansza[1][3] == plansza[1][4])) ||
            ((1 == plansza[2][0]) && (plansza[2][0] == plansza[2][1]) && (plansza[2][1] == plansza[2][2]) && (plansza[2][2] == plansza[2][3]) && (plansza[2][3] == plansza[2][4])) ||
            ((1 == plansza[3][0]) && (plansza[3][0] == plansza[3][1]) && (plansza[3][1] == plansza[3][2]) && (plansza[3][2] == plansza[3][3]) && (plansza[3][3] == plansza[3][4])) ||
            ((1 == plansza[4][0]) && (plansza[4][0] == plansza[4][1]) && (plansza[4][1] == plansza[4][2]) && (plansza[4][2] == plansza[4][3]) && (plansza[4][3] == plansza[4][4])) ||
            ((1 == plansza[5][0]) && (plansza[5][0] == plansza[5][1]) && (plansza[5][1] == plansza[5][2]) && (plansza[5][2] == plansza[5][3]) && (plansza[5][3] == plansza[5][4])) ||

            ((1 == plansza[0][1]) && (plansza[0][1] == plansza[0][2]) && (plansza[0][2] == plansza[0][3]) && (plansza[0][3] == plansza[0][4]) && (plansza[0][4] == plansza[0][5])) ||
            ((1 == plansza[1][1]) && (plansza[1][1] == plansza[1][2]) && (plansza[1][2] == plansza[1][3]) && (plansza[1][3] == plansza[1][4]) && (plansza[1][4] == plansza[1][5])) ||
            ((1 == plansza[2][1]) && (plansza[2][1] == plansza[2][2]) && (plansza[2][2] == plansza[2][3]) && (plansza[2][3] == plansza[2][4]) && (plansza[2][4] == plansza[2][5])) ||
            ((1 == plansza[3][1]) && (plansza[3][1] == plansza[3][2]) && (plansza[3][2] == plansza[3][3]) && (plansza[3][3] == plansza[3][4]) && (plansza[3][4] == plansza[3][5])) ||
            ((1 == plansza[4][1]) && (plansza[4][1] == plansza[4][2]) && (plansza[4][2] == plansza[4][3]) && (plansza[4][3] == plansza[4][4]) && (plansza[4][4] == plansza[4][5])) ||
            ((1 == plansza[5][1]) && (plansza[5][1] == plansza[5][2]) && (plansza[5][2] == plansza[5][3]) && (plansza[5][3] == plansza[5][4]) && (plansza[5][4] == plansza[5][5])) ||

            ((1 == plansza[0][0]) && (plansza[0][0] == plansza[1][0]) && (plansza[1][0] == plansza[2][0]) && (plansza[2][0] == plansza[3][0]) && (plansza[3][0] == plansza[4][0])) ||
            ((1 == plansza[0][1]) && (plansza[0][1] == plansza[1][1]) && (plansza[1][1] == plansza[2][1]) && (plansza[2][1] == plansza[3][1]) && (plansza[3][1] == plansza[4][1])) ||
            ((1 == plansza[0][2]) && (plansza[0][2] == plansza[1][2]) && (plansza[1][2] == plansza[2][2]) && (plansza[2][2] == plansza[3][2]) && (plansza[3][2] == plansza[4][2])) ||
            ((1 == plansza[0][3]) && (plansza[0][3] == plansza[1][3]) && (plansza[1][3] == plansza[2][3]) && (plansza[2][3] == plansza[3][3]) && (plansza[3][3] == plansza[4][3])) ||
            ((1 == plansza[0][4]) && (plansza[0][4] == plansza[1][4]) && (plansza[1][4] == plansza[2][4]) && (plansza[2][4] == plansza[3][4]) && (plansza[3][4] == plansza[4][4])) ||
            ((1 == plansza[0][5]) && (plansza[0][5] == plansza[1][5]) && (plansza[1][5] == plansza[2][5]) && (plansza[2][5] == plansza[0][5]) && (plansza[3][5] == plansza[4][5])) ||

            ((1 == plansza[1][0]) && (plansza[1][0] == plansza[2][0]) && (plansza[2][0] == plansza[3][0]) && (plansza[3][0] == plansza[4][0]) && (plansza[4][0] == plansza[5][0])) ||
            ((1 == plansza[1][1]) && (plansza[1][1] == plansza[2][1]) && (plansza[2][1] == plansza[3][1]) && (plansza[3][1] == plansza[4][1]) && (plansza[4][1] == plansza[5][1])) ||
            ((1 == plansza[1][2]) && (plansza[1][2] == plansza[2][2]) && (plansza[2][2] == plansza[3][2]) && (plansza[3][2] == plansza[4][2]) && (plansza[4][2] == plansza[5][2])) ||
            ((1 == plansza[1][3]) && (plansza[1][3] == plansza[2][3]) && (plansza[2][3] == plansza[3][3]) && (plansza[3][3] == plansza[4][3]) && (plansza[4][3] == plansza[5][3])) ||
            ((1 == plansza[1][4]) && (plansza[1][4] == plansza[2][4]) && (plansza[2][4] == plansza[3][4]) && (plansza[3][4] == plansza[4][4]) && (plansza[4][4] == plansza[5][4])) ||
            ((1 == plansza[1][5]) && (plansza[1][5] == plansza[2][5]) && (plansza[2][5] == plansza[3][5]) && (plansza[3][5] == plansza[4][5]) && (plansza[4][5] == plansza[5][5])) ||

            ((1 == plansza[0][1]) && (plansza[0][1] == plansza[1][2]) && (plansza[1][2] == plansza[2][3]) && (plansza[2][3] == plansza[3][4]) && (plansza[3][4] == plansza[4][5])) ||
            ((1 == plansza[1][0]) && (plansza[1][0] == plansza[2][1]) && (plansza[2][1] == plansza[3][2]) && (plansza[3][2] == plansza[4][3]) && (plansza[4][3] == plansza[5][4])) ||
            ((1 == plansza[0][4]) && (plansza[0][4] == plansza[1][3]) && (plansza[1][3] == plansza[2][2]) && (plansza[2][2] == plansza[3][1]) && (plansza[3][1] == plansza[4][0])) ||
            ((1 == plansza[1][5]) && (plansza[1][5] == plansza[2][4]) && (plansza[2][4] == plansza[3][3]) && (plansza[3][3] == plansza[4][2]) && (plansza[4][2] == plansza[5][1])) ||

            ((1 == plansza[0][0]) && (plansza[0][0] == plansza[1][1]) && (plansza[1][1] == plansza[2][2]) && (plansza[2][2] == plansza[3][3]) && (plansza[3][3] == plansza[4][4])) ||
            ((1 == plansza[1][1]) && (plansza[1][1] == plansza[2][2]) && (plansza[2][2] == plansza[3][3]) && (plansza[3][3] == plansza[4][4]) && (plansza[4][4] == plansza[5][5])) ||
            ((1 == plansza[0][5]) && (plansza[0][5] == plansza[1][4]) && (plansza[1][4] == plansza[2][3]) && (plansza[2][3] == plansza[3][2]) && (plansza[3][2] == plansza[4][1])) ||
            ((1 == plansza[1][4]) && (plansza[1][4] == plansza[2][3]) && (plansza[2][3] == plansza[3][2]) && (plansza[3][2] == plansza[4][1]) && (plansza[4][1] == plansza[5][0])) ||

            ((2 == plansza[0][0]) && (plansza[0][0] == plansza[0][1]) && (plansza[0][1] == plansza[0][2]) && (plansza[0][2] == plansza[0][3]) && (plansza[0][3] == plansza[0][4])) ||
            ((2 == plansza[1][0]) && (plansza[1][0] == plansza[1][1]) && (plansza[1][1] == plansza[1][2]) && (plansza[1][2] == plansza[1][3]) && (plansza[1][3] == plansza[1][4])) ||
            ((2 == plansza[2][0]) && (plansza[2][0] == plansza[2][1]) && (plansza[2][1] == plansza[2][2]) && (plansza[2][2] == plansza[2][3]) && (plansza[2][3] == plansza[2][4])) ||
            ((2 == plansza[3][0]) && (plansza[3][0] == plansza[3][1]) && (plansza[3][1] == plansza[3][2]) && (plansza[3][2] == plansza[3][3]) && (plansza[3][3] == plansza[3][4])) ||
            ((2 == plansza[4][0]) && (plansza[4][0] == plansza[4][1]) && (plansza[4][1] == plansza[4][2]) && (plansza[4][2] == plansza[4][3]) && (plansza[4][3] == plansza[4][4])) ||
            ((2 == plansza[5][0]) && (plansza[5][0] == plansza[5][1]) && (plansza[5][1] == plansza[5][2]) && (plansza[5][2] == plansza[5][3]) && (plansza[5][3] == plansza[5][4])) ||

            ((2 == plansza[0][1]) && (plansza[0][1] == plansza[0][2]) && (plansza[0][2] == plansza[0][3]) && (plansza[0][3] == plansza[0][4]) && (plansza[0][4] == plansza[0][5])) ||
            ((2 == plansza[1][1]) && (plansza[1][1] == plansza[1][2]) && (plansza[1][2] == plansza[1][3]) && (plansza[1][3] == plansza[1][4]) && (plansza[1][4] == plansza[1][5])) ||
            ((2 == plansza[2][1]) && (plansza[2][1] == plansza[2][2]) && (plansza[2][2] == plansza[2][3]) && (plansza[2][3] == plansza[2][4]) && (plansza[2][4] == plansza[2][5])) ||
            ((2 == plansza[3][1]) && (plansza[3][1] == plansza[3][2]) && (plansza[3][2] == plansza[3][3]) && (plansza[3][3] == plansza[3][4]) && (plansza[3][4] == plansza[3][5])) ||
            ((2 == plansza[4][1]) && (plansza[4][1] == plansza[4][2]) && (plansza[4][2] == plansza[4][3]) && (plansza[4][3] == plansza[4][4]) && (plansza[4][4] == plansza[4][5])) ||
            ((2 == plansza[5][1]) && (plansza[5][1] == plansza[5][2]) && (plansza[5][2] == plansza[5][3]) && (plansza[5][3] == plansza[5][4]) && (plansza[5][4] == plansza[5][5])) ||

            ((2 == plansza[0][0]) && (plansza[0][0] == plansza[1][0]) && (plansza[1][0] == plansza[2][0]) && (plansza[2][0] == plansza[3][0]) && (plansza[3][0] == plansza[4][0])) ||
            ((2 == plansza[0][1]) && (plansza[0][1] == plansza[1][1]) && (plansza[1][1] == plansza[2][1]) && (plansza[2][1] == plansza[3][1]) && (plansza[3][1] == plansza[4][1])) ||
            ((2 == plansza[0][2]) && (plansza[0][2] == plansza[1][2]) && (plansza[1][2] == plansza[2][2]) && (plansza[2][2] == plansza[3][2]) && (plansza[3][2] == plansza[4][2])) ||
            ((2 == plansza[0][3]) && (plansza[0][3] == plansza[1][3]) && (plansza[1][3] == plansza[2][3]) && (plansza[2][3] == plansza[3][3]) && (plansza[3][3] == plansza[4][3])) ||
            ((2 == plansza[0][4]) && (plansza[0][4] == plansza[1][4]) && (plansza[1][4] == plansza[2][4]) && (plansza[2][4] == plansza[3][4]) && (plansza[3][4] == plansza[4][4])) ||
            ((2 == plansza[0][5]) && (plansza[0][5] == plansza[1][5]) && (plansza[1][5] == plansza[2][5]) && (plansza[2][5] == plansza[0][5]) && (plansza[3][5] == plansza[4][5])) ||

            ((2 == plansza[1][0]) && (plansza[1][0] == plansza[2][0]) && (plansza[2][0] == plansza[3][0]) && (plansza[3][0] == plansza[4][0]) && (plansza[4][0] == plansza[5][0])) ||
            ((2 == plansza[1][1]) && (plansza[1][1] == plansza[2][1]) && (plansza[2][1] == plansza[3][1]) && (plansza[3][1] == plansza[4][1]) && (plansza[4][1] == plansza[5][1])) ||
            ((2 == plansza[1][2]) && (plansza[1][2] == plansza[2][2]) && (plansza[2][2] == plansza[3][2]) && (plansza[3][2] == plansza[4][2]) && (plansza[4][2] == plansza[5][2])) ||
            ((2 == plansza[1][3]) && (plansza[1][3] == plansza[2][3]) && (plansza[2][3] == plansza[3][3]) && (plansza[3][3] == plansza[4][3]) && (plansza[4][3] == plansza[5][3])) ||
            ((2 == plansza[1][4]) && (plansza[1][4] == plansza[2][4]) && (plansza[2][4] == plansza[3][4]) && (plansza[3][4] == plansza[4][4]) && (plansza[4][4] == plansza[5][4])) ||
            ((2 == plansza[1][5]) && (plansza[1][5] == plansza[2][5]) && (plansza[2][5] == plansza[3][5]) && (plansza[3][5] == plansza[4][5]) && (plansza[4][5] == plansza[5][5])) ||

            ((2 == plansza[0][1]) && (plansza[0][1] == plansza[1][2]) && (plansza[1][2] == plansza[2][3]) && (plansza[2][3] == plansza[3][4]) && (plansza[3][4] == plansza[4][5])) ||
            ((2 == plansza[1][0]) && (plansza[1][0] == plansza[2][1]) && (plansza[2][1] == plansza[3][2]) && (plansza[3][2] == plansza[4][3]) && (plansza[4][3] == plansza[5][4])) ||
            ((2 == plansza[0][4]) && (plansza[0][4] == plansza[1][3]) && (plansza[1][3] == plansza[2][2]) && (plansza[2][2] == plansza[3][1]) && (plansza[3][1] == plansza[4][0])) ||
            ((2 == plansza[1][5]) && (plansza[1][5] == plansza[2][4]) && (plansza[2][4] == plansza[3][3]) && (plansza[3][3] == plansza[4][2]) && (plansza[4][2] == plansza[5][1])) ||

            ((2 == plansza[0][0]) && (plansza[0][0] == plansza[1][1]) && (plansza[1][1] == plansza[2][2]) && (plansza[2][2] == plansza[3][3]) && (plansza[3][3] == plansza[4][4])) ||
            ((2 == plansza[1][1]) && (plansza[1][1] == plansza[2][2]) && (plansza[2][2] == plansza[3][3]) && (plansza[3][3] == plansza[4][4]) && (plansza[4][4] == plansza[5][5])) ||
            ((2 == plansza[0][5]) && (plansza[0][5] == plansza[1][4]) && (plansza[1][4] == plansza[2][3]) && (plansza[2][3] == plansza[3][2]) && (plansza[3][2] == plansza[4][1])) ||
            ((2 == plansza[1][4]) && (plansza[1][4] == plansza[2][3]) && (plansza[2][3] == plansza[3][2]) && (plansza[3][2] == plansza[4][1]) && (plansza[4][1] == plansza[5][0]))

            ) {
            wygrana = true;
            system("CLS");
            cout << "Wygral gracz: ";
            if ((runda - 1) % 2 == 1) {
                cout << gracze[0];
            }
            else if (runda % 2 == 0) {
                cout << gracze[1];
            }
            cout << endl;

            MenuGlowne(gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
        }

    }
    cout << " Rozgrywka zakonczyla sie remisem" << endl;
    MenuGlowne(gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);

}

void predefPentago(string gracze[], int plansza[][6], int cwiartkaQ[][3], int cwiartkaW[][3], int cwiartkaA[][3], int cwiartkaS[][3]) {// Funkcja odpowiada za grę w pentago na częściowo uzupełnionej planszy

    int runda = 17;
    bool wygrana = false;

    zerowaniePlanszy(plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
    wczytaniePredefPlanszy(runda, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
    while ((runda <= 36) || (wygrana != false)) {

        wyrysujPlansze(plansza);
        ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
        zapiszPlansze(plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
        system("CLS");
        wyrysujPlansze(plansza);
        obrotCwiartki(plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
        zapiszPlansze(plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);

        runda++;
        system("CLS");

        if (
            ((1 == plansza[0][0]) && (plansza[0][0] == plansza[0][1]) && (plansza[0][1] == plansza[0][2]) && (plansza[0][2] == plansza[0][3]) && (plansza[0][3] == plansza[0][4])) ||
            ((1 == plansza[1][0]) && (plansza[1][0] == plansza[1][1]) && (plansza[1][1] == plansza[1][2]) && (plansza[1][2] == plansza[1][3]) && (plansza[1][3] == plansza[1][4])) ||
            ((1 == plansza[2][0]) && (plansza[2][0] == plansza[2][1]) && (plansza[2][1] == plansza[2][2]) && (plansza[2][2] == plansza[2][3]) && (plansza[2][3] == plansza[2][4])) ||
            ((1 == plansza[3][0]) && (plansza[3][0] == plansza[3][1]) && (plansza[3][1] == plansza[3][2]) && (plansza[3][2] == plansza[3][3]) && (plansza[3][3] == plansza[3][4])) ||
            ((1 == plansza[4][0]) && (plansza[4][0] == plansza[4][1]) && (plansza[4][1] == plansza[4][2]) && (plansza[4][2] == plansza[4][3]) && (plansza[4][3] == plansza[4][4])) ||
            ((1 == plansza[5][0]) && (plansza[5][0] == plansza[5][1]) && (plansza[5][1] == plansza[5][2]) && (plansza[5][2] == plansza[5][3]) && (plansza[5][3] == plansza[5][4])) ||

            ((1 == plansza[0][1]) && (plansza[0][1] == plansza[0][2]) && (plansza[0][2] == plansza[0][3]) && (plansza[0][3] == plansza[0][4]) && (plansza[0][4] == plansza[0][5])) ||
            ((1 == plansza[1][1]) && (plansza[1][1] == plansza[1][2]) && (plansza[1][2] == plansza[1][3]) && (plansza[1][3] == plansza[1][4]) && (plansza[1][4] == plansza[1][5])) ||
            ((1 == plansza[2][1]) && (plansza[2][1] == plansza[2][2]) && (plansza[2][2] == plansza[2][3]) && (plansza[2][3] == plansza[2][4]) && (plansza[2][4] == plansza[2][5])) ||
            ((1 == plansza[3][1]) && (plansza[3][1] == plansza[3][2]) && (plansza[3][2] == plansza[3][3]) && (plansza[3][3] == plansza[3][4]) && (plansza[3][4] == plansza[3][5])) ||
            ((1 == plansza[4][1]) && (plansza[4][1] == plansza[4][2]) && (plansza[4][2] == plansza[4][3]) && (plansza[4][3] == plansza[4][4]) && (plansza[4][4] == plansza[4][5])) ||
            ((1 == plansza[5][1]) && (plansza[5][1] == plansza[5][2]) && (plansza[5][2] == plansza[5][3]) && (plansza[5][3] == plansza[5][4]) && (plansza[5][4] == plansza[5][5])) ||

            ((1 == plansza[0][0]) && (plansza[0][0] == plansza[1][0]) && (plansza[1][0] == plansza[2][0]) && (plansza[2][0] == plansza[3][0]) && (plansza[3][0] == plansza[4][0])) ||
            ((1 == plansza[0][1]) && (plansza[0][1] == plansza[1][1]) && (plansza[1][1] == plansza[2][1]) && (plansza[2][1] == plansza[3][1]) && (plansza[3][1] == plansza[4][1])) ||
            ((1 == plansza[0][2]) && (plansza[0][2] == plansza[1][2]) && (plansza[1][2] == plansza[2][2]) && (plansza[2][2] == plansza[3][2]) && (plansza[3][2] == plansza[4][2])) ||
            ((1 == plansza[0][3]) && (plansza[0][3] == plansza[1][3]) && (plansza[1][3] == plansza[2][3]) && (plansza[2][3] == plansza[3][3]) && (plansza[3][3] == plansza[4][3])) ||
            ((1 == plansza[0][4]) && (plansza[0][4] == plansza[1][4]) && (plansza[1][4] == plansza[2][4]) && (plansza[2][4] == plansza[3][4]) && (plansza[3][4] == plansza[4][4])) ||
            ((1 == plansza[0][5]) && (plansza[0][5] == plansza[1][5]) && (plansza[1][5] == plansza[2][5]) && (plansza[2][5] == plansza[0][5]) && (plansza[3][5] == plansza[4][5])) ||

            ((1 == plansza[1][0]) && (plansza[1][0] == plansza[2][0]) && (plansza[2][0] == plansza[3][0]) && (plansza[3][0] == plansza[4][0]) && (plansza[4][0] == plansza[5][0])) ||
            ((1 == plansza[1][1]) && (plansza[1][1] == plansza[2][1]) && (plansza[2][1] == plansza[3][1]) && (plansza[3][1] == plansza[4][1]) && (plansza[4][1] == plansza[5][1])) ||
            ((1 == plansza[1][2]) && (plansza[1][2] == plansza[2][2]) && (plansza[2][2] == plansza[3][2]) && (plansza[3][2] == plansza[4][2]) && (plansza[4][2] == plansza[5][2])) ||
            ((1 == plansza[1][3]) && (plansza[1][3] == plansza[2][3]) && (plansza[2][3] == plansza[3][3]) && (plansza[3][3] == plansza[4][3]) && (plansza[4][3] == plansza[5][3])) ||
            ((1 == plansza[1][4]) && (plansza[1][4] == plansza[2][4]) && (plansza[2][4] == plansza[3][4]) && (plansza[3][4] == plansza[4][4]) && (plansza[4][4] == plansza[5][4])) ||
            ((1 == plansza[1][5]) && (plansza[1][5] == plansza[2][5]) && (plansza[2][5] == plansza[3][5]) && (plansza[3][5] == plansza[4][5]) && (plansza[4][5] == plansza[5][5])) ||

            ((1 == plansza[0][1]) && (plansza[0][1] == plansza[1][2]) && (plansza[1][2] == plansza[2][3]) && (plansza[2][3] == plansza[3][4]) && (plansza[3][4] == plansza[4][5])) ||
            ((1 == plansza[1][0]) && (plansza[1][0] == plansza[2][1]) && (plansza[2][1] == plansza[3][2]) && (plansza[3][2] == plansza[4][3]) && (plansza[4][3] == plansza[5][4])) ||
            ((1 == plansza[0][4]) && (plansza[0][4] == plansza[1][3]) && (plansza[1][3] == plansza[2][2]) && (plansza[2][2] == plansza[3][1]) && (plansza[3][1] == plansza[4][0])) ||
            ((1 == plansza[1][5]) && (plansza[1][5] == plansza[2][4]) && (plansza[2][4] == plansza[3][3]) && (plansza[3][3] == plansza[4][2]) && (plansza[4][2] == plansza[5][1])) ||

            ((1 == plansza[0][0]) && (plansza[0][0] == plansza[1][1]) && (plansza[1][1] == plansza[2][2]) && (plansza[2][2] == plansza[3][3]) && (plansza[3][3] == plansza[4][4])) ||
            ((1 == plansza[1][1]) && (plansza[1][1] == plansza[2][2]) && (plansza[2][2] == plansza[3][3]) && (plansza[3][3] == plansza[4][4]) && (plansza[4][4] == plansza[5][5])) ||
            ((1 == plansza[0][5]) && (plansza[0][5] == plansza[1][4]) && (plansza[1][4] == plansza[2][3]) && (plansza[2][3] == plansza[3][2]) && (plansza[3][2] == plansza[4][1])) ||
            ((1 == plansza[1][4]) && (plansza[1][4] == plansza[2][3]) && (plansza[2][3] == plansza[3][2]) && (plansza[3][2] == plansza[4][1]) && (plansza[4][1] == plansza[5][0])) ||

            ((2 == plansza[0][0]) && (plansza[0][0] == plansza[0][1]) && (plansza[0][1] == plansza[0][2]) && (plansza[0][2] == plansza[0][3]) && (plansza[0][3] == plansza[0][4])) ||
            ((2 == plansza[1][0]) && (plansza[1][0] == plansza[1][1]) && (plansza[1][1] == plansza[1][2]) && (plansza[1][2] == plansza[1][3]) && (plansza[1][3] == plansza[1][4])) ||
            ((2 == plansza[2][0]) && (plansza[2][0] == plansza[2][1]) && (plansza[2][1] == plansza[2][2]) && (plansza[2][2] == plansza[2][3]) && (plansza[2][3] == plansza[2][4])) ||
            ((2 == plansza[3][0]) && (plansza[3][0] == plansza[3][1]) && (plansza[3][1] == plansza[3][2]) && (plansza[3][2] == plansza[3][3]) && (plansza[3][3] == plansza[3][4])) ||
            ((2 == plansza[4][0]) && (plansza[4][0] == plansza[4][1]) && (plansza[4][1] == plansza[4][2]) && (plansza[4][2] == plansza[4][3]) && (plansza[4][3] == plansza[4][4])) ||
            ((2 == plansza[5][0]) && (plansza[5][0] == plansza[5][1]) && (plansza[5][1] == plansza[5][2]) && (plansza[5][2] == plansza[5][3]) && (plansza[5][3] == plansza[5][4])) ||

            ((2 == plansza[0][1]) && (plansza[0][1] == plansza[0][2]) && (plansza[0][2] == plansza[0][3]) && (plansza[0][3] == plansza[0][4]) && (plansza[0][4] == plansza[0][5])) ||
            ((2 == plansza[1][1]) && (plansza[1][1] == plansza[1][2]) && (plansza[1][2] == plansza[1][3]) && (plansza[1][3] == plansza[1][4]) && (plansza[1][4] == plansza[1][5])) ||
            ((2 == plansza[2][1]) && (plansza[2][1] == plansza[2][2]) && (plansza[2][2] == plansza[2][3]) && (plansza[2][3] == plansza[2][4]) && (plansza[2][4] == plansza[2][5])) ||
            ((2 == plansza[3][1]) && (plansza[3][1] == plansza[3][2]) && (plansza[3][2] == plansza[3][3]) && (plansza[3][3] == plansza[3][4]) && (plansza[3][4] == plansza[3][5])) ||
            ((2 == plansza[4][1]) && (plansza[4][1] == plansza[4][2]) && (plansza[4][2] == plansza[4][3]) && (plansza[4][3] == plansza[4][4]) && (plansza[4][4] == plansza[4][5])) ||
            ((2 == plansza[5][1]) && (plansza[5][1] == plansza[5][2]) && (plansza[5][2] == plansza[5][3]) && (plansza[5][3] == plansza[5][4]) && (plansza[5][4] == plansza[5][5])) ||

            ((2 == plansza[0][0]) && (plansza[0][0] == plansza[1][0]) && (plansza[1][0] == plansza[2][0]) && (plansza[2][0] == plansza[3][0]) && (plansza[3][0] == plansza[4][0])) ||
            ((2 == plansza[0][1]) && (plansza[0][1] == plansza[1][1]) && (plansza[1][1] == plansza[2][1]) && (plansza[2][1] == plansza[3][1]) && (plansza[3][1] == plansza[4][1])) ||
            ((2 == plansza[0][2]) && (plansza[0][2] == plansza[1][2]) && (plansza[1][2] == plansza[2][2]) && (plansza[2][2] == plansza[3][2]) && (plansza[3][2] == plansza[4][2])) ||
            ((2 == plansza[0][3]) && (plansza[0][3] == plansza[1][3]) && (plansza[1][3] == plansza[2][3]) && (plansza[2][3] == plansza[3][3]) && (plansza[3][3] == plansza[4][3])) ||
            ((2 == plansza[0][4]) && (plansza[0][4] == plansza[1][4]) && (plansza[1][4] == plansza[2][4]) && (plansza[2][4] == plansza[3][4]) && (plansza[3][4] == plansza[4][4])) ||
            ((2 == plansza[0][5]) && (plansza[0][5] == plansza[1][5]) && (plansza[1][5] == plansza[2][5]) && (plansza[2][5] == plansza[0][5]) && (plansza[3][5] == plansza[4][5])) ||

            ((2 == plansza[1][0]) && (plansza[1][0] == plansza[2][0]) && (plansza[2][0] == plansza[3][0]) && (plansza[3][0] == plansza[4][0]) && (plansza[4][0] == plansza[5][0])) ||
            ((2 == plansza[1][1]) && (plansza[1][1] == plansza[2][1]) && (plansza[2][1] == plansza[3][1]) && (plansza[3][1] == plansza[4][1]) && (plansza[4][1] == plansza[5][1])) ||
            ((2 == plansza[1][2]) && (plansza[1][2] == plansza[2][2]) && (plansza[2][2] == plansza[3][2]) && (plansza[3][2] == plansza[4][2]) && (plansza[4][2] == plansza[5][2])) ||
            ((2 == plansza[1][3]) && (plansza[1][3] == plansza[2][3]) && (plansza[2][3] == plansza[3][3]) && (plansza[3][3] == plansza[4][3]) && (plansza[4][3] == plansza[5][3])) ||
            ((2 == plansza[1][4]) && (plansza[1][4] == plansza[2][4]) && (plansza[2][4] == plansza[3][4]) && (plansza[3][4] == plansza[4][4]) && (plansza[4][4] == plansza[5][4])) ||
            ((2 == plansza[1][5]) && (plansza[1][5] == plansza[2][5]) && (plansza[2][5] == plansza[3][5]) && (plansza[3][5] == plansza[4][5]) && (plansza[4][5] == plansza[5][5])) ||

            ((2 == plansza[0][1]) && (plansza[0][1] == plansza[1][2]) && (plansza[1][2] == plansza[2][3]) && (plansza[2][3] == plansza[3][4]) && (plansza[3][4] == plansza[4][5])) ||
            ((2 == plansza[1][0]) && (plansza[1][0] == plansza[2][1]) && (plansza[2][1] == plansza[3][2]) && (plansza[3][2] == plansza[4][3]) && (plansza[4][3] == plansza[5][4])) ||
            ((2 == plansza[0][4]) && (plansza[0][4] == plansza[1][3]) && (plansza[1][3] == plansza[2][2]) && (plansza[2][2] == plansza[3][1]) && (plansza[3][1] == plansza[4][0])) ||
            ((2 == plansza[1][5]) && (plansza[1][5] == plansza[2][4]) && (plansza[2][4] == plansza[3][3]) && (plansza[3][3] == plansza[4][2]) && (plansza[4][2] == plansza[5][1])) ||

            ((2 == plansza[0][0]) && (plansza[0][0] == plansza[1][1]) && (plansza[1][1] == plansza[2][2]) && (plansza[2][2] == plansza[3][3]) && (plansza[3][3] == plansza[4][4])) ||
            ((2 == plansza[1][1]) && (plansza[1][1] == plansza[2][2]) && (plansza[2][2] == plansza[3][3]) && (plansza[3][3] == plansza[4][4]) && (plansza[4][4] == plansza[5][5])) ||
            ((2 == plansza[0][5]) && (plansza[0][5] == plansza[1][4]) && (plansza[1][4] == plansza[2][3]) && (plansza[2][3] == plansza[3][2]) && (plansza[3][2] == plansza[4][1])) ||
            ((2 == plansza[1][4]) && (plansza[1][4] == plansza[2][3]) && (plansza[2][3] == plansza[3][2]) && (plansza[3][2] == plansza[4][1]) && (plansza[4][1] == plansza[5][0]))

            ) {
            wygrana = true;
            system("CLS");
            cout << "Wygral gracz: ";
            if ((runda - 1) % 2 == 1) {
                cout << gracze[0];
            }
            else if (runda % 2 == 0) {
                cout << gracze[1];
            }
            cout << endl;

            MenuGlowne(gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
        }

    }
    cout << " Rozgrywka zakonczyla sie remisem" << endl;
    MenuGlowne(gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);

}

void zerowaniePlanszy(int plansza[][6], int cwiartkaQ[][3], int cwiartkaW[][3], int cwiartkaA[][3], int cwiartkaS[][3]) {// Funkcja uzupełnia ćwiartki i planszę zerami, które w funckji wyrysujPlansze odczytywanie są jako puste pola planszy
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cwiartkaQ[i][j] = 0;
        }

    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cwiartkaW[i][j] = 0;
        }

    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cwiartkaA[i][j] = 0;
        }

    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cwiartkaS[i][j] = 0;
        }

    }
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 6; j++) {
            plansza[i][j] = 0;
        }

    }
}

void wyrysujPlansze(int plansza[][6]) {//Funkcja odpowiada za narysowanie w konsoli aktualnego stanu planszy. Za pomocą warunków z tablicy planszy odczytywane są wartości (0,1,2) i przypisywane im dopowienie symbole ('   ',' x ',' o ')
    for (int i = 1; i <= 26; i++) {
        cout << "-";
    }
    cout << endl;
    cout << "|";
    if (plansza[0][0] == 0) {
        cout << "   ";
    }
    else if (plansza[0][0] == 1) {
        cout << " x ";
    }
    else if (plansza[0][0] == 2) {
        cout << " o ";
    }
    cout << '|';
    if (plansza[0][1] == 0) {
        cout << "   ";
    }
    else if (plansza[0][1] == 1) {
        cout << " x ";
    }
    else if (plansza[0][1] == 2) {
        cout << " o ";
    }
    cout << '|';
    if (plansza[0][2] == 0) {
        cout << "   ";
    }
    else if (plansza[0][2] == 1) {
        cout << " x ";
    }
    else if (plansza[0][2] == 2) {
        cout << " o ";
    }
    cout << "||";
    if (plansza[0][3] == 0) {
        cout << "   ";
    }
    else if (plansza[0][3] == 1) {
        cout << " x ";
    }
    else if (plansza[0][3] == 2) {
        cout << " o ";
    }
    cout << '|';
    if (plansza[0][4] == 0) {
        cout << "   ";
    }
    else if (plansza[0][4] == 1) {
        cout << " x ";
    }
    else if (plansza[0][4] == 2) {
        cout << " o ";
    }
    cout << '|';
    if (plansza[0][5] == 0) {
        cout << "   ";
    }
    else if (plansza[0][5] == 1) {
        cout << " x ";
    }
    else if (plansza[0][5] == 2) {
        cout << " o ";
    }
    cout << '|' << endl;
    cout << '|' << "---" << '|' << "---" << '|' << "---" << "||" << "---" << '|' << "---" << '|' << "---" << '|' << endl;
    cout << "|";
    if (plansza[1][0] == 0) {
        cout << "   ";
    }
    else if (plansza[1][0] == 1) {
        cout << " x ";
    }
    else if (plansza[1][0] == 2) {
        cout << " o ";
    }
    cout << '|';
    if (plansza[1][1] == 0) {
        cout << "   ";
    }
    else if (plansza[1][1] == 1) {
        cout << " x ";
    }
    else if (plansza[1][1] == 2) {
        cout << " o ";
    }
    cout << '|';
    if (plansza[1][2] == 0) {
        cout << "   ";
    }
    else if (plansza[1][2] == 1) {
        cout << " x ";
    }
    else if (plansza[1][2] == 2) {
        cout << " o ";
    }
    cout << "||";
    if (plansza[1][3] == 0) {
        cout << "   ";
    }
    else if (plansza[1][3] == 1) {
        cout << " x ";
    }
    else if (plansza[1][3] == 2) {
        cout << " o ";
    }
    cout << '|';
    if (plansza[1][4] == 0) {
        cout << "   ";
    }
    else if (plansza[1][4] == 1) {
        cout << " x ";
    }
    else if (plansza[1][4] == 2) {
        cout << " o ";
    }
    cout << '|';
    if (plansza[1][5] == 0) {
        cout << "   ";
    }
    else if (plansza[1][5] == 1) {
        cout << " x ";
    }
    else if (plansza[1][5] == 2) {
        cout << " o ";
    }
    cout << '|' << endl;
    cout << '|' << "---" << '|' << "---" << '|' << "---" << "||" << "---" << '|' << "---" << '|' << "---" << '|' << endl;
    cout << "|";
    if (plansza[2][0] == 0) {
        cout << "   ";
    }
    else if (plansza[2][0] == 1) {
        cout << " x ";
    }
    else if (plansza[2][0] == 2) {
        cout << " o ";
    }
    cout << '|';
    if (plansza[2][1] == 0) {
        cout << "   ";
    }
    else if (plansza[2][1] == 1) {
        cout << " x ";
    }
    else if (plansza[2][1] == 2) {
        cout << " o ";
    }
    cout << '|';
    if (plansza[2][2] == 0) {
        cout << "   ";
    }
    else if (plansza[2][2] == 1) {
        cout << " x ";
    }
    else if (plansza[2][2] == 2) {
        cout << " o ";
    }
    cout << "||";
    if (plansza[2][3] == 0) {
        cout << "   ";
    }
    else if (plansza[2][3] == 1) {
        cout << " x ";
    }
    else if (plansza[2][3] == 2) {
        cout << " o ";
    }
    cout << '|';
    if (plansza[2][4] == 0) {
        cout << "   ";
    }
    else if (plansza[2][4] == 1) {
        cout << " x ";
    }
    else if (plansza[2][4] == 2) {
        cout << " o ";
    }
    cout << '|';
    if (plansza[2][5] == 0) {
        cout << "   ";
    }
    else if (plansza[2][5] == 1) {
        cout << " x ";
    }
    else if (plansza[2][5] == 2) {
        cout << " o ";
    }
    cout << '|' << endl;

    for (int i = 1; i <= 26; i++) {
        cout << "=";
    }
    cout << endl;

    cout << "|";
    if (plansza[3][0] == 0) {
        cout << "   ";
    }
    else if (plansza[3][0] == 1) {
        cout << " x ";
    }
    else if (plansza[3][0] == 2) {
        cout << " o ";
    }
    cout << '|';
    if (plansza[3][1] == 0) {
        cout << "   ";
    }
    else if (plansza[3][1] == 1) {
        cout << " x ";
    }
    else if (plansza[3][1] == 2) {
        cout << " o ";
    }
    cout << '|';
    if (plansza[3][2] == 0) {
        cout << "   ";
    }
    else if (plansza[3][2] == 1) {
        cout << " x ";
    }
    else if (plansza[3][2] == 2) {
        cout << " o ";
    }
    cout << "||";
    if (plansza[3][3] == 0) {
        cout << "   ";
    }
    else if (plansza[3][3] == 1) {
        cout << " x ";
    }
    else if (plansza[3][3] == 2) {
        cout << " o ";
    }
    cout << '|';
    if (plansza[3][4] == 0) {
        cout << "   ";
    }
    else if (plansza[3][4] == 1) {
        cout << " x ";
    }
    else if (plansza[3][4] == 2) {
        cout << " o ";
    }
    cout << '|';
    if (plansza[3][5] == 0) {
        cout << "   ";
    }
    else if (plansza[3][5] == 1) {
        cout << " x ";
    }
    else if (plansza[3][5] == 2) {
        cout << " o ";
    }
    cout << '|' << endl;
    cout << '|' << "---" << '|' << "---" << '|' << "---" << "||" << "---" << '|' << "---" << '|' << "---" << '|' << endl;
    cout << "|";
    if (plansza[4][0] == 0) {
        cout << "   ";
    }
    else if (plansza[4][0] == 1) {
        cout << " x ";
    }
    else if (plansza[4][0] == 2) {
        cout << " o ";
    }
    cout << '|';
    if (plansza[4][1] == 0) {
        cout << "   ";
    }
    else if (plansza[4][1] == 1) {
        cout << " x ";
    }
    else if (plansza[4][1] == 2) {
        cout << " o ";
    }
    cout << '|';
    if (plansza[4][2] == 0) {
        cout << "   ";
    }
    else if (plansza[4][2] == 1) {
        cout << " x ";
    }
    else if (plansza[4][2] == 2) {
        cout << " o ";
    }
    cout << "||";
    if (plansza[4][3] == 0) {
        cout << "   ";
    }
    else if (plansza[4][3] == 1) {
        cout << " x ";
    }
    else if (plansza[4][3] == 2) {
        cout << " o ";
    }
    cout << '|';
    if (plansza[4][4] == 0) {
        cout << "   ";
    }
    else if (plansza[4][4] == 1) {
        cout << " x ";
    }
    else if (plansza[4][4] == 2) {
        cout << " o ";
    }
    cout << '|';
    if (plansza[4][5] == 0) {
        cout << "   ";
    }
    else if (plansza[4][5] == 1) {
        cout << " x ";
    }
    else if (plansza[4][5] == 2) {
        cout << " o ";
    }
    cout << '|' << endl;
    cout << '|' << "---" << '|' << "---" << '|' << "---" << "||" << "---" << '|' << "---" << '|' << "---" << '|' << endl;
    cout << "|";
    if (plansza[5][0] == 0) {
        cout << "   ";
    }
    else if (plansza[5][0] == 1) {
        cout << " x ";
    }
    else if (plansza[5][0] == 2) {
        cout << " o ";
    }
    cout << '|';
    if (plansza[5][1] == 0) {
        cout << "   ";
    }
    else if (plansza[5][1] == 1) {
        cout << " x ";
    }
    else if (plansza[5][1] == 2) {
        cout << " o ";
    }
    cout << '|';
    if (plansza[5][2] == 0) {
        cout << "   ";
    }
    else if (plansza[5][2] == 1) {
        cout << " x ";
    }
    else if (plansza[5][2] == 2) {
        cout << " o ";
    }
    cout << "||";
    if (plansza[5][3] == 0) {
        cout << "   ";
    }
    else if (plansza[5][3] == 1) {
        cout << " x ";
    }
    else if (plansza[5][3] == 2) {
        cout << " o ";
    }
    cout << '|';
    if (plansza[5][4] == 0) {
        cout << "   ";
    }
    else if (plansza[5][4] == 1) {
        cout << " x ";
    }
    else if (plansza[5][4] == 2) {
        cout << " o ";
    }
    cout << '|';
    if (plansza[5][5] == 0) {
        cout << "   ";
    }
    else if (plansza[5][5] == 1) {
        cout << " x ";
    }
    else if (plansza[5][5] == 2) {
        cout << " o ";
    }
    cout << '|' << endl;

    for (int i = 1; i <= 26; i++) {
        cout << "-";
    }
    cout << endl;
}

void ruchGracza(int runda, string gracze[], int plansza[][6], int cwiartkaQ[][3], int cwiartkaW[][3], int cwiartkaA[][3], int cwiartkaS[][3]) { //Funkcja prosi użytkownika opodanie znaku ćwiartki i numeru pola na ćwiartce. W zależności od numeru rundy funkcja wpisuje w pole ćwiartki odpowiednią wartość (1,2)
    char znakCwiartki;
    char numerPola;
    int gracz;
    cout << "Runda nr. " << runda << endl;
    if (runda % 2 == 1) {
        gracz = 1;
        cout << "Ruch gracza: " << gracze[0] << " - x";
    }
    else if (runda % 2 == 0) {
        gracz = 2;
        cout << "Ruch gracza: " << gracze[1] << " - o";
    }

    cout << endl << "Prosze wybrac cwiartke (q,w,a,s) i numer pola (1-9): ";
    cin >> znakCwiartki >> numerPola;

    switch (znakCwiartki) {
    case 'q':
    case 'Q': {
        switch (numerPola) {
        case '1': {
            if (cwiartkaQ[2][0] == 0) {
                cwiartkaQ[2][0] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '2': {
            if (cwiartkaQ[2][1] == 0) {
                cwiartkaQ[2][1] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '3': {
            if (cwiartkaQ[2][2] == 0) {
                cwiartkaQ[2][2] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '4': {
            if (cwiartkaQ[1][0] == 0) {
                cwiartkaQ[1][0] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '5': {
            if (cwiartkaQ[1][1] == 0) {
                cwiartkaQ[1][1] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '6': {
            if (cwiartkaQ[1][2] == 0) {
                cwiartkaQ[1][2] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '7': {
            if (cwiartkaQ[0][0] == 0) {
                cwiartkaQ[0][0] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '8': {
            if (cwiartkaQ[0][1] == 0) {
                cwiartkaQ[0][1] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '9': {
            if (cwiartkaQ[0][2] == 0) {
                cwiartkaQ[0][2] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        }
    }
            break;

    case 'w':
    case 'W': {
        switch (numerPola) {
        case '1': {
            if (cwiartkaW[2][0] == 0) {
                cwiartkaW[2][0] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '2': {
            if (cwiartkaW[2][1] == 0) {
                cwiartkaW[2][1] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '3': {
            if (cwiartkaW[2][2] == 0) {
                cwiartkaW[2][2] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '4': {
            if (cwiartkaW[1][0] == 0) {
                cwiartkaW[1][0] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '5': {
            if (cwiartkaW[1][1] == 0) {
                cwiartkaW[1][1] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '6': {
            if (cwiartkaW[1][2] == 0) {
                cwiartkaW[1][2] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '7': {
            if (cwiartkaW[0][0] == 0) {
                cwiartkaW[0][0] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '8': {
            if (cwiartkaW[0][1] == 0) {
                cwiartkaW[0][1] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '9': {
            if (cwiartkaW[0][2] == 0) {
                cwiartkaW[0][2] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        }
    }
            break;

    case 'a':
    case 'A': {
        switch (numerPola) {
        case '1': {
            if (cwiartkaA[2][0] == 0) {
                cwiartkaA[2][0] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '2': {
            if (cwiartkaA[2][1] == 0) {
                cwiartkaA[2][1] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '3': {
            if (cwiartkaA[2][2] == 0) {
                cwiartkaA[2][2] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '4': {
            if (cwiartkaA[1][0] == 0) {
                cwiartkaA[1][0] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '5': {
            if (cwiartkaA[1][1] == 0) {
                cwiartkaA[1][1] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '6': {
            if (cwiartkaA[1][2] == 0) {
                cwiartkaA[1][2] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '7': {
            if (cwiartkaA[0][0] == 0) {
                cwiartkaA[0][0] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '8': {
            if (cwiartkaA[0][1] == 0) {
                cwiartkaA[0][1] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '9': {
            if (cwiartkaA[0][2] == 0) {
                cwiartkaA[0][2] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        }
    }
            break;

    case 's':
    case 'S': {
        switch (numerPola) {
        case '1': {
            if (cwiartkaS[2][0] == 0) {
                cwiartkaS[2][0] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '2': {
            if (cwiartkaS[2][1] == 0) {
                cwiartkaS[2][1] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '3': {
            if (cwiartkaS[2][2] == 0) {
                cwiartkaS[2][2] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '4': {
            if (cwiartkaS[1][0] == 0) {
                cwiartkaS[1][0] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '5': {
            if (cwiartkaS[1][1] == 0) {
                cwiartkaS[1][1] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '6': {
            if (cwiartkaS[1][2] == 0) {
                cwiartkaS[1][2] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '7': {
            if (cwiartkaS[0][0] == 0) {
                cwiartkaS[0][0] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '8': {
            if (cwiartkaS[0][1] == 0) {
                cwiartkaS[0][1] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;
        case '9': {
            if (cwiartkaS[0][2] == 0) {
                cwiartkaS[0][2] = gracz;
            }
            else {
                system("CLS");
                cout << "Pole jest zajete, porsze wybrac inne!" << endl;
                wyrysujPlansze(plansza);
                ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
            }
        }
                break;

        }
    }
            break;
    default: {

        system("CLS");
        cout << "Podano niewlasciwy znak cwiartki!" << endl;
        wyrysujPlansze(plansza);
        ruchGracza(runda, gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);

    }
           break;
    }

}

void zapiszPlansze(int plansza[][6], int cwiartkaQ[][3], int cwiartkaW[][3], int cwiartkaA[][3], int cwiartkaS[][3]) {//Funkcja odpowiada za wpisanie wartości umieszczonych w ćwiartkach w odpowiednie pola tablicy planszy
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            plansza[i][j] = cwiartkaQ[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            plansza[i][j + 3] = cwiartkaW[i][j];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            plansza[i + 3][j] = cwiartkaA[i][j];
        }
    }
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            plansza[i + 3][j + 3] = cwiartkaS[i][j];
        }
    }
}

void obrotCwiartki(int plansza[][6], int cwiartkaQ[][3], int cwiartkaW[][3], int cwiartkaA[][3], int cwiartkaS[][3]) {// Funkcja  prosi użytkownika o wybranie ćwiartki, którą gracz chce obrócić oraz wskazanie, w którą stronę dana ćwiartka ma być obrócona. Wartości z danej ćwiartki są przekazywane do tablicy buforu, które następnie są odpowiednio przepisywane spowrotem do danej ćwiartki
    char znakCwiartki;
    char kierunekObrotu;
    int bufor[3][3];

    cout << endl << "Prosze wybrac cwiartke (q,w,a,s) i kierunek obrotu (z- w lewo, x- w prawo): ";
    cin >> znakCwiartki >> kierunekObrotu;

    switch (znakCwiartki) {
    case 'Q':
    case 'q': {

        switch (kierunekObrotu) {
        case 'Z':
        case 'z': {

            bufor[0][0] = cwiartkaQ[0][0];
            bufor[0][1] = cwiartkaQ[0][1];
            bufor[0][2] = cwiartkaQ[0][2];

            bufor[1][0] = cwiartkaQ[1][0];
            bufor[1][1] = cwiartkaQ[1][1];
            bufor[1][2] = cwiartkaQ[1][2];

            bufor[2][0] = cwiartkaQ[2][0];
            bufor[2][1] = cwiartkaQ[2][1];
            bufor[2][2] = cwiartkaQ[2][2];

            cwiartkaQ[2][0] = bufor[0][0];
            cwiartkaQ[1][0] = bufor[0][1];
            cwiartkaQ[0][0] = bufor[0][2];

            cwiartkaQ[2][1] = bufor[1][0];
            cwiartkaQ[1][1] = bufor[1][1];
            cwiartkaQ[0][1] = bufor[1][2];

            cwiartkaQ[2][2] = bufor[2][0];
            cwiartkaQ[1][2] = bufor[2][1];
            cwiartkaQ[0][2] = bufor[2][2];

        }
                break;

        case 'X':
        case 'x': {

            bufor[0][0] = cwiartkaQ[0][0];
            bufor[0][1] = cwiartkaQ[0][1];
            bufor[0][2] = cwiartkaQ[0][2];

            bufor[1][0] = cwiartkaQ[1][0];
            bufor[1][1] = cwiartkaQ[1][1];
            bufor[1][2] = cwiartkaQ[1][2];

            bufor[2][0] = cwiartkaQ[2][0];
            bufor[2][1] = cwiartkaQ[2][1];
            bufor[2][2] = cwiartkaQ[2][2];

            cwiartkaQ[0][2] = bufor[0][0];
            cwiartkaQ[1][2] = bufor[0][1];
            cwiartkaQ[2][2] = bufor[0][2];

            cwiartkaQ[0][1] = bufor[1][0];
            cwiartkaQ[1][1] = bufor[1][1];
            cwiartkaQ[2][1] = bufor[1][2];

            cwiartkaQ[0][0] = bufor[2][0];
            cwiartkaQ[1][0] = bufor[2][1];
            cwiartkaQ[2][0] = bufor[2][2];

        }
                break;

        default: {

            system("CLS");
            cout << "Prosze wybrac z- obrot w lewo lub x- obrot w prawo!" << endl;
            wyrysujPlansze(plansza);
            obrotCwiartki(plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);

        }
               break;
        }

    }
            break;

    case 'W':
    case 'w': {

        switch (kierunekObrotu) {
        case 'Z':
        case 'z': {

            bufor[0][0] = cwiartkaW[0][0];
            bufor[0][1] = cwiartkaW[0][1];
            bufor[0][2] = cwiartkaW[0][2];

            bufor[1][0] = cwiartkaW[1][0];
            bufor[1][1] = cwiartkaW[1][1];
            bufor[1][2] = cwiartkaW[1][2];

            bufor[2][0] = cwiartkaW[2][0];
            bufor[2][1] = cwiartkaW[2][1];
            bufor[2][2] = cwiartkaW[2][2];

            cwiartkaW[2][0] = bufor[0][0];
            cwiartkaW[1][0] = bufor[0][1];
            cwiartkaW[0][0] = bufor[0][2];

            cwiartkaW[2][1] = bufor[1][0];
            cwiartkaW[1][1] = bufor[1][1];
            cwiartkaW[0][1] = bufor[1][2];

            cwiartkaW[2][2] = bufor[2][0];
            cwiartkaW[1][2] = bufor[2][1];
            cwiartkaW[0][2] = bufor[2][2];

        }
                break;

        case 'X':
        case 'x': {

            bufor[0][0] = cwiartkaW[0][0];
            bufor[0][1] = cwiartkaW[0][1];
            bufor[0][2] = cwiartkaW[0][2];

            bufor[1][0] = cwiartkaW[1][0];
            bufor[1][1] = cwiartkaW[1][1];
            bufor[1][2] = cwiartkaW[1][2];

            bufor[2][0] = cwiartkaW[2][0];
            bufor[2][1] = cwiartkaW[2][1];
            bufor[2][2] = cwiartkaW[2][2];

            cwiartkaW[0][2] = bufor[0][0];
            cwiartkaW[1][2] = bufor[0][1];
            cwiartkaW[2][2] = bufor[0][2];

            cwiartkaW[0][1] = bufor[1][0];
            cwiartkaW[1][1] = bufor[1][1];
            cwiartkaW[2][1] = bufor[1][2];

            cwiartkaW[0][0] = bufor[2][0];
            cwiartkaW[1][0] = bufor[2][1];
            cwiartkaW[2][0] = bufor[2][2];

        }
                break;

        default: {

            system("CLS");
            cout << "Prosze wybrac z- obrot w lewo lub x- obrot w prawo!" << endl;
            wyrysujPlansze(plansza);
            obrotCwiartki(plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);

        }
               break;

        }

    }
            break;

    case 'A':
    case 'a': {

        switch (kierunekObrotu) {
        case 'Z':
        case 'z': {

            bufor[0][0] = cwiartkaA[0][0];
            bufor[0][1] = cwiartkaA[0][1];
            bufor[0][2] = cwiartkaA[0][2];

            bufor[1][0] = cwiartkaA[1][0];
            bufor[1][1] = cwiartkaA[1][1];
            bufor[1][2] = cwiartkaA[1][2];

            bufor[2][0] = cwiartkaA[2][0];
            bufor[2][1] = cwiartkaA[2][1];
            bufor[2][2] = cwiartkaA[2][2];

            cwiartkaA[2][0] = bufor[0][0];
            cwiartkaA[1][0] = bufor[0][1];
            cwiartkaA[0][0] = bufor[0][2];

            cwiartkaA[2][1] = bufor[1][0];
            cwiartkaA[1][1] = bufor[1][1];
            cwiartkaA[0][1] = bufor[1][2];

            cwiartkaA[2][2] = bufor[2][0];
            cwiartkaA[1][2] = bufor[2][1];
            cwiartkaA[0][2] = bufor[2][2];

        }
                break;

        case 'X':
        case 'x': {

            bufor[0][0] = cwiartkaA[0][0];
            bufor[0][1] = cwiartkaA[0][1];
            bufor[0][2] = cwiartkaA[0][2];

            bufor[1][0] = cwiartkaA[1][0];
            bufor[1][1] = cwiartkaA[1][1];
            bufor[1][2] = cwiartkaA[1][2];

            bufor[2][0] = cwiartkaA[2][0];
            bufor[2][1] = cwiartkaA[2][1];
            bufor[2][2] = cwiartkaA[2][2];

            cwiartkaA[0][2] = bufor[0][0];
            cwiartkaA[1][2] = bufor[0][1];
            cwiartkaA[2][2] = bufor[0][2];

            cwiartkaA[0][1] = bufor[1][0];
            cwiartkaA[1][1] = bufor[1][1];
            cwiartkaA[2][1] = bufor[1][2];

            cwiartkaA[0][0] = bufor[2][0];
            cwiartkaA[1][0] = bufor[2][1];
            cwiartkaA[2][0] = bufor[2][2];

        }
                break;

        default: {

            system("CLS");
            cout << "Prosze wybrac z- obrot w lewo lub x- obrot w prawo!" << endl;
            wyrysujPlansze(plansza);
            obrotCwiartki(plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);

        }
               break;

        }

    }
            break;

    case 'S':
    case 's': {

        switch (kierunekObrotu) {
        case 'Z':
        case 'z': {

            bufor[0][0] = cwiartkaS[0][0];
            bufor[0][1] = cwiartkaS[0][1];
            bufor[0][2] = cwiartkaS[0][2];

            bufor[1][0] = cwiartkaS[1][0];
            bufor[1][1] = cwiartkaS[1][1];
            bufor[1][2] = cwiartkaS[1][2];

            bufor[2][0] = cwiartkaS[2][0];
            bufor[2][1] = cwiartkaS[2][1];
            bufor[2][2] = cwiartkaS[2][2];

            cwiartkaS[2][0] = bufor[0][0];
            cwiartkaS[1][0] = bufor[0][1];
            cwiartkaS[0][0] = bufor[0][2];

            cwiartkaS[2][1] = bufor[1][0];
            cwiartkaS[1][1] = bufor[1][1];
            cwiartkaS[0][1] = bufor[1][2];

            cwiartkaS[2][2] = bufor[2][0];
            cwiartkaS[1][2] = bufor[2][1];
            cwiartkaS[0][2] = bufor[2][2];

        }
                break;

        case 'X':
        case 'x': {

            bufor[0][0] = cwiartkaS[0][0];
            bufor[0][1] = cwiartkaS[0][1];
            bufor[0][2] = cwiartkaS[0][2];

            bufor[1][0] = cwiartkaS[1][0];
            bufor[1][1] = cwiartkaS[1][1];
            bufor[1][2] = cwiartkaS[1][2];

            bufor[2][0] = cwiartkaS[2][0];
            bufor[2][1] = cwiartkaS[2][1];
            bufor[2][2] = cwiartkaS[2][2];

            cwiartkaS[0][2] = bufor[0][0];
            cwiartkaS[1][2] = bufor[0][1];
            cwiartkaS[2][2] = bufor[0][2];

            cwiartkaS[0][1] = bufor[1][0];
            cwiartkaS[1][1] = bufor[1][1];
            cwiartkaS[2][1] = bufor[1][2];

            cwiartkaS[0][0] = bufor[2][0];
            cwiartkaS[1][0] = bufor[2][1];
            cwiartkaS[2][0] = bufor[2][2];

        }
                break;

        default: {

            system("CLS");
            cout << "Prosze wybrac z- obrot w lewo lub x- obrot w prawo!" << endl;
            wyrysujPlansze(plansza);
            obrotCwiartki(plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);

        }
               break;

        }

    }
            break;

    default: {

        system("CLS");
        cout << "Podano niewlasciwy znak cwiartki!" << endl;
        wyrysujPlansze(plansza);
        obrotCwiartki(plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);

    }
           break;

    }
}

void wczytaniePredefPlanszy(int runda, int plansza[][6], int cwiartkaQ[][3], int cwiartkaW[][3], int cwiartkaA[][3], int cwiartkaS[][3]) {// Przygotowuje planszę do gry w pentago od momentu wskazanego w treści zadania projektu

    cwiartkaQ[1][0] = 1;
    cwiartkaQ[1][1] = 1;
    cwiartkaQ[2][1] = 1;
    cwiartkaQ[0][1] = 2;
    cwiartkaQ[1][2] = 2;

    cwiartkaW[0][1] = 1;
    cwiartkaW[1][0] = 1;
    cwiartkaW[1][1] = 2;

    cwiartkaA[0][0] = 1;
    cwiartkaA[0][1] = 1;
    cwiartkaA[1][2] = 1;
    cwiartkaA[1][0] = 2;
    cwiartkaA[2][1] = 2;

    cwiartkaS[1][1] = 2;
    cwiartkaS[2][1] = 2;
    cwiartkaS[2][2] = 2;

    zapiszPlansze(plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
}

int main() {
    string gracze[2];
    int plansza[6][6], cwiartkaQ[3][3], cwiartkaW[3][3], cwiartkaA[3][3], cwiartkaS[3][3];

    wczytajNazwyGraczy(gracze);
    MenuGlowne(gracze, plansza, cwiartkaQ, cwiartkaW, cwiartkaA, cwiartkaS);
}