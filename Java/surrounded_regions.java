public class Solution {
    public HashSet<Point> visited;
    public class Point {
        public int x;
        public int y;
        public Point(int px, int py) {
            x = px;
            y = py;
        }
        public int hashCode() {
            return x * y;
        } 
        public boolean equals(Object obj) {
        	Point p = (Point) obj;
            return (x == p.x && y == p.y);
        }
    }
    public void change(char[][] board, ArrayList<Point> list) {
        if (list == null) return;
        for (int i = 0; i < list.size(); i++) {
            board[list.get(i).x][list.get(i).y] = 'X';
        }
    }
    public void expandPoint(char[][]board, int x, int y, LinkedList<Point> q) {
        Point tmp = new Point(x, y);
        if (board[x][y] == 'O' && !visited.contains(tmp)) {
            visited.add(tmp);
            q.add(tmp);
        }
    }
    public ArrayList<Point> findConnectO(char[][] board, int px, int py, int l, int w) {
        LinkedList<Point> q = new LinkedList<Point>();
        ArrayList<Point> setToX = new ArrayList<Point>();
        q.add(new Point(px, py));
        visited.add(new Point(px, py));
        int totalAvailable = 0;
        while(!q.isEmpty()) {
            Point p = q.remove();
            setToX.add(p);
            totalAvailable += 4;
            if (p.x + 1 < l) {
                totalAvailable--;
                expandPoint(board, p.x + 1, p.y, q);
            }
            if (p.x - 1 >= 0) {
                totalAvailable--;
                expandPoint(board, p.x - 1, p.y, q);
            }
            if (p.y + 1 < w) {
                totalAvailable--;
                expandPoint(board, p.x, p.y + 1, q);
            }
            if (p.y - 1 >= 0) {
                totalAvailable--;
                expandPoint(board, p.x, p.y - 1, q);
            }
        }
        if (totalAvailable > 0) {
            return null;
        } else {
            return setToX;
        }
    }
    public void solve(char[][] board) {
        visited = new HashSet<Point>();
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] == 'O' && !visited.contains(new Point(i, j))) {
                    change(board, findConnectO(board, i, j, board.length, board[i].length));
                }
            }
        }
    }
}
