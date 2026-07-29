// print name n times

// #include<iostream>
// using namespace std;
//     void print(string name, int n){
//         if(n == 0) return;

//         cout<<name<<endl;
//         print(name, n-1);
//     }
// int main(){
//     print("Tamanna", 5);
// return 0;
// }

// print in terms on N to 1

#include<iostream>
using namespace std;
    void print(int n){
        if(n==0) return;

        cout<<"tamanna"<<endl;
        print(n -1);
    }
int main(){
    print(4);
return 0;
}