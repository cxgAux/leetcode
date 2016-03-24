#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <assert.h>

using namespace std;

template<class T, class Container = vector<T>, class RandomAccessIterator = typename Container::iterator, class Comp = less<T> >
RandomAccessIterator partition(RandomAccessIterator _f, RandomAccessIterator _s) {
	assert(_f < _s);	

	RandomAccessIterator _t = _f, _e = _s;
	Comp comp;
	T _sentinel = * _t;
	while(true) {
		while(comp(* (++ _t), _sentinel) && (_t != _s));
		while(comp(* (-- _e), _sentinel) == false && (_e != _f));
		if(_t >= _e) break;
		swap(* _t, * _e);
	}
	if(_f != _e) {
		swap(* _f, * _e);
	}
	return _e;
}

template<class T, class Container = vector<T>, class RandomAccessIterator = typename Container::iterator, class Comp = less<T> >
RandomAccessIterator randomPartition(RandomAccessIterator _f, RandomAccessIterator _s) {

	RandomAccessIterator _rnd = _f + rand() % int(_s - _f);
	swap(* _f, * _rnd);
	return partition<T, Container, RandomAccessIterator, Comp>(_f, _s);	
}

template<class T, class Container = vector<T>, class RandomAccessIterator = typename Container::iterator, class LessComp = less<T>, class EqualComp = equal_to<T> >
T findKthElement(int k, RandomAccessIterator _f, RandomAccessIterator _s) {
	assert(k >= 0 && k < int(_s - _f));	
	
	if(1 == (_s - _f)) return * _f;
	else {
		RandomAccessIterator _lowerBound = randomPartition<T, Container, RandomAccessIterator, LessComp>(_f, _s), 
					_upperBound = partition<T, Container, RandomAccessIterator, EqualComp>(_lowerBound, _s) + 1;
		if(k < int(_lowerBound - _f)) {
			return findKthElement<T, Container, RandomAccessIterator, LessComp, EqualComp>(k, _f, _lowerBound);	
		}
		else if(k < int(_upperBound - _f)) {
			return * _lowerBound;
		}
		else {
			return findKthElement<T, Container, RandomAccessIterator, LessComp, EqualComp>(k - int(_upperBound - _f), _upperBound, _s);	
		}
	}
}




int main(int argc, char * const argv[]) {
	srand((unsigned int)time(NULL));
	vector<int> v{2, 2, 3, 1, 4};
	cout << findKthElement<int>(4, v.begin(), v.end()) << endl;
	int vv[] = {5, 9, 10, 1, 2, 10000, 5, 3, 1};
	cout << findKthElement<int>(3, vv, vv + sizeof(vv) / sizeof(int)) << endl;
	return 0;
}
