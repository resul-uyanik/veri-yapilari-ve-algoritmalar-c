#include <stdio.h>
#include <stdlib.h>

struct eleman
{
    int veri;
    struct eleman *sonraki;
};
typedef struct eleman e;

e *bas = NULL;
e *son = NULL;
e *aktif = NULL;

int basa_eleman_ekle(int veri_ekle)
{
    e *yeni = malloc(sizeof(e));
    yeni->veri = veri_ekle;
    if (son == NULL)
        son = yeni;
    yeni->sonraki = bas;
    bas = yeni;
}

int yazdir()
{
    aktif = bas;
    printf("\nlistenin elemanlarini yazdir\n");
    // listenin sonuna kadar gider
    while (aktif != NULL)
    {
        printf("%d -> ", aktif->veri);
        aktif = aktif->sonraki;
    }
}

int ara(int aranan)
{
    aktif = bas;
    int sayac = 1;
    while (aktif != NULL)
    {
        if (aktif->veri == aranan)
            return printf("\nlistede aranan deger %d. sirada bulundu", sayac);
        aktif = aktif->sonraki;
        sayac++;
    }
    return printf("\nlistede aranan deger yok");
}

int araya_eleman_ekle(int veri_ekle, int sira)
{
    aktif = bas;
    int i;
    for (i = 1; i < sira; i++)
    {
        aktif = aktif->sonraki;
    }
    e *yeni = malloc(sizeof(e));
    yeni->veri = veri_ekle;
    yeni->sonraki = aktif->sonraki;
    aktif->sonraki = yeni;
}

int bas_elemani_sil()
{
    aktif = bas;
    bas = bas->sonraki;
    free(aktif);
}

int son_elemani_sil()
{
    aktif = bas;
    while (aktif->sonraki->sonraki != NULL)
    {
        aktif = aktif->sonraki;
    }
    free(aktif->sonraki);
    aktif->sonraki = NULL;
}

void aradan_eleman_sil(int sira)
{
    aktif = bas;
    int i;
    for (i = 1; i < sira - 1; i++)
        aktif = aktif->sonraki;
    e *silinecek_eleman = aktif->sonraki;
    aktif->sonraki = silinecek_eleman->sonraki;
    free(silinecek_eleman);
    silinecek_eleman = NULL;
}

int main()
{
    // basa eleman ekle
    basa_eleman_ekle(10);
    basa_eleman_ekle(20);
    basa_eleman_ekle(30);
    yazdir();
    int i;
    for (i = 1; i <= 10; i++)
    {
        basa_eleman_ekle(i);
    }
    yazdir();

    ara(7);

    araya_eleman_ekle(33, 2);
    yazdir();

    bas_elemani_sil();
    yazdir();

    son_elemani_sil();
    yazdir();

    aradan_eleman_sil(5);
    yazdir();

    return 0;
}