#include<bits/stdc++.h>
using namespace std;

class BST{
	private:
		BST *leftNode;
		int data;
		BST *rightNode;

		public:
		BST()
		{
			leftNode = nullptr;
			data = 0;
			rightNode = nullptr;
		}

	BST(int number){
		leftNode = nullptr;
		data = number;
		rightNode = nullptr;
	}

	BST *insert(BST *root, int value){
		if(!root){
			return new BST(value);
		}

		else if(root -> data > value){
			root->leftNode = insert(root->leftNode, value);
		}
		
		else{
			root->rightNode = insert(root->rightNode, value);
		}
		return root;
	}

	BST *search(BST *root, int value){
		if(root == nullptr|| root->data == value){
			return root;
		}

		else if(root->data < value){
			root->rightNode = search(root->rightNode, value);
		}
		
		else{
			root->leftNode = search(root->leftNode, value);
		}

	}

	void inorder(BST *root){
		if(!root){
			return;
		}

		inorder(root->leftNode);
		cout << root->data << " ";
		inorder(root->rightNode);
	}

	void postorder(BST *root){
		if(!root){
			return;
		}

		postorder(root->rightNode);
		postorder(root->leftNode);
		cout << root->data << " "; 
	}
};

int main(){
	BST b, *root = NULL; 
    root = b.insert(root, 50); 
    b.insert(root, 30); 
    b.insert(root, 20); 
    b.insert(root, 40); 
    b.insert(root, 70); 
    b.insert(root, 60); 
    b.insert(root, 80); 
  
    b.inorder(root);
	 cout << endl;
	 b.postorder(root);
	 return 0; 
}