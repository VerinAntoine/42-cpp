#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array
{

private:
	T *content;
	int length;

public:
	Array();
	Array(int size);
	Array(const Array &other);
	~Array();

	int size() const;

	Array &operator=(const Array &other);
	T &operator[](int i) const;

};

#include "Array.tpp"

#endif
