#include "tree.hpp"
#include <stdio.h>
Tree::Tree()
{
    head=NULL;
}

void add_node(int x,Node *&Tree)
{
    if (!Tree)
    {
        Tree=new Node;
        Tree->x = x;
        Tree->l=Tree->r=NULL;
    }

   if (x<Tree->x)   // йдемо вліво
      {
          if (Tree->l)
              add_node(x,Tree->l);  // якщо місце вільне то додаємо тут
          else
          {
              Tree->l=new Node;
              Tree->l->l = Tree->l->r = NULL;
              Tree->l->x = x;
          }
      }

    else if (x>Tree->x)
      {
          if (Tree->r)
              add_node(x,Tree->r);  // йдемо вправо
          else // якщо місце вільне до додаємо тут
          {
              Tree->r = new Node;
              Tree->r->l = Tree->r->r = NULL;
              Tree->r->x = x;
          }
      }
}
void treeWalk(Node *Tree)
{

    if (Tree)
    {
        treeWalk(Tree->l);
        printf("%d, ",Tree->x);
        treeWalk(Tree->r);
    }
}
bool search2(Node *Tree,int value)
{
     while (Tree)
     {
         if (value == Tree->x)
             return true;
         else if (value > Tree->x)
         {
             Tree = Tree->r;
         }

         else if (value  < Tree->x)
         {
             Tree = Tree->l;
         }
     }
     return false;
}
bool search(Node *Tree,int value)
{
     if (Tree)
     {
         if (search (Tree->l, value))
             return true;
         if (Tree->x == value)
             return true;
         if (search(Tree->r, value))
             return true;
     }
     return false;
}
