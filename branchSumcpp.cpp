#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		Node *left;
		int data;
		Node *right;
		Node(){
			left = nullptr;
			data = 0;
			right = nullptr;
		}

		Node(int value){
			left = nullptr;
			data = value;
			right = nullptr;
		}

		Node *insert(Node *root, int value){
			if(root == nullptr)
				return new Node(value);

			if(root->data > value){
				root->left = insert(root->left, value);
			}else{
				root->right = insert(root->right, value);
			}
		}

		vector<int> branchSums(Node *root){
			vector<int> sums;
			calculateBranchSum(root, 0, sums);
			return sums;
		}

		void calculateBranchSum(Node *root, int sum, vector<int> &sums){
			if(root == nullptr)
				return;
			int runningSum = sum + root->data;
			if(!root->left && !root->right){
				sums.push_back(runningSum);
				return;
			}

			calculateBranchSum(root->left, runningSum, sums);
			calculateBranchSum(root->right, runningSum, sums);
		}
};

int main(){
	Node *root = new Node(1);
	Node node;
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->left->left->left = new Node(8);
	root->left->left->right = new Node(9);
	root->left->right->right = new Node(10);
	vector<int> sums = node.branchSums(root);
	for (int i = 0; i < sums.size(); i++){
		cout << sums[i] << " ";
	}
		return 0;
}