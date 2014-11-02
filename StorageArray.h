#ifndef __StorageArray_h__
#define __StorageArray_h__

#include<iostream>
#include<cstdlib>
#include<vector>


class StorageArray
{

public:
	//constructor, destructor
	StorageArray();
	StorageArray(const StorageArray &);
	StorageArray & operator= (const StorageArray &);
	~StorageArray();

	//selector
	virtual const std::size_t Size() const = 0;

	//modifier
	virtual void Element(std::size_t,std::size_t,const double) = 0;

	//operator
	virtual double& operator() (std::size_t,std::size_t) = 0;

};

class RegularArray : public StorageArray
{
private:
	std::vector<double> elements;
	std::size_t nrow, ncol;

public:
	//constructor, destructor
	RegularArray() : StorageArray(){
		std::cout << "RegularArray: default constructor\n" << std::endl;
	};
	RegularArray(const RegularArray& source) :StorageArray(source){
		std::cout << "RegularArray: copy constructor" << std::endl;
	};
	StorageArray & operator= (const StorageArray &);

};

#endif