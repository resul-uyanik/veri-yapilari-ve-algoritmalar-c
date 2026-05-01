#include <stdio.h>
#include <stdlib.h>

#define boyut 10

int dizi[boyut];
int bas = 0, kuyruk_sayisi = 0;

void yazdir()
{
    int i;
    for (i = 0; i < boyut; i++)
        printf("%d ", dizi[i]);
    printf("\n");
}

void kuyruk_ekle(int ekle)
{
    if (kuyruk_sayisi == boyut)
        printf("dizi dolu %d eklenemedi.\n", ekle);
    else
    {

        dizi[(bas + kuyruk_sayisi) % boyut] = ekle;
        kuyruk_sayisi++;
    }
    yazdir();
}

void kuyruk_sil()
{
    if (kuyruk_sayisi == 0)
        printf("kuyruk bos\n");
    else
    {
        dizi[bas] = 0;
        // bas++;
        bas = (bas + 1) % boyut;
        kuyruk_sayisi--;
    }
    yazdir();
}

int main()
{
    kuyruk_ekle(12);
    kuyruk_ekle(20);
    kuyruk_ekle(3);
    kuyruk_ekle(55);
    kuyruk_ekle(4);

    kuyruk_ekle(5);
    kuyruk_sil();
    kuyruk_sil();
    kuyruk_ekle(87);
    kuyruk_sil();
    kuyruk_ekle(99);
    kuyruk_sil();
    kuyruk_sil();

    kuyruk_sil();

    return 0;
}