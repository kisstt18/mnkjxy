#猜数字游戏函数版
# 1. 调用 sj_number() 生成目标

# 2. while True 循环让用户猜

# 3. 调用 check_guess() 判断

# 4. 猜对了 break
'''import random
def sj_number(min_num=1,max_num=10):
    #生成1-100之间的随机整数
    return random.randint(min_num,max_num)

#target 目标数
#guess  用户猜的数
#result 比较
def numbers(target,guess):
    #判断用户猜的数字是大了还是小了或者猜对了
    if guess>target:
        return "猜大了"
    elif guess<target:
        return "猜小了"
    else:
        return "猜对了"
    
def play_game():
    target=sj_number()
    print("猜数字游戏开始!范围在1-10直接")
    while True:
        guess=int(input("请输入您猜的数字："))
        result=numbers(target,guess)

        if result=="猜大了":
            print("猜大了,再猜小一点")
        elif result=="猜小了":
            print("猜小了,再猜大一点")
        else:
            print("恭喜你!猜对了") 
            break
if __name__=="__main__":
    play_game()'''
'''import random
def sj_number(min_num=1,max_num=10):
    #生成1-100之间的随机整数
    return random.randint(min_num,max_num)

#target 目标数
#guess  用户猜的数
#result 比较
def numbers(target,guess):
    #判断用户猜的数字是大了还是小了或者猜对了
    if guess>target:
        return "猜大了"
    elif guess<target:
        return "猜小了"
    else:
        return "猜对了"
    
target=sj_number()
print("猜数字游戏开始!范围在1-10直接")
while True:
    guess=int(input("请输入您猜的数字："))
    result=numbers(target,guess)
    if result=="猜大了":
        print("猜大了,再猜小一点")
    elif result=="猜小了":
        print("猜小了,再猜大一点")
    else:
        print("恭喜你!猜对了") 
        break'''


'''text = """苹果 香蕉 苹果 橘子 香蕉 苹果 葡萄 橘子 西瓜

橘子 苹果 香蕉 葡萄 草莓 苹果 香蕉 西瓜 苹果 橘子"""

def split_words(text):

    return text.split()

def unique_words(words):

    return tuple(set(words))

def count_freq(words, unique):
    result={}
    for word in unique:
        count=words.count(word)
        result[word]=count
    return result 

    # 遍历元组，用 list.count() 统计
    # 返回一个 dict：{"苹果": 5, "香蕉": 3, ...}
    

def print_result(freq_dict):
    for word,count in freq.items():
        print(f"{word}: {count}次")
    # 遍历 dict，打印结果


words = split_words(text)
unique = unique_words(words)
freq = count_freq(words, unique)
print_result(freq)'''


'''def get_input(*args):
    """
    接收多个身高体重对
    例如 get_input(1.75, 70, 1.80, 85) 
    返回 [(1.75, 70), (1.80, 85)]
    """
    hight=float(input("请输入你的身高(m):"))
    weight=float(input("请输入你的体重(kg):"))
    return hight,weight

def js_bmi(height,weight):
    return weight / height**2
    # 把 *args 两两分组

def bmi_fanwei(bmi):
    if  bmi < 18.5:
        return "偏瘦"
    elif bmi <= 23.9:
        return "正常"
    elif bmi <= 27.9:
        return "偏胖"
    else:
        return "肥胖"
h,w=get_input()
bmi=js_bmi(h,w)
result=bmi_fanwei(bmi)
print(f"BMI:{bmi:.2f},{result}")'''