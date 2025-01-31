def push(a):
    stack.append(a)

def pop():
    if(is_empty()):
        return -1
    return stack.pop()

def size():
    return len(stack)

def is_empty():
    if(len(stack)):
        return 0
    else :
        return 1
    
def top():
    if(is_empty()):
        return -1
    return stack[-1]

stack=[]
a=int(input())
for i in range(a):
    b=list(input().split())
    if(b[0]=="push"):
        push(int(b[1]))
    elif(b[0]=="pop"):
        print(pop())
    elif(b[0]=="size"):
        print(size())
    elif(b[0]=="empty"):
        print(is_empty())
    elif(b[0]=="top"):
        print(top())