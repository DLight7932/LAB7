#include <iostream>

using namespace std;

int Method_1(int* mas, int size)
{
    int sum = 0;
    #pragma omp parallel for
    for (int i = 0; i < size; i++)
        sum += mas[i];
    return sum;
}

int Method_2(int* mas, int size)
{
    do
    {
        #pragma omp parallel for
        for (int i = 0; i < size / 2; i++)
        {
            int end = size - 1 - i;
            mas[i] += mas[end];
        }
        size = size / 2 + size % 2;
    } while (size > 1);
    int sum = mas[0];
    return sum;
}

int main()
{
    const int size = 2000;
    int mas[size];
    for (int i = 0; i < size; i++)
        mas[i] = i;

    cout << "Simple sum: " << Method_1(mas, size) << endl;

    cout << "Paralel sum: " << Method_1(mas, size) << endl;

    return 0;
}