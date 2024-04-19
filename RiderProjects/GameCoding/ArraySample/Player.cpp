#include "Player.h"
#include "Map.h"
#include "Helper.h"
bool canMove = true;

int gPlayerX = 2;
int gPlayerY = 2;
void MovePlayer(int x, int y)
{
    // 범위 체크
    if (x < 0 || x >= MAP_SIZE) return;
    if (y < 0 || y >= MAP_SIZE) return;

    // 벽 체크
    int index = y * MAP_SIZE + x;
    if (GMap1D[index] == 1) return;

    // 기존 위치 정리
    {
        int prevIndex = gPlayerY * MAP_SIZE + gPlayerX;
        GMap1D[prevIndex] = 0;
    }

    // 새 위치 이동   
    {
        gPlayerX = x;
        gPlayerY = y;
        int prevIndex = gPlayerY * MAP_SIZE + gPlayerX;
        GMap1D[prevIndex] = 2;
    }
}
void MovePlayer2D(int x, int y)
{
    // 범위 체크
    if (x < 0 || x >= MAP_SIZE) return;
    if (y < 0 || y >= MAP_SIZE) return;

    // 벽 체크     
    if (GMap2D[y][x] == 1) return;

    // 기존 위치 정리
    {       
        GMap2D[gPlayerY][gPlayerX] = 0;
    }

    // 새 위치 이동   
    {
        gPlayerX = x;
        gPlayerY = y;        
        GMap2D[gPlayerY][gPlayerX] = 2;
    }
}
void HandleMove() {
    // 키보드를 떼면, 움직일 수 있다.
    if (GMoveDir == MD_NONE)
    {
        canMove = true;
        return;
    }

    if (canMove == false)
        return;

    canMove = false;

    switch (GMoveDir)
    {
    case MD_NONE:
        break;
    case MD_LEFT:
        MovePlayer2D(gPlayerX - 1, gPlayerY);
        break;
    case MD_RIGHT:
        MovePlayer2D(gPlayerX + 1, gPlayerY);
        break;
    case MD_UP:
        MovePlayer2D(gPlayerX, gPlayerY - 1);
        break;
    case MD_DOWN:
        MovePlayer2D(gPlayerX, gPlayerY + 1);
        break;
    default:
        break;
    }
}
