#include <stdio.h>

int data_ll[] = {5, 8, 19, 4, 3, 8}, i, data_new, total;

int main()
{
    printf("Deret Data \n");
    printf("\n\n");
    for(i=0; i<=5; i++)
    {
        printf("%d",data_ll[i]);
        printf("   ");
    }
    printf("\n\n");
    printf("Input sisipan awal: "); scanf("%d",&data_new);
    for(i=6; i>0; i--)
    {
        data_ll[i]=data_ll[i-1];
    }
    data_ll[i] = data_new;
    for(i=0; i<=6; i++)
    {
        printf("%d", data_ll[i]);
        printf("   ");
    }

    printf("\n\n");
    printf("Input sisipan tengah: "); scanf("%d", &data_new);
    for(i=7; i>4; i--)
    {
        data_ll[i]=data_ll[i-1];
    }
    data_ll[i] = data_new;
    for(i=0; i<=7; i++)
    {
        printf("%d", data_ll[i]);
        printf("   ");
    }
    printf("\n\n");
    printf("Input sisipan akhir: "); scanf("%d", &data_ll[i]);
    for (i=0; i<=8; i++)
    {
        printf("%d", data_ll[i]);
        printf("   ");
    }

    return 0;
}
