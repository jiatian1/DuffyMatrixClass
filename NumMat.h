// Numeric matrix class.
// This is a matrix class for numerical data. Derived from Matrix and 
// it adds mathematical functions.

#ifndef NumMat_h
#define NumMat_h

#include "Matrix.h"
#include "Vector.h"


// Default structure is FullArray with default allocator. Default integral type is int.
template <class V, class I = int, class S = RegularMatrix<V> >
class NumMat : public Matrix<V, I, S>
{
private:

public:
	// Constructors & destructor
	NumMat();													// Default constructor
	NumMat(size_t rows, size_t columns);							// Constructor with size. Start index=1.
	NumMat(size_t rows, size_t columns, I rowStart, I columnStart);		// Constructor with size & start index
	NumMat(const Matrix<V, I, S>& source);			// Constructor with matrix
	NumMat(const NumMat<V, I, S>& source);	// Copy constructor
	virtual ~NumMat();							// Destructor

	// Selectors
	Vector<V, I> Row(I row) const;					// Return row. Overloads Matrix::Row() to return Vector instead of Array
	Vector<V, I> Column(I column) const;			// Return column. Overloads Matrix::Row() to return Vector instead of Array


	// Modifiers
	void Row(I row, const Array<V, I> val);		// Replace row
	void Column(I column, const Array<V, I> val);	// Replace column

	// Operators
	NumMat<V, I, S>& operator = (const NumMat<V, I, S>& source);

	NumMat<V, I, S> operator - () const;			// Unary minus


	NumMat<V, I, S> operator + (const NumMat<V, I, S>& m) const;		// Add the elements
	NumMat<V, I, S> operator - (const NumMat<V, I, S>& m) const;		// Subtract the elements
	NumMat<V, I, S> operator * (const NumMat<V, I, S>& m) const;		// Multiply the matrices
	Vector<V, I> operator * (const Vector<V, I>& v) const;


};


// Constructors & destructor
template <class V, class I, class S>
NumMat<V, I, S>::NumMat() : Matrix<V, I, S>()
{ // Default constructor
}

template <class V, class I, class S>
NumMat<V, I, S>::NumMat(size_t rows, size_t columns) : Matrix<V, I, S>(rows, columns)
{ // Constructor with size. Start index=0.
}

template <class V, class I, class S>
NumMat<V, I, S>::NumMat(size_t rows, size_t columns, I rowStart, I columnStart) : Matrix<V, I, S>(rows, columns, rowStart, columnStart)
{ // Constructor with size & start index
}

template <class V, class I, class S>
NumMat<V, I, S>::NumMat(const Matrix<V, I, S>& source) : Matrix<V, I, S>(source)
{ // Constructor with matrix
}

template <class V, class I, class S>
NumMat<V, I, S>::NumMat(const NumMat<V, I, S>& source) : Matrix<V, I, S>(source)
{ // Copy constructor
}

template <class V, class I, class S>
NumMat<V, I, S>::~NumMat()
{ // Destructor
}

// Selectors
template <class V, class I, class S>
Vector<V, I> NumMat<V, I, S>::Row(I row) const
{ // Return row. Overloads Matrix::Row() to return Vector instead of Array

	return Vector<V, I>(Matrix<V, I, S>::Row(row));
}

template <class V, class I, class S>
Vector<V, I> NumMat<V, I, S>::Column(I column) const
{ // Return Column. Overloads Matrix::Row() to return Vector instead of Array

	return Vector<V, I>(Matrix<V, I, S>::Column(column));
}


// Modifiers
template <class V, class I, class S>
void NumMat<V, I, S>::Row(I row, const Array<V, I> val)
{ // Replace row. Overloaded because Row() selector is overloaded thus hiding Matrix::Row() modifier.

	Matrix<V, I, S>::Row(row, val);
}

template <class V, class I, class S>
void NumMat<V, I, S>::Column(I column, const Array<V, I> val)
{ // Replace column. Overloaded because Column() selector is overloaded thus hiding Matrix::Column() modifier.

	Matrix<V, I, S>::Column(column, val);
}

