//https://www.geeksforgeeks.org/implementation-of-search-insert-and-delete-in-treap/
// C++ program to demonstrate search, insert and delete in Treap
#include <bits/stdc++.h>
#include <fstream> //file
#include <cmath>
#include<time.h>
#include<stdlib.h>
using namespace std;

// A Treap Node
struct TreapNode
{
	int key, priority;
	TreapNode *left, *right;
};

/* T1, T2 and T3 are subtrees of the tree rooted with y
(on left side) or x (on right side)
				y							 x
			/ \	 Right Rotation		 / \
			x T3 – – – – – – – >	 T1 y
			/ \	 < - - - - - - -		 / \
			T1 T2	 Left Rotation		 T2 T3 */

// A utility function to right rotate subtree rooted with y
// See the diagram given above.
TreapNode *rightRotate(TreapNode *y)
{
	TreapNode *x = y->left, *T2 = x->right;

	// Perform rotation
	x->right = y;
	y->left = T2;

	// Return new root
	return x;
}

// A utility function to left rotate subtree rooted with x
// See the diagram given above.
TreapNode *leftRotate(TreapNode *x)
{
	TreapNode *y = x->right, *T2 = y->left;

	// Perform rotation
	y->left = x;
	x->right = T2;

	// Return new root
	return y;
}

/* Utility function to add a new key */
TreapNode* newNode(int key)
{
	TreapNode* temp = new TreapNode;
	temp->key = key;
	temp->priority = rand()%100;
	temp->left = temp->right = NULL;
	return temp;
}

// C function to search a given key in a given BST
TreapNode* search(TreapNode* root, int key)
{
	// Base Cases: root is null or key is present at root
	if (root == NULL || root->key == key)
	return root;

	// Key is greater than root's key
	if (root->key < key)
	return search(root->right, key);

	// Key is smaller than root's key
	return search(root->left, key);
}

/* Recursive implementation of insertion in Treap */
TreapNode* insert(TreapNode* root, int key)
{
	// If root is NULL, create a new node and return it
	if (!root)
		return newNode(key);

	// If key is smaller than root
	if (key <= root->key)
	{
		// Insert in left subtree
		root->left = insert(root->left, key);

		// Fix Heap property if it is violated
		if (root->left->priority > root->priority)
			root = rightRotate(root);
	}
	else // If key is greater
	{
		// Insert in right subtree
		root->right = insert(root->right, key);

		// Fix Heap property if it is violated
		if (root->right->priority > root->priority)
			root = leftRotate(root);
	}
	return root;
}

/* Recursive implementation of Delete() */
TreapNode* deleteNode(TreapNode* root, int key)
{
	if (root == NULL)
		return root;

	if (key < root->key)
		root->left = deleteNode(root->left, key);
	else if (key > root->key)
		root->right = deleteNode(root->right, key);

	// IF KEY IS AT ROOT

	// If left is NULL
	else if (root->left == NULL)
	{
		TreapNode *temp = root->right;
		delete(root);
		root = temp; // Make right child as root
	}

	// If Right is NULL
	else if (root->right == NULL)
	{
		TreapNode *temp = root->left;
		delete(root);
		root = temp; // Make left child as root
	}

	// If key is at root and both left and right are not NULL
	else if (root->left->priority < root->right->priority)
	{
		root = leftRotate(root);
		root->left = deleteNode(root->left, key);
	}
	else
	{
		root = rightRotate(root);
		root->right = deleteNode(root->right, key);
	}

	return root;
}

// A utility function to print tree
void inorder(TreapNode* root)
{
	if (root)
	{
		inorder(root->left);
		cout << "key: "<< root->key << " | priority: %d "
			<< root->priority;
		if (root->left)
			cout << " | left child: " << root->left->key;
		if (root->right)
			cout << " | right child: " << root->right->key;
		cout << endl;
		inorder(root->right);
	}
}

void InsertRandNum(struct TreapNode* root, int kN, int kRandNum) 
{
	for(int s=0; s<kN; s++) // repeat kN times
	{
		int no = rand()%kRandNum; // choose an random num from 1 to kRandNum
		root = insert(root, no); // insert the number into the data structure
	}
}

void SerchRandNum(struct TreapNode* root, int kRandNum)
{
	for(int s=0; s<1000000; s++) // repeat 1000,000 times
	{
		int no = rand()%kRandNum; // choose an random num from 1 to kRandNum
		TreapNode *res = search(root, no); // search the number in the data structure
	}
}

int main(int argc, char *argv[]) {
	// open file to write the data
	ofstream ofs;
	ofs.open("Result.csv", ofstream::app);
	int kExp = atoi(argv[1]);
	time_t startInsert, endInsert;
	time_t startSearch, endSearch;
	double durationInsert=0.0, durationSearch;
	srand(time(NULL));

	// make the input array with random variable
	//BTree t(2);
	struct TreapNode *root = NULL;
	startInsert = clock();
	InsertRandNum(root, pow(2.0, kExp),  pow(2.0, 30));
	endInsert = clock();
	durationInsert = (double) (endInsert-startInsert) / CLOCKS_PER_SEC;
	ofs << "Insert" << "," << kExp << "," << durationInsert << ",";
	
	// search a random num in the data structure	
	startSearch = clock();
	SerchRandNum(root,  pow(2.0, 30));
	endSearch = clock();
	durationSearch = (double) (endSearch-startSearch) / CLOCKS_PER_SEC;
	ofs << "Search" << "," << kExp << "," << durationSearch << endl;
	
	// close the file
	ofs.close();
	return 0;
}
