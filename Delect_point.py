def delect_point(point):
    find=input("请输入选择删除的路由器节点号:\n")
    find=int(find)

    n=0
    r = open("text.txt", "w")
    while 1:
        if (point[n][0]==find or point[n][1]==find):
            point.remove(point[n])
        else :
            n=n+1
        if n==len(point):
            break
    n=0
    while n!=len(point):
        r.writelines(str(point[n][0])+'\n')
        r.writelines(str(point[n][1])+'\n')
        r.writelines(str(point[n][2])+'\n')
        n=n+1
    r.close()      
