#ifndef TREE_HPP
#define TREE_HPP
struct Node
{
public:
    Node *l,*r;
    int x;
};

struct Tree
{
public:
    Node *head;
    Tree();
};

void add_node(int x,Node *&Tree);
void treeWalk(Node * tree);
bool search(Node *tree,int x);
bool search2(Node *Tree,int value);
#endif // TREE_HPP
