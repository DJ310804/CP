def getans(n,arr1,arr2):
    l1 = len(set(arr1))
    l2 = len(set(arr2))
    if l1>=2 and l2>=2:
        return 'YES'
    if l1 >=3 and l2 == 1:
        return 'YES'
    if l2 >=3 and l1 == 1:
        return 'YES'
    
    return 'NO'

t = int(input())
for _ in range(t):
    n = int(input())
    arr1 = list(map(int,input().split()))
    arr2 = list(map(int,input().split()))
    print(getans(n,arr1,arr2))