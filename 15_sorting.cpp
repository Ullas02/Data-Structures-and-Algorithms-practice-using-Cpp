#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &vec)
{
    int n = vec.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

void selectionSort(vector<int> &vec)
{
    int n = vec.size();

    for (int i = 0; i < n - 1; i++)
    {
        int smallesetIndex = i; // unsorted part starting index
        for (int j = i + 1; j < n; j++)
        {
            if (vec[j] < vec[smallesetIndex])
            {
                smallesetIndex = j;
            }
        }
        swap(vec[smallesetIndex], vec[i]);
    }
}

void insertionSort(vector<int> &vec)
{
    int n = vec.size();

    for (int i = 1; i < n; i++)
    {
        int currrent = vec[i], previous = i - 1;
        while (previous >= 0 && vec[previous] > currrent)
        {
            vec[previous + 1] = vec[previous];
            previous--;
        }
        vec[previous + 1] = currrent;
    }
}

void printElements(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> vec = {2, 4, 1, 5, 3};

    cout << "Before sorting : \n";
    printElements(vec);

    // bubbleSort(vec);
    // selectionSort(vec);
    insertionSort(vec);

    cout << "After sorting : \n";
    printElements(vec);

    return 0;
}