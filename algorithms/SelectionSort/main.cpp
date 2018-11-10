
#include <iostream>
#include <vector>


template<class T> void selectionSort(std::vector<T> &arr);

int main() {

	
	std::vector<int> arr = { 31, 47, 175, 183, 123, 115, 13, 165, 112, 139, 129, 55, 26, 188, 53, 76, 44, 163, 70, 108, 21, 36, 40, 42, 152, 195, 193, 182, 181, 20 };

	selectionSort(arr);
	 
	return 0;
}


template<class T>
void selectionSort(std::vector<T> &arr) {

	
	for (int i = 0; i < arr.size() - 1; i++) {
	 
		
		T minValIndex = i;
		for (int j = i + 1; j < arr.size(); j++) {

			if(arr[j] < arr[minValIndex]) minValIndex = j;

		}
		// swap
		if (minValIndex > i) {
			T tmp = arr[i];
			arr[i] = arr[minValIndex];
			arr[minValIndex] = tmp;
		}

	}

}
 
