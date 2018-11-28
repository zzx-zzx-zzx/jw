def add_line():
    r = open("text.txt", "a")
    print("熊于棚")
    while 1:
        a=input("输入边节点号:")
        b=input("输入边节点号:")
        c=input("输入两点距离:")
        r.writelines('\n'+a+'\n')
        r.writelines(b+'\n')
        r.writelines(c)    
        Y_N=input("继续输入？ 是：1  否：2\n")
        Y_N=int(Y_N)
        if Y_N!=2 and Y_N!=1:
            print("错误指令，请重新选择")
            while 1:
                Y_N=input("继续输入？ 是：1  否：2\n")
                if Y_N==1 or Y_N==2:
                    break
        elif Y_N==1:
            continue
        elif Y_N==2:
            break
    r.close()

sdsdsd
26538623485643
