#include <iostream>
#include <string>
using namespace std;
struct Node
{
    string value;
    Node *left{}, *right{};
};
Node *GetNewNode(const string &value)
{
    Node *newNode = new Node();
    newNode->value = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}
typedef struct Node Node;
int check(const string &value, Node *tree){
    if(tree->value[1] < value[1]){
        return -1;
    }
    else return 1;
}
bool search(Node *tree, string &input)
{
    Node *now = tree;
    while (now)
    {
        if (input < now->value)
            now = now->left;
        else if (now->value < input)
            now = now->right;
        else
            return true;
    }
    return false;
}
void free(Node *&tree)
{
    if (tree != nullptr)
    {
        free(tree->left);
        free(tree->right);
        delete tree;
        tree = nullptr;
    }
}
void list(Node *tree)
{
    if (tree != nullptr)
    {
        list(tree->left);
        cout << tree->value << " ";
        list(tree->right);
    }
}
Node *insert(Node *&tree, string &input)
{
    if (search(tree, input))
    {
        return (tree);
    }

    if (tree == nullptr)
    {
        tree = GetNewNode(input);
    }
    else if (check(input,tree) < 0)
    {
        tree->left = insert(tree->left, input);
    }
    else
    {
        tree->right = insert(tree->right, input);
    }
    return (tree);
}
int main()
{
    Node *tree = nullptr;
    string input;
    cout << "Please insert your word:";
    getline(cin, input);
    while (input != ".")
    {
        insert(tree, input);
        cout << "Please insert your word:";
        getline(cin, input);
    }
    list(tree);
    free(tree);
    return 0;
}