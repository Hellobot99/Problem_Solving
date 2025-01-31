first=list(map(int,input().split()))
set1=set()
set2=set()
set3=set()
count=0
for i in range(first[0]):
    word=input()
    set1.add(word)
for i in range(first[1]):
    if input() in set1:
        count+=1
print(count)