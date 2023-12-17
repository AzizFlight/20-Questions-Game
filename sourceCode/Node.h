/* node.h */



#ifndef NODE
#define NODE

#include "constants.h"

class Node         		
{
  public:
	Node();				// default CTOR
	Node(string);		// CTOR when string is known
	
	Node(const Node&);  // COPY CTOR
	
	~Node();			// DTOR
    
    // ---------- SETTERS ------------------------
	void StoreText(const string /*in*/ newText);
	//..........................................
	// PRE:   newText is a valid string
	// POST:  node contains the string in it

	void AppendRight(Node* /*in*/ newNode);
	//..........................................
	// PRE: Assigned(newNode)
	// POST: this-> node has a new right child


	void AppendLeft(Node* /*in*/ newNode);
	//..........................................
	// PRE: Assigned(newNode)
	// POST: this-> node has a new left child



	// ---------- GETTERS ------------------------
	string GetText() const;
	//..........................................
	// POST: RETURN == string in current node

	Node* LChild() const;
	//..........................................
	// PRE: this != NULL
	// POST: RETURN == pointer to left node

	Node* RChild() const;
	//..........................................
	// PRE: this != NULL
	// POST: RETURN == pointer to right node


	// ---------- QUERIES ------------------------
	bool IsLeaf() const;
	//..........................................
	// PRE: this != NULL
	// POST: RETURN T/F whether or not this-> is a leaf node


    char getYesOrNo();
    // PRE: User enters a string from keyboard
    // POST: returns char 'y' or 'n' and keeps repeating the question if the user enters a wrong value.

    void ifQuestion();
    // PRE: this != NULL and functions getYesOrNO and IsLeaf() work
    // POST: prompts the user with the question stored in the node and asks for an answer, and if the node
    // does not store a question, it calls ifObject() function

    void ifObject();
    // PRE: this != NULL and functions getYesOrNO and IfComputerLoses() work
    // POST: asks the user if they were thinking of a certain object based on their answer, and if the computer loses,
    // it calls IfComputerLoses


    void ifComputerLoses();
    // PRE: this != NULL and function getYesOrNO works
    // POST: takes the new object and new question and the answer to it and updates the tree with this info

    friend ostream& operator<<( ostream& output, const Node& aNode);
  
  private:
	 Node* left;	// pointer to a left  child node
	 Node* right;	// pointer to a right child node
	 
	 string Qthing;	// question at a node OR if a leaf node the name of an object
	
}; // class Node


#endif






