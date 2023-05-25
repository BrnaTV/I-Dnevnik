#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <string>
using namespace std;
void pause()
{
    cout << endl << "Pritisnite enter za nastavak...";
    string dummy;
    cin.ignore();
    getline(cin, dummy);
}
int main()
{
    unsigned long long int* redni = new unsigned long long int[1000];
    string* prezimeIme = new string[1000];
    string* rubrika = new string[1000];
    int izbor;
    int br = 0;
    while (1)
    {
        system("cls");
        cout << "Dobrodosli u I-dnevnik\n";
        cout << "1. Unos ucenika " << endl;
        cout << "2. Ispis ucenika " << endl;
        cout << "3. Unos novih ocjena " << endl;
        cout << "4. Slucajni odabir " << endl;
        cout << "5. Brisanje ucenika " << endl;
        cout << "6. Izlaz iz programa " << endl;
        cout << "Vas odabir je: " <<endl ;
        cin >> izbor;
        if (izbor == 1)
        {
            cout << "Unesite redni broj ucenika: ";
            cin >> redni[br];
            cin.ignore();
            cout << "Unesite ime i prezime ucenika: ";
            getline(cin, prezimeIme[br]);
            br++;
        }
        else if (izbor == 2)
        {
            for (int i = 0; i < br; i++)
            {
                cout << "Redni broj mucenika: " << redni[i] << endl;
                cout << "Ime i Prezime mucenuka: " << prezimeIme[i] << endl<< endl;
            }
        }
        else if (izbor == 3)
        {

        }
        else if (izbor == 4)
        {

        }
        else if (izbor == 5)
        {

        }
        else if (izbor == 6)
        {
            cout << "Izlaz iz programa!";
            break;
        }
        else
        {
            cout << "Krivi unos!" << endl;
        }
        pause();
    }
    return 0;
}