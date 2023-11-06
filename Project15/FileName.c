#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
void array(int arr[7][7])
{
    srand(time(NULL));
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            arr[i][j] = rand() % 21 - 10;
        }
    }
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            printf("%3d ", arr[i][j]);
        }
        printf("\n");
    }
}
void tranarray(int arr[7][7], int tran[7][7])
{
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++)
        {
            tran[i][j] = arr[j][i];
        }
    }
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            printf("%3d ", tran[i][j]);
        }
        printf("\n");
    }
}
double Sred(int arr[7][7], int col)
{
    double sum = 0;
    int count = 0;
    for (int i = 0; i < 7; i++)
    {
        if (arr[i][col] % 2 == 0)
        {
            sum += arr[i][col];
            count++;
        }
    }
    if (count > 0)
    {
        return sum / count;
    }
    else {
        printf("Нет четных");
    }
}
int rowpara(int arr[7][7])
{
    int rowpar = 0;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (arr[i][j] == arr[i][j + 1])
            {
                rowpar++;
            }
        }
    }
    return rowpar;
}
int colpara(int arr[7][7])
{
    int colpar = 0;
    for (int j = 0; j < 7; j++)
    {
        for (int i = 0; i < 6; i++)
        {
            if (arr[i][j] == arr[i + 1][j])
            {
                colpar++;
            }
        }
    }
    return colpar;
}
int rowcolpara(int arr[7][7])
{
    int rowcolpar = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (arr[i][j] == arr[i + 1][j] && arr[i][j] == arr[i][j + 1])
            {
                rowcolpar++;
            }
        }
    }
    return rowcolpar;
}
void find(int arr[7][7])
{
    int max = arr[0][0];
    int maxrow = 0;
    int maxcol = 0;
    for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
                maxrow = i;
                maxcol = j;
            }
            else if (arr[i][j] == max && i > maxrow)
            {
                maxrow = i;
                maxcol = j;
            }
        }
    }
    printf("Максимальный элемент в матрице: %d\n", max);
    printf("Координаты самого нижнего максимального элемента: (%d, %d)\n", maxcol + 1, maxrow + 1);
}
int main() {
    setlocale(LC_ALL, "RUS");
    int arr[7][7];
    int tran[7][7];
    printf("Исходный массив\n");
    array(arr);
    printf("Транспонированный массив:\n");
    tranarray(arr, tran);
    int column = 2;
    double sr = Sred(arr, column);
    printf("\nСреднее арифметическое четных элементов столбца 3: %.2lf\n", sr);
    int rowpar = rowpara(arr);
    int colpar = colpara(arr);
    int rowcolpar = rowcolpara(arr);
    printf("\nЧисло пар одинаковых соседних элементов в строках: %d\n", rowpar);
    printf("Число пар одинаковых соседних элементов в столбцах: %d\n", colpar);
    printf("Число пар одинаковых соседних элементов в строках и столбцах: %d\n", rowcolpar);
    find(arr);
}