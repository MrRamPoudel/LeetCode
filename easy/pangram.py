class Solution:
    def checkIfPangram(self, sentence: str) -> bool:
        charset = []
        for i in range(ord('a'), ord('z')+1):
            charset.append(chr(i))
        for chars in sentence:
            if chars.lower() in charset:
                charset.remove(chars.lower())
            if not charset:
                return True
        return False
