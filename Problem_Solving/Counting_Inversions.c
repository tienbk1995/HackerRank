#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);
void swap(int *,int *);
void mergeSort(int*, int, int, int*);
void merge(int*, int, int, int, int*);

void mergeSort(int *arr, int start, int end, int *count)
{
    if (start < end)
    {
        int mid = start + (end - start)/2;

        mergeSort(arr, start, mid, count);
        mergeSort(arr, mid + 1, end, count);
        merge(arr, start, mid, end, count);
    }
}

void merge(int *arr, int start, int mid, int end, int *count)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int i,j,k;
    int temp1[n1], temp2[n2];
    
    for (i = 0; i < n1; i++)
    {
        temp1[i] = arr[start + i];
    }

    for (j = 0; j < n2; j++)
    {
        temp2[j] = arr[mid + j + 1];
    }
    // Initial start index
    i = 0;
    j = 0;
    k = start;
    while ((i < n1) && (j < n2))
    {
        if (temp1[i] <= temp2[j])
        {
            arr[k] = temp1[i];
            i += 1;
            // *count += 1;
        }
        else 
        {
            arr[k] = temp2[j];
            j += 1;
            *count += (n1 - i);
        }
        k += 1;
    }

    while (i < n1)
    {
        arr[k] = temp1[i];
        i += 1;
        k += 1;
        // *count += 1;
    }

    while (j < n2)
    {
        arr[k] = temp2[j];
        j += 1;
        k += 1;
        // *count += 1;
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void createPivot(int arr_count, int* arr, int node, int *count)
{
    int leftNode = node - 1;
    int rightNode = node + 1;
    if (arr[leftNode] > arr[node])
    {
        swap(&arr[leftNode], &arr[node]);
        *count += 1;
        createPivot(arr_count, arr, node - 1, count);
    }
    if (arr[node] > arr[rightNode])
    {
        swap(&arr[rightNode], &arr[node]);
        *count += 1;
        createPivot(arr_count, arr, node, count);
    }
}
// Complete the countInversions function below.
long countInversions(int arr_count, int* arr) 
{
    int i;
    int count = 0;
    mergeSort(arr, 0, arr_count - 1, &count);
    for (i = 0; i < arr_count; i++)
    {
        printf("arr[%d] = %d\n", i, arr[i]);
    }
    return count;
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char* t_endptr;
    char* t_str = readline();
    int t = strtol(t_str, &t_endptr, 10);

    if (t_endptr == t_str || *t_endptr != '\0') { exit(EXIT_FAILURE); }

    for (int t_itr = 0; t_itr < t; t_itr++) {
        char* n_endptr;
        char* n_str = readline();
        int n = strtol(n_str, &n_endptr, 10);

        if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }

        char** arr_temp = split_string(readline());

        int* arr = malloc(n * sizeof(int));

        for (int i = 0; i < n; i++) {
            char* arr_item_endptr;
            char* arr_item_str = *(arr_temp + i);
            int arr_item = strtol(arr_item_str, &arr_item_endptr, 10);

            if (arr_item_endptr == arr_item_str || *arr_item_endptr != '\0') { exit(EXIT_FAILURE); }

            *(arr + i) = arr_item;
        }

        int arr_count = n;

        long result = countInversions(arr_count, arr);

        fprintf(fptr, "%ld\n", result);
    }

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) {
            break;
        }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') {
            break;
        }

        alloc_length <<= 1;

        data = realloc(data, alloc_length);

        if (!line) {
            break;
        }
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';

        data = realloc(data, data_length);
    } else {
        data = realloc(data, data_length + 1);

        data[data_length] = '\0';
    }

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);

        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
