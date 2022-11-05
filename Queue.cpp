#include<iostream>
using namespace std;

const int maxsize = 5;
int queue[maxsize];
int front = -1;
int rear = -1;


int numOfElement() {

	return rear - front;

}

void clear() {
	front = -1;
	rear = -1;
}

bool isFull() {
	return rear == maxsize - 1;
}

bool isEmpty() {
	return (rear == -1 || rear == front);
}

void enqueue(int value) {
	if (isFull()) {
		cout<<"queue is full!!!" << endl;
	}
	else {
		rear++;
		queue[rear] = value;
	}
}

int dequeue() {
	if (!isEmpty()) {
		front++;
		int tmp = queue[front];
		return tmp;
	}
	else {
		exit(0);
	}
}



bool search(int value) {

		for (int i = front+1;i <= rear;i++) {
			if (queue[i] == value) {
				return true;
			}
		}
		return false;
}

void print() {

	for (int i = front + 1;i <= rear;i++) {
		cout << queue[i]<<" ";
	}
	cout<<endl;
}



int main() {

	/*cout << "1.enqueue a value" << endl;
	cout << "2.dequeue" << endl;
	cout << "3.is full?" << endl;
	cout << "4.is empty?" << endl;
	cout << "5.clear queue" << endl;
	cout << "6.num of elements" << endl;
	cout << "7.search for element" << endl;

	int va = 1;
	while (va != 0) {
		cout << "please enter a choice" << endl;
		cin >> va;
		switch (va) {

		case 1:
			int val;
			cout << "enter value to enqueue" << endl;
			cin >> val;
			enqueue(val);
			break;
		case 2:
			cout << dequeue() << "was dequeued from the queue" << endl;
			break;
		case 3:
			cout << "is full?: " << isFull() << endl;
			break;
		case 4:
			cout << "is empty?: " << isEmpty() << endl;
			break;
		case 5:
			cout << "clearing queue..." << endl;
			clear();
			break;
		case 6:
			cout << "number of element is: " << numOfElement() << endl;
			break;
		case 7:
			cout << "enter a value" << endl;
			int value;
			cin >> value;
			cout << "searching for element " << endl<< search(value) << endl;
			break;
		default:
			cout << "plise enter a valid choise" << endl;

			}
		}
	*/

	
	enqueue(3);
	enqueue(5);
	enqueue(4);
	enqueue(7);
	
	//cout << front+1<<endl;
	//cout << rear<<endl;
	//cout<<search(3)<<endl;
	print();

}