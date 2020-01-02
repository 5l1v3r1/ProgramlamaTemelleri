#include "pch.h"
#include <iostream>
#include <locale.h>
#include <random>
#include <time.h>
#include <string>

using namespace std;

int kare(int sayi1, int sayi2);
int kare2(int sayi1, int sayi2);
void kare_yazdir();
int faktoriyel(int sayi);
void faktoriyel_yazdir(int sayi);
void rastgele();
void rastgele2();
void rastgele3();
int rastgele_toplam(int miktar, int baslangic, int bitis);
void maks();
void farklar();
int hesap_giris();
bool hesap_giris2();

int main()
{
	setlocale(LC_ALL, "turkish");
	srand(time(NULL)); //Program her �al��t�r�ld���nda Random ile �retilen de�erlerin farkl� de�erler olmas�n� sa�lar. 
	//Ama bu say�n�n farkl�l�klar�n� ifade etmez. Yani 5 �retildiyse tekrar �retilebilir.
	
	cout << kare(1, 2) << endl;
	cout << kare(3, 2) << endl;
	cout << kare(3, 3) << endl;
	cout << kare2(1, 2) << endl;
	cout << kare2(3, 2) << endl;
	cout << kare2(3, 3) << endl;

	kare_yazdir();

	//��kt�: �r:5 girilirse; 5!=120
	int sayi = 5;
	cout << "faktoriyel() fonksiyonu �al���yor...\n";
	cout << sayi << "!=" << faktoriyel(sayi) << endl;
	sayi = 10;
	cout << sayi << "!=" << faktoriyel(sayi) << endl;
	sayi = 0;
	cout << sayi << "!=" << faktoriyel(sayi) << endl;
	sayi = -10;
	cout << faktoriyel(sayi) << endl;

	cout << "faktoriyel_yazdir() fonksiyonu �al���yor...\n";
	faktoriyel_yazdir(5);
	faktoriyel_yazdir(-2);
	faktoriyel_yazdir(0);


	rastgele();

	rastgele2();

	rastgele3();

	cout << "Toplam:" << rastgele_toplam(5, 20, 30) << endl;
	cout << "Toplam:" << rastgele_toplam(10, -50, -20) << endl;
	cout << "Toplam:" << rastgele_toplam(4, 20 , 23) << endl;
	maks();
	farklar();
	cout << "admin - nimda" << endl;
	cout <<"Hatal� giri� say�s�:" << hesap_giris() << endl;

	cout << "admin - nimda" << endl;
	if (hesap_giris2())
		cout << "Giri� ba�ar�l�" << endl;
	else
		cout << "Giri� ba�ar�s�z" << endl;
	system("pause");
	return 0;
}
//�rnek-1:
//Kendisine g�nderilen iki tamsay� de�erinden b�y�k olan�n karesini, 
//say�lar e�itse say�lardan herhangi birini geri d�nd�ren fonksiyonu yaz�n�z.
//Parametre: int sayi1, int sayi2
//1.y�ntem:
int kare(int sayi1,int sayi2) {
	if (sayi1 > sayi2)
		return sayi1 * sayi1;
	else if (sayi2 > sayi1)
		return sayi2 * sayi2;
	else
		return sayi1; //return sayi2;
}
//2.Y�ntem:
int kare2(int sayi1, int sayi2) {
	int sonuc;
	if (sayi1 > sayi2)
		sonuc = sayi1 * sayi1;
	else if (sayi2 > sayi1)
		sonuc = sayi2 * sayi2;
	else
		sonuc = sayi1; //sonuc=sayi2;
	return sonuc;
}

//�rnek-2:
//Girilen iki tamsay� de�erini kare fonksiyonuna g�nderip fonksiyondan gelen de�eri ekrana yazd�ran fonksiyonu yaz�n�z. 
//Parametre : yok (null)
//G�nderdi�i de�er: yok (void)
void kare_yazdir() {
	//fonksiyonun i�erisinde return yoksa fonksiyon void olarak tan�mlan�r.
	int s1, s2, sonuc;
	cout << "2 sayi giriniz:";
	cin >> s1 >> s2;

	sonuc = kare(s1, s2);
	cout << sonuc << endl;
	//cout << kare(s1, s2) << endl;
	
}


