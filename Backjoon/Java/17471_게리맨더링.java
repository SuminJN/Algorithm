import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

/*
    1. 1 ~ N을 2개의 구역으로 나누기
    2. 각 구역이 연결되어 있는지 체크하기
    3. 연결되었다면 차이(diff) 기록하기
 */
public class Main {

    static int N, diff = Integer.MAX_VALUE;
    static int[] population;
    static ArrayList<ArrayList<Integer>> adj;
    static boolean[] visited, selected;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        N = Integer.parseInt(br.readLine());
        population = new int[N];
        selected = new boolean[N];

        // 인구수 입력 받기
        st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            population[i] = Integer.parseInt(st.nextToken());
        }

        adj = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            adj.add(new ArrayList<>());
        }

        // 인접 노드 입력 받기
        for (int i = 0; i < N; i++) {
            st = new StringTokenizer(br.readLine());
            int count = Integer.parseInt(st.nextToken());

            for (int j = 0; j < count; j++) {
                adj.get(i).add(Integer.parseInt(st.nextToken()) - 1);
            }
        }

        divide(0);

        if (diff == Integer.MAX_VALUE) diff = -1; // 두 구역으로 나눌 수 없다면 -1 리턴
        System.out.println(diff);
    }

    // 두 개의 구역으로 나누기
    static void divide(int now) {
        if (now != N) {
            selected[now] = true;
            divide(now + 1);

            selected[now] = false;
            divide(now + 1);
        } else {
            ArrayList<Integer> A = new ArrayList<>();
            ArrayList<Integer> B = new ArrayList<>();

            for (int i = 0; i < N; i++) {
                if (selected[i]) {
                    A.add(i);
                } else {
                    B.add(i);
                }
            }

            if (A.isEmpty() || B.isEmpty()) return;

            if (isGroup(A) && isGroup(B)) {
                getDiff();
            }
        }
    }

    // list로 받은 구역들이 연결되어 있는지 확인, BFS
    static boolean isGroup(ArrayList<Integer> list) {
        Queue<Integer> q = new LinkedList<>();
        visited = new boolean[N];
        visited[list.get(0)] = true;
        q.add(list.get(0));

        int count = 1;

        while (!q.isEmpty()) {
            int now = q.remove();

            for (int next : adj.get(now)) {
                if (list.contains(next) && !visited[next]) { // 현재 구역에 포함되며 방문하지 않았다면
                    q.add(next);
                    visited[next] = true;
                    count++;
                }
            }
        }

        return count == list.size();
    }

    // 두 구역의 차이를 기록
    static void getDiff() {
        int countA = 0, countB = 0;

        for (int i = 0; i < N; i++) {
            if (selected[i]) countA += population[i];
            else countB += population[i];
        }

        int temp = Math.abs(countA - countB);
        diff = Math.min(diff, temp);
    }
}
