/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedstack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 23:55:36 by bokim             #+#    #+#             */
/*   Updated: 2021/12/02 14:41:09 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedstack.h"
#include <stdio.h>
#include <stdlib.h>

LinkedStack *createLinkedStack()
{
	LinkedStack *linkedStack = (LinkedStack *)malloc(sizeof(LinkedStack));
	if (!linkedStack)
	{
		fprintf(stderr, "Memory allocation error\n");
		return (NULL);
	}
	linkedStack->currentElementCount = 0;
	linkedStack->pTopElement = NULL;
	return (linkedStack);
}

int pushLS(LinkedStack *pStack, MapPosition element)
{
	if (!pStack)
	{
		fprintf(stderr, "Stack does not exist\n");
		return (FALSE);
	}
	else
	{
		MapPosition *newNode = (MapPosition *)malloc(sizeof(MapPosition));
		*newNode = element;
		newNode->pLink = pStack->pTopElement;
		pStack->pTopElement = newNode;
		pStack->currentElementCount++;
	}
	return (TRUE);
}

MapPosition *popLS(LinkedStack *pStack)
{
	if (!pStack)
	{
		fprintf(stderr, "Stack does not exist\n");
		return (FALSE);
	}
	MapPosition *preNode = NULL;
	if (isLinkedStackEmpty(pStack))
	{
		fprintf(stderr, "Stack is empty!\n");
		return (FALSE);
	}
	else
	{
		MapPosition *preNode = pStack->pTopElement;
		pStack->pTopElement = preNode->pLink;
		pStack->currentElementCount--;
		return (preNode);
	}
}

MapPosition *peekLS(LinkedStack *pStack)
{
	if (!pStack)
	{
		fprintf(stderr, "Stack does not exist\n");
		return (FALSE);
	}
	if (isLinkedStackEmpty(pStack))
	{
		fprintf(stderr, "Stack is empty!\n");
		return (FALSE);
	}
	else
		return (pStack->pTopElement);
}

void deleteLinkedStack(LinkedStack *pStack)
{
	if (!pStack)
		fprintf(stderr, "Stack does not exist\n");
	MapPosition *node = NULL;
	for (int i = 0; i < pStack->currentElementCount; i++)
	{
		node = popLS(pStack);
		free(node);
		node = NULL;
	}
	pStack->currentElementCount = 0;
}

int isLinkedStackFull(LinkedStack *pStack)
{
	if (!pStack)
	{
		fprintf(stderr, "Stack does not exist\n");
		return (FALSE);
	}
	return (FALSE);
}

int isLinkedStackEmpty(LinkedStack *pStack)
{
	if (!pStack)
	{
		fprintf(stderr, "Stack does not exist\n");
		return (FALSE);
	}
	return (pStack->currentElementCount == 0);
}

// int main()
// {
// 	int i = 0;
// 	int arrayCount = 0;

// 	LinkedStack *pList = NULL;
// 	MapPosition node;
// 	pList = createLinkedStack();

// 	if (pList != NULL)
// 	{
// 		node.data = 'a';
// 		pushLS(pList, node);
// 		node.data = 'b';
// 		pushLS(pList, node);
// 		node.data = 'c';
// 		pushLS(pList, node);
// 		printf("%c\n", popLS(pList)->data);
// 		printf("%c\n", peekLS(pList)->data);
// 		printf("%c\n", popLS(pList)->data);
// 		printf("%c\n", popLS(pList)->data);
// 		printf("%c\n", popLS(pList)->data);
// 	}

// 	return 0;
// }