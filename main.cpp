/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <map>

using namespace std;

class MyClass {
private:
    int x;
    int instance;
    static int next_instance;
    
public:
    MyClass() {
        this->instance = next_instance++;
        cout<<"#"<<this->instance<<"     "<<this<<" created with empty constructor"<<endl;
    }
    
    //Override copy constructor
    MyClass(const MyClass & old) {
        this->x = old.x;
        this->instance = next_instance++;
        cout<<"#"<<this->instance<<" x:"<<this->x<<" "<<this<<" copied from #"<<
        old.instance<<" "<<&old<<endl;
    }
    
    MyClass(int x) {
        this->x = x;
        this->instance = next_instance++;
        cout<<"#"<<this->instance<<" x:"<<this->x<<" "<<this<<" created"<<endl;
    }
    
    ~MyClass() {
        cout<<"#"<<this->instance<<" x:"<<this->x<<" "<<this<<" destroyed"<<endl;
    }
};

int MyClass::next_instance = 1;

int main()
{
    map<int, MyClass> m;
    m.emplace(1, MyClass(1));
    m[2] = MyClass(2);

    return 0;
}
