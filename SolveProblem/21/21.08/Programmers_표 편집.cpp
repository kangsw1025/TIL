#include <string>
#include <stack>
#include <vector>

using namespace std;

struct Node {
    int num;
    Node *prev;
    Node *next;
    Node(int n) {
        num = n;
        prev =NULL;
        next = NULL;
    }
};

struct LinkedList {
    Node *head;
    Node *tail;
    
    LinkedList() {
        head = NULL;
        tail = NULL;
    }
    
    void insert(int n) {
        if(head==NULL) {
            Node *newnode = new Node(n);
            head = newnode;
            tail = newnode;
        }
        else {
            Node *newnode = new Node(n);
            newnode->prev = tail;
            tail->next = newnode;
            tail = tail->next;
        }
    }
    
    Node *erase(Node *node) {
        if(node==head) {
            head = node->next;
            node->next->prev = NULL;
            return node->next;
        }
        else if(node==tail) {
            tail = node->prev;
            node->prev->next = NULL;
            return node->prev;
        }
        else {
            node->prev->next = node->next;
            node->next->prev = node->prev;
            return node->next;
        }
    }
    
};

stack<Node*> st;
LinkedList *ll;

void make_ll(int n) {
    ll = new LinkedList();
    for(int i=0;i<n;i++)
        ll->insert(i);
}

string solve(int n, int k, vector<string> cmd) {
    Node *itr = ll->head;
    for(int i=0;i<k;i++) itr = itr->next;
    
    for(int i=0;i<cmd.size();i++) {
        string op = cmd[i];
        if(op[0]=='U') {
            string x = op.substr(2);
            int X = stoi(x);
            for(int i=0;i<X;i++) itr = itr->prev;
        }
        else if(op[0]=='D') {
            string x = op.substr(2);
            int X = stoi(x);
            for(int i=0;i<X;i++) itr = itr->next;
        }
        else if(op[0]=='C') {
            st.push(itr);
            itr = ll->erase(itr);
        }
        else {
            Node *z = st.top();
            st.pop();
            ll->restore(z);
        }
    }
    
    string rst = "";
    for(int i=0;i<n;i++) rst += 'O';
    while(!st.empty()) {
        Node *n = st.top();
        st.pop();
        
        rst[n->num] = 'X';
    }
    
    return rst;
}

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    make_ll(n);
    answer = solve(n,k,cmd);
   
    return answer;
}