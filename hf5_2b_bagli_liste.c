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

int sona_eleman_ekle(int veri)
{
    e *yeni = malloc(sizeof(e));
    yeni->veri = veri;
    yeni->sonraki = NULL;

    if(bas==NULL)
    {
        bas = yeni;
    }
    else
    {
        son->sonraki = yeni;
    }
    son = yeni;
};

int main()
{
    sona_eleman_ekle(15);
    sona_eleman_ekle(30);

    return 0;
}