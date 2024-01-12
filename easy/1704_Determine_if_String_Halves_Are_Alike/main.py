class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        vowels = set('aeiouAEIOU')
        nVA = nVB = 0
        i, j = 0, len(s) - 1
        while i < j:
            nVA += s[i] in vowels
            nVB += s[j] in vowels
            i += 1
            j -= 1
        return nVA == nVB
