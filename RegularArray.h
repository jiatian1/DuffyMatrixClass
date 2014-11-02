// Template class for a non-sparse arrays.

#ifndef RegularArray_h
#define RegularArray_h

// Use the STL vector class
#include <vector>
#include "ArrayStorage.h"

template <class V, class TA = std::allocator<V> >
class RegularArray : public ArrayStorage<V>
{
private:
	std::vector<V, TA> m_vector;								// Use STL vector class for storage

public:
	// Constructors & destructor
	RegularArray();
	RegularArray(size_t size);
	RegularArray(const RegularArray<V, TA>& source);
	virtual ~RegularArray();

	// Selectors
	virtual size_t Size() const;

	// Modifiers

	// Operators
	V& operator[] (size_t index);
	const V& operator[] (size_t index) const;

	RegularArray<V, TA>& operator = (const RegularArray<V, TA>& source);
};

// Constructors & destructor
template <class V, class TA>
RegularArray<V, TA>::RegularArray() : ArrayStorage<V>()
{ // Default constructor

	m_vector = std::vector<V, TA>(1);	// vector object with 1 element
}

template <class V, class TA>
RegularArray<V, TA>::RegularArray(size_t size) : ArrayStorage<V>()
{ // Constructor with size

	m_vector = std::vector<V, TA>(size);
}

template <class V, class TA>
RegularArray<V, TA>::RegularArray(const RegularArray<V, TA>& source) : ArrayStorage<V>(source)
{ // Copy constructor

	m_vector = source.m_vector;
}

template <class V, class TA>
RegularArray<V, TA>::~RegularArray()
{ // Destructor
}

// Selectors
template <class V, class TA>
size_t RegularArray<V, TA>::Size() const
{ // Size of the array

	return m_vector.size();
}


// Modifiers

// Operators
template <class V, class TA>
V& RegularArray<V, TA>::operator[] (size_t index)
{ // Subscripting operator


	return m_vector[index - 1];
}

template <class V, class TA>
const V& RegularArray<V, TA>::operator[] (size_t index) const
{ // Subscripting operator


	return m_vector[index - 1];
}

template <class V, class TA>
RegularArray<V, TA>& RegularArray<V, TA>::operator = (const RegularArray<V, TA>& source)
{ // Assignment operator

	// Exit if same object
	if (this == &source) return *this;

	// Call base class constructor
	ArrayStorage<V>::operator = (source);

	// Copy the embedded vector
	m_vector = source.m_vector;

	return *this;
}


#endif