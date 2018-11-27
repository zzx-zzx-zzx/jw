
# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

#根据节点设置二维列表



from Add_point import add_point
from Add_line import add_line
from Select import select
from read import show_list
from read import read_selsect
from Delect_point import delect_point
from Delect_line import delect_line
    

    
while 1:
    print("******路由表生成系统*******")
    print("1.根据路由器号查询路由表\n2.增加拓扑结构中的节点\n3.增加拓扑结构中的边\n4.删除拓扑结构中的节点\n5.删除拓扑结构中的边\n6.退出系统\n")
    a=input("输入对应序号选择相应操作:\n")
    a=int(a)
    list=[]
    if a==1:
        list=select(read_selsect())
        show_list(list) 
    elif a==2:
        add_point()
        print("\n\n")
        list=select(read_selsect())
        show_list(list) 
    elif a==3:
        add_line()
        
        print("\n\n")
        list=select(read_selsect())
        show_list(list)
    elif a==4:
        delect_point(read_selsect())
        print("\n\n")
        list=select(read_selsect())
        show_list(list)
    elif a==5:
        delect_line(read_selsect())
        print("\n\n")
        list=select(read_selsect())
        show_list(list) 
    elif a==6:
        break
    else:
        print("错误指令")
    
