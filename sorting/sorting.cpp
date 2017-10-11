#include <limits>
#include "sorting.h"
#include "../util/utility.h"


namespace algorithms {

	void Sorting::bubbleSort(int *array, int length) {

		bool is_sorted = true;
		for (int i = 0; i < length; i++) {
			for (int j = 0; j < length - i - 1; ++j) {
				if (array[j] > array[j + 1]) {
					is_sorted = false;
					Utility::xchange(&array[j], &array[j + 1]);
				}
			}
			if (is_sorted) {
				break;
			}
		}

	}


	void Sorting::selectionSort(int *array, int length) {

		bool is_sorted = true;
		for (int i = 0; i < length - 1; ++i) {
			int min = std::numeric_limits<int>::max(), min_pos = -1;
			for (int j = i + 1; j < length; ++j) {
				if (min > array[j]) {
					is_sorted = false;
					min = array[j];
					min_pos = j;
				}
			}
			if (is_sorted) {
				break;
			} else {
				Utility::xchange(&array[i], &array[min_pos]);
			}
		}

	}


	void Sorting::insertionSort(int *array, int length) {

		int key, j;
		for (int i = 1; i < length; ++i) {
			key = array[i];
			j = i - 1;
			while (j >= 0 && array[j] > key) {
				array[j + 1] = array[j];
				j--;
			}
			array[j + 1] = key;
		}

	}


	int Sorting::mergeSorter(int *array, int start, int end) {

		if (end > start) {
			int mid = (end + start) / 2;
			if (mid == 0) {
				return array[0];
			}
			Sorting::mergeSorter(array, start, mid);
			Sorting::mergeSorter(array, mid + 1, end);
			Sorting::merge(array, start, mid, end);
		}

	}


	void Sorting::merge(int *array, int start, int mid, int end) {

		int l_size = mid - start + 1, r_size = end - mid;
		int l_arr[l_size], r_arr[r_size];

		for (int i = 0; i < l_size; ++i) {
			l_arr[i] = array[start + i];
		}
		for (int j = 0; j < r_size; ++j) {
			r_arr[j] = array[j + mid + 1];
		}

		int l_cp_pos = 0, r_cp_pos = 0, main_pos = start;
		while (l_cp_pos < l_size && r_cp_pos < r_size) {
			if (l_arr[l_cp_pos] < r_arr[r_cp_pos]) {
				array[main_pos] = l_arr[l_cp_pos];
				l_cp_pos++;
			} else {
				array[main_pos] = r_arr[r_cp_pos];
				r_cp_pos++;
			}
			main_pos++;
		}

		while (l_cp_pos < l_size) {
			array[main_pos] = l_arr[l_cp_pos];
			l_cp_pos++;
			main_pos++;
		}

		while (r_cp_pos < r_size) {
			array[main_pos] = r_arr[r_cp_pos];
			r_cp_pos++;
			main_pos++;
		}

	}


	void Sorting::mergeSort(int *array, int length) {

		Sorting::mergeSorter(array, 0, length - 1);

	}


	void Sorting::quickSorter(int *array, int start, int end) {

		if (start < end) {

			int mid = Sorting::partition(array, start, end);
			Sorting::quickSorter(array, start, mid - 1);
			Sorting::quickSorter(array, mid + 1, end);

		}

	}

	int Sorting::partition(int *array, int start, int end) {

		int pivot = array[end], i = start - 1;

		for (int j = start; j < end; ++j) {
			if (array[j] <= pivot) {
				i++;
				Utility::xchange(&array[i], &array[j]);
			}
		}

		Utility::xchange(&array[i + 1], &array[end]);
		return (i + 1);

	}


	void Sorting::quickSort(int *array, int length) {

		Sorting::quickSorter(array, 0, length - 1);

	}


	void Sorting::heapSort(int *arry, int length) {

	}


	void Sorting::radixSort(int *array, int length) {

	}


	void Sorting::bucketSort(int *array, int length) {

	}

}