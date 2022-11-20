import java.io.*;
import java.util.*;


public class bj_2447 {
    public static char arr [][];	//함수에서 사용하기 위해 배열로 선언 
    public static int N;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in); 
        N = sc.nextInt();
        arr = new char [N][N];	//새로운 배열 생성
        //배열 채우기
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
            	arr[i][j] = ' ';
            }
        }
        //재귀호출 (재귀하는 면 N,x좌표,y좌표)
        recur(N,0,0);
        //출력
        for(int i=0; i<N; i++)
        {
            System.out.println(arr[i]);
        }
    }
    //
    public static void recur(int n,int x,int y){
        //기저조건 한쪽면이 1까지 갔을 떄 별을 찍어주기
        if(n==1){
            arr[x][y]='*';
            return;
        }
        
        int M = n/3;
        
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                if(!(i==1&&j==1)){	//비워놔야될곳은 건너뛰기
                	recur(M,x+(i*M),y+(j*M));	//시작좌표값+(1번ㄷ째,두번재,3번쨰 + 현재벽면 좌표)
                }
            }
        }
    }
}
