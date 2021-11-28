/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 23:55:36 by bokim             #+#    #+#             */
/*   Updated: 2021/11/29 00:30:30 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedstack.h"
#include <stdio.h>
#include <stdlib.h>

LinkedStack *createLinkedStack()
{
	LinkedStack *linkedStack = (LinkedStack *)malloc(sizeof(LinkedStack));
	linkedStack->currentElementCount = 0;
	linkedStack->pTopElement = NULL;
	return (linkedStack);
}

int pushLS(LinkedStack *pStack, StackNode element)
{
	if (isLinkedStackFull(pStack)){
		fprintf(stderr, "Stack is full!\n");
		exit(1);
	}
	else
	{
		StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
		*newNode = element;
		newNode->pLink = pStack->pTopElement;
		pStack->pTopElement = newNode;
		pStack->currentElementCount++;
	}
	return (TRUE);
}

StackNode* popLS(LinkedStack* pStack)
{
	StackNode *preNode = NULL;
	if (isLinkedStackEmpty(pStack))
	{
		fprintf(stderr, "Stack is empty!\n");
		exit(1);
	}
	else
	{
		StackNode *preNode = pStack->pTopElement;
		pStack->pTopElement = preNode->pLink;
		// free(preNode);
		pStack->currentElementCount--;
		return (preNode);
	}
}

StackNode* peekLS(LinkedStack* pStack)
{
	if (isLinkedStackEmpty(pStack))
	{
		fprintf(stderr, "Stack is empty!\n");
		exit(1);
	}
	else
		return (pStack->pTopElement);
}

void deleteLinkedStack(LinkedStack *pStack)
{
	free(pStack);
	pStack = NULL;
}

int isLinkedStackFull(LinkedStack* pStack)
{
	return (FALSE);	
}

int isLinkedStackEmpty(LinkedStack* pStack)
{
	return (pStack->currentElementCount == 0);
}

int main(){
	int i = 0;
	int arrayCount = 0;

	LinkedStack *pList = NULL;
	StackNode node;
	pList = createLinkedStack();

	if (pList != NULL)
	{
		node.data = 'a';
		pushLS(pList, node);
		node.data = 'b';
		pushLS(pList, node);
		node.data = 'c';
		pushLS(pList, node);
		printf("%c\n", popLS(pList)->data);
		printf("%c\n", peekLS(pList)->data);
	}

	return 0;
}