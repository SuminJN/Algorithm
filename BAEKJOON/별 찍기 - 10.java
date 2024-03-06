import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
​
public class Main {
​
    static char[][] arr;
​
    public static void main(String[] args) throws Exception {
        
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
​
        int n = Integer.parseInt(br.readLine());
​
        arr = new char[n][n];
​
        star(0, 0, n, false);
        
        for(int i = 0; i < n; i++) {
            bw.write(arr[i]);
            bw.write("\n");
        }
​
        bw.flush();
        bw.close();
    }
​
    static void star(int x, int y, int n, boolean isBlank) {
        
        if(isBlank) {
            for(int i = x; i < x+n; i++) {
                for(int j = y; j < y+n; j++) {
                    arr[i][j] = ' ';
                }
            }
            return;
        }
​
        if(n == 1) {
            arr[x][y] = '*';
            return;
        }
​
        int size = n / 3;
        int count = 0;
​
        for(int i = x; i < x+n; i += size) {
            for(int j = y; j < y+n; j += size) {
                count++;
​
                if(count == 5) {
                    star(i, j, size, true);
                } else {
                    star(i, j, size, false);
                }
            }
        }
    }
}
​