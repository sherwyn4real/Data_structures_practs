#include<stdio.h>
#include<stdlib.h>
# define MAX 10
struct node *tree[MAX];
int front=-1, rear=-1;
struct node *insert(struct node *ptr, int item);
void preorder(struct node *ptr);
void inorder(struct node *ptr);
void postorder(struct node *ptr);
void level_trav(struct node *root);
void insert_tree(struct node *item);
struct node *del_queue();
int queue_empty();
struct node{
	struct node *lchild;
	int info;
	struct node *rchild;
};
int main(){
	struct node *root = NULL;
	int i, k;
	printf("Enter values:\n");
	for(i=0; i<10; i++){
		scanf("%d", &k);
		root = insert(root, k);
	}
	printf("\nPreorder: ");preorder(root);
	printf("\nInorder: ");inorder(root);
	printf("\nPostorder: ");postorder(root);
	printf("\nLevel order: ");level_trav(root);	
}
struct node *insert(struct node *ptr, int item){
	if(ptr==NULL){
		ptr = (struct node *)malloc(sizeof(struct node));
		ptr->info = item;
		ptr->lchild = NULL;
		ptr->rchild = NULL;
	}
	else if(item < ptr->info)
		ptr->lchild = insert(ptr->lchild, item);
	else if(item > ptr->info)
		ptr->rchild = insert(ptr->rchild, item);
	else
		printf("\nDuplicate Key");
	return ptr;
}
void preorder(struct node *ptr){
	if(ptr == NULL)
		return;
	printf("%d ", ptr->info);
	preorder(ptr->lchild);
	preorder(ptr->rchild);	
}
void inorder(struct node *ptr){
	if(ptr == NULL)
		return;
	inorder(ptr->lchild);
	printf("%d ", ptr->info);
	inorder(ptr->rchild);
}
void postorder(struct node *ptr){
	if(ptr == NULL)
		return;
	postorder(ptr->lchild);
	postorder(ptr->rchild);
	printf("%d ", ptr->info);
}
void insert_tree(struct node *item){
	if(rear == MAX-1){
		printf("Queue Overflow\n");
		return;
	}
	if(front == -1)	
		front = 0;
	rear = rear + 1;
	tree[rear] = item;
}
struct node *del_queue(){
	struct node *item;
	if(queue_empty()){
		printf("Queue Underflow\n");
		return 0;
	}
	item = tree[front];
	front = front + 1;
	return item;
}
int queue_empty(){
	if(front == -1 || front == rear+1)
		return 1;
	else
		return 0;
}
void level_trav(struct node *root){
	struct node *ptr = root;
	if(ptr == NULL){
		printf("Tree is empty\n");
		return;
	}
	insert_tree(ptr);
	while(!queue_empty()){
		ptr = del_queue();
		printf("%d ", ptr->info);
		if(ptr->lchild != NULL)
			insert_tree(ptr->lchild);
		if(ptr->rchild != NULL)
			insert_tree(ptr->rchild);
	}
	printf("\n");
}

