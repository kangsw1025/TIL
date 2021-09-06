#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> pre, pos;

struct node {
    int idx;
    int value;
    node* left = NULL;
    node* right = NULL;
    
    node(int n, int v) {
        idx = n;
        value = v;
    }
};

void insert(node * to, node* n) {
        int to_value = to->value;
        int n_value = n->value;
        
        if(to_value>n_value) {
            if(to->left==NULL) to->left = n;
            else insert(to->left,n);
        }
        else if(to_value<n_value) {
            if(to->right==NULL) to->right = n;
            else insert(to->right,n);
        }
}

void prefix(node* n) {
    pre.push_back(n->idx);
    if(n->left != NULL) prefix(n->left);
    if(n->right != NULL) prefix(n->right);
}
    
void postfix(node *n) {
    if(n->left != NULL) postfix(n->left);
    if(n->right != NULL) postfix(n->right);
    pos.push_back(n->idx);
}

bool cmp(pair<int,pair<int,int>> p1, pair<int,pair<int,int>> p2) {
    return p1.first>p2.first;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<pair<int,pair<int,int>>> v;
    for(int i=0;i<nodeinfo.size();i++) {
        int value = nodeinfo[i][0];
        int height = nodeinfo[i][1];
        v.push_back({height,{i+1,value}});
    }
    
    sort(v.begin(),v.end(),cmp);
    
    node *head = new node(v[0].second.first,v[0].second.second);
    
    for(int i=1;i<v.size();i++) {
        node * n_node = new node(v[i].second.first, v[i].second.second);
        insert(head, n_node);
    }
    prefix(head);
    postfix(head);
    answer.push_back(pre);
    answer.push_back(pos);
    return answer;
}