#ifndef ARRAY_TPP
# define ARRAY_TPP

#include <exception>

template<typename T>
static void copy_content(Array<T> &a, const Array<T> &b)
{
	for (int i = 0; i < a.size(); i++)
		a[i] = b[i];
}

template<typename T>
Array<T>::Array()
: content(new T[0]), length(0)
{ }

template<typename T>
Array<T>::Array(int size)
: content(new T[size]), length(size)
{ }

template<typename T>
Array<T>::Array(const Array &other)
: content(new T[other.length]), length(other.length)
{
	copy_content(*this, other);
}

template<typename T>
Array<T>::~Array()
{
	delete [] content;
}

template<typename T>
int Array<T>::size() const
{
	return this->length;
}

template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &other)
{
	length = other.length;
	delete [] content;
	content = new T[other.length];
	copy_content(*this, other);
	return *this;
}

template<typename T>
T&Array<T>::operator[](int i) const
{
	if (i < 0 || i >= length)
		throw std::exception();
	return content[i];
}

#endif
