#include <stdio.h>

int arr[]={5, 8, 19, 4, 3, 8}, i, data_new, size;
int null;

int main()
{
    printf("Data Awal");
    printf("\n");
    size = sizeof(arr) / sizeof(arr[0]);
    for(i=0; i<6; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n\n");

    //Penghapusan Awal
    printf("Penghapusan Awal");
    printf("\n");
    for(i=0; i<size; i++)
        {
            arr[i]=arr[i+1];
        }
    size--;
    for(i=0; i<size; i++)
        {
            printf("%d ", arr[i]);
        }

    printf("\n\n");

    //Penghapusan tengah
    printf("Penghapusan Tengah");
    printf("\n");
    for(i=size/2; i<size; i++)
        {
            arr[i]=arr[i+1];
        }
    size--;
    for(i=0; i<size; i++)
        {
            printf("%d ", arr[i]);
        }

    printf("\n\n");

    //Penghapusan akhir
    printf("Penghapusan Akhir");
    printf("\n");
    for(i=size; i<size; i--)
        {
            arr[i]= arr[i+1];
        }
    size--;
    for(i=0; i<size; i++)
        {
            printf("%d ", arr[i]);
        }
    printf("\n\n");
    return 0;
}
