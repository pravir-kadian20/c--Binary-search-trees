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

void printInOrder(node *root){
    if(root==NULL){
        return;
    }

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);

}

node *deleteInBst(node *root,int data){
    if(root==NULL){
        return NULL;
    }

    if(data>root->data){
        root->right=deleteInBst(root->right,data);
        return root;
    }
    else if(data<root->data){
        root->left=deleteInBst(root->left,data);
        return root;
    }
    else{
        //it has 3 cases

        //case 1 node to be deleted has 0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        // case 2 node to be deleted has 1 child
        if(root->left==NULL && root->right!=NULL){
            node *temp=root->right;
            delete root;

            return temp;
        }
        if(root->left!=NULL && root->right==NULL){
            node *temp=root->left;
            delete root;

            return temp;
        }
        //case 3 node to be deleted has 2 child
        if(root->left!=NULL && root->right!=NULL){
            node *replace = root->right;

            while(replace->left!=NULL){
                replace=replace->left;
            }
            root->data=replace->data;
            root->right=deleteInBst(root->right,replace->data);

            return root;
        }
    }
}

int main(int argc, char const *argv[])
{
    node *root=buildTree();
    printInOrder(root);
    cout << endl;

    int s;
    cin>>s;
    
    root=deleteInBst(root,s);
    printInOrder(root);
    cout << endl;
    return 0;
}