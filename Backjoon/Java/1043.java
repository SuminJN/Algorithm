import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());

        int[] arr = new int[N + 1];
        for (int i = 1; i <= N; i++) {
            arr[i] = i;
        }

        st = new StringTokenizer(br.readLine());
        int cnt = Integer.parseInt(st.nextToken());
        int[] truePeople = new int[cnt];
        for (int i = 0; i < cnt; i++) {
            truePeople[i] = Integer.parseInt(st.nextToken());
        }

        List<List<Integer>> partyList = new ArrayList<>();

        for (int i = 0; i < M; i++) {
            st = new StringTokenizer(br.readLine());
            int partySize = Integer.parseInt(st.nextToken());
            int firstPerson = Integer.parseInt(st.nextToken());

            List<Integer> party = new ArrayList<>();
            party.add(firstPerson);
            for (int j = 1; j < partySize; j++) {
                int nextPerson = Integer.parseInt(st.nextToken());
                party.add(nextPerson);
                union(arr, firstPerson, nextPerson);
            }

            partyList.add(party);
        }

        int answer = 0;
        for (List<Integer> party : partyList) {
            int leader = party.get(0);
            boolean canLie = true;

            for (int truePerson : truePeople) {
                if (find(arr, leader) == find(arr, truePerson)) {
                    canLie = false;
                    break;
                }
            }

            if (canLie) {
                answer++;
            }
        }

        System.out.println(answer);
    }

    public static int find(int[] arr, int a) {
        if (arr[a] == a) {
            return a;
        } else {
            return arr[a] = find(arr, arr[a]);
        }
    }

    public static void union(int[] arr, int a, int b) {
        a = find(arr, a);
        b = find(arr, b);
        if (a != b) {
            arr[a] = b;
        }
    }
}
