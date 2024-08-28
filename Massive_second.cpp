#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

int main (void)
    {
        setlocale(LC_ALL, "Russian");
        printf("Введите кол-во рядов : ");
        int string_quantity = 0;
        scanf("%d", string_quantity);
        int * address_dynam_mem = (int *) calloc (string_quantity, sizeof(int));
        if (address_dynam_mem == NULL)
            return 0;


        printf("Введите кол-во элементов в каждой строке: ");
        int sum = 0;
        for (int i = 0; i < string_quantity; i++)
            {
                scanf("%d ",  address_dynam_mem[i]);
                sum += address_dynam_mem[i];
            }

        free (address_dynam_mem);
        address_dynam_mem = NULL
        free (address_dynam_mem);

        int * address_dyn_main = (int*) calloc (sum, sizeof (int));
        if (address_dynam_main == NULL)
            return 0;
        printf("\nВведите через пробел значения всех элементов таблицы: ")
        for (int i = 0; i < sum; i++)
            {
                scanf("%d ", address_dyn_main [i])
            }


        return 0;
    }
