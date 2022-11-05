// activity:    write a function  to -->  to check if a value is in stack
// 
// if stack is full		==
//if is empty		==
// push element from user ==
// pop    ==
// clear stack ==


#include <iostream>

using namespace std;

#define maxsize 5

int stack[maxsize];
int top = -1;




int numOfElem() {

	return top + 1;

}

bool isFull() {
	if (top == maxsize-1) {
		return true;
	}
	else {
		return false;
	}
}


bool isEmpty() {
	if (top == -1) {
		return true;
	}
	else {
		return false;
	}

}
void push(int value) {
	if (!(isFull())) {
		top++;
		stack[top]=value;
			
	}
	else {
		cout << "stack is full" << endl;
	}
}

void clearStack() {

	top = -1;
}

int pop() {
	if (isEmpty()) {
		cout << "cannot pop stack is empty" << endl;
		exit(1);
	}
	else {
		int tmp = stack[top];
		top--;
		return tmp;
	}
}

bool isInStack(int number) {
	int stVal;
	for (int i= top;i > -1;i--) {
		stVal = pop();

		if (stVal == number) {

			return true;
		}

	}
	return false;
}


int main() {


	int value;

	/*cout << numOfElem() << endl;
	cout << isEmpty() << endl;
	cout << isFull() << endl;

	cout << "enter value to push" << endl;
	cin >> value;
	push(value);

	cout << pop() << endl;*/

	/*cout << "1.push a value" << endl;
	cout << "2.pop" << endl;
	cout << "3.is full?"<< endl;
	cout << "4.is empty?" << endl;
	cout << "5.clear stack\n" << endl;*/



	/*int va = 1;
	while (va != 0) {
		cout << "please enter a choice" << endl;
		cin >> va;
		switch (va) {

		case 1:
			int val;
			cout << "enter value to push" << endl;
			cin >> val;
			push(val);
			break;
		case 2:
			cout << pop()<<"was poped from the stack"<<endl;
			break;
		case 3:
			cout << "is full?: "<<isFull()<<endl;
			break;
		case 4:
			cout <<"is empty?: "<<isEmpty()<<endl;
			break;
		case 5:
			cout << "clearing stack..." << endl;
			clearStack();
			break;
		case 6:
			cout << "number of element" << endl;
			cout << "number of element is: " << numOfElem() << endl;
			break;
		default:
			cout << "plise enter a valid choise" << endl;


		}




	}*/
	


	push(2);
	push(4);
	push(3);
	push(7);

	int num;
	cout << "enter a value to check if it is in stack: " << endl;
	cin >> num;

	cout << "is your value in stack: " << isInStack(num) << endl;
	cout << pop();

}
