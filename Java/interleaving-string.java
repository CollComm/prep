public class Solution {
    String str1;
    String str2;
    String str3;
    public boolean isInterleave(int p1, int q1, int p2, int q2, int p3, int q3)
    {
        if (p3 > q3) return true;
        if (p1 > q1)
        {
            while(str2.charAt(p2) == str3.charAt(p3) && (p2 < q2) && (p3 < q3))
            {
                p2++;
                p3++;
            }
            if (p2 < q2 && p3 < q3) return false;
            if (p2 == q2 && p3 == q3) return true;
        }
        if (p2 > q2)
        {
            while(str1.charAt(p1) == str3.charAt(p3) && (p1 < q1) && (p3 < q3))
            {
                p1++;
                p3++;
            }
            if (p1 < q1 && p3 < q3) return false;
            if (p1 == q1 && p3 == q3) return true;
        }
        if (str1.charAt(p1) == str3.charAt(p3))
        {
            if (str1.charAt(q1) == str3.charAt(q3) && isInterleave(p1 + 1, q1 - 1, p2, q2, p3 + 1, q3 - 1)) return true;
            if (str2.charAt(q2) == str3.charAt(q3) && isInterleave(p1 + 1, q1, p2, q2 - 1, p3 + 1, q3 - 1)) return true;
        }
        if (str2.charAt(p2) == str3.charAt(p3))
        {
            if (str1.charAt(q1) == str3.charAt(q3) && isInterleave(p1, q1 - 1, p2 + 1, q2, p3 + 1, q3 - 1)) return true;
            if (str2.charAt(q2) == str3.charAt(q3) && isInterleave(p1, q1, p2 + 1, q2 - 1, p3 + 1, q3 - 1)) return true;
        }
        return false;
    }
    public boolean isInterleave(String s1, String s2, String s3) {
        if (s1.length() + s2.length() == s3.length())
        {
            str1 = s1;
            str2 = s2;
            str3 = s3;
            int[] s1_s2_CharCount = new int[26];
            int[] s3CharCount = new int[26];
            for (int i = 0; i < s1.length(); i++)
            {
                s1_s2_CharCount[s1.charAt(i) - 'a']++;
            }
            for (int i = 0; i < s2.length(); i++)
            {
                s1_s2_CharCount[s2.charAt(i) - 'a']++;
            }
            for (int i = 0; i < s3.length(); i++)
            {
                s3CharCount[s3.charAt(i) - 'a']++;
            }
            for (int i = 0; i < 26; i++)
            {
                if (s1_s2_CharCount[i] != s3CharCount[i])
                {
                    return false;
                }
            }
            return isInterleave(0, s1.length() - 1, 0, s2.length() - 1, 0, s3.length() - 1);
        }
        else
        {
            return false;
        }
    }
}
