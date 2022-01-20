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
    printf("\n CHOOSE 'I or i' FOR INSERT, 'D or d' FOR DELETE , 's or S' FOR DELETE& 'E or e' FOR EXIT\n");
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
            case 'D':
            {
            	int data;
                printf("\n Enter the data(int) to be deleted:");
	            scanf("%d",&data);
                deleteLeaf(root,data);
                break;
            }
            case 'd':
            {
            	int data;
                printf("\n Enter the data(int) to be deleted:");
	            scanf("%d",&data);
                deleteLeaf(root,data);
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

struct tree_leaf* minLeaf(struct tree_leaf* node)
{
    struct tree_leaf* thisLeaf = node;
    while (thisLeaf && thisLeaf->left_leaf != NULL)
        thisLeaf = thisLeaf->left_leaf;

    return thisLeaf;
}


struct tree_leaf* deleteLeaf(struct tree_leaf* root, int key)
{

    if (root == NULL)
        return root;

    if (key < root->data)
        root->left_leaf = deleteLeaf(root->left_leaf, key);

    else if (key > root->data)
        root->right_leaf = deleteLeaf(root->right_leaf, key);

    else {

        if (root->left_leaf == NULL) {
            struct tree_leaf* temp = root->right_leaf;
            free(root);
            return temp;
        }
        else if (root->right_leaf == NULL) {
            struct tree_leaf* temp = root->left_leaf;
            free(root);
            return temp;
        }

        struct tree_leaf* temp = minLeaf(root->right_leaf);
        root->data = temp->data;
        root->right_leaf = deleteLeaf(root->right_leaf,temp->data);
    }
    return root;
}


