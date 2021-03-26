#include <iostream>
#include <string>
using namespace std;

typedef struct Node {
	char data;
	struct Node* left;
	struct Node* right;

}Node;
typedef struct Node* Tree;

void inorder(Node* tree) {
	if (tree != NULL) {
		inorder(tree->left);
		cout << tree->data;
		inorder(tree->right);
	}
}
void preorder(Node* tree) {
	if (tree != NULL) {
		cout << tree->data;
		preorder(tree->left);
		preorder(tree->right);

	}
}
void postorder(Node* tree) {
	if (tree != NULL) {

		postorder(tree->left);
		postorder(tree->right);
		cout << tree->data;
	}
}

Node* Find(Node* tree, char data) {
	if (tree != NULL) {
		if (tree->data == data)
			return tree;
		else {
			Node* newTree = Find(tree->left, data);
			if (newTree != NULL) {
				return newTree;
			}
			return Find(tree->right, data);
		}
	}
	
	return NULL;
}

int main() {
	int n;
	cin >> n;
	Node* tree = NULL;
	Node* root = NULL;
	Node* node;
	char a, b, c;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b >> c;
		if (root == NULL) {
			Node* NewNode = new Node;
			NewNode->data = a;
			NewNode->left = NULL;
			NewNode->right = NULL;
			root = NewNode;
			
			if (b != '.') {
				Node* NewNode = new Node;
				NewNode->data = b;
				NewNode->left = NULL;
				NewNode->right = NULL;
				root->left = NewNode;
				
			}
			if (c != '.') {
				Node* newNode = new Node;
				newNode->data = c;
				newNode->left = NULL;
				newNode->right = NULL;
				root->right = newNode;
				
			}
		}
		else {
			Node* search = Find(root, a);
			
			if (b != '.') {
				Node* newNode = new Node;
				newNode->data = b;
				newNode->left = NULL;
				newNode->right = NULL;
				search->left = newNode;
			}
			if (c != '.') {
				Node* newNode = new Node;
				newNode->data = c;
				newNode->left = NULL;
				newNode->right = NULL;
				search->right = newNode;

			}
		}
	}
	
	preorder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	postorder(root);
}
