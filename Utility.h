#ifndef Utility_h
#define Utility_h

template <class V, class I>
void print(const Array<V, I>& v){
	std::cout << "\n\nMinIndex: " << v.MinIndex() << " , MaxIndex: " << v.MaxIndex() << std::endl;
	std::cout << "\nARR: [";
	for (I j = v.MinIndex(); j <= v.MaxIndex(); j++){
		std::cout << v[j] << " , ";
	}
	std::cout << "]";
}

template <class V, class I>
void print(const Matrix<V, I>& m){
	std::cout << "\n\nMinRowIndex" << m.MinRowIndex() << " , MaxRowIndex: " << m.MaxRowIndex() << std::endl;
	std::cout << "MinColumnIndex: " << m.MinColumnIndex() << " , MaxColumnIndex: " << m.MaxColumnIndex() << std::endl;
	std::cout << "\nMAT: [";
	for (I i = m.MinRowIndex(); i <= m.MaxRowIndex(); i++){
		std::cout << "\nRow" << i << "(";
		for (I j = m.MinColumnIndex(); j <= m.MaxColumnIndex(); j++){
			std::cout << m(i, j) << " , ";

		}
		std::cout << ")";

	}
	std::cout << "]";
}

#endif