//
//  main.cpp
//  Algorythme_2567
//
//  Created by sobokso6ok on 2023/01/15.
//

#include <stdio.h>
#include <iostream>

#define PAPER_COORD_LENGTH 100
#define FILLPAPER_COORD_LENGTH 10

int main(int argc, const char * argv[]) {
    // 도화지 만들기
    int aPaper[PAPER_COORD_LENGTH][PAPER_COORD_LENGTH];
    memset(aPaper, 0, sizeof(aPaper));
    
    // 색종이 갯수 받기
    int nFillPaperNum = 0;
    scanf("%d", &nFillPaperNum);
    
    // 색종이 그리기
    for (int n = 0; n < nFillPaperNum; n++)
    {
        int nStartCoordX, nStartCoordY;
        scanf("%d %d", &nStartCoordX, &nStartCoordY);
        for (int i = nStartCoordX; i < nStartCoordX + FILLPAPER_COORD_LENGTH; i++)
        {
            for (int j = nStartCoordY; j < nStartCoordY + FILLPAPER_COORD_LENGTH; j++)
            {
                aPaper[i][j] = 1;
            }
        }
    }
    
    // 둘레 구하기
    int nPerimeter = 0;
    int aMove_X[] = { 0, 0, -1, 1 };    // 상하좌우
    int aMove_Y[] = { 1, -1, 0, 0 };
    for (int i = 0; i < PAPER_COORD_LENGTH; i++)
    {
        for(int j = 0; j < PAPER_COORD_LENGTH; j++)
        {
            if(aPaper[i][j] == 1)   // 색종이가 붙어있는 좌표
            {
                for (int nMove = 0; nMove < 4; nMove++)
                {
                    int nX = j+aMove_X[nMove];
                    int nY = i+aMove_Y[nMove];
                    if (nX < 0 || nY < 0 || nX > PAPER_COORD_LENGTH || nY > PAPER_COORD_LENGTH)
                        continue;
                    if (aPaper[nY][nX] == 0) nPerimeter++;
                }
            }
        }
    }
    
    // 결과 출력
    printf("%d", nPerimeter);
    
    
    return 0;
}
