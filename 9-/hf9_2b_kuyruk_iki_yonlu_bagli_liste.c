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

void yazdir()
{
    aktif = bas;
    printf("\n---kuyruk elemanlari---\n");
    while (aktif != NULL)
    {
        printf("<- %d -> ", aktif->veri);
        aktif = aktif->sonraki;
    }
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
    yazdir();
}

void ilk_elemani_sil()
{
    bas = bas->sonraki;
    if (bas == NULL)
    {
        printf("kuyruk bos");
        son = NULL;
    }
    else
        bas->onceki = NULL;
    yazdir();
}

int main()
{
    sona_ekle(1);
    sona_ekle(2);
    sona_ekle(3);
    sona_ekle(4);
    sona_ekle(5);
    ilk_elemani_sil();
    ilk_elemani_sil();
    ilk_elemani_sil();
    ilk_elemani_sil();
    ilk_elemani_sil();

    ilk_elemani_sil();
    ilk_elemani_sil();

    return 0;
}