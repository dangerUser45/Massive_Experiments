#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <assert.h>

int** Processing_address (int * const string_quantity, size_t** param_matrix);
int* Matrix (int ** address_for_address, const int string_quantity, bool first_or_second);
int** Creating_an_array_of_addresses (int** address_for_address1, int string_quantity);
void Address_add_sizeof (int** address_for_address, int* address_matrix, int string_quantity);
int* Sum (int** address_for_address1, int** address_for_address2, size_t size_matrix, int string_quantity, size_t* param_matrix);
void Print_Matrix (int* address_matrix, size_t* param_matrix, int string_quantity);
void Print_Input (bool one_or_two);
void Free_All (int** address_for_address1, int** address_for_address2, int* address_matrix1, int* address_matrix2, int* adr_sum);

int main (void)
    {
        setlocale(LC_ALL, "Russian");
        int string_quantity = 0;
        size_t* param_matrix = 0;

        int** address_for_address1 = Processing_address (&string_quantity, &param_matrix);
        size_t size_matrix = (size_t) address_for_address1[string_quantity];

        int** address_for_address2 = Creating_an_array_of_addresses (address_for_address1, string_quantity);
        int* address_matrix1 = Matrix (address_for_address1, string_quantity, true);
        Print_Input (true);
        Print_Matrix (address_matrix1, param_matrix, string_quantity);

        int* address_matrix2 = Matrix (address_for_address2, string_quantity, false);
        Print_Input (false);
        Print_Matrix (address_matrix2, param_matrix, string_quantity);

        Address_add_sizeof (address_for_address1, address_matrix1, string_quantity);
        Address_add_sizeof (address_for_address2, address_matrix2, string_quantity);


        int* adr_sum = Sum (address_for_address1, address_for_address2, size_matrix, string_quantity, param_matrix);
        Print_Matrix (adr_sum, param_matrix, string_quantity);
        Free_All (address_for_address1, address_for_address2, address_matrix1, address_matrix2, adr_sum);
        return 0;
    }

int* Matrix (int ** address_for_address, const int string_quantity, bool first_or_second )
    {
        assert(address_for_address != NULL);
        int* address_matrix = (int*) calloc ((size_t)address_for_address[string_quantity], sizeof (int));
        if (address_matrix == NULL) {printf("Не сработал второй calloc");return 0;}
        int n = 0;
        if (first_or_second) n = 1;
        else n = 2;
        printf("Введите через пробел значения всех элементов %d-ой матрицы: ", n);

         for (size_t i = 0; i < (size_t)address_for_address[string_quantity]; i++)
            scanf("%d", &address_matrix[i]);
         return address_matrix;
    }

int** Processing_address (int * const string_quantity, size_t** param_matrix)
    {
        printf("Введите кол-во рядов : ");
        scanf("%d", string_quantity);
        int ** address_for_address1 = (int **) calloc ((*string_quantity) + 1, sizeof(int));
        (*param_matrix) = (size_t*) calloc ((*string_quantity) + 1, sizeof(size_t));
        if (address_for_address1 == NULL)
            return 0;

        printf("Введите кол-во элементов в каждом ряду: ");
        address_for_address1[0] = 0;
        *(param_matrix[0]) = 0;
        size_t arr = 0;
        for (int i = 1; i <= *string_quantity; i++)
            {
                scanf("%llu",  &arr);
                *(param_matrix[i]) = arr;
                address_for_address1[i] = (int*) arr;
                address_for_address1[i] += (size_t)address_for_address1[i-1];
            }
        return address_for_address1;
    }

void Address_add_sizeof (int** address_for_address, int* address_matrix, int string_quantity)
    {
        for (int i = 0; i <= string_quantity; i++)
            {
      //БЫЛО:  address_for_address[i] = address_for_address[i] * sizeof(int) +  address_matrix;
               address_for_address[i] = (int*)((size_t)address_for_address[i] * sizeof(int) + (size_t)address_matrix);
            }
    }

int** Creating_an_array_of_addresses (int** address_for_address1, int string_quantity)
    {
        int ** address_for_address2 = (int **) calloc (string_quantity + 1, sizeof(size_t));
        if (address_for_address2 == NULL)
            return 0;
        for (int i = 0; i <= string_quantity; i++)
            address_for_address2[i] = address_for_address1[i];
        assert(address_for_address2 != NULL);
        return address_for_address2;
    }

int* Sum (int** address_for_address1, int** address_for_address2, size_t size_matrix, int string_quantity, size_t* param_matrix)
    {
        int* adr_sum = (int*) calloc (size_matrix, sizeof(int));
        for (int i = 0; i < string_quantity; i++)
                for(int j = 0; (size_t)j < param_matrix[j+1]; j++)
                    {
                        adr_sum[i] = address_for_address1[i][j] + address_for_address2[i][j];
                    }
        return adr_sum;
    }

void Print_Matrix (int* address_matrix, size_t* param_matrix, int string_quantity)
    {
        int Count = 0;
        for (int i = 0; i <  string_quantity; i++)
            for (int j = 0; (size_t)j < param_matrix[j+1]; i ++)
                {
                    printf("%d ", address_matrix[Count]);
                    Count++;
                }
        printf("\n");
    }

void Print_Input (bool one_or_two)
    {
        int n = 0;
        if (one_or_two)
            n = 1;
        else
            n = 2;
        printf("Так выглядит %d-ая матрица", n);
    }

void Free_All (int** address_for_address1, int** address_for_address2, int* address_matrix1, int* address_matrix2, int* adr_sum)
    {
        free (address_for_address1);
        free (address_for_address2);
        free (address_matrix1);
        free (address_matrix2);
        free (adr_sum);
    }

