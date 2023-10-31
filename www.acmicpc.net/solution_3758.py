import sys

input = sys.stdin.readline

test_count = int(input())

for _ in range(test_count):
    team_count, problem_count, my_team_id, entry_count = map(int, input().split())
    team_score_board = [[0] * problem_count for _ in range(team_count)]
    submit_count_board = [0] * team_count
    submit_time_board = [0] * team_count

    for team_score in range(entry_count):
        team_id, problem_num, score = map(int, input().split())

        team_score_board[team_id - 1][problem_num - 1] = max(team_score_board[team_id - 1][problem_num - 1], score)
        submit_time_board[team_id - 1] = team_score
        submit_count_board[team_id - 1] += 1

    ranking=[]
    for idx in range(len(team_score_board)):
        ranking.append([sum(team_score_board[idx]),submit_count_board[idx],submit_time_board[idx],idx])

    
    ranking.sort(key=lambda x:(-x[0],x[1],x[2]))

    for idx in range(len(ranking)):
        if ranking[idx][3]==my_team_id-1:
            print(idx+1)
            break
