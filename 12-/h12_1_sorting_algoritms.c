#include <stdio.h>
#include <stdlib.h>

void dizi_yazdir(int dizi[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", dizi[i]);
    printf("\n");
}
// bubble sort - kabarcık sıralama
void bubble_sort(int dizi[], int n)
{
    int i, j, tmp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (dizi[j] > dizi[j + 1])
            {
                tmp = dizi[j];
                dizi[j] = dizi[j + 1];
                dizi[j + 1] = tmp;
            }
        }
    }
}

// selection sort - seçmeli sıralama
void selection_sort(int dizi[], int n)
{
    int i, j, tmp, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (dizi[j] < dizi[min])
            {
                min = j;
            }
        }
        tmp = dizi[i];
        dizi[i] = dizi[min];
        dizi[min] = tmp;
    }
}

// insertion sort - eklemeli sıralama
void insertion_sort(int dizi[], int n)
{
    int i, j, tmp;
    for (i = 1; i < n; i++)
    {
        tmp = dizi[i];
        j = i - 1;
        while (tmp < dizi[j] && j >= 0)
        {
            dizi[j + 1] = dizi[j];
            j--;
        }
        dizi[j + 1] = tmp;
    }
}

// quick sort - hızlı sıralama
int partition(int dizi[], int low, int high)
{
    int pivot = dizi[high];
    int pi = low;

    int j, tmp;
    for (j = low; j < high; j++)
    {
        if (dizi[j] < pivot)
        {
            tmp = dizi[pi];
            dizi[pi] = dizi[j];
            dizi[j] = tmp;
            pi++;
        }
    }
    tmp = dizi[pi];
    dizi[pi] = dizi[high];
    dizi[high] = tmp;
    return pi;
}

void quick_sort(int dizi[], int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(dizi, low, high);

        quick_sort(dizi, low, pivot_index - 1);
        quick_sort(dizi, pivot_index + 1, high);
    }
}

// merge sort - birleştirmeli sıralama
void merge(int dizi[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    int i, j;
    for (i = 0; i < n1; i++)
        L[i] = dizi[l + i];
    for (j = 0; j < n2; j++)
        R[j] = dizi[m + 1 + j];

    i = 0;
    j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            dizi[k] = L[i];
            i++;
        }
        else
        {
            dizi[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        dizi[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        dizi[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int dizi[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - 1) / 2;

        merge_sort(dizi, l, m);
        merge_sort(dizi, m + 1, r);

        merge(dizi, l, m, r);
    }
}

int main()
{
    int n, dizi[] = {9, 7, 2, 5, 3};
    n = sizeof(dizi) / sizeof(dizi[0]);
    dizi_yazdir(dizi, n);
    // bubble_sort(dizi, n);
    // selection_sort(dizi, n);
    // insertion_sort(dizi, n);
    quick_sort(dizi, 0, n - 1);
    //merge_sort(dizi, 0, n - 1);
    dizi_yazdir(dizi, n);
}