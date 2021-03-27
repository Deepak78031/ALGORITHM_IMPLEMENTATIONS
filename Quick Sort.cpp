//Quick Sort Implementation
#include<iostream>
using namespace std;

int count = 0;

int partition (int A[], int low, int high)
{
    int pivot = A[high];
    int i = low-1;

    for (int j = low; j <= high- 1; j++)
    {
        count++;
        if (A[j] <= pivot)
            swap(A[++i],A[j]);
    }
    swap(A[i + 1], A[high]);

    return i + 1;
}

void quick_Sort(int A[], int low, int high)
{
    count++;

    if (low < high)
    {
        int pi = partition(A, low, high);
        quick_Sort(A, low, pi - 1);
        quick_Sort(A, pi + 1, high);
    }
}

void Print(int A[], int size)
{
    for (int i=0; i < size; i++)
        cout<<A[i]<<" ";
}

int main()
{
    int n,A[100];

    cout<<"Enter the Size Of Array : ";
    cin>>n;

    cout<<"\nEnter the  Elements: ";

    for(int i=0; i<n; i++)
        cin>>A[i];

    quick_Sort(A, 0, n-1);

    cout<<"\nThe Sorted array is:  ";
    Print(A, n);

    cout<<"\n\nTotal no. of Comparisons = "<<count;

    return 0;
}
