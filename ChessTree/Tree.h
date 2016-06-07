#pragma once
#include <iostream>
#include <string>
#include "Leaf.h"

// 0-based, so remove one, eg. 8x8 chess would be max 7
const int MAX_HORIZ = 4;
const int MAX_VERT = 4;

template <class T>
class Tree
{
public:
   Tree() : root(nullptr), uniquePaths(0) {}
   ~Tree() {}
   void fillTree();
   void displayTree();
   void displayUniquePaths();

private:
   Leaf<T>* root;
   void recursiveFill(Leaf<T>* branch);
   void recursiveDisplay(Leaf<T>* branch, std::string);
   int uniquePaths;
};


template <class T>
void Tree<T>::fillTree()
{
   // Check for empty tree and create the root object
   if (root == nullptr)
   {
      root = new Leaf<T>(0, 0);
      // Begin recursive calls to fill the tree
      recursiveFill(root);
   }
   // Otherwise tree is not empty, so it's already filled
}


template <class T>
void Tree<T>::recursiveFill(Leaf<T>* branch)
{
   // Check if current branch horiz is equal to max, otherwise make horiz and traverse
   if (branch->getHorizLoc() < MAX_HORIZ)
   {
      branch->setHorizLeaf(new Leaf<T>((branch->getHorizLoc() + 1), branch->getVertLoc()));
      recursiveFill(branch->getHorizLeaf());
   }

   // Check if current branch vert is equal to max, otherwise make vert and traverse
   if (branch->getVertLoc() < MAX_VERT)
   {
      branch->setVertLeaf(new Leaf<T>(branch->getHorizLoc(), (branch->getVertLoc() + 1)));
      recursiveFill(branch->getVertLeaf());
   }

   // Check for final destination, increment unique leaf node
   if ((branch->getHorizLoc() == MAX_HORIZ) && (branch->getVertLoc() == MAX_VERT))
   {
      uniquePaths++;
   }
}


template <class T>
void Tree<T>::displayTree()
{
   // Special case where the root is null
   if (root == nullptr)
   {
      std::cout << "Root is NULL" << std::endl;
   }
   // Display root and begin traversing through the tree
   else
   {
      std::string fullPath = "";
      recursiveDisplay(root, fullPath);
   }
}


template <class T>
void Tree<T>::recursiveDisplay(Leaf<T>* branch, std::string path)
{
   // Add to the path as we traverse
   if (branch != root)
   {
      path.append(" -> ");
   }
   path = path + "(" + std::to_string(branch->getHorizLoc()) + "," + std::to_string(branch->getVertLoc()) + ")";
   // Traverse horiz and vert branches
   if (branch->getHorizLeaf() != nullptr)
   {
      recursiveDisplay(branch->getHorizLeaf(), path);
   }
   if (branch->getVertLeaf() != nullptr)
   {
      recursiveDisplay(branch->getVertLeaf(), path);
   }
   // If at final destination, print the unique path
   if ((branch->getHorizLoc() == MAX_HORIZ) && (branch->getVertLoc() == MAX_VERT))
   {
      std::cout << path << std::endl;
   }
}


template <class T>
void Tree<T>::displayUniquePaths()
{
   std::cout << "Unique Paths: " << uniquePaths << std::endl;
}