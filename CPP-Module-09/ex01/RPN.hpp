#include <stack>

class ReversePolishNotation {

	private:
		std::stack<int> stack;

	public:

		ReversePolishNotation();
		~ReversePolishNotation();

		void add(int);
		int size() const;
		int top() const;

		void addition();
		void substraction();
		void multplication();
		void division();

};
