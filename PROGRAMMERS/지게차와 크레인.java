import java.util.*;

class Solution {

    final int[] dy = {1, -1, 0, 0};
    final int[] dx = {0, 0, -1, 1};

    int N, M, answer;
    char[][] map;

    public int solution(String[] storage, String[] requests) {

        answer = 0;
        N = storage.length;
        M = storage[0].length();
        map = new char[N+2][M+2];

        for(int i = 0; i < N + 2; i++) {
            Arrays.fill(map[i], '0');
        }

        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= M; j++) {
                map[i][j] = storage[i-1].charAt(j-1);
            }
        }

        for(String request : requests) {
            char c = request.charAt(0);

            if(request.length() == 1) { // 지게차
                type1(c);
            } else { // 크레인
                type2(c);
            }
        }

        for(int i = 0; i < N + 2; i++) {
            for(int j = 0; j < M + 2; j++) {
                System.out.print(map[i][j] + " ");
            }
            System.out.println();
        }

        for(int i = 1; i < N + 1; i++) {
            for(int j = 1; j < M + 1; j++) {
                if(map[i][j] == '0' || map[i][j] == '1') continue;

                answer++;
            }
        }

        return answer;
    }

    public void type1(char target) {
        ArrayList<int[]> list = new ArrayList<>();

        for(int i = 1; i < N + 1; i++) {
            for(int j = 1; j < M + 1; j++) {
                if(map[i][j] == target) {
                    for(int k = 0; k < 4; k++) {
                        int ny = i + dy[k];
                        int nx = j + dx[k];

                        if(map[ny][nx] == '0') {
                            list.add(new int[]{i, j});
                            break;
                        }
                    }
                }
            }
        }

        // 빼낸 부분은 바깥과 무조건 연결됨
        for(int[] temp : list) {
            map[temp[0]][temp[1]] = '0';
            isOutside(temp[0], temp[1]);
        }
    }

    public void type2(char target) {
        for(int i = 1; i < N + 1; i++) {
            for(int j = 1; j < M + 1; j++) {
                if(map[i][j] == target) {
                    map[i][j] = '1';
                    isOutside(i, j);
                }
            }
        }
    }

    public void isOutside(int y, int x) {
        boolean outside = false;

        for(int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];

            if(map[ny][nx] == '0') {
                map[y][x] = '0';
                outside = true;
                break;
            }
        }

        if(outside) {
            for(int k = 0; k < 4; k++) {
                int ny = y + dy[k];
                int nx = x + dx[k];

                if(map[ny][nx] == '1') {
                    map[ny][nx] = '0';
                    isOutside(ny, nx);
                }
            }
        }
    }

}