#include <iostream>

using namespace std;

#include <vector>
#include <queue>


// DFS : 깊이 계속 파고 들어가서 정보를 준다.? 
// 깊이 우선 탐색 : 트리의 형태가 아니라면 출발 인덱스를 지정해줘야 한다.

// DFS (depth first search) = 재귀함수, 스택

// BFS (넓이) = 큐 : 입구에서 가장 가까운 곳부터 돌아다니겠다.
// 먼저 만난 걸 먼저 접근한다. 큐(선입선출)과 유사

struct Vertex {
    // int data;
};

vector<Vertex> vertices;
vector<vector<int>> adjacent;
vector<bool> visited;

// 발견한
vector<bool> discorvered;

void Bfs(int here) {    

    // ex) 누구에 의해서 발견되었는지?
    vector<int> parent(6, -1);
    // ex) 시작점에서 얼만큼 떨어져 있는지?
    vector<int> dist(6, -1);

    // 큐에 삽입
    queue<int> q;
    q.push(here);
    discorvered[here] = true;
    
    parent[here] = here;
    dist[here] = 0;

    // 스캔을 끝내서 더 이상 새로운 걸 발견하지 못할 경우에 while 끝
    while (q.empty()== false)
    {
        here = q.front();
        q.pop();

        // 방문 도장
        cout << "Visited : " << here << endl;

        for (int there = 0; there < 6; there++)
        {
            if (adjacent[here][there] == 0)
                continue;
            if (discorvered[there])
                continue;

            q.push(there);
            discorvered[there] = true;

            parent[there] = here;
            dist[there] = dist[here] + 1;
        }

        //int size = adjacent[here].size();
        //for (int i = 0; i < size; i++)
        //{
        //    // 이미 내가 다른 경로에서 발견했으면 무시하고 간다.
        //    // 0번을 방문하다 1, 3번을 방문해서 무시함.
        //    int there = adjacent[here][i];
        //    if (discorvered[there])
        //        continue;

        //    q.push(there);
        //    discorvered[there] = true;
        //}        
    }
}
void Dfs(int here) {
    // 방문 도장
    visited[here] = true;
    cout << "Visited : " << here << endl;

    // here와 인접한 길을 다 체크해서 [인접 리스트]
    // 인접 리스트 0(N + E) => 간선의 개수
    // 모든 간선이 연결되어 있으면 제곱이 될 수도 있다. 
    //const int size = adjacent[here].size();
    //for (int i = 0; i < size; i++)
    //{
    //    // there이 존재한다면? 길은 있다.
    //    int there = adjacent[here][i];

    //    // false는 내가 한 번도 가보지 못한 Vertex
    //    if (visited[there] == false)
    //        Dfs(there); // 재귀
    //}


    // [인접 행렬] 0(N x N) = 0(N^2)
    // 6이 정점 계수에 비례
    // 한 정점마다 내가 방문하는 횟수는 
    // - 1번이라는 정점은 각각 한 번씩 방문 => N
    // - 인접 행렬을 각 정점마다 for문을 돌아야 한다. => N
    for (int there = 0; there < 6; there++)
    {
        // 길은 있는지 (길이 없다면 다음 인덱스로 continue~)
        if (adjacent[here][there] == 0) continue;

        // 아직 방문하지 않은 곳에 한해서 방문
        if (visited[there] == false)
            Dfs(there);
    }
}
void DfsAll()
{
    visited = vector<bool>(6, false);

    for (int i = 0; i < 6; i++)
    {
        if (visited[i] == false)
        {
            Dfs(i);
            cout << "Hi" << endl;
        }
    }
}
void CreateGraph1() {
    vertices.resize(6);

    // 인접 리스트
    /*adjacent = vector<vector<int>>(6);
    adjacent[0] = { 1, 3 };
    adjacent[1] = { 0,2, 3 };
    adjacent[3] = { 4 };
    adjacent[5] = { 4 };*/

    // 인접 행렬
    adjacent = vector<vector<int>>{
        {0, 1, 0, 1, 0, 0},
        {1, 0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
    };
}

// 다 익스트라: 발견해놓은 걸 기록해두고 더 좋은 경로를 선택한다.
// 예약 시스템
void CreateGraph() {
    vertices.resize(6);

    // 가중치
    adjacent = vector<vector<int>>(6, vector<int>(6, -1));
    adjacent[0][1] = adjacent[1][0] = 15;
    adjacent[0][3] = adjacent[3][0] = 35;
    adjacent[1][2] = adjacent[2][1] = 5;
    adjacent[1][3] = adjacent[1][3] = 10;
    adjacent[3][4] = adjacent[4][3] = 5;
    adjacent[4][5] = adjacent[5][4] = 5;
}

struct VertexCost {
    VertexCost(int cost, int vertex) : cost(cost), vertex(vertex) {}

    bool operator<(const VertexCost& other) const {
        return cost < other.cost;
     }
    bool operator>(const VertexCost& other) const {
        return cost > other.cost;
    }

    int cost;
    int vertex;
};

// BFS + 양념(cost)
void Dijikstra(int here) {
    priority_queue<VertexCost, vector<VertexCost>, greater<VertexCost>> pq;

    // 각 정점 별로 최소 거리

    // best case 관리
    vector<int> best(6, INT32_MAX);
    vector<int> parent(6, -1);

    pq.push(VertexCost(0, here));
    best[here] = 0;
    parent[here] = here;

    while (pq.empty() == false)
    {
        // 제일 좋은 후보를 찾는다.
        VertexCost v = pq.top();
        pq.pop();

        int cost = v.cost;
        here = v.vertex;

        // 더 짧은 경로를 뒤늦게 찾았다면 스킵
        if (best[here] < cost)
            continue;

        // 방문
        cout << "방문! " << here << endl;

        for (int there = 0; there < 6; there++)
        {
            // 연결되지 않았으면 스킵
            if (adjacent[here][there] == -1)
                continue;

            // 더 좋은 경로를 과거에 찾았으면 스킵
            int nextCost = best[here] + adjacent[here][there];
            if (nextCost >= best[there])
                continue;

            // 지금까지 찾은 경로 중에서는 최선의 수치 = 갱신
            best[there] = nextCost;
            parent[there] = here;   // 나중에 갱신될 수 있음
            pq.push(VertexCost(nextCost, there));
        }
    }
}

int main()
{
    CreateGraph1();

    // visited = vector<bool>(6, false);

    discorvered = vector<bool>(6, false);
    //Dfs(0);
    // Bfs(0);

    Dijikstra(0);

}