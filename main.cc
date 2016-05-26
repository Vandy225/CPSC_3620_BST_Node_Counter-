#include "BST.h"
#include <iostream>


int main()
{


   //declare BST
   BST<int,int> bst;


   //for loop indexer
   int n =10;

   //for loop to populate the BST
   for (int i =0; i < n; i++)
   {
      bst.insert(i, i+1);
   }




   //print message and then print total number of nodes
   std::cout << "All nodes in the tree: ";
   std::cout << bst.countAllNodes(bst.getRoot()) << std::endl;

   //print message and then print number of leaf nodes
   std::cout << "All leaves in the tree: ";
   std::cout << bst.countAllLeaves(bst.getRoot()) << std::endl;

   //print message nd then print number of full nodes
   std::cout <<"Full Nodes in the tree: ";
   std::cout <<bst.countFullNodes(bst.getRoot()) << std::endl;

//end program
   return 0;
}

