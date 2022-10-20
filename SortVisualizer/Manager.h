#ifndef MANAGER
#define MANAGER

#include "Algorithms/BubbleSort.h"
#include <chrono>
#include <thread>

class MyManager {
public:
	MyManager() {
		Sorter = new BubbleSort;
		Sorter->init();
	}
	~MyManager() = default; 

	void startSort() {
		Sorter->start();
	}

	std::vector<unsigned>* getData() {
		return Sorter->getNumbers();
	}

	void doShuffle() {
		Sorter->stop();
		Sorter->shuffle();
	}

	void stopSort() {
		Sorter->stop();
	}

	SortAlgorithm* Sorter = nullptr;
	int length = 100;
private:
	int delay = 10; //ms
	bool m_paused = 0;
	//std::vector<unsigned>* numbers = nullptr;
};

#endif