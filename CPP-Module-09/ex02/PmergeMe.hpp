#include <deque>
#include <vector>
#include <time.h>

class PmergeMe {

	private:

		std::deque<int>		_deque;
		std::vector<int>	_vector;
		double				_dequeTime;
		double				_vectorTime;
		int					_size;

	public:

		PmergeMe();
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe &);

		~PmergeMe();

		PmergeMe			&operator=(const PmergeMe &);

		void				sortDeque();
		void				sortVector();

		std::deque<int>		&getDeque();
		std::vector<int>	&getVector();

		double				getDequeTime();
		double				getVectorTime();

		int					getSize();

};
