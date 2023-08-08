#include<iostream>
#include<array>

using namespace std;

int main(){

    int basic[3] = {3,4,5};

    array<int, 5> a = {3,4,67,7,76}; 
    // cout<< a.end();
    cout<< a.at(2)<<endl;

    a[2] =34;
    cout<< a.at(2)<<endl;
    cout<< a.front()<<endl;
    cout<< a.back()<<endl;
    cout<< *(a.data())<<endl;
    cout<< *(a.data()+1)<<endl;// ye pointer return krta  h jo ki array ke first element ka address hota h 

    cout<<a.size()<<endl;
    cout<<a.max_size()<<endl;
    cout<<a.empty();

    array<int, 44> b ;

    


    return 0;
}