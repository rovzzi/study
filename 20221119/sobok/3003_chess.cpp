//
//  main.cpp
//  InOutput_Operater
//
//  Created by sobokso6ok on 2022/11/19.
//

#include <iostream>

int main()
{
    int originChess[6] = {1, 1, 2, 2, 2, 8};
    int inputChess[6];
    
    for (int idx = 0; idx < 6; idx++)
    {
        scanf("%d ", &inputChess[idx]);
    }
    
    for (int idx = 0; idx < 6; idx++)
    {
        printf("%d ", originChess[idx] - inputChess[idx]);
    }
    
    return 0;
}
