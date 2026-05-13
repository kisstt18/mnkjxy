#   打印九九乘法表（for 循环嵌套）
'''一行打印九个换行

for i in range(1,10):               
    for j in range(1,10):
        print(f"{i}*{j}={i*j}",end="\t")
    print()     #每一次内层循环结束就换行

'''

'''一行打印自定义个

for i in range(1,10):               
    count=1
    for j in range(1,10):
        print(f"{i}*{j}={i*j}",end="\t")
        count+=1
        if count %5==0:
            print("\n")

'''

'''while实现九九乘法表(消耗内存版)

i=1
while i<10:
    j=1
    while j<10:
        if i<j:
            print(f"{i}*{j}={i*j}",end="\t")
        else:
            print(f"{j}*{i}={i*j}",end="\t")
        j+=1
    i+=1
    print()

'''

'''while实现九九乘法表(优化版)

i=1
while i<=9:
    j=1
    while j<=i:
        print(f"{j}*{i}={i*j}",end="\t")
        j+=1
    i+=1
    print()

'''
    