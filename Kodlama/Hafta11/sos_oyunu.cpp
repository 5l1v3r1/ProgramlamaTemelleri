#include "pch.h"
#include <iostream>
#include <string>
//Bu �rnek Yapay Zeka ile ��z�lebilir
//Bilgisayar SOS yazmaya �al��abilir veya kullan�c�n�n yazmamas� i�in gerekli yerleri doldurabilir.
using namespace std;
char sos[3][3] = { '#','#','#','#','#','#','#','#','#' }, pc_deger;
int i, j;
bool kontrol = false;
void yazdir(){
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cout << sos[i][j];
		}
		cout << endl;
	}
}
void pc() {
	//E�er # kalmam��sa bu fonksiyon �a�r�lmamal�d�r
	char deger[2] = { 'S','O' };
	int x = rand() % 2 + 0;
	pc_deger = deger[x];
	int satir, sutun;
	do {
		satir = rand() % 3 + 0;
		sutun = rand() % 3 + 0;
	} while (sos[satir][sutun]!='#');
	sos[satir][sutun] = pc_deger;
}

void durum() {
	int sayac = 0;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			if (sos[i][j] == '#') {
				sayac++;
			}
		}
	}
	if (sayac == 0)
		kontrol = true; //oyun bitti
}
void kullanici() {
	int satir, sutun;
	char deger;
	do{
	cout << "Sat�r de�eri:";
	cin >> satir;
	cout << "S�tun de�eri:";
	cin >> sutun;
	} while (sos[satir-1][sutun-1] != '#');
	cout << "S-O :";
	cin >> deger;
	//Burada S-O do�ru girildi mi? Kontrol edilecek.
	sos[satir - 1][sutun - 1] = deger;
}

int main()
{
	
	//sos oyunu
	//Bilgisayar bo� olan alanlara rastgele s o s koyar
	//Biz de onu yenmeye �al���r�z
	
	do{
	yazdir();
		pc();
		kullanici();
	} while (kontrol == false);
	//else if () {
		//SOS yaz�ld� m�? Kontrol edilecek

	//}
	cout << "Oyun bitti";
		
	
	

}
