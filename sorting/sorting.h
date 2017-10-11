#pragma once

namespace algorithms {

	class Sorting {

	private:

		static int mergeSorter(int *array, int start, int end);

		static void merge(int *array, int start, int mid, int end);

		static void quickSorter(int *array, int start, int end);

		static int partition(int *array, int start, int end);

	public:

		static void bubbleSort(int *array, int length);

		static void selectionSort(int *array, int length);

		static void insertionSort(int *array, int length);

		static void mergeSort(int *array, int length);

		static void quickSort(int *array, int length);

		static void heapSort(int *arry, int length);

		static void radixSort(int *array, int length);

		static void bucketSort(int *array, int length);

	};

}
