import java.io.*;
import java.util.*;

public class rovzzi_bj_1018 {
    
    static boolean [][] map;
    static String a;
    static int N;
    static int min;
    public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int M = Integer.parseInt(st.nextToken());
        N = Integer.parseInt(st.nextToken());
        
        min = 64;	//칠해야되는 갯수
        map = new boolean[M][N];
        
        for(int i=0; i<M; i++)
        {
            String a = br.readLine();
         	for(int j=0; j<N; j++)
            {
                if(a.charAt(j)=='W')
                {
                    map[i][j] = true;
                }
                else 
                    map[i][j] = false;
            }
        }
        // 시작점 (sx,sy)
        int sx = M - 7;
        int sy = N - 7;
        for(int i=0; i<sx; i++)
        {
            for(int j=0; j<sy; j++)
            {
                find(i,j);
            }
        }
        System.out.println(min);
        
	}
    public static void find(int x,int y){
        int count = 0;	//	보드 1번마다 카운트 초기화
        //체스판 끝점
        int ex = x+8;
        int ey = y+8;
        boolean flag = map[x][y]; 	//첫째 칸 무슨색인지에 따라서 전체 색이 다름 
        
        for(int i=x; i<ex; i++){
            for(int j=y; j<ey; j++)
            {
                if(map[i][j] != flag)	// 현재의 색과 flag 색과 같지 않으면 count++
                {
                    count++;
                }
                flag = !flag;	//다음칸은 색이 바뀌어야함
            }
            flag = !flag; //다음줄도 색이달라져야함
        }
        /*
        	첫번째 색이 반대인 경우중의 최솟값 구하기 -> count
            그 최소값과 경우의 수 보드중 최솟값 구하기 -> min
        */
        count = Math.min(count, 64-count);
        min = Math.min(min, count);
    }
}
