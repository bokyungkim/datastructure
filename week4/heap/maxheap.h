/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxheap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 23:35:14 by bokim             #+#    #+#             */
/*   Updated: 2021/12/15 00:00:18 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _MAX_HEAP_
#define _MAX_HEAP_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_NODE 100

typedef struct HeapNodeType
{
	int key;
} HeapNode;

typedef struct MaxHeapType
{
	HeapNode pElement[MAX_NODE];
	int currentElementCount;
} MaxHeap;

MaxHeap* makeMaxHeap(int rootData);
HeapNode* insertMaxHeap(MaxHeap* heap, int data);
int removeMaxHeap(MaxHeap* heap);
void deleteMaxHeap(MaxHeap* heap);

#endif

#ifndef _COMMON_HEAP_DEF_
#define _COMMON_HEAP_DEF_

#define TRUE		1
#define FALSE		0

#endif