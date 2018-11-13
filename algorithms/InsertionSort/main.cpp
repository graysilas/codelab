#include <iostream>
#include <vector>

 
template <typename T>
void insertionSort(std::vector<T> &arr);

int main() {

	std::vector<int> arr = { 54, 35, 31, 15, 36, 71, 74, 25, 99, 27, 48, 32, 78, 39, 9, 1, 20, 66, 92, 26, 72, 23, 22, 46, 10, 3, 100, 18, 2, 95, 30, 79, 41, 82, 14, 55, 86, 19, 58, 37, 42, 67, 60, 50, 96, 4, 57, 93, 85, 84};
						  
	 
	insertionSort(arr);

 

	system("PAUSE");
	return 0;
}

template <typename T>
void insertionSort(std::vector<T> &arr) {

	
	for (int i = 1; i < arr.size() ; i++) {

		int val = arr[i];

		for (int j = i - 1; j >= 0; j--) {
			
			if (arr[j] > val) {
				arr[j + 1] = arr[j];
				arr[j] = val;
			}
			else if (arr[j] < val) {
				arr[j + 1] = val;
				break;
			}

		}


	}


}

 







