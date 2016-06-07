// ChessTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Tree.h"

int main()
{
   Tree<int> tree;
   tree.displayTree();
   tree.fillTree();
   tree.displayTree();
   tree.displayUniquePaths();

   system("PAUSE");
    return 0;
}

