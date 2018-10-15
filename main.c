#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	printf("--------------------------------------------------\n");
	printf("               SALGIN ODEVI\n");
	printf("               ONUR GOSTERIS\n"); // BAÞLIK
	printf("                 170204031\n");
	printf("--------------------------------------------------\n");
	int girilenSayi; 
	printf("Toplam asi sayisini girin : ");
	scanf("%d",&girilenSayi);
	while(girilenSayi<=0 || 11<=girilenSayi){
		printf("Girilen sayi 1<= N <=10 olmalidir tekrar girin : "); // ÖNCE GÝRÝLEN SAYÝYÝ ALDIK
		scanf("%d",&girilenSayi);
	}
	int dizisiniri;
	dizisiniri=girilenSayi-1; // C DÝLÝNDE DÝZÝLER 0 DAN BAÞLADIÐI ÝÇÝN GÝRÝLEN SAYÝYÝ 1 EKSÝLTÝYORUZ
	int hastalar[dizisiniri],asilar[dizisiniri]; // DÝZÝLERÝ SONRADAN TANIMLADIK SAYILARI ALMADAN TANIMLASAYDIK HATA VERÝRDÝ
	int sayac,yedek,gecis,i;
	int kurtulanlar=0; // DEÐÝÞKENLERÝ ATADIK
	for(sayac=0;sayac<=dizisiniri;sayac++){
		printf("Teker teker asilarin guclerini girin : "); // DÖNGÜ SAYESÝNDE TEKER TEKER AÞILARIN GÜÇLERÝNÝ GÝRÝYORUZ
		scanf("%d",&asilar[sayac]);
	}
	for(sayac=0;sayac<=dizisiniri;sayac++){
		printf("Teker teker hastalarin X degerlerini girin : "); // DÖNGÜ SAYESÝNDE TEKER TEKER HASTALARIN X DEÐERLERÝNÝ GÝRÝYORUZ
		scanf("%d",&hastalar[sayac]);
	}
	// AÞILARIN GÜÇLERÝNÝ SIRALAYALIM
	for(gecis=1;gecis<dizisiniri;gecis++){ // GECÝÞLER ÝÇÝN
		for(i=0;i<dizisiniri;i++){
			if(asilar[i]>asilar[i+1]){ // KENDÝNDEN SONRAKÝYLE KIYASLAMASI
			yedek=asilar[i];
			asilar[i]=asilar[i+1]; // YER DEÐÝÞTÝRME ÝÞLEMLERÝ
			asilar[i+1]=yedek;
			}
		}
	}
	printf("\nAsilarin X degerlerinin sirali hali : ");
	for(sayac=0;sayac<=dizisiniri;sayac++){ // YAZDIRIYORUZ
		printf(" %d ",asilar[sayac]);
	}
	// HASTALARIN GÜÇLERÝNÝ SIRALAYALIM
	for(gecis=1;gecis<dizisiniri;gecis++){ // GEÇÝÞLER ÝÇÝN
		for(i=0;i<dizisiniri;i++){
			if(hastalar[i]>hastalar[i+1]){ // KEMDÝNDEN SONRAKÝYLE KIYASLAMASI
			yedek=hastalar[i];
			hastalar[i]=hastalar[i+1]; // YER DEÐÝÞTÝRME ÝÞLEMLERÝ
			hastalar[i+1]=yedek;
			}
		}
	}
	printf("\nHastalarin X degerlerinin sirali hali : ");
	for(sayac=0;sayac<=dizisiniri;sayac++){
		printf(" %d ",hastalar[sayac]); // YAZDIRIYORUZ
		}
	for(sayac=0;sayac<=dizisiniri;sayac++){
		if(hastalar[sayac]<=asilar[sayac]){ // EÐER ASÝNÝN GÜCÜ HASTALIKTAN BÜYÜKSE YAÞAR
			kurtulanlar++; // YAÞAYANLARIN SAYÝSÝ 1 ARTAR
		}
	}
	if(kurtulanlar == girilenSayi){
		printf("\nOutput : Yes"); // HERKES YAÞARSA ÇIKTI BU OLUR 
	}
	else{
		printf("\nOutput : No"); // HERKES YAÞAMAZSA ÇIKTI BUNLAR OLUR
		printf("\nKurtulan kisi sayisi : %d",kurtulanlar);
	}
	return 0;
}
