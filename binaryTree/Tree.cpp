#include "Tree.h"
#include <iostream>
using namespace std;

Tree::Node::Node(int value) :Node(value, nullptr, nullptr) {}

Tree::Node::Node(int value, Node* right, Node* left)
    :value(value),
    right(right),
    left(left) {}

void Tree::Insert(int value, Node*& node)
{
    if (node == nullptr)
    {
        Node* new_node = new Node(value);
        node = new_node;
        return;
    }
    if (node->value > value)
    {
        Insert(value, node->left);
    }
    else
    {
        Insert(value, node->right);
    }
}

Tree::Tree()
    :root(nullptr) {}

void Tree::Insert(int value)
{
    Insert(value, root);
}

void Tree::Print(Node* node){
    if (node == nullptr)
    {
        return;
    }
    Print(node->left);
    cout << node->value << " ";
    Print(node->right);
}

void Tree::Print(){
    Print(root);
    cout << endl;
}