//�rnek-3:
//Kendisine g�nderilen tamsay� de�erinin fakt�riyelini geri d�nd�ren fonksiyonu yaz�n�z. 
//E�er kendisine g�nderilen say� negatif ise 0 de�erini d�nd�relim.
//Not: 0!=1
//5!=1*2*3*4*5 5!=5*4*3*2*1
//Paremetre: int sayi
//Geri d�nen de�er: int
int faktoriyel(int sayi) {
	int sonuc = 1; //�arpmada 1 etkisiz eleman, 0 yutan eleman. Bu y�zden sonuc de�erine 1 verdik
	for (int i = 1; i <= sayi; i++)
	{
		sonuc *= i; //sonuc = sonuc * i;
	}
	if (sayi < 0)
		sonuc = 0;
	return sonuc;
	//if (sayi < 0)
	//	return 0;
	//else
	//	return sonuc;
}


//�rnek-4:
//Kendisine g�nderilen say�y� fakt�riyel fonksiyonuna g�nderip,
//fakt�riyel fonksiyonundan gelen de�er 0 ise "... say�s�n�n fakt�riyeli yoktur.", 
//0 de�ilse sayi!=sonuc �r/5!=120 ��kt�s�n� versin
void faktoriyel_yazdir(int sayi) {
	int sonuc = faktoriyel(sayi);
	if (sonuc == 0)
		cout << sayi << " say�s�n�n fakt�riyeli yoktur.\n";
	else
		cout << sayi << "!=" << sonuc << endl;
}



//�rnek-5:
//Rastgele �retilen 1-100 aras�nda 5 say�n�n toplam�n� ekrana yazd�ran fonksiyon
//Parametre (Bu fonksiyona g�nderilen de�er) : YOK (NULL)
//Geri d�nd�rd��� de�er (Return de�eri) : YOK (void)
void rastgele() {
	int sayi, toplam=0;
	for (int i = 1; i <= 5; i++) {
		sayi = rand() % 100 + 1;
		cout << sayi << endl;
		//�r: 20 ile 53 aras�nda de�er �retin deseydim;
		//sayi = rand() % 34 + 20;
		//�r: -20 ile 53 aras�ndaki de�er �retin deseydim;
		//sayi = rand() % 74 - 20;
		toplam += sayi; //toplam = toplam + sayi;
	}
	cout << "Toplam:" << toplam << endl;
}


//�rnek-6:
//Rastgele �retilen 1-100 aras�ndaki 20 say�dan tek olanlar� ve �ift olanlar� ayr� ayr� ve alt alta ekrana yazd�ran fonksiyon
//Not: De�erler bir dizide tutulmak zorundad�r
//Parametre (Bu fonksiyona g�nderilen de�er) : YOK (NULL)
//Geri d�nd�rd��� de�er (Return de�eri) : YOK (void)
void rastgele2() {
	int sayilar[20], i;
	for (i = 0; i < 20; i++) {
		sayilar[i] = rand() % 100 + 1;
	}
	cout << "Tek Say�lar\n";
	for (i = 0; i < 20; i++){
		if (sayilar[i] % 2 == 1)
			cout << sayilar[i] << endl;
	}
	cout << "�ift Say�lar\n";
	for (i = 0; i < 20; i++) {
		if (sayilar[i] % 2 == 0)
			cout << sayilar[i] << endl;
	}
}

//�rnek-7:
//Rastgele �retilen  1-100 aras�ndaki 20 say�dan tek olanlar� ve �ift olanlar� ayr� ayr� ve alt alta ekrana yazd�ran,
//tek ve �ift say�lar�n toplamlar�n� ekrana yazd�ran fonksiyon
//Not: De�erler bir dizide tutulmak zorundad�r
//Parametre (Bu fonksiyona g�nderilen de�er) : YOK (NULL)
//Geri d�nd�rd��� de�er (Return de�eri) : YOK (void)
void rastgele3() {
	int sayilar[20], i, tektoplam=0, cifttoplam=0;
	for (i = 0; i < 20; i++) {
		sayilar[i] = rand() % 100 + 1;
	}
	cout << "Tek Say�lar\n";
	for (i = 0; i < 20; i++) {
		if (sayilar[i] % 2 == 1) {
			cout << sayilar[i] << endl;
			tektoplam += sayilar[i];
		}
	}
	cout << "Tek toplam:" << tektoplam << endl;
	cout << "�ift Say�lar\n";
	for (i = 0; i < 20; i++) {
		if (sayilar[i] % 2 == 0) {
			cout << sayilar[i] << endl;
			cifttoplam += sayilar[i];
		}
	}
	cout << "�ift toplam:" << cifttoplam << endl;
}


