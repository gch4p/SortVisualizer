#ifndef SORTALGORITHM
#define SORTALGORITHM

#include <vector>
#include <thread>
#include <algorithm>
#include <random>
#include <atomic>

//struct cursorStats {
//	std::atomic<unsigned> pos = 0;
//	unsigned val = 0;
//};

class SortAlgorithm {
protected:
	std::vector<unsigned> numbers = {};
	unsigned length = 100;
	std::atomic<bool> m_finished, m_running = false;
	std::atomic<unsigned> cursorPos = 0;

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

	void setCursorPos(int pos, int offset) {
		if (pos - offset < 0)
			offset = 0;
		if (pos + offset > length)
			offset = 0;
		cursorPos = pos + offset;
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

	//void setCursorPos(int& pos) {
	//	cursor.pos = pos;
	//}

	std::atomic<unsigned>* getCursorPos() {
		return &cursorPos;
	}

	std::vector<unsigned>* getNumbers() {
		return &numbers;
	}
};

#endif