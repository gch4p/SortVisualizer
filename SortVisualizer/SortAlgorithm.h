#ifndef SORTALGORITHM
#define SORTALGORITHM

#include <vector>
#include <thread>
#include <algorithm>
#include <random>

class SortAlgorithm {
protected:
	std::vector<unsigned> numbers = {};
	unsigned length = 100;
	bool isFinished = 0;

	std::thread sortThread;
	int delay = 10; //ms

	std::default_random_engine rng;

	virtual void algo() = 0;

	void checkStatus() {
		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	}
public:
	//SortAlgorithm(unsigned len = 100) {
	//	for (unsigned i = len; i > 0; --i)
	//		numbers.push_back(i);
	//	length = len;
	//}
	SortAlgorithm() = default;
	virtual ~SortAlgorithm() = default;

	void init() {
		numbers.clear();
		for (unsigned i = length; i > 0; --i)
			numbers.push_back(i);
	}

	void setDelay(int& del) {
		delay = del;
	}

	void setLength(unsigned len) {
		length = len;
	}

	void sort() {
		if (sortThread.joinable())
			sortThread.join();
		sortThread = std::thread(&SortAlgorithm::algo, this);
	}
	
	void shuffle() {
		std::shuffle( numbers.begin(), numbers.end(), rng);
	}

	std::vector<unsigned>* getNumbers() {
		return &numbers;
	}
};

#endif