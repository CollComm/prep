public class Solution {
    public boolean isMatch(String s, String p) {
        if (s.length() == 0 && p.length() == 0) return true;
        if (s.length() != 0 && p.length() == 0) return false;
        int posS = 0, posP = 0, lastPosS = -1, lastPosP = -1;
        while(posS < s.length()) {
            if (posP < p.length()) {
                if (p.charAt(posP) == '?' || p.charAt(posP) == s.charAt(posS)) {
                    posS++; posP++;
                } else if (p.charAt(posP) == '*') {
                    posP++;
                    lastPosS = posS;
                    lastPosP = posP;
                } else {
                    if (lastPosS == -1) {
                        return false;
                    } else {
                        lastPosS++;
                        posS = lastPosS;
                        posP = lastPosP;
                    }
                }
            } else {
                if (lastPosS == -1) {
                    return false;
                } else {
                    lastPosS++;
                    posS = lastPosS;
                    posP = lastPosP;
                }                        
            }
        }
        while(posP < p.length() && p.charAt(posP) == '*') {
                posP++;
        }
        if (posP < p.length()) {
            return false;
        } else {
            return true;
        }
    }
}