//�rnek-8:
//Fonksiyona gelen say� kadar, fonksiyona gelen say� aral���nda de�er �reten ve bu say�lar� ekrana yazd�r�p, say�lar�n toplam�n� geri d�nd�ren fonksiyon
//Parametre (Bu fonksiyona g�nderilen de�er) : int miktar, int baslangic, int bitis
//Geri d�nd�rd��� de�er (Return de�eri) : int (toplam)
int rastgele_toplam(int miktar, int baslangic, int bitis) {
	cout << miktar << " tane say� �retiliyor...\n";
	int sayi, toplam = 0;
	for (int i = 1; i <= miktar; i++){
		sayi = rand() % (bitis-baslangic+1) + baslangic;
		cout << i << ".sayi:" << sayi << endl;
		toplam += sayi;
	}
	return toplam;
}

//�rnek-9:Kullan�c� 0 say�s�n� girene kadar say� girmesini sa�lay�p, bu say�lar�n en b�y���n� (s�f�r say�s�n� dahil etmeden b�y�k say� bulunmal�d�r) ekrana yazd�ran fonksiyon
void maks() {
	int sayi, mak=INT_MIN;
	do
	{
		cout << "Say�:";
		cin >> sayi;
		if (mak < sayi && sayi!=0) {
			//s�f�r� dahil etmememizin sebebi t�m say�lar�n negatif girilmesi durumu i�indir
			mak = sayi;
		}
	} while (sayi!=0);
	cout << "Maksimum de�er:" << mak << endl;
}

//�rnek-10:Kullan�c� 0 say�s�n� girene kadar say� girmesini sa�lay�p, bu say�lar�n farklar�n� ekrana yazd�ran fonksiyon
//�r: 3 4 girdi�inde ��kt�:-1, 6 girdi�inde ��kt�:-2, 0 girdi�inde ��kt�:6 program sonlan�r.
void farklar() {
	int ilksayi, sayi;
	cout << "Say�:";
	cin >> ilksayi;
	do
	{
		cout << "Say�:";
		cin >> sayi;
		cout <<"Fark:" << ilksayi-sayi << endl;
		ilksayi = sayi;
	} while (sayi != 0);
}

//�rnek-11:Kullan�c� ad� ve parola giri�i do�ru olana kadar kontrol edip, kullan�c� ad� ve parola bilgisinin ka� kere yanl�� girildi�ini geri d�nd�ren fonksiyon
int hesap_giris() {
	string k_adi, parola;
	int miktar = 0;
	do
	{
		cout << "Kullan�c� ad�:";
		cin >> k_adi;
		cout << "Parola:";
		cin >> parola;
		if (k_adi == "admin" && parola == "nimda") {
			//yaz�l�m g�venli�i s�z konusu de�il. 
			//Kullan�c� ad� ve �ifre kontrol esnas�nda kodda olmamal�
			cout << "Giri� ba�ar�l�\n";
			break;
		}
		else
			miktar++;
	} while (true);
	return miktar;
}

//�rnek-12:Kullan�c�dan kullan�c� ad� ve parola giri�i al�p  kontrol edelim, 3 yanl�� yapma hakk� olsun. Giri�in ba�ar�l� bir �ekilde olup olmad���n� (bool de�er) d�nd�rs�n ve ka� hakk� kald���n� ekrana yazd�rs�n
bool hesap_giris2() {
	string k_adi, parola;
	int hak = 3;
	bool durum = false;
	do
	{
		cout << "Kullan�c� ad�:";
		cin >> k_adi;
		cout << "Parola:";
		cin >> parola;
		if (k_adi == "admin" && parola == "nimda") {
			//yaz�l�m g�venli�i s�z konusu de�il. 
			//Kullan�c� ad� ve �ifre kontrol esnas�nda kodda olmamal�
			durum = true;
			break;
		}
		else {
			hak--;
			cout << "Kalan hak:" << hak << endl;
		}
			
	} while (hak!=0);
	return durum;
}

