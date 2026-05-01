#include <stdio.h>
#include <stdlib.h>

struct eleman
{
    int veri;
    struct eleman *sonraki;
    struct eleman *onceki;
};
typedef struct eleman e;

e *bas = NULL;
e *son = NULL;
e *aktif = NULL;

void basa_ekle(int veri_ekle)
{
    e *yeni = malloc(sizeof(e));
    yeni->veri = veri_ekle;
    yeni->sonraki = NULL;
    yeni->onceki = NULL;

    if (son == NULL)
        son = yeni;
    else
        bas->onceki = yeni;
    yeni->sonraki = bas;
    bas = yeni;
}

void sona_ekle(int veri_ekle)
{
    e *yeni = malloc(sizeof(e));
    yeni->veri = veri_ekle;
    yeni->sonraki = NULL;
    yeni->onceki = NULL;

    if (bas == NULL)
        bas = yeni;
    else
        son->sonraki = yeni;
    yeni->onceki = son;
    son = yeni;
}

void araya_ekle(int veri_ekle, int sira)
{
    e *yeni = malloc(sizeof(e));
    yeni->veri = veri_ekle;
    yeni->sonraki = NULL;
    yeni->onceki = NULL;

    int i;
    aktif = bas;
    for (i = 1; i < sira; i++)
        aktif = aktif->sonraki;
    yeni->sonraki = aktif->sonraki;
    aktif->sonraki = yeni;
    aktif->sonraki->onceki = yeni;
    yeni->onceki = aktif;
}

void ilk_elemani_sil()
{
    aktif = bas;
    bas = bas->sonraki;
    if (bas == NULL)
        son = NULL;
    else
        bas->onceki = NULL;
    free(aktif);
    aktif = NULL;
}

void son_elemani_sil()
{
    aktif = son;
    son = son->onceki;
    if (son == NULL)
        bas = NULL;
    else
        son->sonraki = NULL;
    free(aktif);
    aktif = NULL;
}

void aradan_eleman_sil(int sira)
{
    aktif = bas;
    int i;
    for (i = 1; i < sira; i++)
        aktif = aktif->sonraki;
    aktif->sonraki->onceki = aktif->onceki;
    aktif->onceki->sonraki = aktif->sonraki;
    free(aktif);
    aktif = NULL;
}

void yazdir()
{
    aktif = bas;
    printf("\nlistenin elemanlarini yazdir\n");
    while (aktif != NULL)
    {
        printf("<- %d -> ", aktif->veri);
        aktif = aktif->sonraki;
    }
}

int main()
{
    sona_ekle(68);
    yazdir();
    basa_ekle(20);
    yazdir();
    basa_ekle(18);
    yazdir();
    basa_ekle(9);
    yazdir();
    sona_ekle(24);
    yazdir();
    araya_ekle(19, 2);
    yazdir();
    ilk_elemani_sil();
    yazdir();
    son_elemani_sil();
    yazdir();
    aradan_eleman_sil(2);
    yazdir();
    return 0;
}