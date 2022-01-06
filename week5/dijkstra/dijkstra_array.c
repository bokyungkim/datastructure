#include "../../week4/graph/arraygraph/arraygraph.h"
#include <stdio.h>
#include <limits.h> // INT_MAX에 이용

#define FIXED		1
#define NOT_FIXED	0

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

// O(n^2)
void dijkstra(ArrayGraph *pGraph, int start){
	int vertexNum = pGraph->currentVertexCount;
    int distance[vertexNum];
	int fixedVertex[vertexNum];
 
    // 초기화
    for (int i = 0; i < vertexNum; i++){
        distance[i] = INT_MAX;
		fixedVertex[i] = NOT_FIXED;
	}

    distance[start] = 0;

    // 모든 노드에 접근해 계산
    for (int count = 0; count < vertexNum - 1; count++){
        
        // 방문하지 않은 노드 중 가장 비용이 적은 노드 찾기
        int u = minDistance(distance, fixedVertex, vertexNum);

        // 모든 노드를 탐색하며 u 노드의 주변 정보 갱신
        for (int v = 0; v < vertexNum; v++){
            // 1. 아직 처리가 되지 않은 노드이고
            // 2. u-v 간 edge가 존재하고
            // 3. 기존의 v노드까지의 최단거리 값보다 새로 계산되는 최단거리가 더 짧을 경우
            if (!fixedVertex[v] && pGraph->ppAdjEdge[u][v] && distance[v] > distance[u] + pGraph->ppAdjEdge[u][v]){
                distance[v] = distance[u] + pGraph->ppAdjEdge[u][v];
            }
        }
        fixedVertex[u] = FIXED;
        printSolution(distance, vertexNum);
    }
}

int main(){
	ArrayGraph *graph = createArrayGraph(10);

	addVertexAG(graph, 0);
	addVertexAG(graph, 1);
	addVertexAG(graph, 2);
	addVertexAG(graph, 3);
	addVertexAG(graph, 4);
	addVertexAG(graph, 5);

 	addEdgewithWeightAG(graph, 0, 1, 1);
	addEdgewithWeightAG(graph, 0, 2, 4);
	addEdgewithWeightAG(graph, 1, 2, 2);
	addEdgewithWeightAG(graph, 2, 3, 1);
	addEdgewithWeightAG(graph, 3, 4, 8);
	addEdgewithWeightAG(graph, 3, 5, 3);
	addEdgewithWeightAG(graph, 4, 5, 4);

    dijkstra(graph, 0);

	return (0);
}