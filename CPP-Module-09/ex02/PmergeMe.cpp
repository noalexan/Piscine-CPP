#include "PmergeMe.hpp"

#include <iostream>

#include <unistd.h>

PmergeMe::PmergeMe(): _dequeTime(0), _vectorTime(0), _size(0) {}

PmergeMe::PmergeMe(char **argv): _dequeTime(0), _vectorTime(0) {
	for (int i = 0; argv[i]; ++i) {
		_deque.push_back(std::stoi(argv[i]));
		_vector.push_back(std::stoi(argv[i]));
	}
	_size = _deque.size();
}

PmergeMe::PmergeMe(const PmergeMe &copy) {
	*this = copy;
}

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &copy) {
	_deque.clear();
	_vector.clear();
	if (this != &copy) {
		_deque = copy._deque;
		_vector = copy._vector;
		_dequeTime = copy._dequeTime;
		_vectorTime = copy._vectorTime;
		_size = copy._size;
	}
	return *this;
}

static void SortByPair(std::deque<int>::iterator begin, std::deque<int>::iterator end) {
	if (std::distance(begin, end) == 2) {
		if (*begin < *std::next(begin)) {
			int tmp = *begin;
			*begin = *std::next(begin);
			*std::next(begin) = tmp;
		}
	}
	else if (std::distance(begin, end) != 1) {
		std::deque<int>::iterator mid = std::next(begin, 2);
		SortByPair(begin, mid);
		SortByPair(mid, end);
	}
}

static void PeerSort(std::deque<int>::iterator begin, std::deque<int>::iterator end) {
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (std::deque<int>::iterator it = begin; it != end; ++it) {
			if (std::distance(begin, it) % 2 == 0) {
				if (it + 1 != end && it + 2 != end && it + 3 != end && *it > *(it + 2)) {

					int tmp = *it;
					int tmp2 = *(it + 1);

					*it = *(it + 2);
					*(it + 1) = *(it + 3);

					*(it + 2) = tmp;
					*(it + 3) = tmp2;

					sorted = false;
				}
			}
		}
	}
}

static void pendInsertion(std::deque<int>::iterator begin, std::deque<int>::iterator end) {
	std::deque<int> main;
	std::deque<int> pend;

	for (std::deque<int>::iterator it = begin; it != end; ++it) {
		if (std::distance(begin, it) % 2) pend.push_back(*it);
		else if (it + 1 == end) pend.push_back(*it);
		else main.push_back(*it);
	}

	while (pend.size()) {

		int left = 0;
		int right = main.size() - 1;

		while (left <= right) {
			int mid = (left + right) / 2;
			if (pend[0] < main[mid]) right = mid - 1;
			else left = mid + 1;
		}

		main.insert(main.begin() + left, pend.begin(), pend.begin() + 1);
		pend.erase(pend.begin(), pend.begin() + 1);

	}

	for (std::deque<int>::iterator it = begin; it != end; ++it) {
		*it = main[std::distance(begin, it)];
	}

}

static void SortByPair(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if (std::distance(begin, end) == 2) {
		if (*begin < *std::next(begin)) {
			int tmp = *begin;
			*begin = *std::next(begin);
			*std::next(begin) = tmp;
		}
	}
	else if (std::distance(begin, end) != 1) {
		std::vector<int>::iterator mid = std::next(begin, 2);
		SortByPair(begin, mid);
		SortByPair(mid, end);
	}
}

static void PeerSort(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (std::vector<int>::iterator it = begin; it != end; ++it) {
			if (std::distance(begin, it) % 2 == 0) {
				if (it + 1 != end && it + 2 != end && it + 3 != end && *it > *(it + 2)) {

					int tmp = *it;
					int tmp2 = *(it + 1);

					*it = *(it + 2);
					*(it + 1) = *(it + 3);

					*(it + 2) = tmp;
					*(it + 3) = tmp2;

					sorted = false;
				}
			}
		}
	}
}

static void pendInsertion(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	std::vector<int> main;
	std::vector<int> pend;

	for (std::vector<int>::iterator it = begin; it != end; ++it) {
		if (std::distance(begin, it) % 2) pend.push_back(*it);
		else if (it + 1 == end) pend.push_back(*it);
		else main.push_back(*it);
	}

	while (pend.size()) {

		int left = 0;
		int right = main.size() - 1;

		while (left <= right) {
			int mid = (left + right) / 2;
			if (pend[0] < main[mid]) right = mid - 1;
			else left = mid + 1;
		}

		main.insert(main.begin() + left, pend.begin(), pend.begin() + 1);
		pend.erase(pend.begin(), pend.begin() + 1);

	}

	for (std::vector<int>::iterator it = begin; it != end; ++it) {
		*it = main[std::distance(begin, it)];
	}

}

void PmergeMe::sortDeque() {
	clock_t	start = clock();
	SortByPair(_deque.begin(), _deque.end());
	PeerSort(_deque.begin(), _deque.end());
	pendInsertion(_deque.begin(), _deque.end());
	_dequeTime = (double) (clock() - start) / CLOCKS_PER_SEC * 1000;
}

void PmergeMe::sortVector() {
	clock_t	start = clock();
	SortByPair(_vector.begin(), _vector.end());
	PeerSort(_vector.begin(), _vector.end());
	pendInsertion(_vector.begin(), _vector.end());
	_vectorTime = (double) (clock() - start) / CLOCKS_PER_SEC * 1000;
}

std::deque<int> &PmergeMe::getDeque() { return _deque; }
std::vector<int> &PmergeMe::getVector() { return _vector; }

double PmergeMe::getDequeTime() { return _dequeTime; }
double PmergeMe::getVectorTime() { return _vectorTime; }

int PmergeMe::getSize() { return _size; }
