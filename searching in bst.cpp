#include<iostream>
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

void searchRoot(node *root,int d){
    if(root==NULL){
        cout << "NOT FOUND" << endl;
        return;
    }
    if(root->data==d){
        cout << "FOUND" << endl;
        return;
    }
    if(d<root->data){
        searchRoot(root->left,d);
    }
    if(d>root->data){
        searchRoot(root->right,d);
    }
}

void printInOrder(node *root){
    if(root==NULL){
        return;
    }

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);

}

int main(int argc, char const *argv[])
{
    node *root=buildTree();
    printInOrder(root);
    cout << endl;
    searchRoot(root,4);
    return 0;
}