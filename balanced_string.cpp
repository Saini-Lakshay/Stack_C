#include<iostream>
#include<stdio.h>
#include<stdlib.h>

struct stack
{
	char ch;
	struct stack *next;	
};

void pop(struct stack **head)
{
	struct stack *curr=*head;
	*head=curr->next;	
}

void push(struct stack **head,char c)
{
	struct stack *node = (struct stack *)malloc(sizeof(struct stack));
	node->ch = c;
	node->next = *head;
	*head = node;
}

char top(struct stack **head)
{
	struct stack *curr=*head;
	return curr->ch;
}

int isempty(struct stack **head)
{
	if(*head == NULL)
	return 1;
	return 0;
}

int main()
{
	struct stack *head=NULL;
	int i=0;
	char st[60];
	printf("Enter the string : ");
	gets(st);
	
	while(st[i] != '\0')
	{
		if(st[i]=='(' || st[i]=='{')
		{
			push(&head,st[i]);
		}
		else
		{
			if(isempty(&head))
			{
				printf("Not Balanced");
				return 0;
			}
			else if(top(&head) == '(' && st[i] == ')')
			{
				pop(&head);
			}
			else if(top(&head) == '{' && st[i] == '}')
			{
				pop(&head);
			}
			else
			{
				printf("Not balanced");
				return 0;
			}
		}
		i++;
	}
	printf("Balanced");
	
	return 0;
}
