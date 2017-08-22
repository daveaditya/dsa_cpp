#pragma once

#include <exception>
#include <string>
#include <utility>

class Underflow : public std::exception {
private:
	const char *msg;

public:
	explicit Underflow(const char *msg) {
		Underflow::msg = msg;
	}

	const char *what() const noexcept override;
};


class Overflow : public std::exception {
private:
	const char *msg;

public:
	explicit Overflow(const char *msg) {
		Overflow::msg = msg;
	}

	const char *what() const noexcept override;
};


class IllegalPosition : public std::exception {
private:
	int position;

public:
	explicit IllegalPosition(int position) {
		IllegalPosition::position = position;
	}

	const char *what() const noexcept override;
};