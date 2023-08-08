#include<iostream>
#include<map>
#include<unordered_map>

using namespace std;

int main(){
    //creation
    map<string,int> m;

    //insertion

    //1
    pair<string,int> p= make_pair("Umang",3);
    m.insert(p);

    //2
    pair<string,int> pair2("Prakash",9);
    m.insert(pair2);

    //3
    m["mera"]= 21;
    m["mera"] =  2;


    m["love"] =  32;

    //search
    cout<< m["mera"]<<endl;
    cout<< m["Umang"]<<endl;
    cout<< m["mera"]<<endl;
    cout<< m["unknown"]<<endl;
    cout<< m.at("mera")<<endl;


    cout<< m.count("love")<<endl;
    cout<< m.count("Umang")<<endl;
    cout<< m.count("Prakash")<<endl;

    cout<<"Size of map-> "<< m.size()<<endl;
    m.erase("love");
    cout<<"Size of map-> "<< m.size()<<endl;


    //bina iterator ka use kiye
    for(auto i:m){
        cout<< i.first << " "<< i.second <<endl;
    }

    //iterator
    // unordered_map<string,int> :: iterator it = m.begin();

    // while(it != m.end()){
    //     cout << it->first << " "<< it->second<<endl;
    //     it++;
    // }

    return 0;
}