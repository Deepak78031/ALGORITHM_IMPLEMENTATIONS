#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    int start;
    int finish;
    int profit;
};

bool myfunction(Interval s1, Interval s2)
{
    return (s1.finish < s2.finish);
}

int binarySearch(Interval Intervals[], int index)
{
    int low = 0, high = index - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (Intervals[mid].finish <= Intervals[index].start)
        {
            if (Intervals[mid + 1].finish <= Intervals[index].start)
                low = mid + 1;
            else
                return mid;
        }
        else
            high = mid - 1;
    }

    return -1;
}

int findMaxDuration(Interval arr[], int n)
{
    sort(arr, arr+n, myfunction);

    int *table = new int[n];
    table[0] = arr[0].profit;

    for (int i=1; i<n; i++)
    {
        int inclProf = arr[i].profit;
        int l = binarySearch(arr, i);
        if (l != -1)
            inclProf += table[l];

        table[i] = max(inclProf, table[i-1]);
    }

    int result = table[n-1];
    delete[] table;

    return result;
}

int main()
{
    int n;
    cout<<"Enter Number Of Intervals: ";
    cin>>n;

    Interval arr[n];

    for(int i=1; i<=n; i++){
        cout<<"Enter Start Time: ";
        cin>>arr[i-1].start;
        cout<<"Enter Finish Time: ";
        cin>>arr[i-1].finish;
        cout<<"Enter Duration: ";
        cin>>arr[i-1].profit;
    }

    cout << "Optimal Duration is " << findMaxDuration(arr, n);
    return 0;
}
