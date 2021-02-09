//INSERTION SORT IMPLEMENTATION 
#include <iostream> 
using namespace std; 
int count=0;
void insertion_Sort(int arr[], int n) 
{ 
	int i, temp, j; 
	for (i = 1; i < n; i++) 
	{ 
		temp = arr[i]; 
		j = i - 1; 
		while (j >= 0 && arr[j] > temp) 
		{ 
			arr[j + 1] = arr[j]; 
			j--; 
            count++;
		} 
		 
        if(j>=0){
            if(arr[j]< temp){
                count++;
            }
        }
        arr[j + 1] = temp;
    } 
} 
int main() 
{ 
	int size; 
	cout<<"Enter the size of array: ";
	cin>>size;
	int arr[size];
	cout<<"Enter the elements: ";
	for(int i=0; i<size; i++)
		cin>>arr[i];
	insertion_Sort(arr, size); 
	cout<<"\nSorted array is: ";
	for(int i=0; i<size; i++){
		if(i>0 && i<size)
			cout<<",";
		cout<<" "<<arr[i];
	}
	cout<<"\nNo. of comparisons made: "<<count;
	return 0; 
}
