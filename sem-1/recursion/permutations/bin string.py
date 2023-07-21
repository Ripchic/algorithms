def permute(self, nums: list) -> List[List[int]]:
    res = []

    def solve(s=[], nums=[]):
        if len(s) == len(nums):
            res.append(s)
            return
        for i in range(len(nums)):
            if nums[i] not in s:
                solve(s + [nums[i]], nums)

    solve([], nums)
    return res