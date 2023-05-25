#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <string>
using namespace std;
void pause()
{
    cout << endl << "Pritisnite enter za nastavak!";
    string dummy;
    cin.ignore();
    getline(cin, dummy);
}
int main()
{
    unsigned long long int* redni = new unsigned long long int[1000];
    string* prezimeIme = new string[1000];
    string* rubrika = new string[1000];
    string* predmet = new string[1000];
    int izbor;
    int br = 0;
    while (1)
    {
        system("cls");
        cout << "Dobrodosli u I-dnevnik\n";
        cout << "1. Unos ucenika " << endl;
        cout << "2. Ispis ucenika " << endl;
        cout << "3. Unos predmeta " << endl;
        cout << "4. Unos novih ocjena " << endl;
        cout << "5. Slucajni odabir " << endl;
        cout << "6. Brisanje ucenika " << endl;
        cout << "7. Izlaz iz programa " << endl;
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
                cout << "Redni broj ucenika: " << redni[i] << endl;
                cout << "Ime i Prezime ucenika: " << prezimeIme[i] << endl;

            }
        }
        else if(izbor == 3)
        {
            cin.ignore();
            cout << "Koliko predmeta zelite upisati?: ";
            cout << "Unesite predmete: "<<endl;
            getline(cin, predmet[br]);
            br++;
        }
        else if (izbor == 4)
        {

        }
        else if (izbor == 5)
        {

        }
        else if (izbor == 6)
        {
			unsigned long long int unosUcenik;
			{
				cout << "Unesite broj racuna: ";
				cin >> unosUcenik;
				int makni = find(redni, redni + br, unosUcenik) - redni;
				if (makni == *redni + br)
				{
					cout << "Broj racuna ne postoji." << endl;
				}
				else
				{
					for (int i = makni; i < br - 1; i++)
					{
						redni[i] = redni[i + 1];
						prezimeIme[i] = prezimeIme[i + 1];
					}
					br--;
				}
			}
        }
        else if (izbor == 7)
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