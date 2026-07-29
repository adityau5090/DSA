// Sum of first N numbers -

// parameterized way

// #include<iostream>
// using namespace std;
//     void func(int i, int sum=0){
//         if(i<1){
//             cout<<sum;
//             return;
//         }
//         func(i-1, sum+i );
//     }
// int main(){
//     func(5);
// return 0;
// }

// functional way 

#include<iostream>
using namespace std;
    int func(int i){
        if(i<=0) return 0;
        
        return i + func(i-1);
    }
int main(){
    cout<<func(2);
return 0;
}