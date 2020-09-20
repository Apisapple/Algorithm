def solution(skill, skill_trees):
    answer = 0
    for skill_tree in skill_trees:
        value = []
        flag = True
        for j in range(len(skill_tree)):
            if skill_tree[j] in skill:
                value.append(skill_tree[j])

        for j in range(len(value)):
            if value[j] != skill[j]:
                flag = False
                break
        if(flag):
            answer += 1
    
    return answer