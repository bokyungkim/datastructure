/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arraygraph.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bokim <bokim@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:56:01 by bokim             #+#    #+#             */
/*   Updated: 2021/12/24 10:17:17 by bokim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
인접리스트에 비해 효율성이 떨어진다.
인접리스트는 어떤 노드에 인접한 노드들을 쉽게 찾을 수 있지만
인접행렬에서는 인접한 노드를 찾기 위해서는 모든 노드를 전부 순회해야 한다.

그래프에 간선이 많이 존재하는 밀집 그래프(Dense Graph)의 경우
장점 :
- 두 정점을 연결하는 간선의 존재 여부를 O(1) 안에 즉시 알 수 있다.
- 정점의 차수는 O(N) 안에 알 수 있다. : 인접 배열의 i번째 행 또는 열을 모두 더한다.
단점 :
- 어떤 노드에 인접한 노드들을 찾기 위해서는 모든 노드를 전부 순회해야 한다.
- 그래프에 존재하는 모든 간선의 수는 O(N^2) 안에 알 수 있다. 인접 행렬 전체를 조사하기 때문
- 필요 이상의 공간 낭비
*/

#include "arraygraph.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// 그래프 생성
ArrayGraph* createArrayGraph(int maxVertexCount){
	if (maxVertexCount <= 0)
		return (FAIL);
	ArrayGraph *graph = (ArrayGraph *)malloc(sizeof(ArrayGraph));
	if (!graph)
		return (FAIL);
	graph->maxVertexCount = maxVertexCount;
	graph->currentVertexCount = 0;
	graph->graphType = GRAPH_UNDIRECTED;
	graph->ppAdjEdge = (int **)calloc(maxVertexCount, sizeof(int *));
	if (!graph->ppAdjEdge)
		return (FAIL);
	for (int i = 0; i < maxVertexCount; i++)
		graph->ppAdjEdge[i] = (int *)calloc(maxVertexCount, sizeof(int));
	graph->pVertex = (int *)calloc(maxVertexCount, sizeof(int));
	return (graph);
}

ArrayGraph* createArrayDirectedGraph(int maxVertexCount){
	if (maxVertexCount <= 0)
		return (FAIL);
	ArrayGraph *graph = (ArrayGraph *)malloc(sizeof(ArrayGraph));
	if (!graph)
		return (FAIL);
	graph->maxVertexCount = maxVertexCount;
	graph->currentVertexCount = 0;
	graph->graphType = GRAPH_DIRECTED;
	graph->ppAdjEdge = (int **)calloc(maxVertexCount, sizeof(int *));
	if (!graph->ppAdjEdge)
		return (FAIL);
	for (int i = 0; i < maxVertexCount; i++){
		graph->ppAdjEdge[i] = (int *)calloc(maxVertexCount, sizeof(int));
	}
	graph->pVertex = (int *)calloc(maxVertexCount, sizeof(int));
	return (graph);
}

// 그래프 삭제
void deleteArrayGraph(ArrayGraph* pGraph){
	if (!pGraph)
		return ;
	for (int i = 0; i < pGraph->maxVertexCount; i++)
		free(pGraph->ppAdjEdge[i]);
	free(pGraph->pVertex);
	free(pGraph);
}

// 공백 그래프 여부 판단
int isEmptyAG(ArrayGraph* pGraph){
	if (!pGraph)
		return (FAIL);
	return (pGraph->currentVertexCount == 0);
}

// 노드 추가
int addVertexAG(ArrayGraph* pGraph, int vertexID){
	if (!pGraph || (vertexID > pGraph->maxVertexCount - 1)
			|| pGraph->maxVertexCount == pGraph->currentVertexCount
			|| pGraph->pVertex[vertexID] == 1)
		return (FAIL);
	pGraph->pVertex[vertexID] = 1;
	pGraph->currentVertexCount++;
	return (SUCCESS);
}

// 간선 추가
int addEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID){
	if (!pGraph || !checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FAIL);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = 1;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = 1;
	return (SUCCESS);
}

int addEdgewithWeightAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID, int weight){
	if (!pGraph || !checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FAIL);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = weight;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = weight;
	return (SUCCESS);
}

// 노드의 유효성 점검
int checkVertexValid(ArrayGraph* pGraph, int vertexID){
	if (!pGraph)
		return (FAIL);
	if (pGraph->pVertex[vertexID])
		return (TRUE);
	return (FALSE);
}

