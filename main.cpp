#include <iostream>
#include <list>

using namespace std;

class MyClass{
private:
    int x;
public:
    MyClass(int x);
    
    MyClass(const MyClass& old)
    {
        std::cout << "Copying... "<<&old<<" into "<<this<<"\n";
        *this = old;
    }
    
    ~MyClass();
};

MyClass::MyClass(int x){
    this->x = x;
    cout<<"Class "<<this->x<<" at "<<this<<" was created"<<endl;
}

MyClass::~MyClass(){
    cout<<"Class "<<this->x<<" at "<<this<<" has been destroyed"<<endl;
}

int main()
{
    list<MyClass> myList;
    myList.push_back(MyClass(2));
    myList.push_back(MyClass(7));
    for (auto it = myList.begin(); myList.end() != it; it++)
        cout<<&(*it)<<endl;
    return 0;
}
