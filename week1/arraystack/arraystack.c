/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraystack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 23:17:09 by bokim             #+#    #+#             */
/*   Updated: 2021/11/29 13:33:35 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "arraystack.h"

ArrayStack *createArrayStack(int maxElementCount)
{
	if (maxElementCount < 0)
	{
		fprintf(stderr, "Wrong input\n");
		return (NULL);
	}
	ArrayStack *arrayStack = (ArrayStack *)malloc(sizeof(ArrayStack));
	if (!arrayStack)
	{
		fprintf(stderr, "Memory allocation error\n");
		return (NULL);
	}
	arrayStack->maxElementCount = maxElementCount;
	arrayStack->currentElementCount = 0;
	arrayStack->pElement = (ArrayStackNode *)malloc(maxElementCount * sizeof(ArrayStackNode));
	if (!(arrayStack->pElement))
	{
		fprintf(stderr, "Memory allocation error\n");
		return (NULL);
	}
	return (arrayStack);
}

int pushAS(ArrayStack *pStack, ArrayStackNode element)
{
	if (!pStack)
	{
		fprintf(stderr, "Stack does not exist\n");
		return (FALSE);
	}
	if (isArrayStackFull(pStack))
	{
		fprintf(stderr, "Stack is full\n");
		return (FALSE);
	}
	else
	{
		pStack->pElement[pStack->currentElementCount] = element;
		pStack->currentElementCount++;
		return (TRUE);
	}
}

ArrayStackNode *popAS(ArrayStack *pStack)
{
	if (!pStack)
	{
		fprintf(stderr, "Stack does not exist\n");
		return (FALSE);
	}
	if (isArrayStackEmpty(pStack))
	{
		fprintf(stderr, "Stack is empty!\n");
		return (FALSE);
	}
	else
	{
		ArrayStackNode *retNode = &(pStack->pElement[pStack->currentElementCount - 1]);
		pStack->currentElementCount--;
		return (retNode);
	}
}

ArrayStackNode *peekAS(ArrayStack *pStack)
{
	if (!pStack)
	{
		fprintf(stderr, "Stack does not exist\n");
		return (FALSE);
	}
	if (isArrayStackEmpty(pStack))
	{
		fprintf(stderr, "Stack is empty\n");
		return (FALSE);
	}
	return (&(pStack->pElement[pStack->currentElementCount - 1]));
}

void deleteArrayStack(ArrayStack *pStack)
{
	if (!pStack)
		fprintf(stderr, "Stack does not exist\n");
	free(pStack->pElement);
	pStack->pElement = NULL;
}

int isArrayStackFull(ArrayStack *pStack)
{
	if (!pStack)
	{
		fprintf(stderr, "Stack does not exist\n");
		return (FALSE);
	}
	return (pStack->maxElementCount == pStack->currentElementCount);
}

int isArrayStackEmpty(ArrayStack *pStack)
{
	if (!pStack)
	{
		fprintf(stderr, "Stack does not exist\n");
		return (FALSE);
	}
	return (pStack->currentElementCount == 0);
}

int main(void)
{
	ArrayStack *AS = createArrayStack(5);
	ArrayStackNode *node = malloc(sizeof(ArrayStackNode));
	node->data = 'a';
	pushAS(AS, *node);
	node->data = 'b';
	pushAS(AS, *node);
	node->data = 'c';
	pushAS(AS, *node);
	node->data = 'd';
	pushAS(AS, *node);
	printf("%c\n", popAS(AS)->data);
	printf("%c\n", peekAS(AS)->data);
	free(node);
	return (0);
}