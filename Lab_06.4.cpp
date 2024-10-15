#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

void create(int* arr, int SIZE, int MIN, int MAX)
{
    for (int i = 0; i < SIZE; i++) {
        arr[i] = MIN + rand() % (MAX - MIN + 1);
    }
}

void Print(int* arr, const int SIZE)
{
    for (int i = 0; i < SIZE; i++) {
        cout << setw(4) << arr[i];
    }
    cout << endl;
}

int count(int* arr, int SIZE, int C)
{
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] > C) {
            count++;
        }
    }
    return count;
}

double mult(int* arr, int SIZE, int maxIndex)
{
    double mul = 1.0;
    for (int i = maxIndex + 1; i < SIZE; i++) {
        mul *= arr[i];
    }
    return mul;
}

int findMaxIndex(int* arr, const int SIZE)
{
    int maxIndex = 0;
    for (int i = 1; i < SIZE; i++) {
        if (abs(arr[i]) > abs(arr[maxIndex])) {
            maxIndex = i;
        }
    }
    return maxIndex;
}

void Sort(int* arr, const int SIZE)
{
    int* temp = new int[SIZE];
    int negIndex = 0;

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] < 0) {
            temp[negIndex++] = arr[i];
        }
    }

    for (int i = 0; i < SIZE; i++) {
        if (arr[i] >= 0) {
            temp[negIndex++] = arr[i];
        }
    }

    for (int i = 0; i < SIZE; i++) {
        arr[i] = temp[i];
    }

    delete[] temp;
}

int main()
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int SIZE;
    int MIN = -10;
    int MAX = 10;
    double C;

    cout << "Введіть значення C: ";
    cin >> C;

    cout << "Введіть розмір масиву: ";
    cin >> SIZE;

    int* arr = new int[SIZE];

    create(arr, SIZE, MIN, MAX);
    cout << "Сгенерований масив: ";
    Print(arr, SIZE);
    cout << endl;

    int countGreater = count(arr, SIZE, C);
    cout << "Кількість елементів, більших за " << C << ": " << countGreater << endl;

    int maxIndex = findMaxIndex(arr, SIZE);
    cout << "Добуток елементів масиву після максимального за модулем елементу: " << mult(arr, SIZE, maxIndex) << endl;

    Sort(arr, SIZE);
    cout << "Відсортований масив: ";
    Print(arr, SIZE);

    delete[] arr;
    return 0;
}
