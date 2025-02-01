import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

// https://www.acmicpc.net/problem/10814
public class A082 {

    static class User implements Comparable<User> {
        int age;
        String name;

        public User(int age, String name) {
            this.age = age;
            this.name = name;
        }

        @Override
        public String toString() {
            return age + " " + name;
        }

        @Override
        public int compareTo(User o) {
            return this.age - o.age;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int N = Integer.parseInt(br.readLine());
        User[] users = new User[N];

        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            users[i] = new User(Integer.parseInt(st.nextToken()), st.nextToken());
        }

        Arrays.sort(users);

        for (int i = 0; i < N; i++) {
            System.out.println(users[i]);
        }
    }
}