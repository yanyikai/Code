q=int(input())
for i in range(q):
    n,m,k=map(int,input().split())
    if(max(n,m)>k):
        print(-1)
    else:
        print(k-(n-k)%2-(m-k)%2)
