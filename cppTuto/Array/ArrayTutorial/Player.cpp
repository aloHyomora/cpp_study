#include "Player.h"
#include "Map.h"
#include "Helper.h"

// 플레이어는 좌표를 가진다.

int GPlayerX = 2;
int GPlayerY = 2;

bool canMove = true;

void HandleMove() {

    // 키보드를 떼고 있으면, 다음 번엔 움직일 수 없다.
    if (GMoveDir == NONE) {
        canMove = true;
        return;
    }

    if (canMove == false)
        return;

    canMove = false;

    switch (GMoveDir)
    {
    case LEFT:
        // MovePlayer1D(GPlayerX - 1, GPlayerY);
        MovePlayer2D(GPlayerX - 1, GPlayerY);
        break;
    case RIGHT:
        // MovePlayer1D(GPlayerX + 1, GPlayerY);
        MovePlayer2D(GPlayerX + 1, GPlayerY);
        break;
    case UP:
        // MovePlayer1D(GPlayerX, GPlayerY - 1);
        MovePlayer2D(GPlayerX, GPlayerY - 1);
        break;
    case DOWN:
        // MovePlayer1D(GPlayerX, GPlayerY + 1);
        MovePlayer2D(GPlayerX, GPlayerY + 1);
        break;
    }
}

void MovePlayer1D(int x, int y) {
    // 범위 체크
    if (x < 0 || x >= MAP_SIZE) return;
    if (y < 0 || y >= MAP_SIZE) return;

    // 벽 체크
    int index = y * MAP_SIZE + x;
    if (GMap1D[index] == 1) return;

    // 기존 위치 정리
    {
        int index = GPlayerY * MAP_SIZE + GPlayerX;
        GMap1D[index] = 0;
    }
    // 새 위치 이동    
    {
        GPlayerX = x;
        GPlayerY = y;
        int index = GPlayerY * MAP_SIZE + GPlayerX;
        GMap1D[index] = 2;
    }
}
void MovePlayer2D(int x, int y) {
    // 범위 체크
    if (x < 0 || x >= MAP_SIZE) return;
    if (y < 0 || y >= MAP_SIZE) return;

    // 벽 체크
    int index = y * MAP_SIZE + x;
    if (GMap2D[y][x] == 1) return;

    // 기존 위치 정리
    {       
        GMap2D[GPlayerY][GPlayerX] = 0;
    }
    // 새 위치 이동    
    {
        GPlayerX = x;
        GPlayerY = y;        
        GMap2D[GPlayerY][GPlayerX] = 2;
    }
}