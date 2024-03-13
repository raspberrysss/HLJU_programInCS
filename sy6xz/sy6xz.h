#ifndef SY6XZ_H_
#define SY6XZ_H_

class Tree
{
    public:
        virtual void show()=0;//此时Tree类为抽象类，此纯虚函数可以定义也可以不定义
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

//void useshow_reference(Tree &t);
//void useshow_address(Tree *t);

#endif // SY6XZ_H_
