#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <assert.h>

int** Processing_address (int * const string_quantity);
int* Matrix (int ** address_for_address, const int string_quantity, bool first_or_second);
int** Creating_an_array_of_addresses (int** address_for_address1, int string_quantity);
//void Address_add_sizeof (size_t* address_for_address, int* address_matrix, int string_quantity);
void Sum (int* address_matrix1, int* address_matrix2, size_t size_matrix);
void Print_Matrix (int* address_matrix, int* copy_param_matrix, int string_quantity);

int main (void)
    {
        setlocale(LC_ALL, "Russian");
        int string_quantity = 0;
        size_t size_matrix = 0;
        int** address_for_address1 = Processing_address (&string_quantity, &size_matrix);
        int** address_for_address2 = Creating_an_array_of_addresses (address_for_address1, string_quantity);
        int* address_matrix1 = Matrix (address_for_address1, string_quantity, true);
        int* address_matrix2 = Matrix (address_for_address2, string_quantity, false);
        //Address_add_sizeof (address_for_address1, address_matrix1, string_quantity);
        //Address_add_sizeof (address_for_address2, address_matrix2, string_quantity);
        int* adr_sum = Sum (address_matrix1, address_matrix2, size_matrix);
        Print_Matrix (adr_sum, copy_param_matrix, string_quantity);
        free (address_for_address1);
        free (address_for_address2);
        free (address_matrix1);
        free (adr_sum);
        return 0;
    }

int* Matrix (size_t size_matrix, bool first_or_second )
    {
        int* address_matrix = (int*) calloc (size_matrix, sizeof (int));
        if (address_matrix == NULL) {printf("�� �������� ������ calloc");return 0;}
        int n = 0;
        if (first_or_second) n = 1;
        else n = 2;
        printf("������� ����� ������ �������� ���� ��������� %d-�� �������: ", n);

         for (size_t i = 0; i < size_matrix; i++)
            scanf("%d", &address_matrix[i]);
         return address_matrix;
    }

int** Processing_address (int * const string_quantity, size_t* size_matrix)
    {
        printf("������� ���-�� ����� : ");
        scanf("%d", string_quantity);
        int ** address_for_address1 = (int **) calloc ((*string_quantity) + 1, sizeof(int));
        if (address_for_address1 == NULL)
            return 0;

        printf("������� ���-�� ��������� � ������ ����: ");
        address_for_address1[0] = 0;
        int arr = 0;
        for (int i = 1; i <= *string_quantity; i++)
            {
                scanf("%d",  &arr);
                address_for_address1[i] = (int*) arr;
                *size_matrix += (size_t) address_for_address1[i]
                //address_for_address1[i] += address_for_address1[i-1];
            }
        return address_for_address1;
    }

 /*void Address_add_sizeof (int** address_for_address, int* address_matrix, int string_quantity)
    {
        for (int i = 0; i <= string_quantity; i++)
            {
               address_for_address[i] = address_for_address[i] * sizeof(int) +  address_matrix;
            }
    } */

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

void Sum (int* addres_matrix1, int* address_matrix2, size_t size_matrix)
    {
        int* adr_sum = (int*) calloc (size_matrix, sizeof(int));
        for (size_t i = 0; i < size_matrix; i++)
            {
                adr_sum[i] = address_matrix1[i] + address_matrix1[i];
            }
        return adr_sum;
    }
void Print_Matrix (int* address_matrix, int* copy_param_matrix, int string_quantity)
    {
        int count = 0;
        for (int i = 0; i <  string_quantity)
            for (int* i = 0; i < copy_param_matrix[i+1]; i ++)
                {
                    printf("%d ", address_matrix[count]);
                    count++;
                }
            printf("\n");
    }
    {
        ;
    } */



