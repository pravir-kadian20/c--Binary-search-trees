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

void printInOrder(node *root){
    if(root==NULL){
        return;
    }

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);

}
class LinkedList{
public:
    node *head;
    node *tail;
};

LinkedList flattenTree(node *root){

    LinkedList l;
    //This is a base case if tree is empty so we will not hit this base case if our tree has even one node
    if(root==NULL){
        l.head=NULL;
        l.tail=NULL;
        return l;
    }
    //we will hit this base case if the tree is not empty
    if(root->left==NULL && root->right==NULL){//that is we have only one node
        l.head=root;
        l.tail=root;
        return l;
    }

    if(root->left!=NULL && root->right==NULL){
        LinkedList left=flattenTree(root->left);
        left.tail->right=root;

        l.head=left.head;
        l.tail=root;
        return l;
    }
    if(root->right!=NULL && root->left==NULL){
        LinkedList right=flattenTree(root->right);
        root->right=right.head;

        l.head=right.head;
        l.tail=right.tail;
        return l;
    }
    if(root->right!=NULL && root->left!=NULL){
        LinkedList left=flattenTree(root->left);
        LinkedList right=flattenTree(root->right);
        left.tail->right=root;
        root->right=right.head;

        l.head=root;
        l.tail=right.tail;
        return l;
    }
}



int main(int argc, char const *argv[])
{
    node *root=buildTree();
    printInOrder(root);
    cout << endl;
    
    LinkedList L=flattenTree(root);

    node *temp=L.head;
    while(temp!=NULL){
        cout << temp->data << "->";
        temp=temp->right;
    }
    cout << endl;
    return 0;
}
