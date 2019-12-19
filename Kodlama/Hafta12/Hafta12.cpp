#include "pch.h"
#include <iostream>
#include <locale.h>
#include <string>
#include <random>
#include <time.h>

using namespace std;

void topla();
void topla(int sayi1, int sayi2);
void topla(double sayi1, double sayi2);
void topla(int s1, int s2, int s3);
int toplam(int s1, int s2);
int rastgele();
void mukemmel_sayi();
bool asal(int sayi);
void asal_sayilar(int s1, int s2);
int asal_sayi(int sira);

char ilk_harf(string kelime);
//string tan�ml� fonksiyonlarda using namespace std; tan�mlamas� fonksiyon tan�mlamas�ndan �nce gelmelidir. Ya da bunun i�in bir k�t�phane tan�mlamas� yap�labilir.
string kelimenin_tersi(string kelime);

int main()
{
	int sayi1, sayi2,toplamlar;
	string kelime, cumle;

	setlocale(LC_ALL, "turkish");

	srand(time(NULL));

	/*
	topla();
	topla(2,4);
	sayi1 = 3;
	sayi2 = 7;
	topla(sayi1, sayi2);
	topla(5.3, 4.6);
	topla(double(5), 4.6);
	topla(5.0, 4.6);
	topla(2, 3, 4);
	cout << toplam(3, 6) << endl;
	toplamlar = toplam(3,6);
	cout << toplamlar << endl;
	*/

	//Birden fazla c�mleyi klavyeden okutabilmek i�in getline fonksiyonu kullan�l�r.
	//cin >> kelime; okunan de�erin bo�lu�a kadar olan k�sm�n� de�i�kene atamay� ger�ekle�tirir. Ama getline(cin,kelime) kodu enter'a bas�ncaya kadar olan t�m karakterleri string de�i�kende tutmam�z� sa�lar.
	/*
	getline(cin, kelime);
	*/
	
	/*
	cout << ilk_harf("Beykoz") << endl;
	cout << "Kelime:";
	getline(cin, kelime);
	//cin >> kelime; //getline(cin, kelime);
	cout << "Cumle:";
	getline(cin, cumle);
	cout << cumle << endl;
	cout <<"�lk harf:" <<  ilk_harf(kelime) << endl;
	cout << "Kelimenin tersi:" << kelimenin_tersi(kelime) << endl;
	cout << "C�mlenin tersi:" << kelimenin_tersi(cumle) << endl;
	//kelimenin_tersi(kelime) d�nen de�eri bir string de�erde saklay�p o de�eri de kullanabiliriz.
	if (kelimenin_tersi(kelime) == kelime) 
		cout << kelime << " kelimesinin tersi kendisine e�it" << endl;
	else
		cout << kelime << " kelimesinin tersi kendisine e�it de�il" << endl;

	cout << "Mak:" << rastgele() << endl;
	
	mukemmel_sayi();
	*/
	cout << "2 say� giriniz..:";
	cin >> sayi1 >> sayi2;
	asal_sayilar(sayi1, sayi2);

	cout <<"4.sayi:" <<  asal_sayi(4) << endl;
	cout << "10.sayi:" << asal_sayi(10) << endl;
	system("pause");

	return 1;

	cout << "Deneme"; 
	//return ifadesinden sonraki hi�bir kod �al��maz. 
	//Bunun nedeni fonksiyonun return i�leminden sonra sona ermesidir.
}

/*
donus_deger_turu fonksiyon_adi(parametre(ler)){

fonksiyonun_icinde_yapilacak_islemler

}
*/

//Parametre: null (yok)
//Geri d�nd�rd��� de�er void (yok)
void topla() {
	cout << "void topla() fonksiyonu �al��t�." << endl;
	int sayi1 = 3;
	int sayi2 = 5;
	cout << sayi1 + sayi2 << endl;
}

//Parametre: (int sayi1, int sayi2)
//Geri d�nd�rd��� de�er void (yok)
void topla(int sayi1, int sayi2) {
	cout << "void topla(int sayi1, int sayi2) fonksiyonu �al��t�." << endl;
	cout << sayi1 + sayi2 << endl;
}

//Parametre: (double sayi1, double sayi2)
//Geri d�nd�rd��� de�er void (yok)
void topla(double sayi1, double sayi2) {
	cout << "void topla(double sayi1, double sayi2) fonksiyonu �al��t�." << endl;
	cout << sayi1 + sayi2 << endl;
}

