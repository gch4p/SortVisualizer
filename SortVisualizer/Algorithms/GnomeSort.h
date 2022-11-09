#ifndef GNOMESORT
#define GNOMESORT

#include "../SortAlgorithm.h"

class GnomeSort : public SortAlgorithm {
private:
	void algo() override {
		int idx = 0;
		while (idx < length) {
			setCursorPos(idx, -1);

			if (idx == 0) {
				++idx;
			}
			else if (numbers[idx - 1] < numbers[idx]) {
				++idx;
			}
			else {
				std::swap(numbers[idx - 1], numbers[idx]);
				--idx;
			}
			if (!checkStatus())
				return;
		}
		m_finished = true;
	}
};

#endif