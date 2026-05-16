#   写一个学生成绩管理系统（纯 dict 版）

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


student_dict={
    "张三":90,
    "李四":99,
    "王五":88
}
    
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

    if choice =="1":
        name=input("请输入你的姓名:")
        score=float(input("请输入你的成绩:"))
        student_dict[name]=score
        print(f"\n已帮你添加{name}的成绩{score}")

    elif choice =="2":
        if not student_dict:
            print("暂无学生数据")
        else:
            for name,score in student_dict.items():
                print(f"\n{name}的成绩为：{score}分")

    elif choice =="3":
        name=input("请输入要查找的学生名字:")
        score=student_dict.get(name)
        if score is not None:
            print(f"\n{name}的成绩为：{score}分")
        else:
            print(f"未找到学生：{name}")
    
    elif choice =="4":
        name=input("请输入要查找的学生名字:")
        if name in student_dict:
            new_score=float(input("请输入您要修改的成绩:"))
            student_dict[name]=new_score
        else:
            print("未找到该学生")
    
    elif choice =="5":
        name=input("请输入要查找的学生名字:")
        if name in student_dict:
            del student_dict[name]
            print(f"已删除学生:{name}")
        else:
            print("未找到该学生")

    elif choice == "6":
        #.keys是取键；.values是取值；.items是键值都取
        avg=sum(student_dict.values()) / len(student_dict)
        print(f"\n平均分为: {avg:.2f}分")

    elif choice =="7":
        #sorted排序返回新列表
        # 第 1 轮：x = ("张三", 90)
        # 第 2 轮：x = ("李四", 99)
        # 第 3 轮：x = ("王五", 88)
        score_dict=sorted(student_dict.items(),key=lambda x:x[1],reverse=True)
        print("已经按成绩降序排好啦")
        for name,score in score_dict:
            print(f"{name}的成绩是:{score}分")
            
    elif choice =="8":
        break