void topla(int s1, int s2, int s3) {
	cout << "topla(int s1, int s2, int s3)fonksiyonu �al��t�." << endl;
	cout << s1 + s2 + s3 << endl;
}

//Kendisine g�nderilen 2 tamsay�n�n toplam�n� geri d�nd�ren fonksiyon:
int toplam(int s1, int s2) {
	cout << "int toplam(int s1, int s2)fonksiyonu �al��t�." << endl;
	return s1 + s2;
}

//Kendisine g�nderilen kelimenin ilk harfini geri d�nd�ren fonksiyon
//Parametre : string kelime
//Geri d�nen de�er : char
char ilk_harf(string kelime) {
	return kelime[0];
}

//Kendisine g�nderilen kelimeyi tersini geri d�nd�ren fonksiyon
//�r: kedi -> idek 
//�r: ipek -> kepi
string kelimenin_tersi(string kelime) {
	int uzunluk = kelime.length();
	string tersi="";
	for (int i = uzunluk-1; i >= 0; i--)
	{
		tersi += kelime[i]; 
		//tersi=tersi+kelime[i];
	}
	return tersi;
}
//------PROBLEM:-----//
//Rastgele �retilen 20 ile 36 aras�ndaki 6 say�dan en b�y�k de�eri geri d�nd�ren fonksiyonu yaz�n�z.

//Parametre : null (yok)
//Geri d�nd�rd��� de�er : int
//Fonksiyon ad�: rastgele

//int random=rand()%17+20; 
//Son de�er: 17+20-1=36

//min=20;

int rastgele() {
	int sayi, mak=20;
	for (int i = 1; i <= 6; i++) {
		sayi = rand() % 17 + 20;
		cout << sayi << " ";
		if (sayi > mak) //if (mak < sayi)
			mak = sayi;
	}
	cout << endl;
	return mak;
}


//------PROBLEM:-----//
//1-9000 aras�ndaki m�kemmel say�lar� ekrana yazd�ran fonksiyon
//M�kemmel say�: Kendisi hari� pozitif b�lenlerinin toplamlar� kendisine e�it olan say�d�r.
//Fonksiyon ad�: mukemmel_sayi
//Parametre: null (yok)
//Geri d�nd�rd��� de�er: void (yok)
void mukemmel_sayi() {
	int toplam;
	for (int sayi = 1; sayi <= 9000; sayi++)
	{
		toplam = 0;
		for (int bolen = 1; bolen < sayi; bolen++)
		{
			if (sayi%bolen == 0) {
				toplam += bolen;
			}
		}
		if (toplam == sayi) //Say� m�kemmel say�d�r
			cout << sayi << endl;
	}
}


//------PROBLEM:-----//
//Fonksiyonu gelen (Kullan�c�n�n girdi�i) iki de�er aras�ndaki asal say�lar� ekrana yazd�ran fonksiyon
//Asal say�, 1 ve kendisi hari� b�leni olmayan say�d�r
//Fonksiyon ad�: asal_sayilar
//Parametre: int s1, int s2
//Geri d�nd�rd��� de�er: void (yok)
void asal_sayilar(int s1, int s2) {
	for (int sayi = s1; sayi <= s2; sayi++)
	{
		if (asal(sayi))
			cout << sayi << endl;
	}
}

bool asal(int sayi) {
	bool kontrol = true; //say� asald�r
	if (sayi <= 1)
		kontrol = false;
	else
		for (int i = 2; i <= sayi/2; i++)
		//Bir say� kendisinin yar�s�ndan daha b�y�k say�lara b�l�nemez. 
		//Bu y�zden i <= sayi/2 ko�ulunu kulland�k.
		{
			if (sayi%i == 0) {
				kontrol = false; //say� asal de�ildir
				break;
			}
		}
	return kontrol;
}

//------PROBLEM:-----//
//Kullan�c�n�n girdi�i s�radaki asal say�y� geri d�nd�ren fonksiyon
//Fonksiyon ad�: asal_sayi
//Parametre: int s1
//Geri d�nd�rd��� de�er: int
int asal_sayi(int sira) {
	int sayi = 0, sayac=0;
	while(sira>=1)
	{
		sayi++;
		if (asal(sayi)) {
			sayac++;
		}
		if (sayac == sira) {
			//cout << sayi;
			break;
		}
	}
	return sayi;
}