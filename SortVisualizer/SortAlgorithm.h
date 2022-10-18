#ifndef SORTALGORITHM
#define SORTALGORITHM

#include <vector>
#include <thread>
#include <algorithm>
#include <random>

struct cursorStats {
	int pos = 0;
	int val = 0;
};

class SortAlgorithm {
protected:
	std::vector<unsigned> numbers = {};
	unsigned length = 100;
	bool m_finished, m_running = false;

	std::thread sortThread;
	int delay = 10; //ms

	std::default_random_engine rng;

	virtual void algo() = 0;

	bool checkStatus() {
		if (!m_running)
			return 0;

		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		return 1;
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

	void setLength(int& len) {
		length = len;
	}

	void start() {
		m_running = true;
		if (sortThread.joinable())
			sortThread.join();
		sortThread = std::thread(&SortAlgorithm::algo, this);
	}
	
	void shuffle() {
		std::shuffle( numbers.begin(), numbers.end(), rng);
	}

	void stop() {
		m_running = false;
	}

	void setCursorPos(int& pos) {
		cursor.pos = pos;
	}

	cursorStats* getCursorStats() {
		return &cursor;
	}

	std::vector<unsigned>* getNumbers() {
		return &numbers;
	}
};

#endif