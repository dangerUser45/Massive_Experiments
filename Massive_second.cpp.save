#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

size_t* Processing_address (int * string_quantity);
int* Matrix (size_t * address_for_address, int string_quantity, bool first_or_second);
size_t* Creating_an_array_of_addresses (size_t* address_for_address1, int string_quantity);
void Address_add_sizeof (size_t* address_for_address, int* address_matrix, int string_quantity);
//void Sum (int* address_for_address1, int* address_for_address2);

int main (void)
    {
        setlocale(LC_ALL, "Russian");
        int string_quantity = 0;
        size_t* address_for_address1 = Processing_address (&string_quantity);
        size_t* address_for_address2 = Creating_an_array_of_addresses (address_for_address1, string_quantity);
        int* address_matrix1 = Matrix (address_for_address1, string_quantity, true);
        int* address_matrix2 = Matrix (address_for_address2, string_quantity, false);
        Address_add_sizeof (address_for_address1, address_matrix1, string_quantity);
        Address_add_sizeof (address_for_address2, address_matrix2, string_quantity);
        //Sum (address_for_address1, address_for_address2);
        free (address_for_address1);
        free (address_for_address2);
        free (address_matrix1);
        free(address_matrix2);
        return 0;
    }

int* Matrix (size_t * address_for_address, int string_quantity, bool first_or_second )
    {

        int* address_matrix = (int*) calloc (address_for_address[string_quantity], sizeof (int));
        if (address_matrix == NULL) {printf("Danil");return 0;}
        int n = 0;
        if (first_or_second) n = 1;
        else n = 2;
        printf("Введите через пробел значения всех элементов %d-ой матрицы: ", n);

         for (size_t i = 0; i < address_for_address[string_quantity]; i++)
            scanf("%d", &address_matrix[i]);
         return address_matrix;
    }

size_t* Processing_address (int * string_quantity)
    {
        printf("Введите кол-во рядов : ");
        scanf("%d", string_quantity);
        size_t * address_for_address1 = (size_t *) calloc ((*string_quantity) + 1, sizeof(int));
        if (address_for_address1 == NULL)
            return 0;

        printf("Введите кол-во элементов в каждом ряду: ");
        address_for_address1[0] = 0;
        for (int i = 1; i <= *string_quantity; i++)
            {
                scanf("%llu",  &address_for_address1[i]);
                address_for_address1[i] += address_for_address1[i-1];
            }
        return address_for_address1;
    }

 void Address_add_sizeof (size_t* address_for_address, int* address_matrix, int string_quantity)
    {
        for (int i = 0; i <= string_quantity; i++)
            {
               address_for_address[i] = (size_t) address_for_address[i] * sizeof(int) + (size_t) address_matrix;
            }
    }

size_t* Creating_an_array_of_addresses (size_t* address_for_address1, int string_quantity)
    {
        size_t * address_for_address2 = (size_t *) calloc (string_quantity + 1, sizeof(int));
        if (address_for_address2 == NULL)
            return 0;
        for (int i = 0; i < string_quantity; i++)
            address_for_address2[i] = address_for_address1[i];

        return address_for_address2;
    }

/*void Sum (int* address_for_address1, int* address_for_address2)
    {
        ;
    } */



