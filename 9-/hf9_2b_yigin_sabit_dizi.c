#include <stdio.h>
#include <stdlib.h>

#define boyut 5

int dizi[boyut];
int ust = 0;

void yazdir()
{
    int i;
    for (i = 0; i < boyut; i++)
        printf("%d ", dizi[i]);
    printf("\n");
}

void yigin_ekle(int ekle)
{
    // doluluk kontrol
    if (ust == boyut)
        printf("dizi dolu %d eklenemedi.\n", ekle);
    else
    {
        dizi[ust] = ekle;
        ust++;
    }
    yazdir();
}

void yigin_sil()
{
    // boş olup olmadığının kontrolü
    if (ust == 0)
        printf("dizi bos\n");
    else
    {
        ust--;
        dizi[ust] = 0;
    }
    yazdir();
}

int main()
{
    yigin_ekle(3);
    yigin_ekle(2);
    yigin_ekle(11);
    yigin_ekle(7);
    yigin_ekle(9);
    yigin_ekle(1);
    yigin_sil();
    yigin_sil();
    yigin_sil();
    yigin_sil();
    yigin_sil();
    yigin_sil();
    return 0;
}