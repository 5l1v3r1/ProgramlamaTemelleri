#include "pch.h"
#include <iostream>
#include <locale.h>
#include <string>
#include <random>
#include <time.h>

using namespace std;

void arttir5(int sayi);
void arttir5(int *p);
void kat(int *ptr);
int * rastgele();
void neg_poz(int *s, int *ptoplam, int *ntoplam);
void random();

void tersine(string *p);

int main() {
	setlocale(LC_ALL, "turkish");
	srand(time(NULL));
	int sayi = 10;
	int *p = &sayi;
	
	cout << "sayi:" << sayi << endl;
	cout << "&sayi:"<< &sayi << endl;//de�erin tutuldu�u adres de�erini yazd�r�r

	cout << "p:" << p << endl; //i�inde tuttu�u adresi yazd�r�r
	cout << "*p:" << *p << endl; //i�inde tuttu�u adresteki de�eri yazd�r�r
	
	arttir5(sayi);
	cout <<"arttir5(sayi) fonksiyonu �al��t�..: " << sayi << endl;

	arttir5(&sayi);
	cout << "arttir5(&sayi) fonksiyonu �al��t�..: " << sayi << endl;
	
	kat(&sayi); //say�n�n i�aret etti�i adres (i�aret�i/pointer) bilgisini  kat fonksiyonuna parametre olarak g�nderdik
	cout << "sayi:" << sayi << endl;

	string kelime;
	cout << "Kelime:";
	cin >> kelime;
	//getline(cin, kelime);
	//Birden fazla kelimeyi de�i�ken i�inde tutmay� sa�lar.
	tersine(&kelime);
	cout << "kelime:" << kelime << endl;
	

	int toplam = * rastgele();
	cout << "Toplam:" << toplam << endl;

	//Kullan�c� 0 girene kadar girdi�i de�erlerin pozitif olanlar�n� ve negatif olanlar�n� bir de�i�kende tutup bu de�erleri main i�erisinde yazd�ral�m
	int s, ptoplam=0, ntoplam=0;
	cout << endl << "Burada girdi�iniz pozitif ve negatif say�lar�n toplam� hesaplanacakt�r." << endl;
	cout << "��kmak i�in 0 de�erini giriniz..." << endl;
	do
	{
		cout << "Say�:";
		cin >> s;
		neg_poz(&s, &ptoplam, &ntoplam);
	} while (s!=0);
	cout << "Pozitif Toplam:" << ptoplam << endl;
	cout << "Negatif Toplam:" << ntoplam << endl;
	
	random();

	system("pause");

	return 1;
}
void arttir5(int sayi) {
	//kendisine g�nderilen sayi de�i�keninin kopyas�n� olu�turdu.
	//Bu sebeple g�nderilen fonksiyon i�erisindeki bu de�er de�i�medi.
	sayi += 5;
}

//Kendisine g�nderilen bellek adresinin i�inde saklanan de�eri 5 artt�ran fonksiyon:
void arttir5(int *p) {
	cout << "p:" << p << endl;
	*p += 5; // *p = *p + 5;
	cout << "*p:" << *p << endl; //
	cout << "&p:" << &p << endl; //p adresi
}

//Problem: Kullan�c�dan al�nan de�eri fonksiyon parametre olarak als�n ve 
//bu de�eri fonksiyon i�erisinde kullan�c�n�n girdi�i kata e�itlesin
//�r:main i�inde 4 girilirse, fonksiyonda 5 girilirse, mainden gelen 4 de�eri 20 olacak
void kat(int *ptr) {
	int kat;
	cout << "Kat de�eri:";
	cin >> kat;
	*ptr = *ptr * kat; // *ptr *= kat;
	//*ptr pointer'�n tuttu�u adresteki veriye gitti ve bu de�eri kat de�eriyle �arp�p yeni de�eri yapt�.
}

//Kendisine g�nderilen kelimenin adresini (pointer) tutan fonksiyon tan�mlayal�m. Bu kelimeyi fonksiyon i�inde tersine d�n��t�relim.
//�R: kendisine "kedi" kelimesi geldi�inde, kelime "idek" olacak.
void tersine(string *p) {
	string ters = "";
	int uzunluk = (*p).length();
	for (int i = uzunluk-1; i >=0; i--)
		//uzunluk kelimenin karakter say�s�n� tutuyor. �ndis de�erimiz s�f�rdan ba�lad��� i�in 1 eksi�ini ald�k.
	{
		ters += (*p)[i];
	}
	*p = ters;
}

//random ile olu�turulan 1-10 aras�ndaki 10 say�n�n toplam�n�n tutuldu�u adresi �a�r�ld��� fonksiyona g�nderen fonksiyonu yazal�m.
int * rastgele() {
	int sayi, toplam = 0;
	for (int i = 1; i <= 10; i++)
	{
		sayi = rand() % 10 + 1;
		cout << sayi << " ";
		toplam += sayi;
	}
	cout << endl;
	cout << "Toplam:" << toplam << endl;
	return &toplam;
}

void neg_poz(int *s, int *ptoplam, int *ntoplam) {
	if (*s > 0)
		*ptoplam += *s;
	else if (*s < 0)
		*ntoplam += *s;
}

//10 tane 0-100 aras�nda rastgele �retilen say�y� bir dizide tutarak bu de�erleri adres de�erleri ile yazd�ral�m
void random() {
	int sayilar[10];
	for (int i = 0; i < 10; i++){
		sayilar[i] = rand() % 101+0;
		cout << sayilar[i] << " ";
	}
	cout << endl;
	int *p = sayilar;
	cout << "p:" << p << endl;
	cout << "p+1:" << p + 1 << endl;
	cout << "*p:" << *p << endl;
	cout << "*(p+1):" << *(p + 1) << endl;
	//p+1 adresinde tutulan de�eri getirir
	cout << "*p+1:" << *p + 1 << endl;
	//p adresinde tutulan de�erin 1 fazlas�n� getirir
	cout << "De�erler:" << endl;
	for (int i = 0; i < 10; i++){
		cout << *(p+i) << " ";
	}
	cout << endl;
	cout << "Adresler:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << p + i << endl;
	}
	cout << endl;
	cout << "Adresler:\tDe�erler:\n";
	for (int i = 0; i < 10; i++) {
		cout << p + i << "\t" << *(p + i) << endl;
	}
}