#include "../include/binTree.h"
#include <iostream>

int main()
{
   int a = 30;
   int b = 80;
   int c = 20;
   int d = 80;
   int e = 90;
   int f = 70;
   int g = 9;

   binTree tree1;
   binTree tree2;
   
   tree1.add(a);
   tree1.add(b);
   tree1.add(c);
   tree1.add(d);
   tree1.add(e);
   tree1.add(f);

   tree2.add(a);
   tree2.add(b);
   tree2.add(c);
   tree2.add(d);
   tree2.add(e);
   tree2.add(f);
   tree2.add(g);

   tree1.display();
   tree2.display();

   std::cout << isSimilar(tree1, tree2) << std::endl;
   return 0;
}
