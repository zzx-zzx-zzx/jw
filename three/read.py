from Select import Find

def read_selsect():
    points = []
    point=[]
    r = open("text.txt", "r")
    i=0
    while True:
        point_1=r.readline()
        if not point_1:      
            break
        point_1=int(point_1)
        point_2=r.readline()
        point_2=int(point_2)
        t=r.readline()
        t=int(t)
        points=[point_1,point_2,t]
        point.append(points)
        i=i+1
    r.close()
    return point  
       
def show_list(list):
    j=[]
    print("\n******路由表*******\n")
    print("节点:   下一跳：")
    while len(list)!=0:
        j=(min(list))
        num=Find(list,j[0])
        print(" ",j[0],"     ",list[num][2])
        list.remove(list[num])
    print("\n")
    
