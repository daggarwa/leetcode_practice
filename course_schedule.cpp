class Solution {
   public static boolean canFinish(int numCourses, int[][] prerequisites) {

  HashMap<Integer, Set<Integer>> courseList = new HashMap<>();
  boolean[] visited = new boolean[numCourses];

  for (int i = 0; i < prerequisites.length; i++) {
    int[] edge = prerequisites[i];
    if (courseList.containsKey(edge[0])) {
      courseList.get(edge[0]).add(edge[1]);
    } else {
      Set<Integer> courseNeighs = new HashSet<>();
      courseNeighs.add(edge[1]);
      courseList.put(edge[0], courseNeighs);
    }
  }

  for(int i = 0; i < numCourses; i++) {
    if (!dfs(i, visited, courseList)) return false;
  }
  return true;
  }

  static boolean dfs(int course, boolean[] visited, HashMap<Integer, Set<Integer>> courseList) {
    if (!courseList.containsKey(course)) return true;
    if (visited[course]) return false;

    visited[course] = true;
    if (courseList.containsKey(course)) {
          for (int neigh : courseList.get(course)) {
            if (!dfs(neigh, visited, courseList)) return false;
          }
    }
    visited[course] = false;
    return true;
  }
}