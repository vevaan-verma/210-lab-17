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

	createList(head); // create a linked list of size SIZE with random numbers 0-99
	output(head); // output the linked list
	cout << "----------------------------------" << endl; // output a line for formatting purposes

	// NODE DELETION
	// prompt the user for the index of the node to delete
	cout << "Which node to delete? " << endl;
	output(head);
	int entry;
	cout << "Choice --> ";
	cin >> entry;

	cout << endl; // output blank line for formatting purposes
	deleteNode(head, entry); // delete the node at the specified index
	output(head); // output the linked list
	cout << "----------------------------------" << endl; // output a line for formatting purposes

	// NODE INSERTION
	// prompt the user for the index of the node to insert after
	cout << "After which node to insert 10000? " << endl;
	output(head);
	cout << "Choice --> ";
	cin >> entry;

	cout << endl; // output blank line for formatting purposes
	insertNode(head, 10000, entry); // insert the node with value 10000 after the specified index
	output(head); // output the linked list
	cout << "----------------------------------" << endl; // output a line for formatting purposes

	// LIST DELETION
	cout << "Deleting the linked list..." << endl;
	deleteList(head); // delete the linked list
	output(head);
	cout << "----------------------------------" << endl;

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

// deleteNode() deletes a node from the linked list
// arguments: Node*& - the head of the linked list, int - the index of the node to delete
// returns: none
void deleteNode(Node*& head, int index) {

	// make sure the list isn't empty
	if (!head) {

		cout << "Empty list.\n";
		return;

	}

	Node* current = head; // start at the head of the list
	Node* prev = nullptr;
	int count = 0;

	// traverse the list to the node before the one to delete
	while (current && count < index - 1) {

		prev = current;
		current = current->next;
		count++;

	}

	// if the index is out of bounds, output an error message
	if (!current) {

		cout << "Index out of bounds.\n";
		return;

	}

	// if the node to delete is the head, update the head
	if (!prev)
		head = current->next;
	else
		prev->next = current->next; // reroute the pointers to skip the node to delete (by pointing the previous node to the node after the current node)

	// delete the current node
	delete current;

}

// deleteList() deletes the linked list
// arguments: Node*& - the head of the linked list
// returns: none
void deleteList(Node*& head) {

	// make sure the list isn't empty
	if (!head) {

		cout << "Empty list.\n";
		return;

	}

	Node* current = head; // start at the head of the list

	while (current) {

		head = current->next; // move the head to the next node
		delete current; // delete the current node
		current = head; // move to the next node

	}

	head = nullptr; // set the head to null

}

// output() outputs the linked list to the console
// arguments: Node* - the head of the linked list
// returns: none
void output(Node* hd) {

	// make sure the list isn't empty
	if (!hd) {

		cout << "Empty list.\n";
		return;

	}

	int count = 1;
	Node* current = hd; // start at the head of the list

	// traverse the list and print each node
	while (current) { // make sure the current node exists

		cout << "[" << count++ << "] " << current->value << endl; // output the value of the current node
		current = current->next; // move to the next node

	}
}