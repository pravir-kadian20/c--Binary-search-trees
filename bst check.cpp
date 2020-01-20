#include<iostream>
#include<climits>
using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;

    node(int d){
        data=d;
        left=NULL;
        right=NULL;
    }
};

node *insertInBst(node *root,int data){
    if(root==NULL){
        return new node(data);
    }

    if(data<=root->data){
        root->left=insertInBst(root->left,data);
    }
    else{
        root->right=insertInBst(root->right,data);
    }
    return root;
}

node *buildTree(){
    int d;
    cin>>d;

    node *root=NULL;

    while(d!=-1){
        root=insertInBst(root,d);
        cin>>d;
    }
    return root;
}
bool isTreeBst(node *root,int minv=INT_MIN,int maxv=INT_MAX){
    if(root==NULL){
        return true;
    }
    if(root->data >= minv && root->data <= maxv && isTreeBst(root->left,minv,root->data) && isTreeBst(root->right,root->data,maxv)){
        return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    node *root=buildTree();
    printInOrder(root);
    cout << endl;
    if(isTreeBst(root)){
        cout << "YES" << endl;
    }
    else{
        cout << "NOT A BST" << endl;
    }
    
    return 0;
}