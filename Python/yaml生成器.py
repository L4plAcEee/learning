"""
@date(2025-02-26)
用于个人博客自动生成yml数据源
注意点如下：
1. 注意markdown格式，这里用原生str拼接内容保证行为受控
2. 正则表达式用于自动捕获tag - tag格式：“#{tag}”，
    为了尽量避免错误捕获，所以要写复杂一点的匹配规则。

"""

import yaml
import datetime
import os
import re
from textwrap import indent

your_api_key = ""
target_txt = "temp.txt"
target_yaml = "shuoshuo.yml"

def generate_yaml_entry():
    # 检查temp.txt是否存在
    if not os.path.exists(target_txt):
        print("错误: temp.txt 文件不存在!")
        return
    
    # 读取temp.txt中的内容
    try:
        with open(target_txt, 'r', encoding='utf-8') as file:
            original_content = file.read().strip()
    except Exception as e:
        print(f"读取文件时出错: {e}")
        return
    
    # 检查内容是否为空
    if not original_content:
        print("错误: temp.txt 内容为空!")
        return
    
    # 保存一份原始内容的副本，用于处理标签
    content = original_content
    
    # 捕获标签 - 改进的正则表达式
    tags = ['default_tag']  # 默认标签
    
    # 使用更精确的正则表达式，只匹配中文、英文字母和数字
    tag_pattern = r'#([一-龥a-zA-Z0-9_\-]+)'
    found_tags = re.findall(tag_pattern, content)
    
    # 从内容中移除标签标记
    if found_tags:
        # 去重
        unique_tags = []
        for tag in found_tags:
            if tag not in unique_tags:
                unique_tags.append(tag)
        
        # 将找到的标签添加到tags列表，避免重复
        for tag in unique_tags:
            if tag not in tags:
                tags.append(tag)
        
        # 从内容中移除标签标记
        content = re.sub(tag_pattern, '', content)
        # 清理多余的空格
        content = re.sub(r' +', ' ', content)
        content = content.strip()
    
    # 格式化内容为缩进正确的多行字符串
    # 分割成行
    lines = content.split('\n')
    # 重新组装并缩进
    formatted_content = '\n    '.join(lines)
    
    # 获取当前时间并格式化
    current_time = datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')
    
    # 创建新的YAML条目
    new_entry = {
        'author': 'L4place',
        'avatar': 'https://www.l4place.icu/img/avatar.jpg',
        'date': current_time,
        'key': f'key-{int(datetime.datetime.now().timestamp())}',
        'content': f"|\n    {formatted_content}",
        'tags': tags
    }
    
    # 使用原生方式构建YAML字符串，避免PyYAML自动转义
    yaml_str = "- author: L4place\n"
    yaml_str += "  avatar: https://www.l4place.icu/img/avatar.jpg\n"
    yaml_str += f"  date: {current_time}\n"
    yaml_str += f"  key: {your_api_key}\n"
    yaml_str += "  content: |\n"
    
    # 直接添加内容，保持每行前面有4个空格的缩进
    for line in content.split('\n'):
        yaml_str += f"    {line}\n"
    
    # 添加标签
    yaml_str += "  tags:\n"
    for tag in tags:
        yaml_str += f"  - {tag}\n"
    
    # 尝试读取现有的YAML文件
    existing_yaml = ""
    yaml_file = target_yaml
    if os.path.exists(yaml_file):
        try:
            with open(yaml_file, 'r', encoding='utf-8') as file:
                existing_yaml = file.read()
        except Exception as e:
            print(f"读取现有YAML文件时出错: {e}")
    
    # 将新条目添加到现有YAML
    if existing_yaml:
        with open(yaml_file, 'w', encoding='utf-8') as file:
            file.write(existing_yaml + "\n" + yaml_str)
    else:
        with open(yaml_file, 'w', encoding='utf-8') as file:
            file.write(yaml_str)
    
    print(f"已成功将内容添加到 {yaml_file}")
    print(f"使用的时间戳为: {current_time}")
    print(f"捕获的标签: {tags}")
    
    # 打印实际内容格式以供确认
    print("\n实际内容格式预览:")
    print("content: |")
    for line in content.split('\n'):
        print(f"    {line}")

if __name__ == "__main__":
    generate_yaml_entry()