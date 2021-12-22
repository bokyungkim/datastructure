/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedgraph.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:43:25 by bokim             #+#    #+#             */
/*   Updated: 2021/12/22 14:55:37 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GRAPH_LIST_
#define _GRAPH_LIST_

#include "linkedlist.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#define MAX_PATH 1000

typedef struct LinkedGraphType
{
	int maxVertexCount;
	int currentVertexCount;				// 현재 사용되는 노드의 개수
	int currentEdgeCount;
	int graphType;						// 그래프 종류: 1-Undirected, 2-Directed
	int *pVertex;
	LinkedList **ppAdjEdge;
} LinkedGraph;

// 그래프 생성
LinkedGraph* createLinkedGraph(int maxVertexCount);
LinkedGraph* createLinkedDirectedGraph(int maxVertexCount);

// 그래프 삭제
void deleteLinkedGraph(LinkedGraph* pGraph);

// 공백 그래프 여부 판단
int isEmptyLG(LinkedGraph* pGraph);

// 노드 추가
int addVertexLG(LinkedGraph* pGraph, int vertexID);

// 간선 추가
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);
int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight);

// 노드의 유효성 점검
int checkVertexValid(LinkedGraph* pGraph, int vertexID);

// 노드 제거
int removeVertexLG(LinkedGraph* pGraph, int vertexID);

// 간선 제거
int removeEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID);

// 그래프 정보 출력
void displayLinkedGraph(LinkedGraph* pGraph);

int findGraphNodePosition(LinkedList *pList, int vertexID);

#endif

#ifndef _COMMON_GRAPH_DEF_
#define _COMMON_GRAPH_DEF_

#define USED				1
#define NOT_USED			0

#define SUCCESS				1
#define FAIL				0

#define TRUE				1
#define FALSE				0

#define GRAPH_UNDIRECTED	1
#define GRAPH_DIRECTED		2
#endif
