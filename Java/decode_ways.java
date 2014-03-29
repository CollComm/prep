public class Solution {
    HashMap<String, Integer> hashMap;
    public int numDecoding(String s) {
        if (s.charAt(0) == '0') {
            return 0;
        }
        if (s.length() == 1) {
            return 1;
        } else if (s.length() == 2) {
            if (s.charAt(0) >= '3') {
                return numDecoding(s.substring(1));
            } else {
                if (s.charAt(0) == '2') {
                    if (s.charAt(1) <= '6') {
                        if (s.charAt(1) == '0') {
                            return 1;
                        } else {
                            return 2;
                        }
                    } else {
                        return 1;
                    }
                } else {
                    // 1x
                    if (s.charAt(1) == '0') {
                        return 1;
                    } else {
                        return 2;
                    }
                }
            }
        } else {
            if (hashMap.containsKey(s)) {
                return hashMap.get(s);
            }
            int a = numDecoding(s.substring(1));
            if (s.charAt(0) == '1' || (s.charAt(0) == '2' && s.charAt(1) <= '6')) {
                a += numDecoding(s.substring(2));
            }
            hashMap.put(s, a);
            return a;
        }
    }
    public int numDecodings(String s) {
        if (s.length() == 0) return 0;
        hashMap = new HashMap<String, Integer>();
        return numDecoding(s);
    }
}
