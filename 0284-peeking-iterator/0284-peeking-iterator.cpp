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
public:
	PeekingIterator(const vector<int>& nums) : Iterator(nums) 
    {
	    doPeek = false;
	}
	
	int peek() 
	{
        if(!doPeek)
        {
            if(Iterator::hasNext())
            {
                peekElement = Iterator::next();
                doPeek = true;
            }
        }
        return peekElement;
	}
	
	int next() 
	{
	    if(doPeek)
        {
            doPeek = false;
            return peekElement;
        }
            
        return Iterator::next();
	}
	
	bool hasNext() const 
    {
        if(doPeek)
            return true;
        
	    return Iterator::hasNext();
	}
    
private:
    bool doPeek;
    int peekElement;
};