'''
@date(2025-02-13)
写来给我的博客推送百度收录的，但是不知道为什么这b百度限制我推送数量，艹了。
'''
import os
import requests
from bs4 import BeautifulSoup
import xml.etree.ElementTree as ET

# 配置
sitemap_path = "public/sitemap.xml"  # sitemap.xml 路径
public_path = "public"  # Hexo 生成的 public 文件夹路径
base_url = "https://www.example.com"  # 你的网站域名
# 百度推送接口
api_url = ""

# 1. 从 sitemap.xml 获取 URLs
def get_urls_from_sitemap(sitemap_path):
    urls = []
    try:
        tree = ET.parse(sitemap_path)
        root = tree.getroot()
        # 遍历所有 <loc> 标签
        for child in root:
            for item in child:
                if "loc" in item.tag:
                    urls.append(item.text)
    except Exception as e:
        print(f"解析 sitemap.xml 失败: {e}")
    return urls

# 2. 从 public 文件夹获取 URLs
def get_urls_from_public(public_path, base_url):
    urls = []
    for root, dirs, files in os.walk(public_path):
        for file in files:
            if file.endswith(".html"):
                # 构建完整 URL
                relative_path = os.path.relpath(os.path.join(root, file), public_path)
                url = base_url + "/" + relative_path.replace("\\", "/")
                urls.append(url)
    return urls

# 3. 推送到百度
def push_to_baidu(urls):
    if not urls:
        print("没有可推送的 URLs！")
        return

    # 将链接列表转换为换行分隔的字符串
    urls_str = "\n".join(urls)

    # 发送 POST 请求
    headers = {
        "Content-Type": "text/plain"
    }
    response = requests.post(api_url, data=urls_str, headers=headers)

    # 输出结果
    if response.status_code == 200:
        print("推送成功！")
        print("返回结果：", response.json())
    else:
        print("推送失败！")
        print("状态码：", response.status_code)
        print("返回内容：", response.text)

if __name__ == "__main__":
    urls = get_urls_from_sitemap(sitemap_path)  # 从 sitemap.xml 获取
    if not urls:
        print("从 sitemap.xml 获取 URLs 失败，尝试从 public 文件夹获取...")
        urls = get_urls_from_public(public_path, base_url)  # 从 public 文件夹获取

    # 推送 URLs
    push_to_baidu(urls)