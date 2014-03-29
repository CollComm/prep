public class Solution {
public int calcDistance(String a, String b) {
        // Assumption : a.length() == b.length()
        int totalDist = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                totalDist++;
            }
        }
        return totalDist;
    }
    public class QueueNode {
        String a;
        int step;
        QueueNode(String str, int s) {
            a = str;
            step = s;
        }
    }
    public int ladderLength(String start, String end, HashSet<String> dict) {
        if (start.length() != end.length() || dict == null) {
            return 0;
        }
        Queue<QueueNode> q = new LinkedList<QueueNode>();
        int ladderDist = 0;
        q.add(new QueueNode(start, 1));
        while(!q.isEmpty()) {
            QueueNode currLevel = q.remove();
            if (calcDistance(currLevel.a, end) == 1) {
                ladderDist = currLevel.step + 1;
                break;
            }
            for (int i = 0; i < currLevel.a.length(); i++) {
                char[] tmpStr = currLevel.a.toCharArray();
                for (int j = 0; j < 26; j++) {
                    tmpStr[i] = (char)('a' + j);
                    String newStr = new String(tmpStr);
                    if (dict.contains(newStr)) {
                        if (calcDistance(newStr, end) == 1) {
                            ladderDist = currLevel.step + 2;
                            break;
                        }
                        q.add(new QueueNode(newStr, currLevel.step + 1));
                        dict.remove(newStr);
                    }
                }
            }
            if (ladderDist != 0) {
                break;
            }
        }
        return ladderDist;
    }
}
