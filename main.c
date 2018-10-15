#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	printf("--------------------------------------------------\n");
	printf("               SALGIN ODEVI\n");
	printf("               ONUR GOSTERIS\n"); // BA�LIK
	printf("                 170204031\n");
	printf("--------------------------------------------------\n");
	int girilenSayi; 
	printf("Toplam asi sayisini girin : ");
	scanf("%d",&girilenSayi);
	while(girilenSayi<=0 || 11<=girilenSayi){
		printf("Girilen sayi 1<= N <=10 olmalidir tekrar girin : "); // �NCE G�R�LEN SAY�Y� ALDIK
		scanf("%d",&girilenSayi);
	}
	int dizisiniri;
	dizisiniri=girilenSayi-1; // C D�L�NDE D�Z�LER 0 DAN BA�LADI�I ���N G�R�LEN SAY�Y� 1 EKS�LT�YORUZ
	int hastalar[dizisiniri],asilar[dizisiniri]; // D�Z�LER� SONRADAN TANIMLADIK SAYILARI ALMADAN TANIMLASAYDIK HATA VER�RD�
	int sayac,yedek,gecis,i;
	int kurtulanlar=0; // DE���KENLER� ATADIK
	for(sayac=0;sayac<=dizisiniri;sayac++){
		printf("Teker teker asilarin guclerini girin : "); // D�NG� SAYES�NDE TEKER TEKER A�ILARIN G��LER�N� G�R�YORUZ
		scanf("%d",&asilar[sayac]);
	}
	for(sayac=0;sayac<=dizisiniri;sayac++){
		printf("Teker teker hastalarin X degerlerini girin : "); // D�NG� SAYES�NDE TEKER TEKER HASTALARIN X DE�ERLER�N� G�R�YORUZ
		scanf("%d",&hastalar[sayac]);
	}
	// A�ILARIN G��LER�N� SIRALAYALIM
	for(gecis=1;gecis<dizisiniri;gecis++){ // GEC��LER ���N
		for(i=0;i<dizisiniri;i++){
			if(asilar[i]>asilar[i+1]){ // KEND�NDEN SONRAK�YLE KIYASLAMASI
			yedek=asilar[i];
			asilar[i]=asilar[i+1]; // YER DE���T�RME ��LEMLER�
			asilar[i+1]=yedek;
			}
		}
	}
	printf("\nAsilarin X degerlerinin sirali hali : ");
	for(sayac=0;sayac<=dizisiniri;sayac++){ // YAZDIRIYORUZ
		printf(" %d ",asilar[sayac]);
	}
	// HASTALARIN G��LER�N� SIRALAYALIM
	for(gecis=1;gecis<dizisiniri;gecis++){ // GE���LER ���N
		for(i=0;i<dizisiniri;i++){
			if(hastalar[i]>hastalar[i+1]){ // KEMD�NDEN SONRAK�YLE KIYASLAMASI
			yedek=hastalar[i];
			hastalar[i]=hastalar[i+1]; // YER DE���T�RME ��LEMLER�
			hastalar[i+1]=yedek;
			}
		}
	}
	printf("\nHastalarin X degerlerinin sirali hali : ");
	for(sayac=0;sayac<=dizisiniri;sayac++){
		printf(" %d ",hastalar[sayac]); // YAZDIRIYORUZ
		}
	for(sayac=0;sayac<=dizisiniri;sayac++){
		if(hastalar[sayac]<=asilar[sayac]){ // E�ER AS�N�N G�C� HASTALIKTAN B�Y�KSE YA�AR
			kurtulanlar++; // YA�AYANLARIN SAY�S� 1 ARTAR
		}
	}
	if(kurtulanlar == girilenSayi){
		printf("\nOutput : Yes"); // HERKES YA�ARSA �IKTI BU OLUR 
	}
	else{
		printf("\nOutput : No"); // HERKES YA�AMAZSA �IKTI BUNLAR OLUR
		printf("\nKurtulan kisi sayisi : %d",kurtulanlar);
	}
	return 0;
}
