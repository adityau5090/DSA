#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cout << "**********************************************" << endl;
    vector<int> vec; // creating an empty vector
    cout << "Size of vector = " << vec.size() << "\n";
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);
    // size and capacity of a vector
    cout << "Size of vector after push back = " << vec.size() << endl; // print number of elements
    cout << "capacity = " << vec.capacity() << endl;                   // print capacity of vector
    for (int i : vec)
    {
        cout << i << endl;
    }

    cout << "**********************************************" << endl;

    // push_back and pop_back in vector
    vector<int> v;
    cout << "size = " << v.size() << endl;
    cout << "Capacity = " << v.capacity() << "\n";
    v.push_back(24);
    v.push_back(30);
    v.push_back(45);
    cout << "size after push back = " << v.size() << endl;
    cout << "Capacity = " << v.capacity() << "\n";
    for (int i : v)
    {
        cout << i << endl;
    }
    v.pop_back();
    cout << "size after pop back= " << v.size() << endl;
    cout << "Capacity = " << v.capacity() << "\n";
    for (int i : v)
    {
        cout << i << endl;
    }

    cout << "**********************************************" << endl;

    // front and back in vector
    vector<char> c = {'a', 'b', 'c', 'd'};
    cout << "size = " << c.size() << endl;
    cout << "Front = " << c.front() << endl; // first value
    cout << "Back = " << c.back() << endl;   // last value
    cout << "**********************************************" << endl;
    
    // at in vector
    vector<int> v1 = {30, 40, 78};
    cout << v1.at(0) << endl; // print the value at particular index
    cout << v1.at(2) << endl;
    return 0;
}