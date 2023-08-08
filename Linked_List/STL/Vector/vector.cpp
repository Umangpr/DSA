#include<iostream>
#include<vector>

using namespace std;
int main()
{
    // std::vector<int> v;
    // std::cout << "Default-constructed capacity is " << v.capacity() << '\n';
    // v.resize(100);
    // std::cout << "Capacity of a 100-element vector is " << v.capacity() << '\n';
    // v.resize(50);
    // std::cout << "Capacity after resize(50) is " << v.capacity() << '\n';
    // v.shrink_to_fit();
    // std::cout << "Capacity after shrink_to_fit() is " << v.capacity() << '\n';
    // v.clear();
    // std::cout << "Capacity after clear() is " << v.capacity() << '\n';
    // v.shrink_to_fit();
    // std::cout << "Capacity after shrink_to_fit() is " << v.capacity() << '\n';
    // for (int i = 1000; i < 1300; ++i)
    //     v.push_back(i);
    // std::cout << "Capacity after adding 300 elements is " << v.capacity() << '\n';
    // v.shrink_to_fit();
    // std::cout << "Capacity after shrink_to_fit() is " << v.capacity() << '\n';

    vector<int> a;
    cout<<"Size-> "<<a.size()<<endl;
    cout<<"Capacity-> "<<a.capacity()<<endl;

    a.push_back(1);
    cout<<"Capacity-> "<<a.capacity()<<endl;


    a.push_back(2);
    cout<<"Capacity-> "<<a.capacity()<<endl;
    a.push_back(3);
    cout<<"Capacity-> "<<a.capacity()<<endl;
    a.push_back(4);
    cout<<"Capacity-> "<<a.capacity()<<endl;
    a.push_back(1);
    cout<<"Capacity-> "<<a.capacity()<<endl;
    cout<<"Size-> "<<a.size()<<endl;
    for(auto i= 0 ; i<a.size(); i++){
        cout<<a.at(i)<<" ";
    }
    cout <<endl;

    for(int i:a){
        cout<<i<<" ";
    }
    a.pop_back();
    cout <<endl;
    cout<<"Front-> "<<a.front()<<endl;
    cout<<"Back-> "<<a.back()<<endl;

    a.clear();
    cout<<"Size-> "<<a.size()<<endl;
    cout<<"Front-> "<<a.front()<<endl;
    cout<<"Back-> "<<a.back()<<endl;



    //initialize all with given data .ex = 2
    vector<int> b(5,2);
    for(int i:b){
        cout<< i << " ";
    }

    cout<<endl;
    vector<int> copy1(b);
    vector<int> copy2 = b;
    for(int i:copy1){
        cout<< i << " ";
    }



}