#include <iostream>
#include <random>
#include <ctime>

using namespace std;

void inputData(int *a, int n);
void outputData(int *a, int n);
void remove(int *a, int *n, int k);
void removeOdd(int *a, int *n);

int main()
{
    int n;
    cin >> n;

    srand(time(0));
    int *arr = new int[n];

    inputData(arr, n);

    outputData(arr, n);

    removeOdd(arr, &n);

    outputData(arr, n);

    delete[] arr;
    return 0;
}

void inputData(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        a[i] = rand();
    }
}
void outputData(int *a, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
void remove(int *a, int *n, int k)
{
    int index = -1;
    for (int i = 0; i < *n; i++)
    {
        if (a[i] == k)
        {
            index = i;
            break;
        }
    }
    if (index != -1)
    {
        for (int i = index; i < *n - 1; i++)
        {
            a[i] = a[i + 1];
        }
            (*n)--;
    }
}
void removeOdd(int *a, int *n)
{
    for (int i = 0; i < *n; i++)
    {
        if (a[i] % 2 != 0)
        {
            remove(a, n, a[i]);
            i--;
        }
    }
}