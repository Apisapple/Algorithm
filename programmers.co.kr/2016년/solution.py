def solution(a, b):
    answer = ''
    calender = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    week_list = ["FRI","SAT","SUN", "MON","TUE","WED","THU"]
    count = 0
    for i in range(a - 1):
        count += calender[i]
    count += (b - 1)
    answer = week_list[count % 7]
    return answer