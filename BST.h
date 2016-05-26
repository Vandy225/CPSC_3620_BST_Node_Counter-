#ifndef BST_H
#define BST_H

#include "BSTNode.h"
#include "Dictionary.h"
#include <iostream>


// Binary Search Tree implementation for the Dictionary ADT
template <typename Key, typename E>
   class BST : public Dictionary<Key,E>, public BSTNode<Key,E>
   {

  private:
      BSTNode<Key,E>*root; // Root of the BST
      int nodecount; // Number of nodes in the BST
// Private "helper" functions

  public:


      //getter function for root of BST
      BSTNode<Key, E>* getRoot(){
	 return this->root;
      }

      //clear helper function
      void clearhelp(BSTNode<Key, E>*root) {
	 if (root == nullptr) return;
	 clearhelp(root->left());
	 clearhelp(root->right());
	 delete root;
      }

      //void printhelp(BSTNode<Key, E>*, int) const;

      void printhelp(BSTNode<Key, E>*root, int level) const
      {
	 if (root == nullptr) return; // Empty tree
	 printhelp(root->left(), level+1); // Do left subtree
	 for (int i=0; i<level; i++) // Indent to level
	    std::cout << " ";
	 std::cout << root->key() << "\n"; // Print node value
	 printhelp(root->right(), level+1); // Do right subtree
      }



      BST() { root = nullptr; nodecount = 0; } // Constructor

      ~BST() { clearhelp(root); } // Destructor

      void clear() // Reinitialize tree
      { clearhelp(root); root = nullptr; nodecount = 0; }


// Insert a record into the tree.
// k Key value of the record.
// e The record to insert.
      void insert(const Key& k, const E& e) {
	 root = inserthelp(root, k, e);
	 nodecount++;
      }


// Return the number of records in the dictionary.
	 int size() { return nodecount; }
	 void print() const { // Print the contents of the BST
	    if (root == nullptr) std::cout << "The BST is empty.\n";
	    else printhelp(root, 0);
	 }

	 BSTNode<Key, E>* inserthelp(BSTNode<Key, E>*root, const Key& k, const E& it)
	 {
	    if (root == nullptr) // Empty tree: create node
	       return new BSTNode<Key, E>(k, it, nullptr, nullptr);
	    if (k < root->key())
	       root->setLeft(inserthelp(root->left(), k, it));
	    else root->setRight(inserthelp(root->right(), k, it));
	    return root; // Return tree with node inserted
	 }

	 //function that counts all the nodes in a BST
	 int countAllNodes (BSTNode<Key,E>* root)
	 {
	    if (root != nullptr)
	    {
	       return 1 + countAllNodes(root->left()) + countAllNodes(root->right());
	    }
	    else {
	       return 0;
	    }
	 }

	 //function that counts all the leaf nodes in a BST
	 int countAllLeaves (BSTNode<Key,E>* root)
	 {
	    //stops the recursion
	    if (root == nullptr)
	    {
	       return 0;
	    }
	    //make sure node is a leaf by making sure that
	    if (root->left() == nullptr && root->right() == nullptr)
	    {
	       //add 1 to the running recursive total
	       return 1;
	    }
	    //return the result of the left subtree and right subtree
	    return countAllLeaves(root->left()) + countAllLeaves(root->right());
	 }

	 //function to count all the full nodes in a BST
	 int countFullNodes(BSTNode<Key, E>* root)
	 {
	    //stops the recursion
	    if (root == nullptr)
	    {
	       return 0;
	    }
	    //if both children are null, it is not a full node, return 0
	    if (root->left() == nullptr && root->right() == nullptr)
	    {
	       return 0;
	    }
	    //if the right and left child are not null, return 1 to recursive total
	    if (root->left() != nullptr && root->right() != nullptr)
	    {
	       return 1;
	    }

	    //return the result
	    return countFullNodes(root->left()) + countFullNodes(root->right());



	 }
};

#endif
