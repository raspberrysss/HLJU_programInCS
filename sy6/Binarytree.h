#ifndef BINARYTREE_H_
#define BINARYTREE_H_

class Tree
{
    public:
        virtual void show();
        //virtual void useshow_reference(Tree &t);
        //virtual void useshow_point();
        //virtual void useshow_address(Tree *t);
        virtual ~Tree();

};

class Binary_Tree:public Tree
{
    public:
        virtual void show();
        virtual ~Binary_Tree();

};

class Binary_Sort_Tree:public Binary_Tree
{
    public:
        virtual void show();
        virtual ~Binary_Sort_Tree();

};

void useshow_reference(Tree &t);
void useshow_address(Tree *t);
#endif // BINARYTREE_H_
