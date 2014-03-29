public class Solution {
    public ArrayList<Integer> findSubstring(String S, String[] L) {
        if (S.length() == 0) return null;
        if (L.length == 0) return null;
        HashMap<String, Integer> words = new HashMap<String, Integer>();
        ArrayList<Integer> answer = new ArrayList<Integer>();
        int wordLength = L[0].length();
        for (int i = 0; i < L.length; i++) {
            if (words.containsKey(L[i])) {
                words.put(L[i], words.get(L[i]) + 1);
            }
            else {
                words.put(L[i], 1);
            }
        }
        for (int i = 0; i < wordLength; i++) {
        	HashMap<String, Integer> freqs = new HashMap<String, Integer>(words);
        	int queueHead = i;
            for (int j = i; j <= S.length() - freqs.size() * wordLength; j += wordLength) {
                String currWord = S.substring(j, j + wordLength);
                if (freqs.containsKey(currWord)) {
                    int wordFreq = freqs.get(currWord);
                    if (wordFreq == 1) {
                        freqs.remove(currWord);
                        if (freqs.size() == 0) {
                            // We found one
                            answer.add(queueHead);
                            freqs.put(S.substring(queueHead, queueHead + wordLength), 1);
                            queueHead += wordLength;
                        }
                    } else {
                        freqs.put(currWord, wordFreq - 1);
                    }
                } else {
                    int k = 0;
                    if (words.containsKey(currWord)) {
                        // Case 1: Exists but we meet a new one
                        for (k = queueHead; k <= j - wordLength; k+=wordLength) {
                            String currHeadStr = S.substring(k, k + wordLength);
                            if (currHeadStr.compareTo(currWord) != 0) {
                                if (freqs.containsKey(currHeadStr)) {
                                    freqs.put(currHeadStr, freqs.get(currHeadStr) + 1);
                                } else {
                                    freqs.put(currHeadStr, 1);
                                }
                            } else {
                                k += wordLength;
                                break;
                            }
                        }
                    } else {
                        // Case 2: Never exists in words
                        for (k = queueHead; k <= j - wordLength; k+=wordLength) {
                            String currHeadStr = S.substring(k, k + wordLength);
                            if (freqs.containsKey(currHeadStr)) {
                                freqs.put(currHeadStr, freqs.get(currHeadStr) + 1);
                            } else {
                                freqs.put(currHeadStr, 1);
                            }
                        }
                        k = j + wordLength;
                    }
                    queueHead = k;
                }
            }
        }
        return answer;
    }
}
