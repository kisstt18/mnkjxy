#   写一个学生成绩管理系统（纯 list 版）

# 学生成绩用 list 存储，每个学生是一个 dict
# 例如: students = [{"name": "张三", "score": 85}, {"name": "李四", "score": 92}]

# 程序运行后显示菜单：
# ========== 学生成绩管理系统 ==========
# 1. 添加学生成绩
# 2. 查看所有学生成绩
# 3. 查找某个学生
# 4. 修改学生成绩
# 5. 删除学生
# 6. 计算平均分
# 7. 按成绩排序
# 8. 退出
# 请输入选项(1-8):

# 每个功能都要实现：
# 1. 添加 → input 姓名和成绩，append 到 list
# 2. 查看 → 遍历 list 打印所有学生
# 3. 查找 → input 姓名，遍历找匹配的打印
# 4. 修改 → input 姓名，找到后改成绩
# 5. 删除 → input 姓名，找到后 remove/pop
# 6. 平均分 → 遍历取成绩求和 ÷ 人数
# 7. 排序 → 用 sort() 按成绩降序排
# 8. 退出 → break 跳出循环


students_list = [
    {"name":"张三","score":90},
    {"name":"李四","score":91},
    {"name":"王五","score":80}
    ]

while True:
    print("========== 学生成绩管理系统 ==========")
    print("1. 添加学生成绩")
    print("2. 查看所有学生成绩")
    print("3. 查找某个学生")
    print("4. 修改学生成绩")
    print("5. 删除学生")
    print("6. 计算平均分")
    print("7. 按成绩排序")
    print("8. 退出")
    choice = input("请输入选项(1-8):")

    if choice == "1":
        Name = input("请输入你的姓名:")
        score = float(input("请输入你的成绩:"))
        students_list.append({"name":Name,"score":score})   #print("你好 name")      # 输出：你好 name（原样输出）
                                                            #{}里是变量(f"你好 {name}")   # 输出：你好 张三（{name} 被替换成 "张三"）
        print(f"\n已帮你添加{Name}的成绩{score}")

    elif choice == "2":
        if not students_list:
            print("暂无学生数据")
        else:
            for i,stu in enumerate(students_list,1):
                print(f"\n{i}. {stu['name']}: {stu['score']}分")

    elif choice == "3":
        Name = input("请输入要查找的学生名字:")
        found =False
        for stu in students_list:
            if stu["name"]==Name:
                print(f"\n{stu['name']}的成绩是: {stu['score']}分")
                break
        else:
            print(f"未找到学生:{Name}")

    elif choice =="4":
        Name = input("请输入要查找的学生名字:")
        for stu in students_list:
            if stu["name"]==Name:
                new_score=float(input("请输入您要修改的成绩:"))
                stu["score"]=new_score      #stu["score"]获取key的值
                print(f"{stu['name']}同学的成绩已修改为：{stu['score']}分")
                break
        else:
            print(f"未找到学生: {Name}")
    
    elif choice == "5":
        Name = input("请输入要查找的学生名字:")
        for i,stu in enumerate(students_list):
            if stu["name"]==Name:
                students_list.pop(i)    #pop删除列表最后一项
                print(f"已删除学生: {Name}")
                break
        else:
            print(f"未找到学生: {Name}")
    
    elif choice == "6":
        total=0
        for s in students_list:
            total+=s["score"]       #total求和
        avg=total / len(students_list)
        print(f"\n平均分为: {avg:.2f}分")

    elif choice == "7":  
        students_list.sort(key=lambda x:x["score"],reverse=True)    #reverse=True降序/False升序
        print("已经按成绩降序排好啦")
        for i,stu in enumerate(students_list,1):
                print(f"\n{i}. {stu['name']}: {stu['score']}分")

    elif choice =="8":
        break
    else:
        print("输入错误")