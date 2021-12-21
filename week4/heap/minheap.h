/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minheap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 23:35:14 by bokim             #+#    #+#             */
/*   Updated: 2021/12/15 00:16:57 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MIN_HEAP_
#define _MIN_HEAP_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_NODE 100

typedef struct HeapNodeType
{
	int key;
} HeapNode;

typedef struct MinHeapType
{
	HeapNode pElement[MAX_NODE];
	int currentElementCount;
} MinHeap;

MinHeap* makeMinHeap(int rootData);
HeapNode* insertMinHeap(MinHeap* heap, int data);
int removeMinHeap(MinHeap* heap);
void deleteMinHeap(MinHeap* heap);

#endif

#ifndef _COMMON_HEAP_DEF_
#define _COMMON_HEAP_DEF_

#define TRUE		1
#define FALSE		0

#endif