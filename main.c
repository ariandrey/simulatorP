#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int saglik = 100;
    int enerji = 100;
    int yemek = 0;
    int siginak = 0;
    char komut;

    srand(time(NULL));

    printf("Simulator Baslik\n");

    do {
        printf("\n--- Durum ---\n");
        printf("Saglik: %d | Enerji: %d | Yemek: %d | Siginak: %s\n",
                saglik, enerji, yemek, siginak ? "Var" : "Yok");
        printf("Komut gir (A(AV),S(SIGINAK),E(ENVANTER),R(DINLEN),F(BOLGE KONTROL),P(SIFRE),X(CIKIS)): ");
        scanf(" %c", &komut);

        switch (komut) {

            // AVLAN
            case 'A': {
                printf("Avlaniyorsun...\n");
                enerji -= 15;

                int sans = rand() % 100;

                if (sans < 40) { 
                    printf("Hayvan yakaladin! Yemek +1\n");
                    yemek++;
                } 
                else if (sans >= 40 && sans < 60) { 
                    printf("Hayvan saldirdi! 10 saglik gitti\n");
                    saglik -= 10;
                } 
                else {
                    printf("Bos dondun.\n");
                }

                if (enerji < 0) enerji = 0;
                if (saglik < 0) saglik = 0;

                break;
            }

            // SIÐINAK ARAMA
            case 'S': {
                printf("Siginak araniyor...\n");

                int hava = rand() % 2; 
                int cevre = rand() % 2;

                if (hava == 1 && cevre == 1) {
                    printf("Siginak bulundu!\n");
                    siginak = 1;
                } else {
                    printf("Bulunamadi.\n");
                }

                break;
            }

            // ENVANTER
            case 'E':
                printf("Envanter:\n");
                printf("Yemek: %d\n", yemek);
                printf("Siginak: %s\n", siginak ? "Var" : "Yok");
                break;

            // DÝNLEN
            case 'R': {
                printf("Dinleniyorsun...\n");
                enerji += 20;

                if (enerji > 100) enerji = 100;

                if (siginak == 1) {
                    printf("Siginakta oldugun icin sagligin +10 artti!\n");
                    saglik += 10;
                    if (saglik > 100) saglik = 100;
                }

                break;
            }

            // TEHLÝKE DALGASI
            case 'F': {
                printf("Tehlike dalgasi geliyor!\n");

                for (int i = 1; i <= 5; i++) {
                    int risk = rand() % 3;

                    if (risk == 0) {
                        saglik -= 5;
                        printf("%d. dalga: Hasar aldin! -5 saglik\n", i);
                    } 
                    else if (risk == 1) {
                        enerji -= 10;
                        printf("%d. dalga: Yoruldun! -10 enerji\n", i);
                    } 
                    else {
                        printf("%d. dalga: Sansliisin, kacmayi basardin.\n", i);
                    }

                    if (saglik <= 0) {
                        printf("Öldün!\n");
                        return 0;
                    }
                }

                break;
            }

            // ÞÝFRELÝ GEÇÝÞ
            case 'P': {
                printf("Gizli kapý! Dogru karakteri girmen lazim.\n");

                char giris;
                char sifre = 'K';

                do {
                    printf("Sifreyi gir: ");
                    scanf(" %c", &giris);
                } while (giris != sifre);

                printf("Kapidan gectin!\n");
                break;
            }

            // ÇIKIÞ
            case 'X':
                printf("Cikiliyor...\n");
                break;

            default:
                printf("Bilinmeyen komut.\n");
        }

    } while (komut != 'X');

    return 0;
}

