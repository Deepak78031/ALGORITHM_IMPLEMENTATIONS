//HEAP SORT IMPLEMENTATION
#include <iostream>
using namespace std;

int count=0;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    count++;

    if (r < n && arr[r] > arr[largest])
        largest = r;
    count++;

    if (largest != i)
    {
        count++;
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout <<endl<<endl<<"Total no. of Comparisons made = "<<count;
}

int main()
{
    int n;

    cout<<"Enter the Size Of Array: ";
    cin>>n;

    int arr[n];

    cout<<"\nEnter the Elements: ";

    for(int i=0; i<n; i++)
        cin>>arr[i];

    heapSort(arr, n);
    cout << "The sorted array is: \n";
    printArray(arr, n);
}
