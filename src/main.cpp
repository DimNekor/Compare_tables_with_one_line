#include "../include/binTree.h"
#include <iostream>
#include <limits>

void firstMenu()
{
   std::cout << "\n_________________START_______________\n" << std::endl;
   std::cout << "If you want to fill trees, input 'f'" << std::endl;
   std::cout << "If you want to end the program, input 'e'" << std::endl;
}

void mainMenu()
{
   std::cout << "\n_________________MENU________________\n" << std::endl;
   std::cout << "If you want to add elements, input 'a'" << std::endl;
   std::cout << "If you want to display trees, input 'd'" << std::endl;
   std::cout << "If you want to compare trees,input 'c'" << std::endl;
   std::cout << "If you want to finish program, input 'f'"<<std::endl;
}

void typeAddMenu()
{
   std::cout << "\n_________________ADDING_____________\n" << std::endl;
   std::cout << "If you want to add from file, input 'f'" << std::endl;
   std::cout << "If you want to add by keyboard, input 'k'" << std::endl;
}

void addMenu()
{
   std::cout << "\n_________________ADDING______________\n" << std::endl;
   std::cout << "If you want to choose first tree, input '1'"<< std::endl;
   std::cout << "If you want to choose second tree, input '2'"<<std::endl;
   std::cout << "If you want to finish adding, input 'f'" << std::endl;
}

int countNumTree(FILE* f)
{
   int count = 0;
   char ch;
   while ( (ch = getc(f)) != '\n')
   {
      if (ch == ' ')
         count++;
   }
   return count;
}
   
void addFromFile(binTree& tree1, binTree& tree2)
{
   int countNumTree1;
   int countNumTree2;
   char filename[30];
   std::cout << "Enter the name of file " << std::endl;
   std::cin >> filename;
   FILE* f = fopen(filename, "r");
   if (!f)
   {
      std::cout << "Incorrect name of file. Enter another one" <<std::endl;
      std::cin >> filename;
      f = fopen(filename, "r");
   }
   countNumTree1 = countNumTree(f);
   countNumTree2 = countNumTree(f);
   countNumTree1++;
   countNumTree2++;
   rewind(f);
   int x;
   for (int i = 0; i < countNumTree1; i++)
   {  
      fscanf(f, "%d", &x);
      tree1.add(x);
   }
   for (int i = 0; i < countNumTree2; i++)
   {
      fscanf(f, "%d", &x);
      tree2.add(x);
   }
   fclose(f);
}
  
void addByKeyboard(binTree& tree)
{
   int digit;
   std::cout << "Enter a number" << std::endl;
   std::cin >> digit;
   while (!std::cin.good())
   { 
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Enter a number!" <<std::endl;
      std::cin >> digit;
   }
   tree.add(digit);
}
   
void addByKeyboard(binTree& tree1, binTree& tree2)
{
   char choice;
   addMenu();
   std::cin >> choice;
   while (true)
   {
      if (choice == '1')
      {
         addByKeyboard(tree1);
         addMenu();
         std::cin >> choice;
      }
      else if (choice == '2')
      {
         addByKeyboard(tree2);
         addMenu();
         std::cin >> choice;
      }
      else if (choice == 'f')
         break;
      else
      {
         std::cout << "Incorrect input" << std::endl;
         addMenu();
         std::cin >> choice;
      }
   }
}

char adding(binTree& tree1, binTree& tree2)
{
   firstMenu();
   char choice;
   std::cin >> choice;
   while (choice == 'f')
   {
      typeAddMenu();
      std::cin >>choice;
      if (choice == 'f')
      {
         addFromFile(tree1, tree2);
         choice = 'h';
      }
      else if (choice == 'k')
      {
         addByKeyboard(tree1, tree2);
         choice = 'h';
      }
      else 
         std::cout << "Incorrect Input" << std::endl;
   }
   if (choice == 'e')
   {
      std::cout << "The program is finished" << std::endl;
      return choice;
   }
   if (choice == 'h')
   {
      std::cout << "Adding is finished" << std::endl;
      return choice;
   }
   else return adding(tree1, tree2);
}

char processing(binTree& tree1, binTree& tree2)
{
   mainMenu();
   char choice;
   std::cin >> choice;
   if (choice == 'a')
   {
      addByKeyboard(tree1, tree2);
      return choice;
   }
   else if (choice == 'd')
   {
      std::cout << "\n_________DISPLAY_TREE1_________\n" << std::endl;
      tree1.display();
      std::cout << "\n_________DISPLAY_TREE2_________\n" << std::endl;
      tree2.display();
      return choice;
   }
   else if (choice == 'c')
   {
      std::cout << "\n____________COMPARING__________\n" << std::endl;
      char sign = isSimilar(tree1, tree2);
      if (sign) 
         std::cout << "Two tables have a similar set of data"<< std::endl;
      else
         std::cout << "Tables haven't a similar set of data" << std::endl;
      return choice;
   }
   else if (choice == 'f')
   {
      std::cout << "Program is over" << std::endl;
      return choice;
   }
   else return processing(tree1, tree2);
}
      


int main()
{
   binTree tree1;
   binTree tree2;
   bool isFirst = true;
   char ch;

   while (true)
   {
      if (isFirst)
      {
         ch = adding(tree1, tree2);
         isFirst = false;
      }
      else
      {
         if (ch == 'e')
            break;
         else if (processing(tree1, tree2) == 'f')
            break;
      }
   }     
   return 0;
}
