import java.util.*;

class Solution {

    class Album implements Comparable<Album> {
        int index, count;

        public Album(int index, int count) {
            this.index = index;
            this.count = count;
        }

        @Override
        public int compareTo(Album o) {
            if(this.count == o.count) {
                return this.index - o.index;
            } else {
                return o.count - this.count;
            }
        }
    }

    public int[] solution(String[] genres, int[] plays) {

        Map<String, Integer> genreRank = new HashMap<>();
        Map<String, List<Album>> albumRank = new HashMap<>();

        for(int i = 0; i < genres.length; i++) {
            genreRank.put(genres[i], genreRank.getOrDefault(genres[i], 0) + plays[i]);

            albumRank.putIfAbsent(genres[i], new ArrayList<>());
            albumRank.get(genres[i]).add(new Album(i, plays[i]));
        }

        List<String> sortedGenres = new ArrayList<>(genreRank.keySet());
        sortedGenres.sort((o1, o2) -> genreRank.get(o2) - genreRank.get(o1));

        List<Integer> answer = new ArrayList<>();

        for(String genre : sortedGenres) {
            List<Album> albums = albumRank.get(genre);
            Collections.sort(albums);

            for(int i = 0; i < Math.min(2, albums.size()); i++) {
                answer.add(albums.get(i).index);
            }
        }

        return answer.stream().mapToInt(Integer::intValue).toArray();
    }
}