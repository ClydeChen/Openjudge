while True:
    k=int(input())
    if k==0 :
        break
    kills=[0]*30
    m=1
    n=2*k
    first=True
    while True:
        flag=False
        if first:
            first=False
            for i in range (1,k):
                kills[i]=(kills[i-1]+m-1)%(n-i+1)
                if kills[i]<k:
                    m+=1
                    flag=True
                    break
        else:
            for i in range (0,k):
                kills[i]=(kills[i-1]+m-1)%(n-i+1)
                if kills[i]<k:
                    m+=1
                    flag=True
                    break
        if flag==False:
            break
    print(m)
