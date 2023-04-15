#include "Searching.h"


namespace algorithms {

	int Searching::linearSearch(const int *array, int length, int key) {
		for (int i = 0; i < length; ++i) {
			if (array[i] == key) {
				return i;
			}
		}
		return -1;
	}


	int Searching::binarySearch(const int *array, int key, int start, int end) {
		if (start < end) {
			int mid = (start + end) / 2;
			if (array[mid] == key) {
				return mid;
			} else if (key < array[mid]) {
				return Searching::binarySearch(array, key, start, mid);
			} else {
				return Searching::binarySearch(array, key, mid + 1, end);
			}
		}
		return -1;
	}


	int Searching::binarySearch(const int *array, int length, int key) {
		return Searching::binarySearch(array, key, 0, length);
	}

}
