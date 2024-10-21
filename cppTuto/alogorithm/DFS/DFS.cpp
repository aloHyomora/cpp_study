#include <iostream>

using namespace std;

#include <vector>
#include <queue>


// DFS : 깊이 계속 파고 들어가서 정보를 준다.? 
// 깊이 우선 탐색 : 트리의 형태가 아니라면 출발 인덱스를 지정해줘야 한다.

// DFS (depth first search) = 재귀함수, 스택

struct Vertex {
    // int data;
};

vector<Vertex> vertices;
vector<vector<int >> adjacent;
vector<bool> visited;

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
int main()
{
    CreateGraph1();

    visited = vector<bool>(6, false);

    Dfs(0);
    // 0 -> 1 -> 2 -> 3 -> 4
    //

}