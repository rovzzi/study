import java.io.*;
import java.util.*;

public class bj_2567 {
    public static int board[][];
    public static int [] dx={0,0,-1,1}; //상하좌우
    public static int [] dy={1,-1,0,0};
	public static void main(String[] args) throws IOException{
        
        board = new int[102][102]; //크기
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int p = Integer.parseInt(br.readLine());
        
        
        // 맵채우기
        for(int n=0; n<p; n++)
        {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int y = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            for(int i=x+1; i<= x+10; i++)
            {
                for(int j=y+1; j<=y+10; j++)
                {
                    board[i][j] = 1;
                }
            }
        }
        
        
        // 탐색
        int answer = 0;
        for(int i=1; i<101; i++)
        {
            for(int j=1; j<101; j++)
            {
                if(board[i][j]==1)
                {
                    for(int d = 0; d<4; d++)
                    {
                        int x = j+dx[d]; //j가 x축 진행방향으로 움직이므로
                        int y = i+dy[d];
                        if(x<0 || y<0 || x>=102 || y>=102) continue;	//board범위 벗어나면 걍넘어감
                        if(board[y][x]==0) answer++;	//
                    }   
                }
            }
        }
        
        
        System.out.println(answer);
        
    }
   
}
