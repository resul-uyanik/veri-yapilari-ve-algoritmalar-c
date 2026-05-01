#include <stdio.h>
#include <stdlib.h>

#define boyut 5

int hash_dizi[boyut];

int hash(int key)
{
    return key % boyut;
}

void ekle(int key)
{
    int index = hash(key);
    int bas_index = index;
    while (1)
    {
        if (hash_dizi[index] == 0)
        {
            hash_dizi[index] = key;
            return;
        }
        index = (index + 1) % boyut;
        // dizi bos yer yoksa
        if (bas_index == index)
        {
            printf("dizide yer yok\n %d eklenemedi\n", key);
            return;
        }
    }
}

int main()
{
    int i;
    for (i = 0; i < boyut; i++)
        hash_dizi[i] = 0;
    ekle(13);
    ekle(24);
    ekle(4);
    ekle(7);
    ekle(12);
    ekle(33);
    for (i = 0; i < boyut; i++)
        printf("%d. sayi %d\n", i, hash_dizi[i]);
    return 0;
}