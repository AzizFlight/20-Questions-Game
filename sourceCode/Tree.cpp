
#include <iostream>
#include <stdlib.h>

#include "Tree.h"

// ======================================================================
Tree::Tree()			    					//CTOR
//..........................................
//POST: new tree is created with a root
{
	this->root = new Node;
	
	// NOTE:  we must use the functions in the Node class to change things!
	root->AppendLeft( 0 );
	root->AppendRight( 0 );
}//CTOR


// ======================================================================
Tree::Tree(string questionText, string leftObject, string rightObject)
//..........................................
//POST: new tree is created with a root with known question and left/right objects
{
	this->root = new Node(questionText);
	
	// NOTE:  we must use the functions in the Node class to change things!
	root->AppendLeft( new Node(leftObject) );
	root->AppendRight( new Node(rightObject) );
}//CTOR


// ======================================================================
Tree::~Tree()								//DTOR
{


    deleteTree(root); //  Call deleteTree function
	
	
} //DTOR
	
	
// ======================================================================
bool Tree::IsEmpty(void) const
//..........................................
//POST: RETURN == whether or not the root node has children
{
	return (root->RChild() == 0  &&  root->LChild() == 0 );
}// IsEmpty


// ======================================================================
Node* Tree::GetRoot(void) const
//..........................................
//POST: RETURN == address of root node
{
	return root;
}// GetRoot


void Tree::ifQuestion() const{

    this->root->ifQuestion();  //  Calls the ifQuestion() method in the Node class

}


void Tree::deleteTree(Node* node){

    if(!node->IsLeaf()){  //  Do not delete a node until it is a leaf
        deleteTree(node->LChild());
        deleteTree(node->RChild());

    }



    delete node;


}



