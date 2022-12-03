members = ( ('qqq', 13) , ('www', 83) , ('eee', 72) ,('rrr', 32) ,('tt', 12) ,('aa', 92) ,('qss', 63) ,('qdsa', 85) ,('qbb', 95) ,('jghn', 38))

memberName = ''
score = 0


for x in range(len(members)):
    if(score < members[x][1]):
        score = members[x][1]
        memberName = members[x][0]
        
print("만족도 점수가 가장 높은 회원은 {0}, 점수는 {1}입니다".format(memberName,score))
