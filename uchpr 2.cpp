#include <iostream>

using namespace std;

void PlusSize(int* &arr, int &size);

short repnum[10000] = { 0 };

int main()
{
    int a = 0, temp = 0;
    double n = 0;
    int size = 10;

    cout << "Input number of elements of sequence: ";
    cin >> n;
    cout << endl;
    
    int* arr = new int[size];

    for (int i = 0; i < n; i++)
    {
        cin >> a;

        if (repnum[a] == 0)
        {
            repnum[a]++;
        }
        else if (repnum[a] == 1)
        {
            if (temp == size)
            {
                PlusSize(arr, size);
            }

            arr[temp] = a;
            temp++;
            repnum[a]++;
        }

        a = 0;

    }

    for (int i = 0; i < temp; i++)
    {
        for (int j = temp - 1; j > 0; j--)
        {
            if (arr[j] > arr[j - 1])
            {
                int o = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = o;
            }
        }
    }

    for (int i = 0; i < temp; i++)
    {

            cout << arr[i] << " ";

    }
}

void PlusSize(int*& arr, int& size)
{
    int* newArray = new int[size * 2];

    for (int i = 0; i < size; i++)
    {
        newArray[i] = arr[i];
    }

    for (int i = size; i < size * 2; i++)
    {
        newArray[i] = 0;
    }

    size *= 2;

    delete[] arr;

    arr = newArray;
}
