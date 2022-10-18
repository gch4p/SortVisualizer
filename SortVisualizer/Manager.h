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

	//int& getLength() {
	//	return length;
	//}

	void doShuffle() {
		Sorter->shuffle();
	}

	void stopSort() {
		Sorter->stop();
	}

	int length = 100;
	const cursorStats cursor = cursorStats();
private:
	int delay = 10; //ms
	bool m_paused = 0;
	SortAlgorithm* Sorter = nullptr;
	//std::vector<unsigned>* numbers = nullptr;
};

#endif