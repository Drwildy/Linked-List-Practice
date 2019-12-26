#include <iostream>
using namespace std;

//Singly Linked List
struct Node {
	int data;
	Node* next;
};

//Doubly Linked List
struct NodeD {
	int data;
	NodeD* next;
	NodeD* prev;
};

Node* head;  //Global for simplification
NodeD* headD;

void Insert(int data, int n) { //Insert an integer at any position in a linked list
	Node* temp1 = new Node();
	temp1->data = data; //new node set data
	temp1->next = NULL; //new node next points to NULL
	if (n <= 0) {
		cout << "0 and below are outside of the scope" << endl;
		return;
	}
	if (n == 1) {		//If inserting at the beginning
		temp1->next = head;
		head = temp1;
		return;
	}
	Node* temp2 = head;
	for (int i = 0; i < n-2; i++) {
		temp2 = temp2->next;
		if (temp2->next == NULL) {
			cout << "There is no node at "<< n-1 <<"th position to be linked to." << endl;
			return;
		}
	}
	temp1->next = temp2->next;
	temp2->next = temp1;


}

void Print() { //Print all elements in the list
	Node* temp = head; //Start at head and traverse the whole list
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
	
}

//Use much more memory in the stack than a linear print, Linear can not print in reverse.
void printRecursion(Node *p) {
	if (p == NULL) return;
	cout << p->data << " "; //Print first value
	printRecursion(p->next); //Recursive call

}
void printReverseRecursion(Node *p) {
	if (p == NULL) return;
	printRecursion(p->next); //Recursive call
	cout << p->data << " "; //Print first value
}

void Delete(int n) { //Delete a node at the nth position
	Node* temp1 = head;
	if (n <= 0) {
		cout << "0 and below are outside of the scope" << endl;
		return;
	}
	if (n == 1) {
		head = temp1->next; //head now points to second node
		delete temp1; //delete first node
		return; //don't run rest of code
	}
	for (int i = 0; i < n - 2; i++) {
		temp1 = temp1->next;
		if (temp1->next == NULL) {
			cout << "There is no node at this position to be deleted." << endl;
			return;
		}
	}
	//Temp 1 points to (n-1)th node at this point
	Node* temp2 = temp1->next; //Temp2 points to nth node
	temp1->next = temp2->next; //(set n-1th next node to nth next node)
	delete temp2;
}

void Reverse() {
	Node *next, *prev, *current;
	current = head;
	prev = NULL;

	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

void ReverseRecursion(Node *p) {
	if (p->next == NULL) {
		head = p;
		return;
	}
	ReverseRecursion(p->next);
	Node* q = p->next;
	q->next = p;
	p->next = NULL;
}

//Advantages of Doubly Linked List
// We can do a forward as well as a reverse lookup if we have a pointer to any position
// Makes implementation of the operations such as deletion becomes much easier
//Disadvantages of Doubly Linked List
// Extra memory for pointer in previous node (8 bytes for pointers + bytes for data)
// Must be more careful when changing pointers and is more prone to errors

NodeD* getNewNode(int x) {
	NodeD* newNode = new NodeD();
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

void InsertAtHead(int x) {
	NodeD* newNode = getNewNode(x);
	if (headD == NULL) { //List is empty
		headD = newNode;
		return;
	}
	headD->prev = newNode;
	newNode->next = headD;
	headD = newNode;
}

void InsertAtTail(int x) {
	NodeD* newNode = getNewNode(x);
	if (headD == NULL) { //List is empty
		headD = newNode;
		return;
	}

	NodeD* temp = headD; 
	while (temp->next != NULL) { //Traverse to end of list, when Next is NULL we are at the end
		temp = temp->next;
	}

	temp->next = newNode;
	newNode->prev = temp;
}

void PrintDLL() {
	NodeD* temp = headD;
	cout << "Forward: ";
	while(temp != NULL) {
		cout << " " << temp->data;
		temp = temp->next;
	}
	cout << endl;

}
void ReversePrintDLL() {
	NodeD* temp = headD;
	if (temp == NULL) return; //List empty
	//Traverse to last Node
	while (temp->next != NULL) {
		temp = temp->next;
	}
	//Traverse backwards
	cout << "Reverse: ";
	while (temp != NULL) {
		cout << " " << temp->data;
		temp = temp->prev;
	}
	cout << endl;
}

int main() {

	//Singly Linked List
	cout << "Begin Singly Linked List" << endl;
	head = NULL; //empty list
	Insert(2, 1); // 2
	Insert(4, 2); // 2 4
	Insert(6, 1); // 6 2 4
	Insert(5, 3); // 6 2 5 4
	Insert(6, 6); // Error
	Print();	  // 6 2 5 4
	Reverse();	  // 4 5 2 6
	Print();	  // 4 5 2 6
	int n;
	cout << "Enter a position" << endl;
	cin >> n;
	Delete(n);
	Print();
	cout << "printing recursively" << endl;
	printRecursion(head);
	cout << "printing reverse recursively" << endl;
	printReverseRecursion(head);
	cout << endl;

	//Doubly Linked List
	cout << "Begin Doubly Linked List" << endl;
	InsertAtHead(2); PrintDLL(); ReversePrintDLL();
	InsertAtHead(4); PrintDLL(); ReversePrintDLL();
	InsertAtHead(6); PrintDLL(); ReversePrintDLL();
	InsertAtTail(8); PrintDLL(); ReversePrintDLL();




}



