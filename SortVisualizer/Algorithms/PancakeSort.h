#ifndef PANCAKESORT
#define PANCAKESORT

#include "../SortAlgorithm.h"

class PancakeSort : public SortAlgorithm {
private:
	int maxIdx(std::vector<int>& arr,int sz) {
		int max = 0;
		for (int i = 1; i < sz; ++i) {
			if (arr[i] > arr[max])
				max = i;
		}
		return max;
	}

	void flip(std::vector<int>& arr, int idx) {
		int tmp, start = 0;
		while (start < idx) {
			setCursorPos(start);
			tmp = arr[start];
			arr[start] = arr[idx];
			arr[idx] = tmp;
			++start;
			--idx;
			if (!checkStatus())
				return;
		}
	}

	void algo() override {
		for (int cur_size = length; cur_size > 1; --cur_size) {
			int max = maxIdx(numbers, cur_size);

			if (max != cur_size - 1) {
				flip(numbers, max);
				flip(numbers, cur_size - 1);
			}
		}
		m_finished = true;
	}
};

#endif