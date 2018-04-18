/* @Author
 * Muhammed YILMAZ
 * yilmazmu15@gmail.com
 * 2017 Spring
 */

#include <iostream>
#include <stdlib.h>
//#include <cstdlib.h>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include "diziislemleri.h"

using namespace std;
void Dizi::ekle(Tel_Kayit *ykptr){
	strcpy(k[kayitsayisi].ad, ykptr->ad);
	strcpy(k[kayitsayisi].telno, ykptr->telno);
	kayitsayisi++;
}

void Dizi::olustur(){
	kayitsayisi = 0;
}

int Dizi::ara(char aranacak[]){
	int sayac = 0;
	bool tumu = false;
	int bulunan, flag = 0;
	if (strcmp(aranacak, "*") == 0) {
		tumu = true;
	}
	for (int i = 0; i<kayitsayisi || tumu; i++) {
		if (!tumu && strncmp(k[i].ad, aranacak, strlen(aranacak)) != 0) continue;
		cout << i + 1 << ". " << k[i].ad << endl;
		bulunan = i;
		flag = 1;
		
	}
	return flag;
}

void Dizi::guncelle(int kayitno, Tel_Kayit *ykptr){
	strcpy(k[kayitno - 1].ad, ykptr->ad);
	strcpy(k[kayitno - 1].telno, ykptr->telno);
}

void Dizi::sil(int kayitno){
	Tel_Kayit temp;
	strcpy(temp.ad, "");
	strcpy(temp.telno, "");
	int indisno;
	indisno = kayitno - 1;
	k[indisno] = temp;
}

void Dizi::listele(){
	for (int i = 0; i<kayitsayisi; i++)
		cout << i + 1 << ". " << k[i].ad << " \t" << k[i].telno << endl;
}

bool Dizi::dosyaoku()
{
	FILE *dg_oku;

	dg_oku = fopen("kayitlar.txt", "r");
	if (dg_oku == NULL){
		return EXIT_FAILURE;
	}

	for (; !feof(dg_oku); kayitsayisi++){
		fscanf(dg_oku, "%s %s", k[kayitsayisi].ad, k[kayitsayisi].telno);
	}
	
	return EXIT_SUCCESS;
}

bool Dizi::dosyayaz()
{
	FILE *dg_yaz;
	dg_yaz = fopen("kayitlar.txt", "w");
	if (dg_yaz == NULL) {
		//dg_yaz = fopen("kayitlar.txt", "w");
		if (dg_yaz == NULL){
			printf("Hata01");
			return EXIT_FAILURE;
		}
	}

	for (int i = 0; i < kayitsayisi; i++) {
		if (k[i].ad[0] == ' ')		{
			printf("asasas");
			continue;
		}
		fprintf(dg_yaz, "\n%s\t%s", k[i].ad, k[i].telno);
	}
	return EXIT_SUCCESS;
}

bool Dizi::sirala()
{
	char temp[30], temptel[15];
	for (int i = 0; i < kayitsayisi-1; i++)	{
		for (int j = 0; j < kayitsayisi-1; j++){
			if (k[j].ad[0] == ' ')			{
				continue;
			}
			if (strcmp(k[j].ad, k[j + 1].ad)>0){
				strcpy(temp, " ");
				strcpy(temptel, " ");
				strcpy(temp, k[j + 1].ad);
				strcpy(temptel, k[j + 1].telno);
				strcpy(k[j + 1].ad, k[j].ad);
				strcpy(k[j + 1].telno, k[j].telno);
				strcpy(k[j].ad, temp);
				strcpy(k[j].telno, temptel);
			}
		}
	}
	return EXIT_SUCCESS;
}