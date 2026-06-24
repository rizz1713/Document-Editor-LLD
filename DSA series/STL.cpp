#include<iostream>
#include<vector>
#include<list>
#include<deque>
#include<stack>
#include<queue>
#include<map>
#include<unordered_map>
#include<set>

using namespace std;
int main(){

    set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(1);
    s.insert(2);
    s.insert(3);
    for(auto n:s){
        cout<<n<<" ";
    }
    // multimap<string,int> m;
    // m.emplace("tv",100);
    // m.emplace("tv",100);
    // m.emplace("tv",100);
    // m.emplace("tv",100);

    // unordered_map<string,int> um;
    // um.emplace("tv",100);
    // um.emplace("fridge",100);
    // um.emplace("fan",100);
    // um.emplace("light",100);

    // for(auto p:um){
    //     cout<<p.first<<" "<<p.second<<endl;
    // }
    // map<string,int> m ;
    // m["tv"] = 100;
    // m["laptop"] = 50;
    // m["headphones"] = 50;

    // m.emplace("camera",25);

    
    // for(auto p:m){
    //     cout<<p.first<<":"<<p.second<<endl;
    // }

    // cout<<"count:"<<m["laptop"]<<endl;

    // if(m.find("camera")!=m.end()){
    //     cout<<"found";
    // }
    // else{
    //     cout<<"Not found";
    // }
//     priority_queue<int,vector<int>,greater<int>> q;
//     q.push(3);
//     q.push(10);
//     q.push(4);
//     q.push(5);
    
// while(!q.empty()){
//         cout<<q.top()<<" ";
//         q.pop();
//     }

    // queue<int> q;
    // q.push(1);
    // q.push(2);
    // q.push(3);

    // while(!q.empty()){
    //     cout<<q.front()<<endl;
    //     q.pop();
    // }

    // stack<int> s;
    // s.push(1);
    // s.push(2);
    // s.push(3);
   

    // stack<int> s2;
    // s2.swap(s);

    // cout<<s.size()<<endl;
    // cout<<s2.size()<<endl;

    // pair<int,int> p = {3,2};
    // cout<<p.first<<" "<<p.second<<endl;

    // pair<int,pair<char,int>> p1 = {1,{'C',2}};
    // cout<<p1.first<<endl;
    // cout<<p1.second.first<<" "<<p1.second.second<<endl;

    // vector<pair<int,int>> vp = {{1,2},{2,3},{3,4}};
    // for(auto p:vp){
    //     cout<<p.first<<" "<<p.second<<endl;
    // }


    // deque<int> d = {6,7,8,9};
    // for(int n:d){
    //     cout<<n<<" ";
    // }

    // list<int> l = {1,2,3,4,5};
    // l.push_back(6);
    // l.push_front(0);

    // l.pop_front();
    // l.pop_front();
    // l.pop_back();
    // l.pop_back();
    // for(int num:l){
    //     cout<<num<<" ";
    // }

    // vector<int> vec1 = {1,2,3,4,5};
    
    // vector<int> vec2(3,10);
    

    // vec1.push_back(6);
   
    // vec1.pop_back();
    // cout<<vec1.front()<<endl;
    // cout<<vec1.back()<<endl;
    // vec2.emplace_back(-1);

    // for(int num:vec2){
    //     cout<<num<<" ";
    // }

    // vector<int> vec3(vec1);
    // for(int num:vec3){
    //     cout<<"Vector 3:"<<num<<" ";
    // }

    // cout<<vec1.at(4)<<" ";
    // cout<<vec1.capacity()<<endl;

    // vec1.erase(vec1.begin()+2,vec1.begin()+4);\
    // vec1.insert(vec1.begin()+2,100);
    // vec1.clear();
    //  for(int num:vec1){
    //     cout<<num<<" ";
    // }
    // cout<<" is empty:"<<vec1.empty();


    
}