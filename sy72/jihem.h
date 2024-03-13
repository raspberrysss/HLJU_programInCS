#ifndef JIHE_H_
#define JIHE_H_
#include<iostream>

using namespace std;

template <class T>
class Set
{
   private:
       T *value;
       int size;//元素个数
       int length;//动态数组长度，有什么不同吗？add那里需要区分
   public:
       Set(int len);
       Set();
       ~Set();
       void add(T v);
       bool isExist(T v);
       void display();
       void Resize(int len);
       int getSize()
       {
           return size;
       };
       int getLength()
       {
           return length;
       };
       Set<T>& operator=(Set<T>& r);
       Set<T> operator+(Set<T>& r);
       Set(Set<T>& A);

};

template <class T>
Set<T>::Set(int len)
{
    value=new T[len];
     size=0;
    length=len;
}

template <class T>
Set<T>::Set()
{
    value=new T[length];
    size=0;
    length=0;
}

template <class T>
Set<T>::~Set()
{
    size=0;
    length=0;
    delete []value;
}

template <class T>
void Set<T>::add(T v)
{
    value[size]=v;
    size++;//类似于队列，进入之后加加，方便下一次进入,
}

template <class T>
bool Set<T>::isExist(T v)
{
    for(int i=0;i<size;i++)
    {
        if(v==value[i])
        {
            return true;
        }
    }
            return false;//都遍历一遍才知道它是否存在
}

template <class T>
void Set<T>::display()
{
    cout<<"结果如下"<<endl;
    int i;
    for(i=0;i<size;i++)
    {
        cout<<value[i]<<" ";
    }
    cout<<endl;
}

template <class T>
void Set<T>::Resize(int len)
{
    delete []value;//~Set();
    size=0;//Set(len);可以用构造和析构吗？
    length=len;
    value=new T[length];
}

template <class T>
Set<T>& Set<T>:: operator=(Set<T>& r)
{
    Resize(r.getLength());//将承接的数组变成想要的大小
    int i;
    for(i=0;i<r.getSize();i++)//r.size也可以正确，但是编了就用一下
    {
        value[i]=r.value[i];
        size++;//重置完之后size变为0，需要再次叠加
    }
    return *this;
}

template <class T>
Set<T> Set<T>::operator+(Set<T>& r)
{
     int i,j;
     Set<T>new_vs(getLength()+r.getLength());
     for(i=0;i<getSize();i++)
     {
         new_vs.add(value[i]);
     }
     for(j=0;j<r.getSize();j++)
     {
         if(new_vs.isExist(r.value[j]))
         {
             continue;
         }
         else
         {
             new_vs.add(r.value[j]);
         }
     }

     return new_vs;
}
template <class T>
Set<T>::Set(Set<T>& A)
{
    size=A.size;
    length=A.length;
    value=new T[A.length];//为A开辟新的内存空间
    for(int i=0;i<A.getSize();i++)
    {
      value[i]=A.value[i];
    }
}

#endif // JIHE_H_
