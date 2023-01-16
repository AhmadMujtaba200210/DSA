#include<iostream>
using namespace std;

class Node{
    public:
    Node *left,*right;
    int key;

    Node(int key){
        this->key;
        left=right=NULL;
    }    
};

Node* insert(Node*root,int key){
    
    if(root==NULL) return new Node(key);

    if(key<root->key) root->left=insert(root->left,key);
    else root->right=insert(root->right,key);

    return root;
}
void display(Node*root){
    if(root==NULL) return;

    display(root->left);
    cout<<root->key<<", ";
    display(root->right);

}

bool search(Node*root,int key){
    if(root==NULL) return false;

    if (root->key==key)
    {
        return true;
    }

    if (key<root->key)
    {
        return search(root->left,key);
    }
    return search(root->right,key);
}

int main(){
    Node* root;

    int arr[]={8,2,3,10,9,4,15};

    for(int x: arr){
        root=insert(root,x);
    }

    display(root);

    cout<<search(root,8);
}