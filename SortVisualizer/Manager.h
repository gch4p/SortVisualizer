#ifndef MANAGER
#define MANAGER

#include "Algorithms/Includes.h"
#include <chrono>
#include <thread>

class MyManager {
public:
	MyManager();
	~MyManager() = default; 

	std::vector<int>* getData();

	void doShuffle();

	void startSort();
	void stopSort();

	void setDelay(int del);

	void setSort(int id);

	SortAlgorithm* Sorter = nullptr;
	int length = 100;
	int sortID = 0;
	bool m_running = 0;
private:
	unsigned delay = 10; //ms
};

#endif