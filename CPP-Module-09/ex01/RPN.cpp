#include "RPN.hpp"

ReversePolishNotation::ReversePolishNotation() {}

ReversePolishNotation::~ReversePolishNotation() {}

void ReversePolishNotation::add(int i) {
	this->stack.push(i);
}

int ReversePolishNotation::size() const {
	return this->stack.size();
}

int ReversePolishNotation::top() const {
	return this->stack.top();
}

void ReversePolishNotation::addition() {
	if (this->stack.size() < 2) throw std::exception();
	int a = this->stack.top();
	this->stack.pop();
	int b = this->stack.top();
	this->stack.pop();
	this->stack.push(a + b);
}

void ReversePolishNotation::substraction() {
	if (this->stack.size() < 2) throw std::exception();
	int a = this->stack.top();
	this->stack.pop();
	int b = this->stack.top();
	this->stack.pop();
	this->stack.push(b - a);
}

void ReversePolishNotation::multplication() {
	if (this->stack.size() < 2) throw std::exception();
	int a = this->stack.top();
	this->stack.pop();
	int b = this->stack.top();
	this->stack.pop();
	this->stack.push(a * b);
}

void ReversePolishNotation::division() {
	if (this->stack.size() < 2) throw std::exception();
	int a = this->stack.top();
	this->stack.pop();
	int b = this->stack.top();
	this->stack.pop();
	this->stack.push(b / a);
}
