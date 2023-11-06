import heapq as hq
import sys

input = sys.stdin.readline

heap = []
board_size = int(input())

for _ in range(board_size):
    numbers = map(int, input().split())
    
    for number in numbers:
        if len(heap) < board_size:
            hq.heappush(heap, number)
            
        else:
            if heap[0] < number:
                hq.heappop(heap)
                hq.heappush(heap, number)
                
print(heap[0])