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
		//numbers = getData();
	}
	~MyManager() = default; 

	void startSort() {
		Sorter->sort();
	}

	std::vector<unsigned>* getData() {
		return Sorter->getNumbers();
	}

	int& getLength() {
		return length;
	}

	void doShuffle() {
		Sorter->shuffle();
	}

	void stopSort() {
		Sorter->stop();
	}

	int length = 100;
private:
	int delay = 10; //ms
	bool m_paused = 0;
	SortAlgorithm* Sorter = nullptr;
	//std::vector<unsigned>* numbers = nullptr;
};

#endif