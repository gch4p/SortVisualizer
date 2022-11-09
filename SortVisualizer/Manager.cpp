#include "Manager.h"

MyManager::MyManager() {
	Sorter = new BubbleSort;
	Sorter->init(delay);
	Sorter->shuffle();
}

void MyManager::startSort() {
	m_running = 1;
	Sorter->start();
}

void MyManager::stopSort() {
	m_running = 0;
	Sorter->stop();
}

void MyManager::setDelay(int del) {
	delay = del;
	Sorter->setDelay(delay);
}

std::vector<unsigned>* MyManager::getData() {
	return Sorter->getNumbers();
}

void MyManager::doShuffle() {
	m_running = 0;
	Sorter->stop();
	Sorter->shuffle();
}

void MyManager::setSort(int id) {
	m_running = 0;
	sortID = id;
	Sorter->stop();
	switch (id) {
	case 0:
		Sorter = new BubbleSort;
		break;
	case 1:
		Sorter = new InsertionSort;
		break;
	case 2:
		Sorter = new SelectionSort;
		break;
	case 3: 
		Sorter = new GnomeSort;
		break;
	}
	Sorter->init(delay);
	Sorter->shuffle();
}

