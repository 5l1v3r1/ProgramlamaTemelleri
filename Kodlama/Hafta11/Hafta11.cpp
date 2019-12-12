//Bu �rne�i Visual Studio 2017 C++ ile olu�turduk

#include "pch.h"
#include <iostream>
#include <locale.h>
#include <random>
#include <time.h>

//#include <bits/stdc++.h> //Visual studio'da bu k�t�phanenin eklenmesine gerek yoktur.
//https://repl.it/ �zerinden �al��t�rmak i�in ekledik.

using namespace std;
int main() {
	setlocale(LC_ALL, "turkish");
	srand(time(NULL));
	int matris[2][3];
	//matris[satir][sutun];
	//Matrisin i�ine 1 ile 6 aras�ndaki say�lar� atayal�m
	matris[0][0] = 1;
	matris[0][1] = 2;
	matris[0][2] = 3;
	cout << matris[0][0] << endl;
	cout << matris[0][1] << endl;
	cout << matris[0][2] << endl;
	cout << matris[1][0] << endl;
	cout << matris[1][2] << endl;
	int sayac = 1, satir, sutun;
	//int matris[2][3];
	for (satir = 0; satir < 2; satir++) {
		for (sutun = 0; sutun < 3; sutun++) {
			matris[satir][sutun] = sayac;
			sayac = sayac + 1;
			//matris[satir][sutun]=sayac++;
			cout << matris[satir][sutun];
		}
	}
	cout << endl;
	//3*2 bir matrise rastgele 1-20 aras�nda de�erler atay�p ekrana yazd�ral�m
	int matris2[3][2];
	//int satir,sutun;
	for (satir = 0; satir < 3; satir++) {
		for (sutun = 0; sutun < 2; sutun++) {
			matris2[satir][sutun] = rand() % 10 + 1;
			cout << matris2[satir][sutun] << "\t";
		}
		cout << endl;
	}

	//Bu matristeki en b�y�k de�eri bulup ekrana yazd�ral�m
	int mak = 1;
	//mak=INT_MIN;
	//cout << mak << endl;
	for (satir = 0; satir < 3; satir++) {
		for (sutun = 0; sutun < 2; sutun++) {
			if (matris2[satir][sutun] > mak)
				mak = matris2[satir][sutun];
		}
	}
	cout << "Mak:" << mak << endl;
	int mak2 = 1; //mak2=INT_MIN;
	//2.en b�y�k de�eri bulal�m.
	for (satir = 0; satir < 3; satir++) {
		for (sutun = 0; sutun < 2; sutun++) {
			if (matris2[satir][sutun] >= mak2 && matris2[satir][sutun] != mak)
				mak2 = matris2[satir][sutun];
		}
	}
	cout << "2.Mak:" << mak2 << endl;

	//Ayn� d�ng� i�erisinde mak ve mak2 de�erlerini bulal�m
	mak = 1; mak2 = 1;
	for (satir = 0; satir < 3; satir++) {
		for (sutun = 0; sutun < 2; sutun++) {
			if (mak < matris2[satir][sutun])
			{
				mak2 = mak;
				mak = matris2[satir][sutun];
			}
			else if (mak2 < matris2[satir][sutun] && matris2[satir][sutun] != mak)
				mak2 = matris2[satir][sutun];
		}
	}
	cout << "Mak:" << mak << endl;
	cout << "2.Mak:" << mak2 << endl;


	//Matrisin en b�y�k eleman�n�n bulundu�u s�tunda yer alan en k���k eleman� bulal�m
	//matris2[3][2]
	mak = 1;
	int maksutun;
	for (satir = 0; satir < 3; satir++) {
		for (sutun = 0; sutun < 2; sutun++) {
			if (mak < matris2[satir][sutun]) {
				mak = matris2[satir][sutun];
				maksutun = sutun;
			}
		}
	}
	cout << "Mak:" << mak << endl;
	int min = 20;
	for (satir = 0; satir < 3; satir++) {
		if (min > matris2[satir][maksutun])
			min = matris2[satir][maksutun];
	}
	cout << "Mak de�erin oldu�u s�tun:" << maksutun + 1 << endl;
	cout << "Mak de�erin oldu�u s�tundaki min de�eri:" << min << endl;

	//4*4'l�k i�erisinde -20 ile 50 aras�nda rastgele de�er tutan matriste yer alan sat�rlardaki ve s�tunlardaki de�erlerden en b�y�k ve en k���k de�erleri ekrana yazd�ral�m
	int rastgele[4][4], i, j;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			rastgele[i][j] = rand() % 71 - 20;
			//Son de�er 71+(-20)-1=50
			cout << rastgele[i][j] << "\t";
		}
		cout << endl;
	}
	//De�erlerimiz -20 ile 50 aras�nda oldu�u i�in a�a��daki atamalar� yap�yoruz. Min de�erine alabilece�i maksimum de�eri, mak de�erine alabilece�i minimum de�eri at�yoruz
	int min_satir[4] = { 50,50,50,50 }, mak_satir[4] = { -20,-20,-20,-20 }, min_sutun[4] = { 50,50,50,50 }, mak_sutun[4] = { -20,-20,-20,-20 };
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (rastgele[i][j] < min_satir[i])
				min_satir[i] = rastgele[i][j];

			if (rastgele[i][j] > mak_satir[i])
				mak_satir[i] = rastgele[i][j];

			if (rastgele[j][i] < min_sutun[i])
				min_sutun[i] = rastgele[j][i];

			if (rastgele[j][i] > mak_sutun[i])
				mak_sutun[i] = rastgele[j][i];
		}
	}
	for (i = 0; i < 4; i++)
	{
		cout << i + 1 << ".sat�rdaki mak:" << mak_satir[i] << endl;
		cout << i + 1 << ".sat�rdaki min:" << min_satir[i] << endl;
		cout << i + 1 << ".s�tundaki mak:" << mak_sutun[i] << endl;
		cout << i + 1 << ".s�tundaki min:" << min_sutun[i] << endl;
	}

	char harfler[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','r','q','s','t','u','v','x','w','y','z' };
	//Random 25 kelime 6 harfli 2 boyutlu dizide tutulacak
	char kelime[25][6];
	int random;
	for (i = 0; i < 25; i++ ) {
		for (j = 0; j < 6; j++) {
			random = rand() % 26 + 0; //0 ile 25 aras�nda de�er �retir
			kelime[i][j] = harfler[random];
			cout << kelime[i][j];
		}
		cout << endl;
	}
	cout << "-------------------------------" << endl;
	char sesli[5] = { 'a','e','i','o','u' };
	char sessiz[21] = {'b','c','d','f','g','h','j','k','l','m','n','p','r','q','s','t','v','x','w','y','z' };
	for (i = 0; i < 25; i++) {
		for (j = 0; j < 6; j++) {
			if (j % 2 == 0) {
				random = rand() % 21 + 0; //0 ile 20 aras�nda de�er �retir
				kelime[i][j] = sessiz[random];
			}
			else {
				random = rand() % 5 + 0; //0 ile 4 aras�nda de�er �retir
				kelime[i][j] = sesli[random];
			}
			cout << kelime[i][j];
		}
		cout << endl;
	}

	system("pause");
}