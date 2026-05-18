import os

'''# rename_files("./111.txt")

# script_dir=os.path.dirname(__file__)
# folder=os.path.join(script_dir,"test")

# old=os.path.join(script_dir,"./test/111.txt")
# new=os.path.join(script_dir,"./test/444.txt")
# # files=os.listdir(folder)
# os.rename(old,new)
# print("改名成功")'''

def rename_files(folder_path,old_prefix,new_prefix):        #批量改名(文件夹路径, 旧文字, 新文字)
    #列出所有文件
    files=os.listdir(folder_path)
    if not os.path.exists(folder_path):
        print(f"错误:文件夹{folder_path}不存在")
        return

    files=os.listdir(folder_path)
    for filename in files:
        if old_prefix in filename:

            #拼出旧路径跟新路径
            old_path =os.path.join(folder_path,filename)
            new_name=filename.replace(old_prefix,new_prefix)
            new_path=os.path.join(folder_path,new_name)

            #改名
            os.rename(old_path,new_path)
            print(f"重命名:{filename}————>{new_name}")

#调用函数   __file__自定定位test文件夹
script_dir = os.path.dirname(__file__)
test_folder = os.path.join(script_dir, "test")
rename_files(test_folder, "photo", "img")