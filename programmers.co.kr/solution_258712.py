def solution(friends, gifts):
    sorted(friends)

    give_count = {friend:0 for friend in friends}
    take_count = {friend:0 for friend in friends}
    present_point = {friend:0 for friend in friends}
    next_month_present = {friend:0 for friend in friends}

    give_and_take = {
        friend : { others : [0, 0] for others in set(friends) - {friend}} for friend in friends
    }

    for gift in gifts :
        giver, taker = gift.split(' ')
        give_count[giver] += 1
        take_count[taker] += 1
        give_and_take[giver][taker][0] += 1
        give_and_take[taker][giver][1] += 1
        
    for key in give_count.keys():
        present_point[key] += (give_count[key] - take_count[key])
    

    for index in range(len(friends) - 1):
        
        alice = friends[index]
        bobs = friends[index + 1:]
        
        for bob in bobs:
            AtoB = give_and_take[alice][bob][0]
            BtoA = give_and_take[alice][bob][1]
            if AtoB > BtoA:
                next_month_present[alice] += 1
            elif AtoB < BtoA:
                next_month_present[bob] += 1
            elif AtoB == BtoA :
                if present_point[alice] > present_point[bob]:
                    next_month_present[alice] += 1
                elif present_point[alice] < present_point[bob]:
                    next_month_present[bob] += 1
                else:
                    next_month_present[bob] += 0
                    
    return max(list(next_month_present.values()))

answer = solution(["muzi", "ryan", "frodo", "neo"], ["muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"])
print(answer)