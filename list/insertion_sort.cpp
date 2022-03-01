#include <iostream>

using namespace std;

void InsertionSort(int *arr, int size)
{
	int i, j, key;

	for(i = 1; i < size; i++){
		key = arr[i];

		for(j = i-1; j >=0; j--){
			if(arr[j] > key){
				arr[j+1] = arr[j];
			}
			else{
				break;
			}
		}

		arr[j+1] = key;
	}
}

int main()
{
	int arr[10] = {5, 7, 3, 4, 1, 9, 2, 0, 8, 6};

	for(int i = 0; i < 10; i++){
		cout << arr[i] << " ";
	}

	cout << "\n";

	InsertionSort(arr, 10);

	for(int i = 0; i < 10; i++){
		cout << arr[i] << " ";
	}

    return 0;
}
