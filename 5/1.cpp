#include <iostream>
#include <string>
using namespace std;
string input;
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
void free(Node *tree)
{
    if (tree != NULL)
    {
        free(tree->left);
        delete tree;
        free(tree->right);
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
Node *insert(Node *tree)
{
    if (tree->value.compare(input) != 0)
    {
        if (tree == NULL)
        {
            tree = GetNewNode(input);
        }
        else if (tree->value.compare(input) < 0)
        {
            tree->left = insert(tree->left);
        }
        else if (tree->value.compare(input) > 0)
        {
            tree->right = insert(tree->right);
        }
        return (tree);
    }
}
int main()
{
    Node *tree = NULL;
    cout << "Please insert your word: ";
    getline(cin, input);
    while (input != ".")
    {
        tree = insert(tree);
        cout << "Please insert your word: ";
        getline(cin, input);
    }
    list(tree);
    free(tree);
    cout << "\n\n\n";
    list(tree);
    return 0;
}