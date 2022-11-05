#include<iostream>

using namespace std;



struct node {
	int value;
	node* next;
};

bool isEmpty(node* list) {
	return list == NULL;
}


node* insertF(node* list, int val) {
	node* newNode = new node;
	newNode->value = val;
	newNode->next = list;
	return newNode;
}


node* insertL(node* list, int val) {
	node* newNode = new node;
	newNode->value = val;
	newNode->next = NULL;


	if (list == NULL) {
		list = newNode;
		return list;
	}
	else {

		node* current = list;

		while (current->next != NULL) {

			current = current->next;
		}

		current->next = newNode;

		return list;

	}
} 


node* insertAfterX(node* list, int val,int x) {
	node* r = list; 
	node* temp = new node;
	temp->value = val;


		while (r != NULL) {

			if (r->value == x) {
				temp->next = r->next;
				r->next = temp;
				break;
			}
			r = r->next;
		}
		return list;
}


node* deleteFirst(node* list) {
	if (isEmpty(list)) {
		cout << "list is empty" << endl;
		exit(0);
	}
	else {
		return list->next;
	}

}


node* deleteLast(node* list) {
	if (isEmpty(list)) {
		cout << "list is empty" << endl;
		exit(0);
	}
	if (list->next == NULL) {
		return NULL;
	}
	else {
		node* prevNode = NULL;
		node* temp = list;
		while (temp->next != NULL) {
			prevNode = temp;
			temp = temp->next;
		}

		prevNode->next = temp->next;
		return list;
	}

}


node* deleteVal(node* list,int val) {
	if (isEmpty(list)) {
		cout << "list is empty" << endl;
		exit(0);
	}
	else{

		node* current = list;
		node* prev = list;

		while (current != NULL) {

			if (current->value == val) {

				if (current == list) {
					list = current->next;
					break;
				}
				else {
					prev->next = current->next;
					break;
				}


			}
			else {
				prev = current;
				current = current->next;
			}

		}

		return list;
	}

}


void display(node* list) {
	if (isEmpty(list)) {
		cout << "list is empty" << endl;
		exit(0);
	}
	else {
		while (list != NULL) {

			cout << list->value << "->";
			list = list->next;

		}
		if (list == NULL) {
			cout << "NULL";
		}

		cout << endl;
	}
}


int size(node* list) {
	if (isEmpty(list)) {
		return 0;
	}
	else {
		int count = 0;
		while (list != NULL) {
			count++;
			list = list->next;
		}
		return count;
	}
}


bool isContain(node* list,int value) {
	if (isEmpty(list)) {
		return false;
	}
	else {
		while (list != NULL) {

			if (list->value == value) {
				return true;
			}
			list = list->next;
		}
		return false;
	}
}


int firstElement(node *list){
	if (isEmpty(list)) {
		cout << "Empty list\n";
		exit(0);
	}
	else {
		return list->value;
	}
}


int lastElement(node* list) {
	if (isEmpty(list)) {
		cout << "Empty list\n";
		exit(0);
	}
	else {

		while (list->next != NULL) {

			list = list->next;
		}
		return list->value;
	}

}


int beforeElement(node* list, int val) {
	if (isEmpty(list)) {
		cout << "Empty list\n";
		exit(0);
	}
	else {
		while (list->next != NULL) {

			if (list->next->value == val) {
				return list->value;
			}
			list = list->next;
		}
		cout << "given value not found" << endl;
		exit(0);
	}
}


int afterElement(node* list, int val) {
	if (isEmpty(list)) {
		cout << "Empty list\n";
		exit(0);
	}
	else {

		while (list->next != NULL) {

			if (list->value == val) {
				return list->next->value;
			}
			list = list->next;
		}
		cout << "given value not found" << endl;
		exit(0);
	}
}


bool isFirstElement(node* list, int val) {
	if (isEmpty(list)) {
		cout << "Empty list\n";
		exit(0);
	}
	else {
		return list->value==val;
	}

}


bool isLastElement(node* list, int val) {
	if (isEmpty(list)) {
		cout << "Empty list\n";
		exit(0);
	}
	else {

		while (list->next != NULL) {
			list = list->next;
		}
		return list->value == val;
	}
}


node* replaceElement(node* list, int value, int reValue) {
	if (isEmpty(list)) {
		cout << "Empty list\n";
		exit(0);
	}
	else {

		// replace by creating a newNode
		
		node* newNode = new node;
		newNode->value = reValue;
		newNode->next = NULL;


		if (list->value == value) {
			
			newNode->next = list->next;              //              ___strange___!!!!
			return newNode;
			
		}

		else {
			node* temp = list;
			node* prevNode = NULL;

			while (temp != NULL) {

				if (temp->value == value) {
					newNode->next = temp->next;
					prevNode->next = newNode;
					
					return list;
				}
				prevNode = temp;
				temp = temp->next;
			}
			cout << "element not in list" << endl;
			return list;
		}

		
		//node* temp = list;

		//while (temp != NULL) {	// only changing the value

		//	if (temp->value == value) {
		//		temp->value = reValue;
		//		return list;
		//	}
		//	temp = temp->next;
		//}
		//
		//cout << "value not in list" << endl;
		//return list;
	}

}


node* revers(node* list) {

	node* current = list;
	node* prev = NULL;
	node* nextt=NULL;

	while (current != NULL) {
		nextt = current->next;

		current->next = prev;

		prev = current;
		current = nextt;
		
		
	}
	return prev;
}


int main() {

	node* head = NULL;
	node* me = NULL;
	me = insertF(me, 3);
	me = insertF(me, 2);
	
	//me = deleteLast(me);
	
	head = insertF(head, 300);
	head = insertF(head, 21);
	head = insertF(head, 3);
	head = insertF(head, 4);
	head = insertF(head, 8);
	head = insertF(head, 22);
	head = insertF(head, 111);
	head = insertAfterX(head, 999, 4);
	//head = deleteFirst(head);

	//cout << isFirstElement(head,3000)<< endl;
	//head = replaceElement(head,111, 44);
	//me = replaceElement(me,1, 44);
	

	display(head);
	//head = swapElement(head, 3, 8);   // problem with swap
	//me=revers(me);
	//display(head);
	display(me);
	
	

	delete head;
	delete me;

	return 0;
}
