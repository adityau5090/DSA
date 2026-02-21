/*  
You are running a lemonade stall where each lemonade costs ₹5. Customers come one by one and pay using bills of ₹5, ₹10, or ₹20. Initially, you have no change.

For every customer:

If the customer pays with ₹5, no change is needed.

If the customer pays with ₹10, you must return ₹5 as change.

If the customer pays with ₹20, you must return ₹15 as change (either one ₹10 and one ₹5, or three ₹5 bills).

Your task is to check whether it is possible to give correct change to every customer in the order they arrive.
Return true if you can serve all customers successfully, otherwise return false.
*/

#include<iostream>
using namespace std;

bool lemondate(int arr[], int size){
    int five=0;
    int ten=0;
    // int twenty=0;

    for(int i=0; i<size; i++){
        if(arr[i] == 5){
            five += 1;
        }else if(arr[i] == 10){
            if(five){
                five -= 1;
                ten += 1;
            }else{
                return false;
            }
        }else{
            if(ten && five){
                ten -= 1; five -= 1;                
            }else if(five > 3){
                five -= 3;
            }else{
                return false;
            }
        }
    }
    return true;
}

int main(){
        int bills[] = {5,5,5,10,20};
        int size = sizeof(bills)/ sizeof(int);

        cout<<lemondate(bills, size)<<"\n";
}