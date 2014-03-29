public class Solution {
	public String minWindow(String S, String T) {
	        int[] targetCount = new int[128];
	        int[] sourceCount = new int[128];
	        int totalCount = 0;
	        int minWindowLeft = 0, minWindowRight = S.length();
	        boolean isMinWindowFound = false;
	        for (int i = 0; i < T.length(); i++) {
	            targetCount[(byte)T.charAt(i)]++;
	        }
	        int begin = 0; int end = 0;
	        while (end < S.length()) {
	            sourceCount[S.charAt(end)]++;
	            if (sourceCount[S.charAt(end)] <= targetCount[S.charAt(end)]) {
	                totalCount++;
	            }
	            if (totalCount == T.length()) {
	                    //Found a match
	                    isMinWindowFound = true;
	                    while (begin < end) {
	                        if (sourceCount[S.charAt(begin)] > targetCount[S.charAt(begin)]) {
	                            sourceCount[S.charAt(begin)]--;
	                            begin++;
	                        } else {
	                            break;
	                        }
	                    }
	                    if (end - begin < minWindowRight - minWindowLeft) {
	                        minWindowRight = end + 1;
	                        minWindowLeft = begin;
	                    }
	            }
	            end++;
	        }
	        if (isMinWindowFound) {
	            return S.substring(minWindowLeft, minWindowRight);
	        } else {
	            return new String();
	        }
	}
}
