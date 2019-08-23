#include<iostream>
#include<stdio.h>
#include<stdlib.h>

struct stack
{
	int data;
	struct stack *next;	
};

void push(struct stack **head, int d)
{
	struct stack *node = (struct stack *)malloc(sizeof(struct stack));
	node->data=d;
	node->next=*head;
	*head=node;
}

void pop(struct stack **head)
{
	struct stack *curr=*head;
	*head=curr->next;
}

int top(struct stack **head)
{
	struct stack *curr=*head;
	return curr->data;
}

int isempty(struct stack **head)
{
	if(*head == NULL)
	return 1;
	return 0;
}

int main()
{
	int t=1;
	
	while(t!=0)
	{
		struct stack *head=NULL;
		int n,n1=0;;
		printf("Enter size of array : ");
		scanf("%d",&n);
		int arr[n];
		int ans[n];
		int i=0;
		
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		scanf("%d",&t);
		i=0;
		
		while(arr[i]!=1)
		{
			push(&head,i);
			i++;
		}
		ans[n1]=1;
		n1++;
		i++;
		
		while(i<n)
		{
			if(arr[i]-ans[n1-1]==1)
			{
				ans[n1]=arr[i];
				n1++;
				i++;
			}
			else
			{
				push(&head,i);
				i++;
			}
		}
		
		while(!isempty(&head))
		{
			ans[n1]=arr[top(&head)];
			n1++;
			pop(&head);
		}
		
		for(i=1;i<n1;i++)
		{
			if(ans[i]-ans[i-1]!=1)
			{
				break;
			}
		}
		if(i==n)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
		
		
		
	}
	
	return 0;
}

