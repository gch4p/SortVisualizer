#ifndef COCKTAILSORT
#define COCKTAILSORT

#include "../SortAlgorithm.h"

//https://www.geeksforgeeks.org/cocktail-sort/
class CocktailSort : public SortAlgorithm {
	void algo() override {
		bool swapped = true;
		int start = 0,len = length-1;

		while (swapped) {
			swapped = false;

			for (int i = start; i < len; ++i) {
				setCursorPos(i);
				if (!checkStatus())
					return;

				if (numbers[i] > numbers[i + 1]) {
					std::swap(numbers[i], numbers[i + 1]);
					swapped = true;
				}
			}

			if (!swapped)
				break;

			swapped = false;
			--len;

			for (int i = len - 1; i >= start; --i) {
				setCursorPos(i,1);
				if (!checkStatus())
					return;

				if (numbers[i] > numbers[i + 1]) {
					std::swap(numbers[i], numbers[i + 1]);
					swapped = true;
				}
			}

			++start;
		}
	}
};

#endif