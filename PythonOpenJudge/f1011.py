#描述
#George took sticks of the same length and cut them randomly until all parts became at most 50 units long. Now he wants to return sticks to the original state, but he forgot how many sticks he had originally and how long they were originally. Please help him and design a program which computes the smallest possible original length of those sticks. All lengths expressed in units are integers greater than zero.
#输入
#The input contains blocks of 2 lines. The first line contains the number of sticks parts after cutting, there are at most 64 sticks. The second line contains the lengths of those parts separated by the space. The last line of the file contains zero.
#输出
#The output should contains the smallest possible length of original sticks, one per line.
#样例输入
#9
#5 2 1 5 2 1 5 2 1
#4
#1 2 3 4
#0
#样例输出
#6
#5
#sticks = []
#counts = []
#while True:
#    num = int(input())
#    if num == 0:
#        break
#    counts.append(num)
#    sticks.append(input())
#for i in range(len(counts)):
#    stickcount = counts[i]
#    datastr = sticks[i]
#    datas = str(datastr).split(sep=" ")
#    dataint = [int(datai) for datai in datas]
#    dataint.sort(reverse = True)
#    totallen = 0
#    maxlen = 0
#    for j in range(len(datas)):
#        if maxlen < int(datas[j]):
#            maxlen = int(datas[j])
#        totallen+=int(datas[j])  
#    right = False
#    result = 0
#    for k in range(maxlen,totallen + 1):
#        if right:
#            break
#        if totallen % k == 0:
#            result = k
#            stickcount = int(totallen / k)
#            sl = [k] * stickcount
#            for stick in dataint:
#                if result == -1:
#                    break
#                stickindex = 0
#                while True:         
#                    processed = False
#                    if stickindex >= stickcount:
#                        result = -1
#                        break
#                    for si in range(len(sl)):
#                        if sl[si] == stick:
#                            sl[si]-=stick
#                            processed = True
#                            break
#                    if processed:
#                        break
#                    if sl[stickindex] == 0 or sl[stickindex] < stick:
#                        stickindex+=1
#                        continue
#                    else:
#                        sl[stickindex]-=stick
#                        stickindex+=1
#                        break
#            if sl == [0] * stickcount:
#                    right = True
#    print(result)
def dfs(s,len,pos,L,k):
    global v,dataint,stickcount
    if s==k : 
        return True
    for i in range(pos+1,stickcount):
        if v[i]==True :
            continue
        if len+dataint[i]==L:
            v[i]==True
            if dfs(s+1,0,-1,L,k):
                return True
            sefl.v[i]=False
            return False
        elif dataint[i]+len<L:
            v[i]=True
            if(dfs(s,len+dataint[i],i,L,k)):
                return True
            v[i]=False
            if len==0 :
                return False
    return False
sticks = []
counts = []
dataint=[]
v=[]
stickcount=0
while True:
    num = int(input())
    if num == 0:
        break
    counts.append(num)
    sticks.append(input())
for i in range(len(counts)):
    v=[False]*70
    stickcount = counts[i]
    datastr = sticks[i]
    datas = str(datastr).split(sep=" ")
    dataint = [int(datai) for datai in datas]
    dataint.sort(reverse = True)
    totallen = sum(dataint) 
    maxlen = max(dataint)
    for L in range(maxlen,totallen + 1):
        if totallen%L!=0:
            continue
        n=totallen/L
        if dfs(1,0,-1,L,int(n)):
            print(L)
            break