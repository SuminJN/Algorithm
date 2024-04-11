import java.io.*;
import java.util.*;
​
public class Main {
​
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        String input = br.readLine();
        char now = input.charAt(0);
        int count = 0;
​
        for(int i = 0; i < input.length(); i++) {
            if(input.charAt(i) != now) {
                now = input.charAt(i);
                count++;
            }
        }
        if(input.charAt(0) != input.charAt(input.length()-1)) {
            System.out.println(count/2 + 1);
        } else {
            System.out.println(count/2);
        }
    }
}
​