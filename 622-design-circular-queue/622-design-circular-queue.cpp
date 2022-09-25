class MyCircularQueue {
public:
   int n;
	vector<int> qu;
	MyCircularQueue(int k) {
		n=k;

	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if(qu.size()==n) return false;
		qu.push_back(value);
		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if(qu.size()==0) return false;
		qu.erase(qu.begin());
		return true;
	}

	/** Get the front item from the queue. */
	int Front() {
		if(qu.size()==0) return -1;
		return qu[0];
	}

	/** Get the last item from the queue. */
	int Rear() {
		if(qu.size()==0) return -1;
		return qu.back();
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		if(qu.size()==0) return true;
		return false;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		if(qu.size()==n) return true;
		return false;
	}
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */