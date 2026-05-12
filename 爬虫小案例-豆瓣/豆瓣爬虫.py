import requests
from bs4 import BeautifulSoup 

'''#示例

# head ={"user-Agent":"tt/5.0(Windows NT 10.0; Win64;64)"}    #伪装成浏览器请求
# response = requests.get("http://books.toscrape.com/",header=head)   #获取网址发送http请求

# # print(response)   #服务器发回响应
# # print(response.status_code)   #状态码202表示成功

# if  response.ok:
#     print("请求成功")
#     print(response.text)
# else:
#     print("请求失败")
'''

headers ={
    "user-Agent":"Mozilla/5.0 ( Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/147.0.0.0 Safari/537.36"
    }

for start_num in range(0,250,25):
    print(start_num)

    response = requests.get(f"https://movie.douban.com/top250?start={start_num}",headers=headers)
    html = response.text     #返回源码
    soup = BeautifulSoup(html,"html.parser")   #构造函数
    all_Titles = soup.findAll("span",attrs={"class":"title"})   #返回可迭代对象  需要爬取的网站源代码中包含的数据

    for title in all_Titles:
        title_string = title.string
        if "/" not in title_string:  #如果带有/的不在title里就打印输出
            print(title_string)