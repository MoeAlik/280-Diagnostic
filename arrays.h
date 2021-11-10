#include <iostream>
#include <string>
#include <fstream>
#include <cstring>

const int SIZE = 60;

const int MAX_PRINTABLE_ASCII = '~';
const int MIN_PRINTABLE_ASCII = ' ';
const int ASCII_PRINTABLE_RANGE = MAX_PRINTABLE_ASCII - MIN_PRINTABLE_ASCII + 1;

using namespace std;

void printRight(int n)
{
    if (n > 0)
    {

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                cout << "*";
            }
        }
    }
}

void printRight_upsideDown_rightJustified(int n)
{
    if (n > 0)
    {
        for (int i = n; i > 0; i--)
        {
            for (int k = n - i; k > 0; k--)
            {
                cout << " ";
            }
            for (int j = i; j > 0; j--)
            {

                cout << "*";
            }
            cout << endl;
        }
    }
}

void printArray(const char arr[], int size)
{
    if (size > 0 && size <= SIZE)
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i];
        }
        cout << endl;
    }
}

void printArray(const char arr[][SIZE], int rows, int cols)
{
    if (rows > 0 && rows <= SIZE && cols > 0 && cols <= SIZE)
        for (int i = 0; i < rows; i++)
        {
            printArray(arr[i], cols);
        }
}
void add(char arr[], int size, int val)
{
    if (size > 0 && size <= SIZE)
    {

        for (int i = 0; i < size; i++)
        {
            int temp = arr[i] + val;

            while (temp < MIN_PRINTABLE_ASCII)
            {
                temp += ASCII_PRINTABLE_RANGE;
            }
            while (temp > MAX_PRINTABLE_ASCII)
            {
                temp -= ASCII_PRINTABLE_RANGE;
            }
            arr[i] = temp;
        }
    }
}

void add(char arr[][SIZE], int rows, int cols, int val)
{
    if (rows > 0 && rows <= SIZE && cols > 0 && cols <= SIZE)
        for (int i = 0; i < rows; i++)
        {

            add(arr[i], cols, val);
        }
}

void rotateLeft(char arr[], int size)
{
    if (size > 0 && size <= SIZE)
    {
        char temp = arr[0];

        int i;
        for (i = 0; i < size - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
        arr[i] = temp;
    }
}
void rotateLeft(char arr[][SIZE], int rows, int cols)
{
    if (rows > 0 && rows <= SIZE && cols > 0 && cols <= SIZE)
    {
        for (int i = 0; i < rows; i++)
        {
            rotateLeft(arr[i], cols);
        }
    }
}
void rotateRight(char arr[], int size)
{
    if (size > 0 && size <= SIZE)
    {

        char temp = arr[size - 1];
        for (int i = size - 1; i > 0; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = temp;
    }
}
void rotateRight(char arr[][SIZE], int rows, int cols)
{
    if (rows > 0 && rows <= SIZE && cols > 0 && cols <= SIZE)
    {
        for (int i = 0; i < rows; i++)
        {
            rotateRight(arr[i], cols);
        }
    }
}
void reverse(char arr[], int size)
{
    if (size > 0 && size <= SIZE)
    {
        for (int i = 0; i < size / 2; i++)
        {
            swap(arr[i], arr[size - 1 - i]);
        }
    }
}

void swapRange(char arr1[], int size1, int index1,
               char arr2[], int size2, int index2, int len)
{
    if (size1 >= index1 + len && size1 > 0 && size1 <= SIZE && size2 >= index2 + len && size2 > 0 && size2 <= SIZE && len >= 0)
    {
        for (int i = 0; i < len; i++)
        {
            swap(arr1[index1 + i], arr2[index2 + i]);
        }
    }
}

void swapWithinOneRow(char arr[], int size, int len)
{
    if (size > 0 && size <= SIZE && len > 0)
    {
        int thing = 2 * len;
        for (int i = 0; i < size; i += thing)
        {
            if (i + thing - 1 < size)
            {
                swapRange(arr, size, i, arr, size, len + i, len);
            }
        }
    }
}

void swapRows(char arr[][SIZE], int rows, int cols)
{
    if (rows > 0 && rows <= SIZE && cols > 0 && cols <= SIZE)
    {

        if (rows % 2 == 0)
        {
            for (int i = 0; i < rows; i += 2)
            {
                swapRange(arr[i], cols, 0, arr[1 + i], cols, 0, cols);
            }
        }
        else
        {
            for (int i = 0; i < rows - 2; i += 2)
            {
                swapRange(arr[i], cols, 0, arr[1 + i], cols, 0, cols);
            }
        }
    }
}
