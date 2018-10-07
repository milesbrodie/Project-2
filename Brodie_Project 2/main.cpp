/*
Miles Brodie
CS20A -- Section 4452
Project #2

*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;


template<class T>
class LinearList
{
private:
    int length;
    int MaxSize;
    T *element;
public:
    LinearList(int MaxLinearSize=11);
    ~LinearList(){delete[]element;}
    int isEmpty()const{return length==0;}
    int Length()const{return length;}
    int Find(int k,T&x)const;
    int Search(const T&x)const;
    void Delete(int k,T&x);
    void Insert(int k,const T&x);
    void Output()const;
};

template<class T>
LinearList<T>::LinearList(int MaxListSize)
{
    MaxSize=MaxListSize;
    element=new T[MaxSize];
    length=0;
}

template<class T>
int LinearList<T>::Find(int k,T&x)const
{
    if(k<1||k>length)
        return 0;
    x=element[k-1];
    return 1;
}

template<class T>
int LinearList<T>::Search(const T&x)const
{
    for(int i=0;i<length;i++)
        if(element[i]==x)
            return ++i;
    return 0;
}

template<class T>
void LinearList<T>::Delete(int k,T&x)
{
    if(Find(k,x))
    {
        for(int i=k;i<length;i++)
            element[i-1]=element[i];
        length--;
    }
    else
        cout<<"out of bounds\n";
}

template<class T>
void LinearList<T>::Insert(int k,const T&x)
{
    if(k<0||k>length)
        cout<<"out of bounds\n";
    if(length==MaxSize)
        cout<<"no memory\n";
    for(int i=length-1;i>=k;i--)
        element[i+1]=element[i];
    element[k]=x;
    length++;
}

template<class T>
void LinearList<T>::Output()const
{
    ofstream txt_file;
    txt_file.open("Miles.Brodie.aList.txt", std::ios_base::app);

    if(isEmpty())
        txt_file <<"list is empty\n";
    else
        for(int i=0; i<length; i++){
            txt_file << element[i] << " ";
        }
    txt_file << "\n";

    txt_file.close();
}

int main()
{
    //Create a class for the ARRAY list
    LinearList <int> obj;

    //Insert values into the ARRAY list
    obj.Insert(0, 11);
    obj.Insert(1, 10);
    obj.Insert(2, 9);
    obj.Insert(3, 8);
    obj.Insert(4, 7);
    obj.Insert(5, 6);
    obj.Insert(6, 5);
    obj.Insert(7, 4);
    obj.Insert(8, 3);
    obj.Insert(9, 2);
    obj.Insert(10, 1);

    int temp;
    obj.Delete(6, temp);

    obj.Insert(8, 100);

    //Output values from the ARRAY list into the .txt file
    obj.Output();

    return 0;
}
