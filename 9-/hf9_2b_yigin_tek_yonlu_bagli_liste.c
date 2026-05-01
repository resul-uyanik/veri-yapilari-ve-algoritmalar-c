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

int yazdir()
{
    printf("\nyiginin elemanlari: \n");
    aktif = bas;
    while (aktif != NULL)
    {
        printf("%d -> ", aktif->veri);
        aktif = aktif->sonraki;
    }
    printf("\n");
}

int basa_eleman_ekle(int veri_ekle)
{
    e *yeni = malloc(sizeof(e));
    yeni->veri = veri_ekle;
    if (son == NULL)
        son = yeni;
    yeni->sonraki = bas;
    bas = yeni;
    yazdir();
}

int ilk_elemani_sil()
{
    aktif = bas;
    bas = bas->sonraki;
    if (bas == NULL)
    {
        printf("\nliste bos\n");
        son = NULL;
    }
    free(aktif);
    aktif = NULL;
    yazdir();
}

int main()
{
    basa_eleman_ekle(3);
    basa_eleman_ekle(2);
    basa_eleman_ekle(11);
    basa_eleman_ekle(7);
    basa_eleman_ekle(9);
    basa_eleman_ekle(1);
    ilk_elemani_sil();
    ilk_elemani_sil();
    ilk_elemani_sil();
    ilk_elemani_sil();
    ilk_elemani_sil();
    ilk_elemani_sil();

    ilk_elemani_sil();
    ilk_elemani_sil();
    return 0;
}