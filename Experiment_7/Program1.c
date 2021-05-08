#include<stdio.h>
#include<stdlib.h>
# define MAX 10
struct node *insert(struct node *ptr, int ikey);
struct node *search(struct node *ptr, int skey);
struct node *del(struct node *ptr, int dkey);
void preorder(struct node *ptr);
void inorder(struct node *ptr);
void postorder(struct node *ptr);
struct node{
	struct node *lchild;
	int info;
	struct node *rchild;
};


int main(){
	struct node *root = NULL, *ptr;
	int ch, data;
	while(1){
		printf("\n-----------------------------------------");
		printf("\n1. Insert \n2. Search \n3. Delete \n4. Display\n5. Quit");
		printf("\nEnter Choice: ");
		scanf("%d",&ch);
		printf("\n-----------------------------------------");
		switch(ch){
			case 1: printf("\nEnter element to be inserted: ");
					scanf("%d", &data);
					root = insert(root,data);
					break;
					
			case 2: printf("\nEnter element to be searched: ");
					scanf("%d", &data);
					ptr = search(root,data);
					if(ptr== NULL)
						printf("\nKey not found");
					else
						printf("\nKey found");
					break;
			
			case 3: printf("\nEnter element to be deleted: ");
					scanf("%d", &data);
					root = del(root,data);
					break;
					
			case 4: printf("\nPreorder: ");
					preorder(root);
					printf("\nInorder: ");
					inorder(root);
					printf("\nPostorder: ");
					postorder(root);
					break;
		
			case 5: exit(1);
			
			default: printf("\nWRONG CHOICE");
					 break;
		}
	}	
}
struct node *insert(struct node *ptr, int ikey){
	if(ptr==NULL){
		ptr = (struct node *)malloc(sizeof(struct node));
		ptr->info = ikey;
		ptr->lchild = NULL;
		ptr->rchild = NULL;
	}
	else if(ikey < ptr->info)
		ptr->lchild = insert(ptr->lchild, ikey);
	else if(ikey > ptr->info)
		ptr->rchild = insert(ptr->rchild, ikey);
	else
		printf("\nDuplicate Key");
	return ptr;
}
struct node *search(struct node *ptr, int skey){
	if(ptr == NULL){
		printf("\nKey not found");
		return NULL;
	}	
	else if(skey < ptr->info)
		return search(ptr->lchild, skey);
	else if(skey > ptr->info)
		return search(ptr->rchild, skey);
	else
		return ptr;
}
struct node *del(struct node *ptr, int dkey){
	struct node *temp, *succ;
	if(ptr == NULL){
		printf("\nKey not present in tree");
		return ptr;
	}
		
	if(dkey < ptr->info)
			ptr->lchild = del(ptr->lchild, dkey);
	else if(dkey > ptr->info)
		ptr->rchild = del(ptr->rchild, dkey);
	else{
		if(ptr->lchild != NULL && ptr->rchild != NULL){
			succ = ptr->rchild;
			while(succ->lchild != NULL)
				succ = succ->lchild;
			ptr->info = succ->info;
			ptr->rchild = del(ptr->rchild, succ->info);
		}
		else{
			temp = ptr;
			if(ptr->lchild != NULL)
				ptr = ptr->lchild;
			else if(ptr->rchild != NULL)
				ptr = ptr->rchild;
			else
				ptr = NULL;
			free(temp);	
		}
	}
	return ptr;	
}
void preorder(struct node *ptr){
	if(ptr == NULL)
		return;
	printf(" %d", ptr->info);
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
