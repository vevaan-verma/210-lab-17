// COMSC-210 | Lab 17 | Vevaan Verma
#include <iostream>
using namespace std;

struct Node;

/* CONSTANTS */
const int SIZE = 7;

/* FUNCTION PROTOTYPES */
void createList(Node*&);
void addNodeFront(Node*&, float);
void addNodeBack(Node*&, float);
void insertNode(Node*&, float, int);
void deleteNode(Node*&, int);
void deleteList(Node*&);
void output(Node*);

struct Node {

	float value;
	Node* next;

};

// main() is the entry point of the program
// arguments: none
// returns: int - the exit code of the program
int main() {

	Node* head = nullptr;
	int count = 0;

	// create a linked list of size SIZE with random numbers 0-99
	for (int i = 0; i < SIZE; i++) {

		int tmp_val = rand() % 100;
		Node* newVal = new Node;

		// adds node at head
		if (!head) { // if this is the first node, it's the new head

			head = newVal;
			newVal->next = nullptr;
			newVal->value = tmp_val;

		} else { // its a second or subsequent node; place at the head

			newVal->next = head;
			newVal->value = tmp_val;
			head = newVal;

		}
	}

	output(head);

	// deleting a node
	Node* current = head;
	cout << "Which node to delete? " << endl;
	output(head);
	int entry;
	cout << "Choice --> ";
	cin >> entry;

	// traverse that many times and delete that node
	current = head;
	Node* prev = head;

	for (int i = 0; i < (entry - 1); i++) {

		if (i == 0) {

			current = current->next;

		} else {

			current = current->next;
			prev = prev->next;

		}
	}

	// at this point, delete current and reroute pointers
	if (current) {  // checks for current to be valid before deleting the node

		prev->next = current->next;
		delete current;
		current = nullptr;

	}

	output(head);

	// insert a node
	current = head;
	cout << "After which node to insert 10000? " << endl;
	count = 1;

	while (current) {

		cout << "[" << count++ << "] " << current->value << endl;
		current = current->next;

	}

	cout << "Choice --> ";
	cin >> entry;

	current = head;
	prev = head;

	for (int i = 0; i < (entry); i++) {

		if (i == 0) {

			current = current->next;

		} else {

			current = current->next;
			prev = prev->next;

		}
	}

	//at this point, insert a node between prev and current
	Node* newnode = new Node;
	newnode->value = 10000;
	newnode->next = current;
	prev->next = newnode;
	output(head);

	// deleting the linked list
	current = head;

	while (current) {

		head = current->next;
		delete current;
		current = head;

	}

	head = nullptr;
	output(head);

	return 0;

}

// createList() creates a linked list of size SIZE with random numbers 0-99
// arguments: Node*& - the head of the linked list
// returns: none
void createList(Node*& head) {

	// create a linked list of size SIZE with random numbers 0-99
	for (int i = 0; i < SIZE; i++)
		addNodeFront(head, rand() % 100); // add the new node to the front of the list

}

// addNodeFront() adds a node to the front of the linked list
// arguments: Node*& - the head of the linked list, float - the value of the new node
// returns: none
void addNodeFront(Node*& head, float nodeVal) {

	Node* newNode = new Node;
	newNode->value = nodeVal;
	newNode->next = head;
	head = newNode;

}

// addNodeBack() adds a node to the back of the linked list
// arguments: Node*& - the head of the linked list, float - the value of the new node
// returns: none
void addNodeBack(Node*& head, float nodeVal) {

	Node* newNode = new Node;
	newNode->value = nodeVal;
	newNode->next = nullptr;

	// if the list is empty, the new node is the head
	if (!head) {

		head = newNode;

	} else {

		Node* current = head;

		// traverse the list to the last node
		while (current->next)
			current = current->next;

		// add the new node to the end of the list
		current->next = newNode;

	}
}

// insertNode() inserts a node into the linked list after a specified index
// arguments: Node*& - the head of the linked list, int - the index of the node to insert after
// returns: none
void insertNode(Node*& head, float nodeVal, int index) {

	// make sure the list isn't empty
	if (!head) {

		cout << "Empty list.\n";
		return;

	}

	Node* current = head;
	int count = 1;

	// traverse the list to the node to insert after
	while (current && count < index) {

		current = current->next;
		count++;

	}

	// if the index is out of bounds, output an error message
	if (!current) {

		cout << "Index out of bounds.\n";
		return;

	}

	// create the new node
	Node* newNode = new Node;
	newNode->value = nodeVal;
	newNode->next = current->next; // the new node points to the node after the current node
	current->next = newNode; // the current node points to the new node

}

void output(Node* hd) {

	if (!hd) {

		cout << "Empty list.\n";
		return;

	}

	int count = 1;
	Node* current = hd;

	while (current) {

		cout << "[" << count++ << "] " << current->value << endl;
		current = current->next;

	}

	cout << endl;

}