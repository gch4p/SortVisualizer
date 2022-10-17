#ifndef BUBBLESORT
#define BUBBLESORT

#include "../SortAlgorithm.h"

class BubbleSort : public SortAlgorithm {
private:
	void algo() override {
		for (int i = 0; i < length - 1; i++) {
			for (int j = 0; j < length - i - 1; j++) {

				if (numbers[j] > numbers[j + 1])
					std::swap(numbers[j], numbers[j + 1]);

				if (!checkStatus())
					return;
			}
		}
		m_finished = true;
}
};

#endif