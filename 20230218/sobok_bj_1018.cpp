//
//  main.cpp
//  BJ_1018_Chess
//
//  Created by sobokso6ok on 2023/02/18.
//

#include <iostream>
#include <math.h>

int main(int argc, const char * argv[]) {
    
    // 직사각형 M(열), N(행) 크기 입력받기
    int N, M;
    scanf("%d %d", &N, &M);
    if((N < 8) || (N > 50) || (M < 8) || (M > 50))
    {
        printf("8 이상 50 이하의 값으로 다시 입력하세요\n");
        scanf("%d %d\n", &N, &M);
    }
    
    // M, N 크기만큼 체스만으로 만들 보드형태 입력 받기
    char cBoard[N][M];
    for (int n = 0; n < N; n++)
    {
        scanf("%s", &cBoard[n]);
    }
    
    
    // M, N 형태의 보드를 8X8로 자르기
    // 입력된 개수에서 자르기 위한 시작점을 정하기 위해서는 최대 값에서 7을 빼준만큼 반복문을 실행
    int nMin = 100;
    for (int nStartN = 0; nStartN < N - 7; nStartN++)
    {
        for (int nStartM = 0; nStartM < M - 7; nStartM++)
        {
            // 시작점(0,0)부터 행, 열로 8개까지 B W 검사
            // N(행) M(열)의 합이 짝수이면 시작점과 같은 색, 다르면 시작점과 다른 색
            // 입력된 보드에서 B로 더 많이 바꿔야할지 W로 더 많이 바꿔야할지 둘다 해보고 작은값 전달
            // 시작점이 B일 때 바꿔야할 갯수
            int nNumB = 0;
            // 시작점이 W일 때 바꿔야할 갯수
            int nNumW = 0;
            for (int n = nStartN; n < nStartN + 8; n++ )
            {
                for (int m = nStartM; m < nStartM + 8; m++)
                {
                    if ((n + m) % 2 == 0)
                    {
                        // 시작점이 B일 때 짝수값이 B가 아닐 경우
                        if (cBoard[n][m] != 'B')
                        {
                            nNumB += 1;
                        }
                        else // 시작점이 W일 때 짝수값이 W가 아닐 경우
                        {
                            nNumW += 1;
                        }
                    }
                    else
                    {
                        // 시작점이 B일 때 홀수값이 W가 아닐 경우
                        if (cBoard[n][m] != 'W')
                        {
                            nNumB += 1;
                        }
                        else // 시작점이 W라면 홀수값이 B가 아닐 경우
                        {
                            nNumW += 1;
                        }
                    }
                }
            }
            // 모든 시작점들 중 최소로 바꿀 수 있는 값 저장
            int nCompare = std::min(nNumB, nNumW);
            if (nMin > nCompare)
            {
                nMin = nCompare;
            }
        }
    }
    
    // 출력
    printf("%d", nMin);
    return 0;
}