// 노드 제거
int removeVertexAG(ArrayGraph* pGraph, int vertexID){
	if (!pGraph || (vertexID > pGraph->maxVertexCount - 1) || pGraph->currentVertexCount == 0)
		return (FAIL);
	for (int i = 0; i < pGraph->maxVertexCount; i++){
		removeEdgeAG(pGraph, vertexID, i);
	}
	pGraph->pVertex[vertexID] = 0;
	pGraph->currentVertexCount--;
	return (SUCCESS);
}

// 간선 제거
int removeEdgeAG(ArrayGraph* pGraph, int fromVertexID, int toVertexID){
	if (!pGraph || !checkVertexValid(pGraph, fromVertexID) || !checkVertexValid(pGraph, toVertexID))
		return (FAIL);
	pGraph->ppAdjEdge[fromVertexID][toVertexID] = 0;
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		pGraph->ppAdjEdge[toVertexID][fromVertexID] = 0;
	return (SUCCESS);
}

// 그래프 정보 출력
void displayArrayGraph(ArrayGraph* pGraph){
	printf("=============================\n");
	printf("maxVertexCount = %d\n", pGraph->maxVertexCount);
	printf("currentVertexCount = %d\n", pGraph->currentVertexCount);
	printf("graph type = ");
	if (pGraph->graphType == GRAPH_UNDIRECTED)
		printf("Undirected\n");
	else
		printf("Directed\n");
	printf("\n------------EDGE-----------\n");
	printf("   ");
	for (int i = 0; i < pGraph->maxVertexCount; i++){
		printf("[%d]", i);
	}
	printf("\n");
	for (int i = 0; i < pGraph->maxVertexCount; i++){
		printf("[%d]  ", i);
		for (int j = 0; j < pGraph->maxVertexCount; j++){
			printf("%d  ", pGraph->ppAdjEdge[i][j]);	
		}
		printf("\n");
	}
	printf("\n-----VERTEX-----\n");
	for (int i = 0; i < pGraph->maxVertexCount; i++){
		printf("[%d]  %d\n", i, pGraph->pVertex[i]);
	}
}

// int main(){
// 	//Undirected graph (p3 G1)
// 	// ArrayGraph *graph1 = createArrayGraph(7);
// 	// if (isEmptyAG(graph1))
// 	// 	printf("Graph is Empty\n");
// 	// addVertexAG(graph1, 0);
// 	// addVertexAG(graph1, 1);
// 	// addVertexAG(graph1, 2);
// 	// addVertexAG(graph1, 3);
// 	// addVertexAG(graph1, 4);
// 	// addVertexAG(graph1, 5);
// 	// addEdgeAG(graph1, 0, 1);
// 	// addEdgeAG(graph1, 0, 2);
// 	// addEdgeAG(graph1, 1, 2);
// 	// addEdgeAG(graph1, 3, 2);
// 	// addEdgeAG(graph1, 3, 4);
// 	// addEdgeAG(graph1, 3, 5);
// 	// addEdgeAG(graph1, 4, 5);
// 	// displayArrayGraph(graph1);
// 	// printf("\nAfter removing Vertex 0, 1\n");
// 	// removeVertexAG(graph1, 0);
// 	// removeVertexAG(graph1, 1);
// 	// displayArrayGraph(graph1);
	
// 	//Directed & has weight (p3 G4)
// 	ArrayGraph *graph2 = createArrayDirectedGraph(7);
// 	addVertexAG(graph2, 0);
// 	addVertexAG(graph2, 1);
// 	addVertexAG(graph2, 2);
// 	addVertexAG(graph2, 3);
// 	addVertexAG(graph2, 4);
// 	addVertexAG(graph2, 5);
// 	addEdgewithWeightAG(graph2, 0, 1, 4);
// 	addEdgewithWeightAG(graph2, 1, 2, 1);
// 	addEdgewithWeightAG(graph2, 2, 0, 2);
// 	addEdgewithWeightAG(graph2, 2, 1, 3);
// 	addEdgewithWeightAG(graph2, 2, 3, 2);
// 	addEdgewithWeightAG(graph2, 3, 2, 1);
// 	addEdgewithWeightAG(graph2, 3, 4, 1);
// 	addEdgewithWeightAG(graph2, 4, 5, 1);
// 	addEdgewithWeightAG(graph2, 5, 3, 2);
// 	displayArrayGraph(graph2);
// 	printf("\nAfter removing Vertex 0, 1\n");
// 	removeVertexAG(graph2, 0);
// 	removeVertexAG(graph2, 1);
// 	displayArrayGraph(graph2);
// }