class MyCircularQueue {
	// queue        - 
	// frontIndex   - head/front of queue
	// qSize        - current size of queue
	// k            - max capacity of queue
    vector<int> queue;
    int frontIndex, qSize, k;
public:
    MyCircularQueue(int _k) : queue(vector<int>(_k)), frontIndex(0), qSize(0), k(_k)  {    }
	
    bool enQueue(int value) {
        if(isFull()) return false;        
        queue[(frontIndex + qSize) % k] = value;
        qSize++;
        return true;
    }
    bool deQueue() {
        if(isEmpty()) return false;  
        frontIndex = (frontIndex + 1) % k;
        qSize--;
        return true;
    }
    int Front()    {   return isEmpty() ? -1 : queue[frontIndex]; }
    int Rear()     {   return isEmpty() ? -1 : queue[(frontIndex + qSize - 1) % k];  }
    bool isEmpty() {   return !qSize;      }
    bool isFull()  {   return qSize == k;  }
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