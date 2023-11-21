import sys

input = sys.stdin.readline

def searchAnswer():
    sentence = input().strip()
    number_k = int(input())
    
    characters_count = countCharacter(sentence=sentence)
    searchAnswerInSentence(characters_count=characters_count, sentence=sentence, number_k=number_k)

def countCharacter(sentence: str) -> dict:
    characters_count = {}
    
    for char in sentence:
        characters_count[char] = characters_count.get(char, 0) + 1
    
    return characters_count

def searchAnswerInSentence(characters_count, sentence, number_k):
    
    check_dictionary = findIndexMeetsConditions(characters_count, sentence, number_k)
    printAnswer(check_dictionary=check_dictionary, sentence=sentence, number_k=number_k)


def findIndexMeetsConditions(characters_count, sentence, number_k) :
    
    check_dictionary = {}
    
    for index in range(len(sentence)):
        if validateCharacter(characters_count=characters_count, char=sentence[index], number_k=number_k) :
            continue
        
        check_dictionary[sentence[index]] = check_dictionary.get(sentence[index], []) + [index]
        
    return check_dictionary
        

def validateCharacter(characters_count, char, number_k) :
    return characters_count[char] < number_k


def printAnswer(check_dictionary, sentence, number_k):
    max_answer = -1
    min_answer = len(sentence)
    
    for _, value in check_dictionary.items():
        
        for i in range(len(value) - number_k + 1) :
            max_answer = max(max_answer, value[i + number_k - 1] - value[i] + 1)
            min_answer = min(min_answer, value[i + number_k - 1] - value[i] + 1)


    if max_answer == -1 and min_answer == len(sentence):
        print(-1)
    else:
        print(min_answer, max_answer)
    

test_case = int(input())
for i in range(test_case):
    searchAnswer()