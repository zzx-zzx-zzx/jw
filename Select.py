def select(point):
    n=0
    k=0
    List=[]
    p=[]
    Len=len(point)
    i=Len
    store=[]
    next_find=0
    find=input("请输入选择查询的路由器号:\n")
    find=int(find)
    first=find
    while 1:
        
        while 1:
            if n==i:
                break
            if (point[n][0]==find or point[n][1]==find):
                if point[n][0]==find:
                    next_find=point[n][1]
                else :
                    next_find=point[n][0]
               
                if find==first:
                    p=[next_find,point[n][2],next_find]
                    List.append(p)
                    
                else:
                    j=Find (List,next_find)
                    if(j!=1000):
                        if List[j][1]>List[k][1]+point[n][2]:
                            List[j][1]=List[k][1]+point[n][2]
                            List[j][2]=List[k][2]
                    else:
                        p=[next_find,(point[n][2]+List[k][1]),List[k][2]]
                        List.append(p)
                        
                point.remove(point[n])
                i=len(point)
            else:
                n+=1             
            
        if len(point)==0:
            return List
        n=0
        if find!=first:
            k=Find(List,find)
        find=min_L(List,store)
        store.append(find)

            

    
def min_L(List,store):
    Min=[1000,0]
    n=0
    while n!=len(List):
        if (List[n][0] not in store) and List[n][1]<Min[0]:
            Min[0]=List[n][1]
            Min[1]=List[n][0]
        n+=1    
    return Min[1]


def Find (List,next_find):
    n=0
    i=len(List)
    while n<i:
        if List[n][0]==next_find :
            return n
        n=n+1
    return 1000


