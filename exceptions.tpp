#include "exceptions.h"
#include <cstring>

const char *Underflow::what() const noexcept {
	return strcat(const_cast<char *>("UNDERFLOW : "), msg);
}

const char *Overflow::what() const noexcept {
	return strcat(const_cast<char *>("OVERFLOW : "), msg);
}

const char *IllegalPosition::what() const noexcept {
	return strcat(const_cast<char *>("Illegal Position : "), reinterpret_cast<const char *>(position));
}
