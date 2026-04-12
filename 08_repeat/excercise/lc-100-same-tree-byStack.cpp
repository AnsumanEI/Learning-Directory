#include<iostream>
#include <bits/stdc++.h>
#include<math.h>
#include <strings.h>
#include <string>
#include <cstring>
using namespace std;
class node {
    public:
    int val;
    node* left ;
    node* right;

    node(){
        val = NULL;
        left = nullptr;
        right = nullptr;
    }
    node(int val){
        this->val = val;
        left = nullptr;
        right = nullptr;
    }
};
void buildTree(node *& root)
{
    int val;

    cout<<"Enter the value of the root : \n";
    cin>>val;

    if (val == -1) return ;

    root = new node(val);
    buildTree(root->left);
    buildTree(root->right);

}
bool isSametreeStack(node* p , node* q){
    stack <pair<node*, node*>> visits;
    visits.push({p,q});

    while(!visits.empty()){
        //auto [node1 , node2] = visits.top();
        pair<node* , node*> current = visits.top();
        visits.pop();

        node* temp1 = current.first;
        node* temp2 = current.second;

        if ( temp1 == nullptr && temp2 == nullptr) continue;
        else if(temp1 == nullptr|| temp2 == nullptr) return false;
        else if (temp1->val != temp2->val) return false;

        visits.push({temp1->left , temp2->left});
        visits.push({temp1->right , temp2->right});
    }
    return true;
}
int main()
{

return 0;
}