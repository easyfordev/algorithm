from itertools import product

class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        
        if len(digits) == 0:
            return [] 
        
        letters = {'2':'abc', '3':'def','4':'ghi','5':'jkl','6':'mno','7':'pqrs','8':'tuv','9':'wxyz' }
        
        # digit에 해당하는 map 멤버 찾아서 넣기
        l = []
        for d in digits:
            l.append(letters[d])
        
        # Cartesian Product 구하기
        ans = list(map(''.join, product(*l)))

        return ans

s = Solution()
print(s.letterCombinations("23"))


        



        