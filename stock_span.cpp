#include<iostream>
#include <stdio.h>
#include <stdlib.h>

struct stack 
{
    int data;
    struct stack *next;
};

void pop(struct stack **head)
{
    struct stack *curr=*head;
    *head=curr->next;
}

void push(struct stack **head, int d)
{
    struct stack *node=(struct stack *)malloc(sizeof(struct stack));
    node->data=d;
    node->next=*head;
    *head=node;
}

int isempty(struct stack **head)
{
    return !*head;
}

int top(struct stack **head)
{
    struct stack *curr=*head;
    return curr->data;
}


int main() {
    int t;
    printf("Enter test cases : ");
    scanf("%d",&t);
    int k=0;
    
    for(k=0;k<t;k++)
    {
        struct stack *head=NULL;
        int n,i;
        printf("Enter length of array : ");
        scanf("%d",&n);
        int arr[n];
        printf("Enter array :\n");
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        
        for(i=0;i<n;i++)
        {
            if(isempty(&head))
            {
                push(&head,i);
                printf("1 ");
            }
            else
			{
				if(arr[i]<arr[top(&head)])
            	{
               	 printf("1 ");
               	 push(&head,i);
            	}
            	else
            	{
               		while((!isempty(&head)) && arr[i]>arr[top(&head)])
                	{
                    	pop(&head);
                	}
                	if(!isempty(&head))
                	{
                		printf("%d ",i-top(&head));
                		push(&head,i);
					}
                	else if(isempty(&head))
                	{
                		printf("%d ",i+1);
                		push(&head,i);
					}
            	}
        	}
    	}
    	printf("\n");
	}
	
	return 0;
}
