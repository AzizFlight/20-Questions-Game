
#ifndef TREE
#define TREE


#include "Node.h"


class Tree
{
	public:
	
		Tree();													// Default CTOR
		//..........................................
		//POST: new tree is created with a root
		
		
		Tree(string questionText, string leftObject, string rightObject);	// CTOR when root info is known
		//..........................................
		//POST: new tree is created with a root with text questionText, plus two children:
		//		right child has text of rightObject, and left child has text of leftObject
		
		
		~Tree();												// DTOR
		//..........................................
		//POST: entire tree is deleted/freed and all dynamic memory cleared
		
		
		bool IsEmpty(void) const;
		//..........................................
		//POST: RETURN T/F whether or not the root node of the Tree has children


		Node* GetRoot(void) const;
		//..........................................
		//POST: RETURN == address of root node



        void ifQuestion() const;
        // PRE: this != NULL and the node class methods work
        // POST: calls the ifQuestion method in the Node class

        void deleteTree(Node* node);
        // PRE: the Node class works. node = a pointer to a Node object
        // POST: takes the argument node as the root and deletes everything under it



	private:
		Node* root;    // pointer to root node of tree
		
};// class Tree

#endif

