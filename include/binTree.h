struct Node
{
   int number;
   Node* left;
   Node* right;
};

class binTree
{
private:
   Node* root;
   Node* create(int);
   void add(Node*&, int);   
   void display(Node*, int);
   bool isHere(Node*, int);
   
public:
   binTree();
   void add(int);
   void display();
   Node* retRoot();
   bool isHere(int);
};

bool isSimilar(binTree, binTree);
bool isSimilar(Node*, binTree);
   
