#ifndef INSERTIONSORT
#define INSERTIONSORT

#include "../SortAlgorithm.h"
//https://www.geeksforgeeks.org/insertion-sort/

class InsertionSort : public SortAlgorithm {
	void algo() override {
		int j,key = 0;
		for (int i = 1; i < length; ++i) {
			key = numbers[i];

			j = i - 1;
			while (j >= 0 && numbers[j] > key) {
				setCursorPos(j, -1);

				numbers[j + 1] = numbers[j];
				j = j - 1;

				checkStatus();
			}
			numbers[j + 1] = key;
		}
		m_finished = true;
	}
};


#endif