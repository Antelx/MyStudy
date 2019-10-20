#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int> &a, int i, int n)
{
    int largest = i;
    if (2 * i + 1 < n)
    {
        if (a[i] < a[2 * i + 1])
        {
            largest = 2 * i + 1;
        }
    }
    if (2 * i + 2 < n)
    {
        if (a[largest] < a[2 * i + 2])
        {
            largest = 2 * i + 2;
        }
    }
    if (largest != i)
    {
        int lar = a[largest];
        a[largest] = a[i];
        a[i] = lar;
        heapify(a, largest, n);
    }
}
void sort_heap(vector<int> &a)
{
    int n = a.size();
    for (int i = n / 2; i > -1; i--)
    {
        heapify(a, i, n);
    }
    for (int p = a.size() - 1; p > -1; p--)
    {
        int temp = a[p];
        a[p] = a[0];
        a[0] = temp;
        heapify(a, 0, p);
    }
}
int main()
{
    vector<int> a = {4, 9, 5, 1, 5, 3, 7, 6, 9, 8, 2};
    sort_heap(a);
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << endl;
    }

    getchar();
    return 0;
}