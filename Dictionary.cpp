#include <iostream>
#include <string>
using namespace std;

class Node
{
    //public:
    string word, meaning;
    Node *left, *right;    //Node * because node is storing the address of another Node

    Node()
    {
        left = NULL;
        right = NULL;
    }

    Node(string word, string meaning)     //Parameterised constructor
    {
        this->word = word;
        this->meaning = meaning;
        left = NULL;
        right = NULL;
    }

    friend class Dictionary; // means iska matlab Dictionary uska access le sakta hai 
};

class Dictionary
{
    Node *root;

   public:
    Dictionary()
    {
        root = NULL;
    }
    void create();
    Node *insert(Node *, string,string);
    void inorder(Node *);
    void preorder(Node *);
    void postorder(Node *);
    void update();
    void search(string,int);
    void input();
    void searchMain();
    void inorderMain()
    {
        cout<<"\nInorder is: ";
        inorder(root);
    }

    void preorderMain()
    {
        cout<<"\n\nPreorder is: ";
        preorder(root);
    }
    void postorderMain()
    {
        cout<<"\n\nPostorder is: \n";
        postorder(root);
    }
};

void Dictionary::create()
{
    string ipWord, ipMeaning;
    int noOfNodes;

    cout<<"Enter number of nodes: ";
    cin>>noOfNodes;

    for(int i=0;i<noOfNodes;i++)
    {
        cout<<"\n Enter Word: ";
        cin>>ipWord;
        cout<<"\n Enter Meaning: ";
        cin>>ipMeaning;

        root = insert(root, ipWord, ipMeaning);
        cout<<"Root address: "<<root<<"\n";
    }
    //inorder(root);
}

Node *Dictionary::insert(Node *tempRoot, string tempWord, string tempMeaning)
{
    Node *newNode = new Node(tempWord,tempMeaning);
    if(tempRoot == NULL)
    {
        tempRoot = newNode;
        cout<<tempRoot->word<<":"<<tempRoot->meaning;
        return tempRoot;
    }
    if(tempWord < tempRoot->word)
        tempRoot->left = insert(tempRoot->left, tempWord, tempMeaning);

    else
        tempRoot->right = insert(tempRoot->right, tempWord, tempMeaning);
    return tempRoot;
}

void Dictionary::inorder(Node *inRoot)
{
    if(inRoot!=NULL)
    {
        inorder(inRoot->left);
        cout<<endl<<inRoot->word<<" "<<inRoot->meaning;
        inorder(inRoot->right);
    }
}

void Dictionary::preorder(Node *preRoot)
{
    if(preRoot!=NULL)
    {
        cout<<endl<<preRoot->word<<" "<<preRoot->meaning;
        preorder(preRoot->left);
        preorder(preRoot->right);
    }
}

void Dictionary::postorder(Node *postRoot)
{
    if(postRoot!=NULL)
    {
        postorder(postRoot->left);
        postorder(postRoot->right);
        cout<<postRoot->word<<" "<<postRoot->meaning<<endl;
    }
}
// void Dictionary :: input(){
//     string data;
//      cout<<"Enter the data you want to search for = ";
//    cin>>data;
// }

void Dictionary::searchMain(){  
   int depth = 0; 
   string data;
   cout<<"Enter the data you want to search for";
   cin>>data;

   //  Node *tempRoot = new Node;
      Node *tempRoot = root;
   while(tempRoot != NULL) {
      depth++;
      if(tempRoot->word == data) {
         cout<<" Your Data was found at = "<<depth;
         return;
      } else if(tempRoot->word > data)
         tempRoot = tempRoot->left;
         else
            tempRoot= tempRoot->right;
   }
   cout<<"\n item not found";
   return;
}
int main()
{
    Dictionary dict;
    dict.create();
    dict.inorderMain();
    dict.preorderMain();
    dict.postorderMain();
     // dict.input();
    dict.searchMain();

    return 0;
}
