#include <iostream>
#include <queue>
using namespace std;

class StackImpl
{
    queue<int> q;

public:
    void push(int data)
    {
        int s = q.size();
        q.push(data);

        for (int i = 0; i < s; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        q.pop();
    }

    void print()
    {
        queue<int> temp = q;
        while (!temp.empty())
        {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main()
{
    StackImpl s;
    s.push(5);
    s.push(8);
    s.push(3);
    s.print();
    s.pop();
    s.print();
}