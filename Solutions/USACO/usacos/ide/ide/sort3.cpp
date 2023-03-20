#include <iostream>
#include <memory>

using namespace std;

int main() {
    unique_ptr<int> my_ptr = make_unique<int>(5);
    cout << my_ptr << endl;
    cout << *my_ptr << endl;
    
    int *ptr1 = my_ptr.get();
    cout << ptr1 << endl;
    cout << *ptr1 << endl;
    delete ptr1;
    
    cout << *my_ptr << endl;
}
