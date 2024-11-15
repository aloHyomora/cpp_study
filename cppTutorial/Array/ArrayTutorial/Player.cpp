#include "Player.h"
#include "Map.h"
#include "Helper.h"

// �÷��̾�� ��ǥ�� ������.

int GPlayerX = 2;
int GPlayerY = 2;

bool canMove = true;

void HandleMove() {

    // Ű���带 ���� ������, ���� ���� ������ �� ����.
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
    // ���� üũ
    if (x < 0 || x >= MAP_SIZE) return;
    if (y < 0 || y >= MAP_SIZE) return;

    // �� üũ
    int index = y * MAP_SIZE + x;
    if (GMap1D[index] == 1) return;

    // ���� ��ġ ����
    {
        int index = GPlayerY * MAP_SIZE + GPlayerX;
        GMap1D[index] = 0;
    }
    // �� ��ġ �̵�    
    {
        GPlayerX = x;
        GPlayerY = y;
        int index = GPlayerY * MAP_SIZE + GPlayerX;
        GMap1D[index] = 2;
    }
}
void MovePlayer2D(int x, int y) {
    // ���� üũ
    if (x < 0 || x >= MAP_SIZE) return;
    if (y < 0 || y >= MAP_SIZE) return;

    // �� üũ
    int index = y * MAP_SIZE + x;
    if (GMap2D[y][x] == 1) return;

    // ���� ��ġ ����
    {       
        GMap2D[GPlayerY][GPlayerX] = 0;
    }
    // �� ��ġ �̵�    
    {
        GPlayerX = x;
        GPlayerY = y;        
        GMap2D[GPlayerY][GPlayerX] = 2;
    }
}