#ifndef SORTALGORITHM
#define SORTALGORITHM

#include <vector>
#include <thread>
#include <algorithm>
#include <random>
#include <atomic>

class SortAlgorithm {
protected:
	std::vector<int> numbers = {};
	unsigned length = 100;
	std::atomic<bool> m_finished = false, m_running = false;
	std::atomic<unsigned> cursorPos = 0,delay = 10;

	std::thread sortThread;
	//int delay = 10; //ms

	std::default_random_engine rng;

	virtual void algo() = 0;

	bool checkStatus() {
		if (!m_running)
			return 0;

		std::this_thread::sleep_for(std::chrono::milliseconds(delay));
		return 1;
	}

	void setCursorPos(int pos, int offset = 0) {
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

	void init(unsigned &del) {
		delay = del;
		numbers.clear();
		for (int i = length; i > 0; --i)
			numbers.push_back(i);
	}

	void setDelay(unsigned& del) {
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
		m_finished = false;
		std::shuffle( numbers.begin(), numbers.end(), rng);
	}

	void stop() {
		m_running = false;
		std::this_thread::sleep_for(std::chrono::milliseconds(delay + 10));
	}

	bool isRunning() {
		return m_running;
	}

	std::atomic<unsigned>* getCursorPos() {
		return &cursorPos;
	}

	std::vector<int>* getNumbers() {
		return &numbers;
	}
};

#endif