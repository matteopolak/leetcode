class Solution:
    def missingInteger(self, nums: List[int]) -> int:
        
        sum = 0
        
        for i in range(len(nums)):
            sum += nums[i]
            
            if i == len(nums) - 1 or nums[i] + 1 != nums[i+1]:
                break
                
        
        numset = set(nums)
        
        
        while True:
            if sum in numset:
                sum = sum + 1
            else:
                return sum
