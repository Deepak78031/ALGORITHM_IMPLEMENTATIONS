//RADIX SORT IMPLEMENTATION
#include <iostream>
using namespace std;


int getMax(int A[], int n)      //Function to get the maximum element in an array
{
    int Max = A[0];

    for (int i = 1; i < n; i++)
        if (A[i] > Max)
            Max = A[i];
    return Max;
}



void countSort(int A[], int n, int exp)     //Function to do counting sort of arr[] according to the digit represented by exp.
{
    int output[n];         //Output array
    int i,count[10]={0};


    for (i = 0; i < n; i++)         //Store count of occurrences in count[]
        count[(A[i]/exp)%10]++;


    for (i = 1; i < 10; i++)        //Converting count into it's own prefix array
        count[i]+=count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[(A[i]/exp)%10]-1] = A[i];
        count[(A[i]/exp)%10]--;
    }

    for (i = 0; i < n; i++)
        A[i] = output[i];
}

void RadixSort(int A[], int n)
{
    int m = getMax(A, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(A, n, exp);
}

void Print(int A[], int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
}

int main()
{
    int n,A[100];

    cout<<"Enter the Size Of Array: ";
    cin>>n;

    cout<<"\nEnter the Elements of Array \n";

    for(int i=0; i<n; i++)
        cin>>A[i];

    RadixSort(A,n);

    cout<<"\nThe Sorted array is: \n";
    Print(A, n);

}
