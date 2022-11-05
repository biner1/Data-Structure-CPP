#include<iostream>
using namespace std;


struct node {

	int value;
	node* left;
	node* right;
};


node* insert(node* tree,int val) {

	if (tree == NULL) {
		tree = new node;
		tree->value = val;
		tree->right = NULL;
		tree->left = NULL;
	}
	else if (tree->value > val) {
		tree->left = insert(tree->left, val);
	}
	else {
		tree->right = insert(tree->right, val);
	}
	return tree;
}


void inOrder(node *tree) {
	
	if (tree != NULL) {

		inOrder(tree->left);
		cout << " " << tree->value;
		inOrder(tree->right);

	}

}


void preOrder(node* tree) {

	if (tree != NULL) {

		cout << " " << tree->value;
		preOrder(tree->left);
		preOrder(tree->right);

	}
}


void postOrder(node* tree) {

	if (tree != NULL) {

		postOrder(tree->left);
		postOrder(tree->right);
		cout << " " << tree->value;

	}
}


bool search(node* tree, int val) {

	if (tree == NULL) {
		return false;
	}
	else if (tree->value == val) {
		return true;
	}
	else if (tree->value < val) {
		search(tree->right, val);
	}
	else {
		search(tree->left, val);
	}

}


node* findMin(node* tree) {

	while (tree->left != NULL) {
		tree = tree->left;
	}
	return tree;
}


node* findMax(node* tree) {
	
	while (tree->right != NULL) {
		tree = tree->right;
	}
	return tree;
}


node* Delete(node* tree, int val) {

	if (tree == NULL) {
		return tree;
	}
	else if (val < tree->value) {
		tree->left = Delete(tree->left, val);
	}
	else if (val > tree->value) {
		tree->right = Delete(tree->right, val);
	}
	else {
		if (tree->left == NULL && tree->right == NULL) { // tree has no left and right node: no child
			tree = NULL;
		}
		// it it has one child
		else if (tree->left == NULL) { //if left child is null
			tree = tree->right;
			tree->right = Delete(tree->right, val);
		}
		else if (tree->right == NULL) {// if right child is null
			tree = tree->left;
			tree->left = Delete(tree->left, val);
		}

		else { // if it has both left and right child
			node* temp = findMin(tree->right);
			tree->value = temp->value;
			tree->right = Delete(tree->right, temp->value);

		}

	}
	return tree;
}


int main() {

	node* root=NULL;


	/*root = insert(root, 30);
	root = insert(root, 23);
	root = insert(root, 7);
	root = insert(root, 8);
	root = insert(root, 4);
	root = insert(root, 87);
	root = insert(root, 65);
	root = insert(root, 40);*/

	/*root = insert(root, 44);
	root = insert(root, 2);
	root = insert(root, 51);
	root = insert(root, 5);
	root = insert(root, 0);
	root = insert(root, 20);					// this is the lab assign ment

	postOrder(root);
	root = Delete(root, 44);
	
	cout << "\n";

	inOrder(root);
	cout << "\n";
	preOrder(root);
	cout << "\n";
	postOrder(root);
	cout << "\n";*/


	//cout << search(root, 87) << endl;

	//node* min = findMin(root);
	//cout << min->value << endl;

	//node* max = findMax(root);
	//cout << max->value << endl;
	
	//root = Delete(root, 7);
	//inOrder(root);


	return 0;
}