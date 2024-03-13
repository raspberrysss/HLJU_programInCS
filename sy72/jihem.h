#ifndef JIHE_H_
#define JIHE_H_
#include<iostream>

using namespace std;

template <class T>
class Set
{
   private:
       T *value;
       int size;//Ԫ�ظ���
       int length;//��̬���鳤�ȣ���ʲô��ͬ��add������Ҫ����
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
    size++;//�����ڶ��У�����֮��Ӽӣ�������һ�ν���,
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
            return false;//������һ���֪�����Ƿ����
}

template <class T>
void Set<T>::display()
{
    cout<<"�������"<<endl;
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
    size=0;//Set(len);�����ù����������
    length=len;
    value=new T[length];
}

template <class T>
Set<T>& Set<T>:: operator=(Set<T>& r)
{
    Resize(r.getLength());//���нӵ���������Ҫ�Ĵ�С
    int i;
    for(i=0;i<r.getSize();i++)//r.sizeҲ������ȷ�����Ǳ��˾���һ��
    {
        value[i]=r.value[i];
        size++;//������֮��size��Ϊ0����Ҫ�ٴε���
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
    value=new T[A.length];//ΪA�����µ��ڴ�ռ�
    for(int i=0;i<A.getSize();i++)
    {
      value[i]=A.value[i];
    }
}

#endif // JIHE_H_
