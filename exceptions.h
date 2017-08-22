#pragma once

#include <exception>
#include <string>
#include <utility>
#include <cstring>

class Underflow : public std::exception {
private:
	const char *msg;

public:
	explicit Underflow(const char *msg) {
		Underflow::msg = msg;
	}

	const char *what() const noexcept {
		return strcat(const_cast<char *>("UNDERFLOW : "), msg);
	}
};


class Overflow : public std::exception {
private:
	const char *msg;

public:
	explicit Overflow(const char *msg) {
		Overflow::msg = msg;
	}

	const char *what() const noexcept {
		return strcat(const_cast<char *>("OVERFLOW : "), msg);
	}
};


class IllegalPosition : public std::exception {
private:
	int position;

public:
	explicit IllegalPosition(int position) {
		IllegalPosition::position = position;
	}

	const char *what() const noexcept {
		return strcat(const_cast<char *>("Illegal Position : "), reinterpret_cast<const char *>(position));
	}
};