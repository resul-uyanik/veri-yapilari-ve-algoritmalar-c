#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ogrenci
{
    int ogr_no;
    char ad[20];
    int not;
};
typedef struct ogrenci ogr;

int main()
{
    ogr ogrenci1;
    struct ogrenci ogrenci2;

    ogrenci1.ogr_no = 1;
    strcpy(ogrenci1.ad, "Ali");
    ogrenci1.not = 90;

    printf("1. ogrencinin nosu: %d\n",ogrenci1.ogr_no);
    printf("1. ogrencinin adi: %s\n", ogrenci1.ad);
    printf("1. ogrencinin notu: %d\n",ogrenci1.not);

    ogrenci2.ogr_no = 2;
    strcpy(ogrenci2.ad, "Veli");
    ogrenci2.not = 100;

    printf("2. ogrencinin nosu: %d\n",ogrenci2.ogr_no);
    printf("2. ogrencinin adi: %s\n", ogrenci2.ad);
    printf("2. ogrencinin notu: %d\n",ogrenci2.not);

    //yapıya dolaylı erişim
    ogr *o3ptr;

    o3ptr->ogr_no = 3;
    strcpy(o3ptr->ad, "Hasan");
    o3ptr->not = 70;

    printf("3. ogrencinin nosu: %d\n",o3ptr->ogr_no);
    printf("3. ogrencinin adi: %s\n", o3ptr->ad);
    printf("3. ogrencinin notu: %d\n",o3ptr->not);

    return 0;
}