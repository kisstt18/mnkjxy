#写一个 BMI 计算器
'''BMI公式范围
BMI = 体重(kg) / 身高(m)²
中国标准:BMI 范围
BMI < 18.5	偏瘦
BMI 18.5 ~ 23.9	正常
BMI 24 ~ 27.9	偏胖
BMI ≥ 28	肥胖

'''

'''第一版-基础

shengao = float(input("请输入你的身高(m):"))
tizhong = float(input("请输入你的体重(kg):"))
if 0<shengao<=3  and 0<tizhong <=500: 
    BMI = tizhong / shengao ** 2
    print("您的BMI约为:{:.2f}".format(BMI))
    if BMI <18.5:
        print("您有点偏瘦了")
    elif BMI <=23.9:
        print("您很正常")
    elif BMI <=27.9:
        print("您有点偏胖了")
    else:
        print("您有点肥胖了")
    
else:
    print("输入数值太大，请重新再试")

'''

'''第二版-加入了循环

while True:

    shengao = float(input("请输入你的身高(m):"))
    tizhong = float(input("请输入你的体重(kg):"))

    if 0<shengao<=3  and 0<tizhong <=500: 
        BMI = tizhong / shengao ** 2
        print("\n计算成功!您的BMI约为:{:.2f}\n".format(BMI))
        if BMI <18.5:
            print("您有点偏瘦了")
        elif BMI <=23.9:
            print("您很健康")
        elif BMI <=27.9:
            print("您有点偏胖了")
        else:
            print("您有点肥胖了")
        break
    else:
        print("输入数值太大，请重新再试")


'''

'''第三版-加入异常处理

while True:
    try:
        shengao = float(input("请输入你的身高(m):"))
        tizhong = float(input("请输入你的体重(kg):"))

        if 0<shengao<=3  and 0<tizhong <=500: 
            BMI = tizhong / shengao ** 2
            print("\n计算成功!您的BMI约为:{:.2f}\n".format(BMI))
            if BMI <18.5:
                print("您有点偏瘦了")
            elif BMI <=23.9:
                print("您很健康")
            elif BMI <=27.9:
                print("您有点偏胖了")
            else:
                print("您有点肥胖了")
            break
        # else:
        #     print("输入数值太大，请重新再试")
    except:
        print("请输入数字!")
        break

'''

'''第四版-调用函数运行

def jisuanbmi(shengao,tizhong):     #计算BMI

    return tizhong / shengao ** 2

def bmifanwei(BMI):     #根据BMI范围返回字符串语句
    if BMI <18.5:
        return"您有点偏瘦了"
    elif BMI <=23.9:
        return"您很健康"
    elif BMI <=27.9:
        return"您有点偏胖了"
    else:
        return"您有点肥胖了"
    
while True:
    try:
        shengao = float(input("请输入你的身高(m):"))
        tizhong = float(input("请输入你的体重(kg):"))
        if 0<shengao<=3  and 0<tizhong <=500:     #如果在这个范围就运行下面的代码 
            BMI = jisuanbmi(shengao,tizhong)    #要调用的数据赋值给BMI
            fanwei = bmifanwei(BMI)     #调用BMI范围输出对应的语句
            print("\n您的BMI约为:{:.2f}".format(BMI))     #输出jisuanbmi函数里面的BMI值
            print()     #空一行
            print(fanwei)       #输出bmi所在区间
            break
    except ValueError:      #数值错误Value
        print("请输入有效数字")

'''
