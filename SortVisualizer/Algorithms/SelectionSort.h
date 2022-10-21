#ifndef SELECTIONSORT
#define SELECTIONSORT

#include "../SortAlgorithm.h"

class SelectionSort : public SortAlgorithm {
	void algo() override {
		int min_idx = 0;
		for (int i = 0; i < (length-1); ++i) {
			min_idx = i;
			for (int j = (i+1); j < length; ++j) {
				setCursorPos(j);
				if (numbers[j] < numbers[min_idx])
					min_idx = j;

				if (!checkStatus())
					return;
			}
			if (min_idx != i)
				std::swap(numbers[i], numbers[min_idx]);
		}
		m_finished = 1;
	}
};

#endif