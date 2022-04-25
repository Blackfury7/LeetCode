/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator : public Iterator {
    bool hasPeeked;
    int peekedElem;
public:
	PeekingIterator(const vector<int>& num) : Iterator(num) {
        hasPeeked = false;
	}

	int peek() {
        peekedElem = hasPeeked?peekedElem:Iterator::next();
        hasPeeked = true;
        return peekedElem;
	}

	int next() {
	    int nextElem = hasPeeked?peekedElem:Iterator::next();
	    hasPeeked = false;
	    return nextElem;
	}

	bool hasNext() const {
	    return hasPeeked||Iterator::hasNext();
	}
}; 