import random as rd     
sz=rd.randint(1,10)     #输出随机整数

while True:
    shuru=int(input("请输入一个随机整数："))        #要记得强制转换为int类型
    if shuru > sz:
        print("你猜大啦,再猜小一点")
    elif shuru < sz:
        print("你猜小啦,再猜大一点")
    else:
        print("你猜对啦！恭喜你！")
        break
