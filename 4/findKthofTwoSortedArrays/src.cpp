#include <iostream>
#include <vector>
#include <functional>
#include <cassert>

using namespace std;

template <class T, class Container = vector<T>, class RandomAccessIterator = typename Container::iterator, class LessComp = less<T>, class EqualComp = equal_to<int> >
T findKthofTwoSortedArrays(int k, RandomAccessIterator _fs, RandomAccessIterator _fe, RandomAccessIterator _ss, RandomAccessIterator _se) {
	cout << "cur : " << k << " (";
	for(RandomAccessIterator it = _fs; it != _fe; ++ it) {
		cout << * it << ", ";	
	}
	cout << ") (";
	for(RandomAccessIterator it = _ss; it != _se; ++ it) {
		cout << * it << ", ";	
	}
	cout << ")\n";
	ptrdiff_t _fsz = _fe - _fs, _ssz = _se - _ss, _sz = _fsz + _ssz;
	LessComp isLess;
	EqualComp isEqual;
	assert(k >= 0 && k < _sz);	
	//guarantee that the first array is shorter to make the logic simple 
	if(_fsz > _ssz) {
		return 	findKthofTwoSortedArrays<T, Container, RandomAccessIterator, LessComp, EqualComp>(k, _ss, _se, _fs, _fe);
	}
	//when the shorter array is empty	
	if(_fsz == 0) {
		return * (_ss + k);	
	}
	//when the minimal element is requried
	if(k == 0) {
		return min(* _fs, * _ss, isLess);	
	}
	//Algorithm
	// shorter sorted array1 = [a1, ..., am]
	// sorted array2 = [b1, ..., bn]
	// to find the kth elements using binary-search-like inspiration, guarantee that every iteration (k+1) irrelevant elements will be eliminated, then the problem is to find the ranges.
	// several tips:
	// 1. guarantee the length to be eliminated will not be too large
	// 2. shorter array will take less 
	k += 1;
	ptrdiff_t _foff = min(_fsz, ptrdiff_t((k / 2)), isLess), _soff = ptrdiff_t(k) - _foff;
	RandomAccessIterator _fm = _fs + _foff,  _sm = _ss + _soff;
	if(isLess(* (_fm - 1), * (_sm - 1))) {
		getchar();
		return findKthofTwoSortedArrays<T, Container, RandomAccessIterator, LessComp, EqualComp>(_soff - 1, _fm, _fe, _ss, _sm);
	}
	else if(isEqual(* (_fm - 1), * (_sm - 1))) {
		return * (_fm);	
	}
	else {
		getchar();
		return 	findKthofTwoSortedArrays<T, Container, RandomAccessIterator, LessComp, EqualComp>(_foff - 1, _fs, _fm, _sm, _se);
	}
	
}

int main(int argc, char * const argv[]) {
	int a[] = {1, 4, 7, 1000}, b[] = {2, 3, 4, 5, 6, 7, 8, 9};
	cout << findKthofTwoSortedArrays<int>(1, a, a + 4, b, b + 8) << endl;
 	return 0;
}
