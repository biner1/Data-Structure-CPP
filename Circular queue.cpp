#include<iostream>
using namespace std;

const int maxsize=5;
int CQ[maxsize];
int rear = -1;
int front = -1;

bool isEmpty() {
	return front == -1;
}

bool isFull() {
	return (rear == maxsize - 1 && front == 0) || (rear == front - 1);
}

void clear() {
	rear = -1;
	front = -1;
}

void enqueue(int value) {
	if (isFull()) {
		cout << "queue is full" << endl;
	}
	else {
		if (rear == -1) {
			front++;
			rear++;
			CQ[rear] = value;

		}
		else if (rear==maxsize-1) {
			rear = 0;
			CQ[rear] = value;
		}
		else {
			rear++;
			CQ[rear] = value;
		}

	} // end of else 1

}

int dequeue(){
	if (isEmpty()) {
		cout << "queue is empty" << endl;
		exit(0);
	}
	else {

		if (front == maxsize - 1) {
			int value = CQ[front];
			front = 0;
			return value;
		}
		else if (rear == front) {
			int value = CQ[front];
			front = -1;
			rear = -1;
			return value;
		}
		else {
			int value = CQ[front];
			front++;
			return value;
		}


	} // end of else 1

}

int numOfElement() {

	if (isEmpty()) {
		return 0;
	}
	else {
		if (front<=rear) {
			return rear - front + 1;
		}
		else{
			return maxsize-front + rear + 1;
		}


	}// end of else 1

}

void print() {
	if (isEmpty()) {
		cout << "queue is empty cannot print" << endl;
	}
	else {
		if (rear >= front) {
			for (int i = front;i <= rear;i++) {
				cout << CQ[i];
			}
			cout << endl;
		}

		else {
			int j = front;

			// using while to print when rear < front
			
			//while (j!=rear+1) {
			//	if (j<maxsize) {
			//		cout << CQ[j];
			//		j++;
			//	}
			//	else {
			//		j = 0;
			//		cout << CQ[j];
			//		j++;
			//	}		
			//}//end of while
			//cout << endl;

			// using for loop to print when rear < front

			for (int i = 0;i < numOfElement();i++) // you can use i<maxsize-front+rear+1
			{
				if (j != maxsize-1) {
					cout << CQ[j];
					j++;
				}
				else {
					cout << CQ[j];	
					j = 0;
				}
			}
		}
	}// end of else 1

}

int search(int value) {

	if (isEmpty()) {
		cout << "queue is empty cannot search" << endl;
		return 888;
	}
	else {
		if (rear >= front) {
			for (int i = front;i <= rear;i++) {
				if (value == CQ[i]) {
					return 999;
				}
			}
			return 888;
		}

		else {
			int j = front;
			while (j != rear + 1) {

				if (j < maxsize) {
					if (value == CQ[j]) {
						return 999;
					}
					j++;
				}
				else {
					j = 0;
					if (value == CQ[j]) {
						return 999;
					}
					j++;
				}
			}//end of while
			return 888;
		}
	}// end of else 1

}

int main() {
	

	cout << "emp:"<<isEmpty() << " ful:" << isFull() << endl;
	
	cout << "num of elem: " << numOfElement() << endl;
	enqueue(1);
	cout << "num of elem: " << numOfElement() << endl;
	enqueue(2);
	cout << "num of elem: " << numOfElement() << endl;
	enqueue(3);
	cout << "num of elem: " << numOfElement() << endl;
	enqueue(4);
	cout << "num of elem: " << numOfElement() << endl;
	enqueue(5);
	cout << "num of elem: " << numOfElement() << endl;

	cout << "emp:" << isEmpty() << " ful:" << isFull() << endl;

	cout<<dequeue()<<endl;
	
	//cout << "num of elem: " << numOfElement() << endl;
	
	cout << dequeue() << endl;
	//dequeue();
	enqueue(6);
	enqueue(7);

	cout << "num of elem: " << numOfElement() << endl;

	cout << "printing......" << endl;
	print();
	

	//cout<<"is found?: "<<search(3)<<endl;

	return 0;
}