#pragma once


namespace algorithms {

	class Searching {

	private:

		static int binarySearch(const int *array, int key, int start, int end);

	public:

		static int linearSearch(const int *array, int length, int key);

		static int binarySearch(const int *array, int length, int key);

	};

}

