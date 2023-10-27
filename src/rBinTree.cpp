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
   if (node->number < digit)
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
   if (current->left)
      display(current->left, level + 4);

   std::cout << std::setfill(' ') << std::setw(level);
   std::cout << current->number << std::endl;
   
   if (current->right)
      display(current->right, level + 4);
}

Node* binTree::retRoot()
{
   return root;
}

bool isSimilar(binTree tree1, binTree tree2)
{
   return isSimilar(tree1.retRoot(), tree2.retRoot());
}

bool isSimilar(Node* node1, Node* node2)
{
   if (node1 == nullptr && node2 == nullptr)
      return true;
   
   else if (node1 == nullptr || node2 == nullptr)
      return false;
   
   else
   {
      if (node1->number == node2->number && isSimilar(node1->left, node2->left) && isSimilar(node1->right, node2->right)) return true;
      else return false;
   }
} 
