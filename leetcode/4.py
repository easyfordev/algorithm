"""
Leetcode - 4. Median of Two Sorted Arrays
# O(log (m+n)) 나와야 함
# 2개 배열의 median 리턴
- 그냥 merge sort처럼 구현하면 되는 문제
"""

class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """

        # 예외처리
        if len(nums1)==0 and  len(nums2)==0:
            return float(0)

        # 1. 두 배열 정렬하면서 합치기 (merge sort처럼)
        nums = []

        i=0
        j=0
        while (i < len(nums1)) and (j < len(nums2)):
            # 둘이 비교해서 더 작은거
            if nums1[i] <= nums2[j]:
                nums.append(nums1[i])
                i +=1
            else:
                nums.append(nums2[j])
                j +=1

        # 1번 array에서 남은거 넣기
        if i < len(nums1):
            for a in range(i, len(nums1)):
                nums.append(nums1[a])
        # 2번 array에서 남은거 넣기
        if j < len(nums2):
            for a in range(j, len(nums2)):
                nums.append(nums2[a])
        # print(nums)

        # 2. median 구하기
        mid = len(nums) // 2
        print(mid)
        if len(nums)%2==0:
            return float( (nums[mid-1] + nums[mid])) / 2 
        else:
            return float(nums[mid])

s = Solution()
ans = s.findMedianSortedArrays([1,2], [3,4])

print(ans)