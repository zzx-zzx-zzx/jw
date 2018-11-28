def delect_line(point):
    find_1=input("请输入选择删除边的路由器节点号:\n")
    find_2=input("请输入选择删除边的路由器节点号:\n")
    find_1=int(find_1)
    find_2=int(find_2)

    n=0
    r = open("text.txt", "w")
    while 1:
        if (point[n][0]==find_1 and point[n][1]==find_2 )or (point[n][1]==find_1 and point[n][0]==find_2):
            point.remove(point[n])
            break
        else :
            n=n+1
        if n==len(point):
            break
    n=0
    r.writelines(str(point[n][0])+'\n')
    r.writelines(str(point[n][1])+'\n')
    r.writelines(str(point[n][2]))
    n=n+1
    while n!=len(point):
        r.writelines('\n'+str(point[n][0])+'\n')
        r.writelines(str(point[n][1])+'\n')
        r.writelines(str(point[n][2]))
        n=n+1
    r.close()      
