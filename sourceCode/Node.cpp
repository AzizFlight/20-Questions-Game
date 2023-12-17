/* Node.cpp */



#include<iostream>
#include<stdlib.h>

#include "Node.h"


// ======================================================================
Node::Node()					// Default CTOR
{		
	this->Qthing = DEFAULT_TEXT;
		
	this->left  = 0;			//make left and right point to NULL
	this->right = 0;
	
}// CTOR

// ======================================================================
Node::Node(const string text)	// CTOR when text is known
{
	this->Qthing = text;		
	this->left  = 0;			// make left and right point to NULL
	this->right = 0;
	
}// CTOR

// ======================================================================
Node::Node(const Node& old)		// COPY CTOR 
{
	this->Qthing = old.Qthing;
		
	this->left  = old.left;		// new copy still points to the same children!
	this->right = old.right;
	
}// COPY CTOR

// ======================================================================
Node::~Node()	// DTOR
{
	// Tree DTOR does the work ...
	
}


// ======================================================================
// ---------- SETTERS ------------------------

void Node::StoreText(const string /*in*/ newText)
{
	this->Qthing = newText;
														
}// StoreText

// ======================================================================
void Node::AppendRight(Node* /*in*/ newNode)
{
	this->right = newNode;

}// AppendRight


// ======================================================================
void Node::AppendLeft(Node* /*in*/ newNode)
{

    this->left = newNode;



}// AppendLeft


// ======================================================================
// ---------- GETTERS ------------------------

string Node::GetText() const
{
	return this->Qthing;		// return the text of current node
}// GetText


// ======================================================================
Node* Node::LChild() const
{

    return this->left;
	
}// LChild


// ======================================================================
Node* Node::RChild() const
{
	
    return this->right;
	
}// RChild


// ======================================================================
bool Node::IsLeaf() const
{
	
	if(right == 0 and left == 0){ // if the node has no children
        return true; // it is a leaf
    }
    else{  // otherwise it is not a leaf
        return false;
    }

	
}// IsLeaf


char Node::getYesOrNo()
{
    string answer = ""; //  to store the user input
    while (answer != "y" and answer != "n") // if the answer is not "y" or "n", do not accept it
    {
        getline(cin, answer);
        answer = tolower(answer[0]);  //  turn the letter to lower case
    }
    return answer[0];
} // getYesOrNo end


void Node::ifQuestion() {

    if(!this->IsLeaf()){  // if not a leaf, it is a question
        cout << this->Qthing << endl;  //  start the game by asking the 1st question
        cout << "Please enter 'y' for yes and 'n' for no" << endl;
        char answer = getYesOrNo();  //  get the answer

        if(answer == 'y'){  //  if yes
            this->left->ifQuestion();  // go to the left child
        } //  f(answer == 'y')
        else if(answer == 'n'){  //  if no
            this->right->ifQuestion();  //  go to the right child
        } //  else if(answer == 'n')
    }  //  if(!this->IsLeaf())

    else{
        this->ifObject();
    }  //  else


} //  void Node::ifQuestion

void Node::ifObject() {

    cout << "Are you thinking of " << this->Qthing << "?" << endl; //  the computer is ready to make a guess
    cout << "Please enter 'y' for yes and 'n' for no" << endl;

    char answer = getYesOrNo();  //  get answer from the user if the guess is correct

    if(answer == 'y'){  //  if yes
        cout << "The computer wins!"; //  YAY!!
    }
    else{  //  if no

        this->ifComputerLoses();  //  Call this function to train the computer

    }

}

void Node::ifComputerLoses() {

    cout << "You win! What did you think of?" << endl;
    string newObject; //  store the user's answer
    getline(cin, newObject);
    cout << "Please write a question that distinguishes " << newObject << " from " << this->Qthing << endl;
    string newQuestion;  //  store the new question
    getline(cin, newQuestion);
    cout << "In case you were thinking of a " << newObject << ", what would the answer to that question be?" << endl;
    char answer = getYesOrNo(); //  store the answer

    if(answer == 'y'){  //  if the answer is yes
        this->left = new Node(newObject);  //  arrange the children accordingly
        this->right = new Node(this->Qthing);
    }
    else if(answer == 'n'){  //  if the answer is no
        this->right = new Node(newObject);  //  arrange the children in the opposite way
        this->left = new Node(this->Qthing);
    }

    this->StoreText(newQuestion);  //  store the new question in the node instead of the wrong object
    cout << "Tree successfully updated!";

}


// ======================================================================
// OUTPUT a Node object (show children, if any)
ostream& operator<< ( ostream& OUT, const Node& aNode ) {

    OUT << "----------------------------" << endl;
    OUT << "  " << aNode.GetText() << endl;
    if (aNode.LChild() != 0) {
        cout << "   /         \\" << endl;
        cout << aNode.LChild()->GetText();
    }
    if (aNode.RChild() != 0) {
        cout << "           " << aNode.RChild()->GetText() << endl;
    }
    OUT << "-----------------------------" << endl;
    return OUT;
}