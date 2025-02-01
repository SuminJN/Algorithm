import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;

// https://www.acmicpc.net/problem/1427
public class A066 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        String str = br.readLine();
        ArrayList<Integer> list = new ArrayList<>();

        for (char c : str.toCharArray()) {
            list.add(c - '0');
        }

        Collections.sort(list, Collections.reverseOrder());

        for (Integer i : list) {
            System.out.print(i);
        }
    }
}