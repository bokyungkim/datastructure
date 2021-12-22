#include "dijkstra.h"

int minDistance(int dist[VERTEX_NUM], int sptSet[VERTEX_NUM])
{
    int min = INT_MAX;
	int min_index;
 
    for (int v = 0; v < VERTEX_NUM; v++)
    {
		//방문하지 않았고, 거리가 더 짧다면
        if (!sptSet[v] && min > dist[v])
        {
            min_index = v;
            min = dist[v];
        }
    }
 
    return (min_index);
}
 
 
// 시작점에서 그 정점까지의 최단 거리를 출력해준다.
void printSolution(int dist[], int n)
{
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < VERTEX_NUM; i++)
        printf("%d \t\t %d\n", i, dist[i]);
}
 
void dijkstra(int graph[VERTEX_NUM][VERTEX_NUM], int src)
{
    int dist[VERTEX_NUM]; // 최단 거리를 파악하는 배열
    int sptSet[VERTEX_NUM]; // 방문 했는지 체크 하는 bool형 배열
 
    for (int i = 0; i < VERTEX_NUM; i++){
        dist[i] = INT_MAX;
		sptSet[i] = NOT_VISITED;
	}
 
    // 초기 조건 설정.
    dist[src] = 0;
 
    // V-1번 루프를 수행한다는 것은 첫 src노드를 제외한 모든 노드들에 접근을 해 계산을 한다는 의미.
    for (int count = 0; count < VERTEX_NUM - 1; count++)
    {
        // 최단거리 정보를 알고 있는 노드들 중 가장 거리가 짧은 노드의 인덱스를 가져온다.
        int u = minDistance(dist, sptSet);
 
        // 그래프 상의 모든 노드들을 탐색하며 u 노드의 주변 정보를 갱신한다.
        for (int v = 0; v < VERTEX_NUM; v++)
        {
            // 1. 아직 처리가 되지 않은 노드이어야 하며 (무한루프 방지)
            // 2. u-v 간에 edge가 존재하고
            // 3. src부터 u까지의 경로가 존재하고
            // 4. 기존의 v노드까지의 최단거리 값보다 새로 계산되는 최단거리가 더 짧을 경우
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[v] > dist[u] + graph[u][v])
            {
                // 최단거리를 갱신해준다.
                dist[v] = dist[u] + graph[u][v];
            }
        }
 
        // 이제 이 노드(u)는 접근할 일이 없다. 플래그를 true로 설정.
        sptSet[u] = VISITED;
 
        // 현재까지의 최단 거리를 출력해준다.
        printSolution(dist, VERTEX_NUM);
    }
}
 
int main()
{
    // 다익스트라를 이용할 그래프
    int graph[VERTEX_NUM][VERTEX_NUM] = 
    { 
        { 0, 1, 4, 0, 0, 0 },
        { 1, 0, 2, 0, 0, 0 },
        { 4, 2, 0, 1, 0, 0 },
        { 0, 0, 1, 0, 8, 3 },
        { 0, 0, 0, 8, 0, 4 },
		{ 0, 0, 0, 3, 4, 0 },
    };
 
    // dijkstra(최단 거리를 구하고자 하는 그래프, 시작 하고자 하는 정점);
    dijkstra(graph, 0);
 
    return 0;
}


// 출처: https://www.crocus.co.kr/533 [Crocus]