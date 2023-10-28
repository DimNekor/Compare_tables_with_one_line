#include <iostream>
#include <iomanip>
#include "../include/binTree.h"

binTree::binTree()
{
   root = nullptr;
}

void binTree::add(int digit)
{
   add(root, digit);
}

Node* binTree::create(int digit)
{
   Node* node = new Node;
   node->number = digit;
   node->left = nullptr;
   node->right = nullptr;
   return node;
}

bool toLeft(Node* node, int digit)
{
   if (node->number > digit)
      return true;
   return false;
}

bool isAlreadyHere(Node* node, int digit)
{
   if (node->number == digit)
      return true;
   return false;
}

void binTree::add(Node*& current, int digit)
{
   if (current == nullptr)
   {
      current = create(digit);
      return;
   }

   if (isAlreadyHere(current, digit))
      return;

   if (toLeft(current, digit))
      return add(current->left, digit);

   return add(current->right, digit);  
}

void binTree::display()
{
   display(root, 1);
}

void binTree::display(Node* current, int level)
{
   if (current->right)
      display(current->right, level + 4);

   std::cout << std::setfill(' ') << std::setw(level);
   std::cout << current->number << std::endl;
   
   if (current->left)
      display(current->left, level + 4);
}

Node* binTree::retRoot()
{
   return root;
}

bool binTree::isHere(int digit)
{
   return isHere(root, digit);
}

bool binTree::isHere(Node* node, int digit)
{
   if (node == nullptr)
      return false;
   else if (digit == node->number)
      return true;
   else if (digit < node->number)
      return isHere(node->left, digit);
   else return isHere(node->right, digit);
}

bool isSimilar(binTree tree1, binTree tree2)
{
   return isSimilar(tree2.retRoot(), tree1);
}


bool isSimilar(Node* node2, binTree tree1)
{
   if ( !(node2->left || node2->right) )
      return tree1.isHere(node2->number);
   
   else if (node2->right && !node2->left)
      return isSimilar(node2->right, tree1);
   
   else if (!node2->right && node2->left)
      return isSimilar(node2->left, tree1);

   return tree1.isHere(node2->number) && isSimilar(node2->left, tree1) && isSimilar(node2->right, tree1);
} 
