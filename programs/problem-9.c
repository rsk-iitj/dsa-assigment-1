#include <stdio.h>
#include <stdlib.h>

struct tree_leaf
{
	int data;
	struct tree_leaf* left_leaf;
	struct tree_leaf* right_leaf;
};
/*
struct Tree
{
	struct tree_leaf* root;
};*/

struct tree_leaf* deleteLeaf(struct tree_leaf*, int);
void inorder(struct tree_leaf* root);
void preorder(struct tree_leaf* root);
void postorder(struct tree_leaf* root);

struct tree_leaf* insertIntoTree(struct tree_leaf*,int);

struct tree_leaf* createTreeLeaf(int data)
{

	struct tree_leaf* temp_leaf = (struct tree_leaf*)malloc(sizeof(struct tree_leaf));
	temp_leaf->data = data;
	temp_leaf->left_leaf = NULL;
	temp_leaf->right_leaf = NULL;
	return  temp_leaf;
}

/*struct Tree* createTree()
{

	struct Tree* temp_tree = (struct Tree*)malloc(sizeof(struct Tree));
	return temp_tree;
}*/



struct tree_leaf* insertIntoTree(struct tree_leaf* root,int data)
{

	if(root==NULL)
	{
		return createTreeLeaf(data);
	}

	if (data < root->data)
        root->left_leaf = insertIntoTree(root->left_leaf,data);
    else if (data > root->data)
        root->right_leaf = insertIntoTree(root->right_leaf,data);

    return root;

}

/*void insert(struct Tree* tree)
{
	int data;
	printf("\n Enter the data(int) to be inserted into Tree-:");
	scanf("%d",&data);
	if(tree->root==NULL)
	{
		tree->root = insertIntoTree(tree->root,data);
	}
	else
	{
		insertIntoTree(tree->root,data);
	}

	return tree;
}*/


struct tree_leaf* searchTree(struct tree_leaf* root, int data)
{
    if(root==NULL)
        return NULL;
    if(data == root->data)
        return root;
	if(data < root->data)
       return searchTree(root->left_leaf,data);
    if(data> root->data)
       return searchTree(root->right_leaf,data);
}

void search(struct tree_leaf* root)
{
	int data;
	printf("\n Enter the data(int) to be searched-:");
	scanf("%d",&data);
	struct tree_leaf* result = searchTree(root,data);
	if(result == NULL)
	{
		printf("\n Searched item not found in Tree");
	}
	else
	{
		printf("\n Searched item found in Tree");
	}
}


int main(int argc, char const *argv[])
{
	//struct Tree* tree = createTree();

	struct tree_leaf* root = NULL;
    char operation;
    printf("\n SELECT THE OPERATION WHICH YOU WANT TO PERFORM\n");
    printf("\n CHOOSE 'I or i' FOR INSERT,'o' for INORDER, 'r' for PREORDER, 't' POSTORDER TRAVERSAL or e' FOR EXIT\n");
    do
    {
        printf("\n Enter the operation:-");
        scanf(" %c",&operation);
        switch(operation)
        {
            case 'i' :
            {
                int data;
                printf("\n Enter the data(int) to be inserted into Tree-:");
	            scanf("%d",&data);
                if(root==NULL)
                    root= insertIntoTree(root,data);
                else
                    insertIntoTree(root,data);
                break;
            }
            case 'I':
            {
                int data;
                printf("\n Enter the data(int) to be inserted into Tree-:");
	            scanf("%d",&data);
                if(root==NULL)
                    root= insertIntoTree(root,data);
                else
                    insertIntoTree(root,data);
                break;
            }
            case 'o':
            {
            	inorder(root);
                break;
            }
            case 'r':
            {
                preorder(root);
                break;
            }
            case 't':
            {
                postorder(root);
                break;
            }
            case 's':
            {
                search(root);
                break;
            }
            case 'S':
            {
                search(root);
                break;
            }
            case 'E':
            {
                printf("\n\t EXITING....!");
                break;
            }
            case 'e':
            {
                printf("\n\t EXITING....! ");
                break;
            }
            default:
            {
                printf ("\n Please Enter a Valid Choice(P/p,E/e,D/d or i/I)");
            }

        }
    }
    while(operation!='E' && operation!='e' );
    return 0;
}


void inorder(struct tree_leaf* root)
{
    if (root != NULL) {
        inorder(root->left_leaf);
        printf("%d \n", root->data);
        inorder(root->right_leaf);
    }
}


void preorder(struct tree_leaf* root)
{
    if (root != NULL) {
        printf("%d \n", root->data);
        inorder(root->left_leaf);
        inorder(root->right_leaf);
    }
}


void postorder(struct tree_leaf* root)
{
    if (root != NULL) {
        inorder(root->left_leaf);
        inorder(root->right_leaf);
        printf("%d \n", root->data);
    }
}





