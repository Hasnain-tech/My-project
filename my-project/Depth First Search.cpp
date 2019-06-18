using namespace std;
#include <iostream>
struct node
{
	int data;
	node *left;
	node *right;
};


struct node *newNode(int item)
{
	struct node *t = (struct node *)malloc(sizeof(struct node));
	t->data = item;
	t->left = t->right = NULL;
	return t;
}

//void preOrder(struct node* r)
//{
//	if (r != NULL){
//		printf("%d ", r->data);
//		preOrder(r->left);
//		preOrder(r->right);
//	}
//}

void inOrder(struct node* r)
{
	if (r != NULL){
		inOrder(r->left);
		printf("%d ", r->data);
		inOrder(r->right);
	}
}

struct node* insert(struct node* node, int key)
{
	if (node == NULL) return newNode(key);
	if (key < node->data)
		node->left = insert(node->left, key);
	else
		node->right = insert(node->right, key);
	return node;
}

void dfs(node *ptr, int n)
{

	if (ptr == NULL)
	{
		return;
	}

	if (n == ptr->data)
	{
		cout << n << " Found in Tree" << endl;
	}

	dfs(ptr->left, n);
	
	dfs(ptr->right, n);	
}


int main()
{
	struct node *root = NULL;
	root = insert(root, 14);
	root = insert(root, 56);
	root = insert(root, 32);
	root = insert(root, 77);
	root = insert(root, 11);
	root = insert(root, 7);
	root = insert(root, 9);

	//cout << "Tree Formed in Pre Order " << endl;
	//preOrder(root);

	dfs(root, 77);

	cout << "Tree Formed in In Order " << endl;
	inOrder(root);

	
	system("pause");
}