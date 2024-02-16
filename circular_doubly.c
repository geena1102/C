#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
struct node *head=NULL;
void insert(int e)
{
	struct node *t;
	if(head==NULL)
	{
		head=(struct node *)malloc(sizeof(struct node));
		head->data=e;
		head->prev=head;
		head->next=head;
	}
	else
	{
		t=head;
		while(t->next!=head)
		{
			t=t->next;
		}
		t->next=(struct node *)malloc(sizeof(struct node));
		t->next->data=e;
		t->next->prev=t;
		t->next->next=head;
		head->prev=t->next;
	}
	
}
void disp()
{
	struct node *t;
	t=head;
	printf("\nThe elemets are:");
	do
	{
		printf("%d\t",t->data);
		t=t->next;
	}while(t!=head);
}
void delete(int e)
{
	struct node *t;
	if(head==NULL)
	{
		printf("\nList is empty\n");
	}
	else if(head->data==e&&head->next==head)
	{
		head=NULL;
	}
	else if(head->data==e)
	{
		head->prev->next=head->next;
		head->next->prev=head->prev;
		head=head->next;
	}
	else
	{
		t=head->next;
		while(t!=head&&t->data!=e)
		{
			t=t->next;
		}
		if(t==head)
		{
			printf("\nElement not found\n");
		}
		else
		{
			t->prev->next=t->next;
			t->next->prev=t->prev;
		}
	}
}
void reverse()
{
	struct node *t;
	if(head==NULL)
	{
		printf("List is empty");
	}
	else
	{
		t=head->prev;
		while(t->next!=head)
		{
			t=t->next;
		}
		printf("\n reverse is :");
		while(t!=head)
		{
		printf("%d\t",t->data);
		t=t->prev;
		}
	//	printf("%d",head->data);
		
	}
}
int main()
{
	insert(10);
	insert(20);
	insert(30);
	insert(40);
	insert(50);
	insert(60);
	disp();
	reverse();
	
	delete(70);
	delete(20);
	disp();
	delete(60);
	disp();
	delete(10);
	disp();
	return 0;
		
}

