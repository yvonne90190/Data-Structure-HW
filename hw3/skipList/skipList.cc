// https://www.geeksforgeeks.org/skip-list-set-3-searching-deletion/
// https://cs.stackexchange.com/questions/75691/should-one-limit-the-maximum-level-of-a-skip-list-node (Explain how I set MAXLVL)
// C++ code for searching and deleting element in skip list

#include <bits/stdc++.h>
#include <fstream> //file
//#include <tgmath.h> //pow() 
#include <cmath>
#include<time.h>
#include<stdlib.h>
using namespace std;

// Class to implement node
class Node
{
public:
	int key;

	// Array to hold pointers to node of different level
	Node **forward;
	Node(int, int);
};

Node::Node(int key, int level)
{
	this->key = key;

	// Allocate memory to forward
	forward = new Node*[level+1];

	// Fill forward array with 0(NULL)
	memset(forward, 0, sizeof(Node*)*(level+1));
};

// Class for Skip list
class SkipList
{
	// Maximum level for this skip list
	int MAXLVL;

	// P is the fraction of the nodes with level
	// i pointers also having level i+1 pointers
	float P;

	// current level of skip list
	int level;

	// pointer to header node
	Node *header;
public:
	SkipList(int, float);
	int randomLevel();
	Node* createNode(int, int);
	void insertElement(int);
	void deleteElement(int);
	void searchElement(int);
	void displayList();
};

SkipList::SkipList(int MAXLVL, float P)
{
	this->MAXLVL = MAXLVL;
	this->P = P;
	level = 0;

	// create header node and initialize key to -1
	header = new Node(-1, MAXLVL);
};

// create random level for node
int SkipList::randomLevel()
{
	float r = (float)rand()/RAND_MAX;
	int lvl = 0;
	while(r < P && lvl < MAXLVL)
	{
		lvl++;
		r = (float)rand()/RAND_MAX;
	}
	return lvl;
};

// create new node
Node* SkipList::createNode(int key, int level)
{
	Node *n = new Node(key, level);
	return n;
};

// Insert given key in skip list
void SkipList::insertElement(int key)
{
	Node *current = header;

	// create update array and initialize it
	Node *update[MAXLVL+1];
	memset(update, 0, sizeof(Node*)*(MAXLVL+1));

	/* start from highest level of skip list
		move the current pointer forward while key
		is greater than key of node next to current
		Otherwise inserted current in update and
		move one level down and continue search
	*/
	for(int i = level; i >= 0; i--)
	{
		while(current->forward[i] != NULL &&
			current->forward[i]->key < key)
			current = current->forward[i];
		update[i] = current;
	}

	/* reached level 0 and forward pointer to
	right, which is desired position to
	insert key.
	*/
	current = current->forward[0];

	/* if current is NULL that means we have reached
	to end of the level or current's key is not equal
	to key to insert that means we have to insert
	node between update[0] and current node */
	if (current == NULL || current->key != key)
	{
		// Generate a random level for node
		int rlevel = randomLevel();

		/* If random level is greater than list's current
		level (node with highest level inserted in
		list so far), initialize update value with pointer
		to header for further use */
		if(rlevel > level)
		{
			for(int i=level+1;i<rlevel+1;i++)
				update[i] = header;

			// Update the list current level
			level = rlevel;
		}

		// create new node with random level generated
		Node* n = createNode(key, rlevel);

		// insert node by rearranging pointers
		for(int i=0;i<=rlevel;i++)
		{
			n->forward[i] = update[i]->forward[i];
			update[i]->forward[i] = n;
		}
		//cout<<"Successfully Inserted key "<<key<<"\n";
	}
};

// Delete element from skip list
void SkipList::deleteElement(int key)
{
	Node *current = header;

	// create update array and initialize it
	Node *update[MAXLVL+1];
	memset(update, 0, sizeof(Node*)*(MAXLVL+1));

	/* start from highest level of skip list
		move the current pointer forward while key
		is greater than key of node next to current
		Otherwise inserted current in update and
		move one level down and continue search
	*/
	for(int i = level; i >= 0; i--)
	{
		while(current->forward[i] != NULL &&
			current->forward[i]->key < key)
			current = current->forward[i];
		update[i] = current;
	}

	/* reached level 0 and forward pointer to
	right, which is possibly our desired node.*/
	current = current->forward[0];

	// If current node is target node
	if(current != NULL and current->key == key)
	{
		/* start from lowest level and rearrange
		pointers just like we do in singly linked list
		to remove target node */
		for(int i=0;i<=level;i++)
		{
			/* If at level i, next node is not target
			node, break the loop, no need to move
			further level */
			if(update[i]->forward[i] != current)
				break;

			update[i]->forward[i] = current->forward[i];
		}

		// Remove levels having no elements
		while(level>0 &&
			header->forward[level] == 0)
			level--;
		//cout<<"Successfully deleted key "<<key<<"\n";
	}
};

// Search for element in skip list
void SkipList::searchElement(int key)
{
	Node *current = header;

	/* start from highest level of skip list
		move the current pointer forward while key
		is greater than key of node next to current
		Otherwise inserted current in update and
		move one level down and continue search
	*/
	for(int i = level; i >= 0; i--)
	{
		while(current->forward[i] &&
			current->forward[i]->key < key)
			current = current->forward[i];

	}

	/* reached level 0 and advance pointer to
	right, which is possibly our desired node*/
	current = current->forward[0];

	// If current node have key equal to
	// search key, we have found our target node
//	if(current and current->key == key)
		//cout<<"Found key: "<<key<<"\n";
};

// Display skip list level wise
void SkipList::displayList()
{
	cout<<"\n*****Skip List*****"<<"\n";
	for(int i=0;i<=level;i++)
	{
		Node *node = header->forward[i];
		cout<<"Level "<<i<<": ";
		while(node != NULL)
		{
			cout<<node->key<<" ";
			node = node->forward[i];
		}
		cout<<"\n";
	}
};

void InsertRandNum(SkipList& t, int kN, int kRandNum) 
{
	for(int s=0; s<kN; s++) // repeat kN times
	{
		int no = rand()%kRandNum; // choose an random num from 1 to kRandNum
		t.insertElement(no);  // insert the number into the data structure
	}
}

void SerchRandNum(SkipList& t, int kRandNum)
{
	for(int s=0; s<1000000; s++)  // repeat 1000,000 times
	{
		int no = rand()%kRandNum;  // choose an random num from 1 to kRandNum
		t.searchElement(no); // search the number in the data structure
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

	// create SkipList object with MAXLVL and P
	int maxLvl = int (log2(pow(2.0, kExp))) / int (log2(pow(0.5, -1)));
	//int maxLvl = 1000000;
	SkipList lst(maxLvl, 0.5);
	startInsert = clock();
	InsertRandNum(lst, pow(2.0, kExp), pow(2.0, 30));
	endInsert = clock();
	durationInsert = (double) (endInsert-startInsert) / CLOCKS_PER_SEC;
	ofs << "Insert" << "," << kExp << "," << durationInsert << ",";
	
	// search a random num in the data structure	
	startSearch = clock();
	SerchRandNum(lst, pow(2.0, 30));
	endSearch = clock();
	durationSearch = (double) (endSearch-startSearch) / CLOCKS_PER_SEC;
	ofs << "Search" << "," << kExp << "," << durationSearch << endl;
	
	// close the file
	ofs.close();
	return 0;
}
