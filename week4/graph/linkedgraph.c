/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedgraph.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:43:28 by bokim             #+#    #+#             */
/*   Updated: 2021/12/21 18:23:02 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linkedgraph.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// 그래프 생성
LinkedGraph* createLinkedGraph(){
	LinkedGraph *graph = (LinkedGraph *)malloc(sizeof(LinkedGraph));
	if (!graph)
		return (FAIL);
	graph->currentVertexCount = 0;
	graph->graphType = GRAPH_UNDIRECTED;
	graph->ppVertex[MAX_VERTICES] = (LinkedNode **)calloc(MAX_VERTICES, sizeof(LinkedNode *));
	if (!graph->ppVertex)
		return (FAIL);
	return (graph);
}
LinkedGraph* createLinkedDirectedGraph(){
	LinkedGraph *graph = (LinkedGraph *)malloc(sizeof(LinkedGraph));
	if (!graph)
		return (FAIL);
	graph->currentVertexCount = 0;
	graph->graphType = GRAPH_DIRECTED;
	graph->ppVertex[MAX_VERTICES] = (LinkedNode **)calloc(MAX_VERTICES, sizeof(LinkedNode *));
	if (!graph->ppVertex)
		return (FAIL);
	return (graph);
}

// 그래프 삭제
void deleteLinkedGraph(LinkedGraph* pGraph){
}

// 공백 그래프 여부 판단
int isEmptyLG(LinkedGraph* pGraph){
	if (!pGraph)
		return (FAIL);
	return (pGraph->currentVertexCount == 0);
}

// 노드 추가
int addVertexLG(LinkedGraph* pGraph, LinkedNode vertex){
	if (!pGraph || checkVertexValid(pGraph, vertex.vertexID)
			|| pGraph->currentVertexCount == MAX_VERTICES)
		return (FAIL);
	pGraph->ppVertex[vertex.vertexID] = &vertex;
	pGraph->currentVertexCount++;
	return (SUCCESS);
}

// 간선 추가
int addEdgeLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID){
	if (!pGraph || !checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FAIL);
	LinkedNode *newNode = (LinkedNode *)malloc(sizeof(LinkedNode));
	newNode->vertexID = toVertexID;
	newNode->pLink = NULL;
	LinkedNode *preNode = &(pGraph->ppVertex[fromVertexID]);
	while (preNode->pLink)
	{
		preNode = preNode->pLink;
	}
	newNode->pLink = preNode->pLink;
	preNode->pLink = newNode;
	//directed일 경우도 추가
}
int addEdgewithWeightLG(LinkedGraph* pGraph, int fromVertexID, int toVertexID, int weight){
}

// 노드의 유효성 점검 : 존재하면 TRUE, 없으면 FALSE
int checkVertexValid(LinkedGraph* pGraph, int vertexID){
	if (!pGraph)
		return (FAIL);
	for (int i = 0; i < pGraph->currentVertexCount; i++){
		if (pGraph->ppVertex[i]->vertexID == vertexID){
			return (TRUE);
		}
	}
	return (FALSE);
}

// 노드 제거
int removeVertexLG(LinkedGraph* pGraph, LinkedNode* vertex){
}

// 간선 제거
int removeEdgeLG(LinkedGraph* pGraph, LinkedNode* fromVertex, LinkedNode* toVertex){
}

// 그래프 정보 출력
void displayLinkedGraph(LinkedGraph* pGraph){
}