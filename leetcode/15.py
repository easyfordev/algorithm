class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ans = []

        # 예외처리
        if len(nums) < 3:
            return []
        
        # 일단 정렬
        nums.sort()

        for i in range(len(nums)):
            # 예외처리 앞에 이미 검사한 값은 하지 않는다.
            if i>0 and nums[i-1] == nums[i]:
                continue
            
            # 나머지 투포인터
            left = i+1
            right = len(nums)-1

            while left < right:
                # 정답을 찾은 경우
                if nums[i] + nums[left] + nums[right] == 0:
                    # 정답을 넣고
                    ans.append([nums[i], nums[left], nums[right]])
                    # 이동한다
                    left+=1
                    right-=1
                    # 이동할 때, 중복된 조합을 고려해서 다른 값이 나올 때 까지 반복한다.
                    while left < right and nums[left] == nums[left-1]:
                        left+=1
                    
                    while left < right and nums[right] == nums[right+1]:
                        right-=1
                # 합이 0보다 크면, 합을 줄여야한다
                elif nums[i] + nums[left] + nums[right] > 0 :
                    right -= 1
                # 합이 0보다 작으면, 늘려야한다
                else:
                    left += 1
        return ans

S = Solution()

ans = S.threeSum([-1,0,1,2,-1,-4])

print(ans)
