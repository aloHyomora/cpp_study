#include <iostream>

using namespace std;
#include <vector>
#include <queue>

// 인접 리스트 : 실제 연결된 애들'만' 넣어준다.
void CreateGraph1() {
    struct Vertex {
        vector<Vertex*> edges; // 연결된 간선 관리
    };

    vector<Vertex> v;
    v.resize(6); // size  => 지금 당장 영역 변경, 할당
    // v.reserve(6); // capacity => 오케이 나중에 영역 확보해볼게.


    // 직관적이지 않다. 
    v[0].edges.push_back(&v[1]);
    v[0].edges.push_back(&v[3]);

    v[1].edges.push_back(&v[0]);
    v[1].edges.push_back(&v[2]);
    v[1].edges.push_back(&v[3]);

    v[3].edges.push_back(&v[4]);

    v[5].edges.push_back(&v[4]);
}

// 인접 리스트
void CreateGraph2() {
    struct Vertex {
        int data;
    };

    vector<Vertex> v(6);

    // [v][v][v][v][v][v]
    vector<vector<int>> adjacent;
    adjacent.resize(6);

    adjacent[0] = { 1, 3 };
    adjacent[1] = { 0,2,4 };
    adjacent[3] = { 4 };
    adjacent[5] = { 5 };

    // Q : 0 -> 3번이 연결되어 있난요?
    bool connected = false;

    int size = adjacent[0].size();
    for (int i = 0; i < size; i++)
    {
        int vertexIndex = adjacent[0][i];
        if (vertexIndex == 3) connected = true;
    }
}

// 정점이 100개
// - 지하철 노선도 -> 서로 드문 드문 연결
// - 페이스북 친구 -> 서로 빽빽하게 연결

// 인접 행렬
void CreateGraph3() {
    struct Vertex
    {
        int data;
    };

    vector<Vertex> v(6);

    // 연결된 목록을 행렬로 관리
    // [x][o][x][o][x][x]
    // [o][x][o][o][x][x]
    // [x][x][x][x][x][x]
    // [x][x][x][x][o][x]
    // [x][x][x][x][x][x]
    // [x][x][x][x][o][x]

    // 한 줄 false로 밀기
    vector<bool> v(6, false); 

    // bool 타입 이차원 배열 생성
    vector<vector<bool>> adjacent(6, vector<bool>(6, false));
    adjacent[0][1] = true;
    adjacent[0][3] = true;

    adjacent[1][0] = true;
    adjacent[1][2] = true;
    adjacent[1][3] = true;

    adjacent[3][4] = true;

    adjacent[5][4] = true;

    // Q 0 -> 3번이 연결되어 있습니까?
    //  adjacent[from][to] ? : 행렬을 이용한 그래프 표현
    // 메모리 소모 심하지만, 빠른 접근

    vector<vector<int>> adjacent2 = {
        {-1, -15, -1, 35, -1, -1},
        {15, -1, 5, 10, -1, -1},
        {-1, 5, -1, -1, -1, -1},
        {35, 5, -1, -1, 5, -1},
        {-1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, 5, -1}
    };
}

int main()
{
    
}