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
	int arr[] = {3, 6, 2, 1, 14, 7, 9, 8, 5, 11}; 
	int size = sizeof(arr) / sizeof(arr[0]); 

	insertion_Sort(arr, size); 
    cout<<"No. of comparisons made: "<<count;
	return 0; 
}
