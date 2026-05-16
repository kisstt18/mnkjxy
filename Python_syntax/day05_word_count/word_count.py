
'''tuple

##  创建
t= (1,2,3)
t2=("苹果","香蕉","梨子")
print(t[0])     #1
#   t[0]=88     #Error  tuple不可变

##可以存不会变的数据（如星期、月份、常量等）
week =["星期一","星期二","星期三","星期四","星期五","星期六","星期天"]
print(week[::1])
print(week[0],end=" ")
print(week[1],end=" ")
print(week[2],end=" ")
print(week[3],end=" ")
print(week[4],end=" ")
print(week[5],end=" ")
print(week[6])

'''

'''set

##去重

nums=[1,2,3,4,5,1,2,1]      #八个数
nums2=set(nums)
print(nums2)    #五个数{1,2,3,4,5}

# 交集 &、并集 |、差集 -

a={1,2,3,4}
b={3,4,5,6}
print(a&b)  #交集{3,4}  都有
print(a|b)  #并集{1,2,3,4,5,6}  两个加起来
print(a-b)  #差集{1,2}  a有b没有
print(b-a)  #差集{5,6}  b有a没有

'''

'''str

#字符串方法

#1.split 按分隔符拆分成list
sz=" a b c "
sp=sz.split()
print(sp)           #['a', 'b', 'c']
print(type(sp))     #<class 'list'>
print()

#2.join 把list合成str
jo=" ".join(["a","b"])
print(jo)           #a b
print(type(jo))     #<class 'str'>
print()

#3.strip 去掉首尾空格/换行
st=" h   i  ! ".strip()
print(st)           #h   i  !
print()

#4.replace(a,b) 替换:把a替换成为b
re="hello jack".replace("jack","tom")
print(re)           #hello tom
print()

#5.count(x) 记录出现的次数
co="aaabcd".count("a")
print(co)           #3
print()

#6.startswith(x) 是否以x开头
sta="abcd".startswith("a")
star="abcd".startswith("b")
print(sta)          #True
print(star)         #False

'''

# 要求：

# 1. split() 分词 → 得到一个 list

# 2. set() 去重 → 得到一个不重复词表

# 3. tuple() 转换成元组 → 打印"不重复词表"（元组形式）

# 4. 遍历元组，用 count() 统计每个词出现次数

# 5. 打印结果：苹果: 5次, 香蕉: 3次 ...

text = """
苹果 香蕉 苹果 橘子 香蕉 苹果 葡萄 橘子 西瓜
橘子 苹果 香蕉 葡萄 草莓 苹果 香蕉 西瓜 苹果 橘子
"""

#将text转换为list
text_list=text.split()
#print(text_list)        
#['苹果', '香蕉', '苹果', '橘子', '香蕉', '苹果', '葡萄', '橘子', '西瓜', '橘子',
# '苹果', '香蕉', '葡萄', '草莓', '苹果', '香蕉', '西瓜', '苹果', '橘子']

#使用set让list变成集合去重
text_set=set(text_list)
#print(text_set)     #{'香蕉', '橘子', '葡萄', '草莓', '苹果', '西瓜'}

#使用tuple转换成元组
text_tuple=tuple(text_set)
print("不重复词表：",text_tuple)

#count统计每个词语出现的次数

#先获取每个水果的名字
for word in text_tuple:     
    #然后再在列表里计数出现了几次
    count=text_list.count(word)     
    print(f"{word}: {count}次")