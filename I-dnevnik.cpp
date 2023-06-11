#include <iostream>
#include <algorithm>
#include <numeric>
#include <utility>
#include <cmath>
#include <string>
#include <cstdlib>
#include <fstream>
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
	string predmeti[] = { "AiP", "Hrvatski", "Matematika", "Fizika", "Povijest" };
	string* ucenici = new string[50];
	int* dnevnik = new int[1000];
	int izbor;
	int brojUcenika = 0;
	int brojOcjena = 0;

	srand(time(NULL));

	while (1)
	{
		system("cls");
		cout << "Dobrodosli u I-dnevnik" << endl;
		cout << "1. Unos ucenika" << endl;
		cout << "2. Ispis svih ucenika" << endl;
		cout << "3. Brisanje ucenika" << endl;
		cout << "4. Unos novih ocjena" << endl;
		cout << "5. Ispis ocjena" << endl;
		cout << "6. Slucajni odabir" << endl;
		cout << "7. Spremi ucenike u tekst datoteku" << endl;
		cout << "8. Spremi ucenike u binarnu datoteku" << endl;
		cout << "9. Izlaz iz programa" << endl;
		cout << "Vas odabir je: ";
		cin >> izbor;
		if (izbor == 1)
		{
			cin.ignore();
			cout << "Unesite ime i prezime ucenika: ";
			getline(cin, ucenici[brojUcenika]);
			brojUcenika++;
		}
		else if (izbor == 2)
		{
			if (brojUcenika > 0)
			{
				cout << "Popis ucenika" << endl;
				cout << "---------------" << endl;

				for (int i = 0; i < brojUcenika; i++)
				{
					cout << i << ". " << ucenici[i] << endl;
				}
			}
			else
			{
				cout << "Nema unesenih ucenika." << endl;
			}
		}
		else if (izbor == 3)
		{
			int makniUcenika;

			if (brojUcenika > 0)
			{
				cout << "Popis ucenika" << endl;
				cout << "---------------" << endl;

				for (int i = 0; i < brojUcenika; i++)
				{
					cout << i << ". " << ucenici[i] << endl;
				}

				cout << "Unesite redni broj ucenika za brisanje: ";
				cin >> makniUcenika;

				for (int i = makniUcenika; i < brojUcenika; i++) {
					ucenici[i] = ucenici[i + 1];
				}

				brojUcenika--;
			}
			else
			{
				cout << "Nema unesenih ucenika." << endl;
			}
		}
		else if (izbor == 4)
		{
			int odabraniUcenik;
			int odabraniPredmet;
			int ocjena = 0;

			if (brojUcenika > 0)
			{
				cout << "Popis ucenika" << endl;
				cout << "---------------" << endl;

				for (int i = 0; i < brojUcenika; i++)
				{
					cout << i << ". " << ucenici[i] << endl;
				}

				cout << "Unesite redni broj ucenika za unos ocjene: ";
				cin >> odabraniUcenik;

				cout << "Popis predmeta" << endl;
				cout << "------------------" << endl;

				for (int i = 0; i < sizeof(predmeti) / sizeof(string); i++)
				{
					cout << i << ". " << predmeti[i] << endl;
				}

				cout << "Unesite redni predmeta za unos ocjene: ";
				cin >> odabraniPredmet;

				cout << "Unesite ocjenu: ";
				cin >> ocjena;

				int pokazivac = brojOcjena * 3;

				// upis ucenika
				dnevnik[pokazivac] = odabraniUcenik;
				// upis predmeta
				dnevnik[pokazivac + 1] = odabraniPredmet;
				// upis ocjene
				dnevnik[pokazivac + 2] = ocjena;

				brojOcjena++;
			}
			else
			{
				cout << "Nema unesenih ucenika." << endl;
			}
		}
		else if (izbor == 5)
		{
			int odabraniUcenik;

			if (brojUcenika > 0)
			{
				cout << "Popis ucenika" << endl;
				cout << "---------------" << endl;

				for (int i = 0; i < brojUcenika; i++)
				{
					cout << i << ". " << ucenici[i] << endl;
				}

				cout << "Unesite redni broj ucenika za ispis ocjena: ";
				cin >> odabraniUcenik;

				cout << "Ocjene za: " << ucenici[odabraniUcenik] << endl << endl;

				// petlja po predmetima
				int velicinaPredmeta = (sizeof(predmeti) / sizeof(string)) - 1;
				for (int i = 0; i < velicinaPredmeta; i++) {
					double suma = 0;
					int brojacProsjeka = 0;

					cout << predmeti[i] << " : ";

					// petlja po dnevniku
					// ocjene su zapisane u grupi po 3 -> broj ucenika, broj predmeta, ocjena
					for (int j = 0; j < brojOcjena * 3; j = j + 3) {
						if (dnevnik[j] == odabraniUcenik && dnevnik[j + 1] == i) {
							int ocjena = dnevnik[j + 2];
							cout << ocjena << ", ";
							suma = suma + ocjena;
							brojacProsjeka++;
						}
					}

					double prosjek = 0;
					if (brojacProsjeka > 0) {
						prosjek = suma / brojacProsjeka;
					}

					cout << "Prosjek: " << prosjek << endl;
				}
			}
			else
			{
				cout << "Nema unesenih ucenika." << endl;
			}
		}
		else if (izbor == 6)
		{
			int slucajniUcenik = rand() % brojUcenika;
			cout << "Slucajni odabir je odabrao:" << endl;
			cout << slucajniUcenik << ". " << ucenici[slucajniUcenik] << endl;
		}
		else if (izbor == 7)
		{
			fstream datoteka;
			datoteka.open("ucenici.txt", ios::out);
			for (int i = 0; i < brojUcenika; i++) {
				datoteka << ucenici[i] << endl;
			}
			datoteka.close();
			cout << "Ucenici spremljeni";
		}
		else if (izbor == 8)
		{
			fstream datoteka;
			datoteka.open("ucenici.bin", ios::binary | ios::out);
			for (int i = 0; i < brojUcenika; i++) {
				string ucenik = ucenici[i];
				datoteka.write((char*)&ucenik, sizeof(ucenik));
			}
			datoteka.close();
			cout << "Ucenici spremljeni";
		}
		else if (izbor == 9)
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