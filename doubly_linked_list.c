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
		head->prev=NULL;
		head->next=NULL;
	}
	else
	{
		t=head;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		t->next=(struct node *)malloc(sizeof(struct node));
		t->next->data=e;
		t->next->prev=t;
		t->next->next=NULL;
	}
	
}
void disp()
{
	struct node *t;
	t=head;
	printf("\nThe elemets are:");
	while(t!=NULL)
	{
		printf("%d\t",t->data);
		t=t->next;
	}
}
void delete(int e)
{
	struct node *t;
	if(head==NULL)
	{
		printf("\nList is empty\n");
	}
	else if(head->data==e&&head->next==NULL)
	{
		head=head->next;
	}
	else if(head->data==e)
	{
		head=head->next;
		head->prev=NULL;
	}
	else
	{
		t=head->next;
		while(t!=NULL&&t->data!=e)
		{
			t=t->next;
		}
		if(t==NULL)
		{
			printf("\nElement not found\n");
		}
		else if(t->next==NULL)
		{
			t->prev->next=NULL;
			
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
		t=head;
		while(t->next!=NULL)
		{
			t=t->next;
		}
		printf("\n reverse is :");
		while(t!=NULL)
		{
		printf("%d\t",t->data);
		t=t->prev;
		}
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

