import sys

input = sys.stdin.readline
keyword_cnt, post_cnt = map(int, input().split())
keywords = dict()
for _ in range(keyword_cnt):
    keyword = sys.stdin.readline().rstrip()
    keywords[keyword] = 1

answer = keyword_cnt
for _ in range(post_cnt):
    posts = (input().rstrip().split(","))
    for post in posts :
        if post in keywords.keys() :
            if keywords[post] == 1 :
                keywords[post] -= 1
                answer -=1
    
    print(answer)            
    