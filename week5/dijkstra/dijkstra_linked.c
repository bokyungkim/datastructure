#include "/Users/ellykim/myworkspace/42-datastructure/week1/linkedlist/linkedlist.h"
#include "linkedgraph/linkedgraph.h"
#include <limits.h>
#include <stdio.h>

#define FIXED 1
#define NOT_FIXED 0

int minDistance(int *distance, int *fixedVertex, int vertexNum){
	int min = INT_MAX;
	int minIdx;

	for (int v = 0; v < vertexNum; v++){
		if (!fixedVertex[v] && distance[v] < min){
			minIdx = v;
			min = distance[v];
		}
	}
	return (minIdx);
}

void printSolution(int *distance, int vertexNum){
	printf("Vertex   Distance from Source\n");
	for (int i = 0; i < vertexNum; i++)
		printf("%d \t\t %d\n", i, distance[i]);
}

void dijkstra(LinkedGraph *pGraph, int start){
	int vertexNum = pGraph->maxVertexCount;
	int distance[vertexNum];
	int fixedVertex[vertexNum];

	for (int i = 0; i < vertexNum; i++){
		distance[i] = INT_MAX;
		fixedVertex[i] = NOT_FIXED;
	}

	distance[start] = 0;

	for (int count = 0; count < vertexNum - 1; count++){
		int u = minDistance(distance, fixedVertex, vertexNum);
		for (int v = 0; v < vertexNum; v++){
			if (!fixedVertex[v] && findGraphNodePosition(pGraph->ppAdjEdge[u], v)
				&& distance[u] != INT_MAX && distance[v] > distance[u] + getWeight(pGraph->ppAdjEdge[u], v)){
				distance[v] = distance[u] + getWeight(pGraph->ppAdjEdge[u], v);
			}
		}
		fixedVertex[u] = FIXED;

		printSolution(distance, vertexNum);
	}
}

int main(void){
	LinkedGraph *graph = createLinkedGraph(6);
	
	addVertexLG(graph, 0);
	addVertexLG(graph, 1);
	addVertexLG(graph, 2);
	addVertexLG(graph, 3);
	addVertexLG(graph, 4);
	addVertexLG(graph, 5);
	
	addEdgewithWeightLG(graph, 0, 1, 1);
	addEdgewithWeightLG(graph, 0, 2, 4);
	addEdgewithWeightLG(graph, 1, 2, 2);
	addEdgewithWeightLG(graph, 2, 3, 1);
	addEdgewithWeightLG(graph, 3, 4, 8);
	addEdgewithWeightLG(graph, 3, 5, 3);
	addEdgewithWeightLG(graph, 4, 5, 4);
	
	dijkstra(graph, 0);
	
	return (0);
}