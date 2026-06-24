#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <set>
#include <ctime>
using namespace std;

class User {
public:
    string name;
    string dob;
    int comments;

    User() {}
    User(string name, string dob, int comments) {
        this->name = name;
        this->dob = dob;
        this->comments = comments;
    }
};

map<string, User> users;
map<string, vector<string>> adjList;


void addUser(string name, string dob, int comments) {
    users[name] = User(name, dob, comments);
    adjList[name] = vector<string>();
}

void addFriend(string u1, string u2) {
    adjList[u1].push_back(u2);
    adjList[u2].push_back(u1);
}

void maxFriends() {
    string maxUser = "";
    int maxCount = 0;

    for (auto &pair : adjList) {
        int count = pair.second.size();
        if (count > maxCount) {
            maxCount = count;
            maxUser = pair.first;
        }
    }

    cout << "User with maximum friends: " << maxUser 
         << " (" << maxCount << ")" << endl;
}

void maxMinComments() {
    string maxUser = "", minUser = "";
    int maxComments = INT_MIN;
    int minComments = INT_MAX;

    for (auto &pair : users) {
        User u = pair.second;

        if (u.comments > maxComments) {
            maxComments = u.comments;
            maxUser = u.name;
        }

        if (u.comments < minComments) {
            minComments = u.comments;
            minUser = u.name;
        }
    }

    cout << "Maximum comments: " << maxUser 
         << " (" << maxComments << ")" << endl;

    cout << "Minimum comments: " << minUser 
         << " (" << minComments << ")" << endl;
}

void birthdayThisMonth() {
    time_t t = time(0);
    tm* now = localtime(&t);
    int currentMonth = now->tm_mon + 1;

    cout << "Users having birthday this month:" << endl;

    for (auto &pair : users) {
        User u = pair.second;

        int day, month, year;
        sscanf(u.dob.c_str(), "%d-%d-%d", &day, &month, &year);

        if (month == currentMonth) {
            cout << u.name << endl;
        }
    }
}

void BFS(string start) {
    set<string> visited;
    queue<string> q;

    visited.insert(start);
    q.push(start);

    cout << "BFS: ";

    while (!q.empty()) {
        string user = q.front();
        q.pop();
        cout << user << " ";

        for (string friendName : adjList[user]) {
            if (visited.find(friendName) == visited.end()) {
                visited.insert(friendName);
                q.push(friendName);
            }
        }
    }
    cout << endl;
}

void DFS(string start, set<string> &visited) {
    visited.insert(start);
    cout << start << " ";

    for (string friendName : adjList[start]) {
        if (visited.find(friendName) == visited.end()) {
            DFS(friendName, visited);
        }
    }
}

int main() {

    addUser("A", "10-03-2000", 15);
    addUser("B", "25-07-1999", 30);
    addUser("C", "05-03-2001", 5);
    addUser("D", "18-12-1998", 20);

    addFriend("A", "B");
    addFriend("A", "C");
    addFriend("B", "D");

    maxFriends();
    maxMinComments();
    birthdayThisMonth();

    BFS("A");

    cout << "DFS: ";
    set<string> visited;
    DFS("A", visited);

    return 0;
}