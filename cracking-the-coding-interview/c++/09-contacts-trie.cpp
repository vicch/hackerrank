// Problem:
// Implement a Contacts class that performs two operations:
// - add name, stores name as a new contact.
// - find partial, searches the partial name, counts the number of contacts
//   starting with it and print the count on a new line
// Assume name and partial contain only lowercase letters.
// 
// Example:
// Input: add hack
//        add hackerrank
//        find hac
//        find hak
// Output: 2
//         0

#include <iostream>

using namespace std;

struct Node {
    int count;
    Node* next[26];
};

class Contacts {
protected:
    Node* root;

public:
    Contacts()
    {
        root = new Node;
    }

    void add(string name)
    {
        int i;
        Node* curr;

        for (curr = root, i = 0; name[i] != '\0'; i++) {
            // Current node count increments
            curr->count++;
            // Create next node if not exist
            if (!curr->next[name[i] - 'a'])
                curr->next[name[i] - 'a'] = new Node;
            curr = curr->next[name[i] - 'a'];
        }
        // End node count increments
        curr->count++;

        return;
    }

    int find(string name)
    {
        int i;
        Node* curr;

        for (curr = root, i = 0; curr != NULL && name[i] != '\0'; i++)
            curr = curr->next[name[i] - 'a'];

        return (curr ? curr->count : 0);
    }
};

int main()
{
    int n, i;
    string op, name;
    Contacts contacts;

    cin >> n;

    for (i = 0; i < n; i++) {
        cin >> op >> name;
        if (op == "add")
            contacts.add(name);
        else if (op == "find")
            cout << contacts.find(name) << endl;
    }

    return 0;
}