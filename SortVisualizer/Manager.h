#ifndef MANAGER
#define MANAGER

#include "Algorithms/BubbleSort.h"
#include "Algorithms/InsertionSort.h"
#include <chrono>
#include <thread>

class MyManager {
public:
	MyManager() {
		Sorter = new BubbleSort;
		Sorter->init();
		Sorter->shuffle();
	}
	~MyManager() = default; 

	void startSort() {
		m_paused = 0;
		Sorter->start();
	}

	std::vector<unsigned>* getData() {
		return Sorter->getNumbers();
	}

	void doShuffle() {
		m_paused = 1;
		Sorter->stop();
		Sorter->shuffle();
	}

	void stopSort() {
		m_paused = 1;
		Sorter->stop();
	}

	void setSort(int id) {
		m_paused = 1;
		sortID = id;
		Sorter->stop();
		switch (id) {
		case 0:
			Sorter = new BubbleSort;
			break;
		case 1:
			Sorter = new InsertionSort;
			break;
		}
		Sorter->init();
		Sorter->shuffle();
	}

	SortAlgorithm* Sorter = nullptr;
	int length = 100;
	int sortID = 0;
private:
	int delay = 10; //ms
	bool m_paused = 0;
	//std::vector<unsigned>* numbers = nullptr;
};

#endif