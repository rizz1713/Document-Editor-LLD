#include <iostream>
using namespace std;

int main() {

    cout << "Sender Side:" << endl;

    string data = "1100";
    string key = "1011";
    int key_len = key.length();
    string temp = data;
    for(int i = 0; i < key_len - 1; i++) {
        temp += '0';
    }
    cout<<"Data after appending zeros: " << temp << endl;
    string remainder = temp;
    while(remainder.length() >= key.length()) {
        for(int i = 0; i < key.length(); i++) {
            remainder[i] = ((remainder[i] - '0') ^ (key[i] - '0')) + '0';
        }
        int pos = remainder.find('1');
        if(pos == -1) {
            remainder = "";
            break;
        }
        remainder = remainder.substr(pos);
    }
    while(remainder.length() < key_len - 1) {
        remainder = '0' + remainder;
    }
    cout<<"CRC Remainder: "<< remainder << endl;
    string transmitted = data + remainder;
    cout <<"Transmitted Data: " << transmitted << endl;

    cout<<"Receiver Side:"<<endl;
    string received = transmitted;
    string check = received;
    while(check.length()>=key.length()) {
        for(int i=0;i<key.length();i++) {
            check[i] = ((check[i] - '0') ^ (key[i] - '0')) + '0';
        }
        int pos = check.find('1');
        if(pos == -1) {
            check = "";
            break;
        }
        check = check.substr(pos);
    }

    while(check.length() < key_len - 1) {
        check = '0' + check;
    }

    cout << "Remainder at Receiver: " << check << endl;
    if(check == string(key_len - 1, '0')) {
        cout << "No Error in Transmission" << endl;
    } else {
        cout << "Error Detected in Transmission" << endl;
    }
    return 0;
}