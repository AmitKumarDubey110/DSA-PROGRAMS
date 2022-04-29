#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

//defining the structure
typedef struct nodetype
{
	int info;
	struct nodetype *next;
}node;

//function prototypes
void CreateEmptyList(node **head);
void TraverseInOrder(node *head);
void InsertAtBeginning(node **head, int item);
void TraverseInReverseOrder(node *head);
void InsertAtEnd(node **head, int item);
void InsertAfterElement(node *head, int item, int after);
node *Search(node *head, int item);
node *SearchInSorted(node *head, int item);
void DeleteFromBeginning(node **head);
void DeleteFromEnd(node **head);
void DeleteAfterElement(node *head, int item);

//main function
void main()
{
	node *head;
	int choice,element,after;
	clrscr();
	CreateEmptyList(&head);
	while(1)
	{
		printf("\nOperations available are:");
		printf("\n1.Insert at beginning \n2.Traverse in order \n3.Traverse in reverse order\n4.Insert at end\n5.Search\n6.Insert after element\n7.Search in sorted list\n8.Delete from beginning\n9.Delete from end\n10.Delete after element\n");
		printf("Enter choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter element:");
				scanf("%d",&element);
				InsertAtBeginning(&head, element);
				break;
			case 2:
				if(head==NULL)
					printf("The list is empty");
				else
					TraverseInOrder(head);
				break;
			case 3:
				if(head==NULL)
					printf("The list is empty");
				else
					TraverseInReverseOrder(head);
				break;
			case 4:
				printf("Enter element:");
				scanf("%d",&element);
				InsertAtEnd(&head,element);
				break;
			case 5:
				printf("Enter element:");
				scanf("%d",&element);
				printf("%d",Search(head,element));
				break;
			case 6:
				printf("Enter element after which to store:");
				scanf("%d",&after);
				printf("Enter element:");
				scanf("%d",&element);
				InsertAfterElement(head,element,after);
				break;
			case 7:
				printf("Enter element:");
				scanf("%d",&element);
				printf("%d",SearchInSorted(head,element));
				break;
			case 8:
				DeleteFromBeginning(&head);
				break;
			case 9:
				DeleteFromEnd(&head);
				break;
			case 10:
				printf("Enter element:");
				scanf("%d",&element);
				DeleteAfterElement(head,element);
				break;
			default:
				exit(0);
		}
	}
}

//Function definitions
void CreateEmptyList(node **head)
{
	*head = NULL;
}

void InsertAtBeginning(node **head, int item)
{
	node *ptr;
	ptr = (node*)malloc(sizeof(node));
	ptr->info = item;
	if(*head==NULL)
		ptr->next=NULL;
	else
		ptr->next=*head;
	*head=ptr;
}

void TraverseInOrder(node *head)
{
	while(head!=NULL)
	{
		printf("%d\n", head->info);
		head = head->next;
	}
}

void TraverseInReverseOrder(node *head)
{
	if(head->next!=NULL)
		TraverseInReverseOrder(head->next);
	printf("%d\n",head->info);
}

void InsertAtEnd(node **head, int item)
{
	node *ptr, *loc;
	ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	ptr->next=NULL;
	if(*head==NULL)
		*head=ptr;
	else
	{
		loc=*head;
		while(loc->next!=NULL)
			loc=loc->next;
		loc->next=ptr;
	 }
}

node *Search(node *head, int item)
{
	while((head!=NULL) && (head->info!=item))
		head=head->next;
	return head;
}

node *SearchInSorted(node *head, int item)
{
	while(head!=NULL)
	{
		if(item < head->info)
			return NULL;
		else if(head->info==item)
			return head;
		else
			head=head->next;
	}
	return NULL;
}

void InsertAfterElement(node *head, int item, int after)
{
	node *ptr, *loc;
	loc=Search(head,after);
	if(loc==(node*)NULL)
		return;
	ptr=(node*)malloc(sizeof(node));
	ptr->info=item;
	ptr->next=loc->next;
	loc->next=ptr;
}

void DeleteFromBeginning(node **head)
{
	node *ptr;
	if(*head==NULL)
		return;
	else
	{
		ptr=*head;
		*head=(*head)->next;
		free(ptr);
	}
}

void DeleteFromEnd(node **head)
{
	node *ptr,*loc;
	if(*head==NULL)
		return;
	else if((*head)->next==NULL)
	{
		ptr=*head;
		*head=NULL;
		free(ptr);
	}
	else
	{
		loc=*head;
		ptr=(*head)->next;
		while(ptr->next!=NULL)
		{
			loc=ptr;
			ptr=ptr->next;
		}
		loc->next=NULL;
		free(ptr);
	}
}

void DeleteAfterElement(node *head, int item)
{
	node *ptr,*loc;
	loc=Search(head,item);
	if(loc==(node*)NULL)
		return;
	ptr=loc->next;
	loc->next=ptr->next;
	free(ptr);
}