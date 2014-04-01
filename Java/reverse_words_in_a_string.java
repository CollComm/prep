public class Solution {
    public String reverseWords(String s) {
        if (s.length() == 0) return s;
        String strWithoutWhiteSpace = s.trim();
        ArrayList<String> allWords = new ArrayList<String>();
        int startIndex = 0, endIndex = 0;
        for (; endIndex < strWithoutWhiteSpace.length(); endIndex++) {
            if (strWithoutWhiteSpace.charAt(endIndex) == ' ') {
                if (strWithoutWhiteSpace.charAt(startIndex) != ' ') {
                    allWords.add(strWithoutWhiteSpace.substring(startIndex, endIndex));
                }
                startIndex = endIndex + 1;
            }
        }
        if (startIndex < endIndex) {
            allWords.add(strWithoutWhiteSpace.substring(startIndex));
        }
        String answer = new String();
        for (int i = allWords.size() - 1; i > 0; i--) {
            answer = answer.concat(allWords.get(i));
            answer = answer.concat(" ");
        }
        if (allWords.size() > 0) {
            answer = answer.concat(allWords.get(0));
        }
        return answer;
    }
}
