#include<iostream>
#include<list>
using namespace std;


int hashFunction(string key,int size){
    int sum = 0;
    for(char ch: key){
        sum += ch;
    }
    return sum % size;
}

class client{
public:
    string name;
    string phone;

    client() {}   
    
    client(string n,string p){
        name = n;
        phone= p;
    }
};

class LinearHash{
public:
    int size;
    client* table[100];

    LinearHash(int s){
        size = s;
        for(int i=0;i<size;i++){
            table[i] = NULL;
        }
    }

    void insert(string name,string phone){
        int index = hashFunction(name,size);

        while(table[index]!=NULL){
            index = (index+1)%size;
        }
        table[index] = new client(name,phone);
    }

    int search(string name){
        int index = hashFunction(name,size);
        int comparisons = 1;

        while(table[index]!=NULL){
            if(table[index]->name == name){
                return comparisons;
            }
            index = (index+1)%size;
            comparisons++;
        }
        return -1;
    }

    void display(){
        cout<<"\nLinear Probing Table:\n";
        for(int i=0;i<size;i++){
            if(table[i]!=NULL){
                cout<<i<<" --> "<<table[i]->name<<" : "<<table[i]->phone<<endl;
            }
            else{
                cout<<i<<" --> NULL"<<endl;
            }
        }
    }
};


class chainHash{
public:
    int size;
    list<client> table[100];

    chainHash(int s){
        size = s;
    }

    void insert(string name,string phone){
        int index = hashFunction(name,size);
        table[index].push_back(client(name,phone));
    }

    int search(string name){
        int index = hashFunction(name,size);
        int comparisons = 0;  

        for(auto &c: table[index]){
            comparisons++;
            if(c.name == name){
                return comparisons;
            }
        }
        return -1;
    }

    void display(){
        cout<<"\nChaining Table:\n";
        for(int i=0;i<size;i++){
            cout<<i<<" --> ";
            for(auto &c: table[i]){
                cout<<"[ "<<c.name<<" : "<<c.phone<<" ] -> ";
            }
            cout<<"NULL"<<endl;
        }
    }
};

int main(){
    int size,n;
    cout<<"Enter size of the hash table: ";
    cin>>size;

    LinearHash linear(size);
    chainHash chain(size);

    cout<<"Enter number of clients: ";
    cin>>n;

    string name,phone;

    for(int i=0;i<n;i++){
        cout<<"\nEnter name: ";
        cin>>name;
        cout<<"Enter phone: ";
        cin>>phone;

        linear.insert(name,phone);
        chain.insert(name,phone);
    }

    linear.display();
    chain.display();

    cout<<"\nEnter name to search: ";
    cin>>name;

    int lincompare = linear.search(name);
    int chaincompare = chain.search(name);

    cout<<"\nSearch Comparison:\n";

    if(lincompare!=-1)
        cout<<"Linear Probing comparisons: "<<lincompare<<endl;
    else
        cout<<"Not found in linear probing\n";

    if(chaincompare!=-1)
        cout<<"Chaining comparisons: "<<chaincompare<<endl;
    else
        cout<<"Not found in chaining\n";

    return 0;
}