// Operators
template <class V, class I, class S>
NumMat<V, I, S>& NumMat<V, I, S>::operator = (const NumMat<V, I, S>& source)
{ // Assignment operator

	// Exit if same object
	if (this == &source) return *this;

	// Call base class assignment
	Matrix<V, I, S>::operator = (source);

	return *this;
}

template <class V, class I, class S>
NumMat<V, I, S> NumMat<V, I, S>::operator - () const
{ // Unary minus

	// Create new matrix with same size and same starting index
	NumMat<V, I, S> result(Rows(), Columns(), MinRowIndex(), MinColumnIndex());

	// Copy all elements negative
	for (I r = MinRowIndex(); r <= MaxRowIndex(); r++)
	{
		for (I c = MinColumnIndex(); c <= MaxColumnIndex(); c++)
		{

			result(r, c) = -(*this)(r, c);
		}
	}

	// Return the result
	return result;
}




template <class V, class I, class S>
NumMat<V, I, S> NumMat<V, I, S>::operator + (const NumMat<V, I, S>& m) const
{ // Add the elements


	// Create new matrix with same size and same starting index
	NumMat<V, I, S> result(Rows(), Columns(), MinRowIndex(), MinColumnIndex());
	I r1, c1, r2, c2;

	// Add all elements
	for (r1 = MinRowIndex(), r2 = m.MinRowIndex(); r1 <= MaxRowIndex(); r1++, r2++)
	{
		for (c1 = MinColumnIndex(), c2 = m.MinColumnIndex(); c1 <= MaxColumnIndex(); c1++, c2++) result.Element(r1, c1, Element(r1, c1) + m.Element(r2, c2));
	}

	// Return the result
	return result;
}

template <class V, class I, class S>
NumMat<V, I, S> NumMat<V, I, S>::operator - (const NumMat<V, I, S>& m) const
{ // Subtract the elements

	// Create new matrix with same size and same starting index
	NumMat<V, I, S> result(Rows(), Columns(), MinRowIndex(), MinColumnIndex());
	I r1, c1, r2, c2;

	// Add all elements
	for (r1 = MinRowIndex(), r2 = m.MinRowIndex(); r1 <= MaxRowIndex(); r1++, r2++)
	{
		for (c1 = MinColumnIndex(), c2 = m.MinColumnIndex(); c1 <= MaxColumnIndex(); c1++, c2++) result.Element(r1, c1, Element(r1, c1) - m.Element(r2, c2));
	}

	// Return the result
	return result;
}

template <class V, class I, class S>
NumMat<V, I, S> NumMat<V, I, S>::operator * (const NumMat<V, I, S>& m) const
{ // Multiply the matrix.
	// This function can be optimized by calculating the inner product ourselfs instead of 
	// using the InnerProduct function of Vector. This saves a couple of row and column copies.


	// Create new matrix with same row size of first matrix and column size of second matrix and same starting index as first matrix
	NumMat<V, I, S> result(Rows(), m.Columns(), MinRowIndex(), MinColumnIndex());
	I r1, c2, rr, cr;

	// Element of resulting array is dot/inner product of corresponding row m1 and corresponding column m2
	for (rr = result.MinRowIndex(), r1 = MinRowIndex(); rr <= result.MaxRowIndex(); rr++, r1++)
	{
		for (cr = result.MinColumnIndex(), c2 = m.MinColumnIndex(); cr <= result.MaxColumnIndex(); cr++, c2++) result.Element(rr, cr, Row(r1).InnerProduct(m.Column(c2)));
	}

	// Return the result
	return result;
}


template <class V, class I, class S> Vector<V, I> NumMat<V, I, S>::operator * (const Vector<V, I>& v) const
{

	// Result has same number of rows as m and same start index as v
	Vector<V, I> result(Rows(), v.MinIndex());

	V r(0.0);	// sum of rows
	for (I i = MinRowIndex(); i <= MaxRowIndex(); i++)
	{

		r = 0.0;
		for (I j = MinColumnIndex(); j <= MaxColumnIndex(); j++)
		{
			r += (*this)(i, j) * v[j];
		}

		result[i] = r;
	}

	return result;

}

#endif