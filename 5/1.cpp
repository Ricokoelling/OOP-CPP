#include <iostream>
#include <string>
using namespace std;
struct Node
{
    string value;
    Node *left, *right;
};
Node *GetNewNode(const string &value)
{
    Node *newNode = new Node();
    newNode->value = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
typedef struct Node Node;
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
    if (tree != NULL)
    {
        free(tree->left);
        free(tree->right);
        delete tree;
        tree = NULL;
    }
}
void list(Node *tree)
{
    if (tree != NULL)
    {
        cout << tree->value << " ";
        list(tree->left);
        list(tree->right);
    }
}
Node *insert(Node *&tree, string &input)
{
    if (search(tree, input) == true)
    {
        return (tree);
    }
    if (tree == NULL)
    {
        tree = GetNewNode(input);
    }
    else if (tree->value.compare(input) < 0)
    {
        tree->left = insert(tree->left, input);
    }
    else if (tree->value.compare(input) > 0)
    {
        tree->right = insert(tree->right, input);
    }
    return (tree);
}
int main()
{
    Node *tree = NULL;
    string input;
    cout << "Please insert your word: ";
    getline(cin, input);
    while (input != ".")
    {
        tree = insert(tree, input);
        cout << "Please insert your word: ";
        getline(cin, input);
    }
    list(tree);
    free(tree);
    list(tree);
    return 0;
}