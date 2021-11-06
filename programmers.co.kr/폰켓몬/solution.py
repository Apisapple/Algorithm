def solution(nums):
    ponketmon = len(set(nums))
    
    if ponketmon < (len(nums) / 2) :
        return ponketmon
    else :
        return len(nums) / 2