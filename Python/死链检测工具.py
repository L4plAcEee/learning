"""
@date(2025-02-23)
"""
import os
import requests
import pandas as pd
from urllib3.exceptions import InsecureRequestWarning
from urllib3 import disable_warnings
from concurrent.futures import ThreadPoolExecutor

# 禁用SSL警告
disable_warnings(InsecureRequestWarning)

class URLChecker:
    def __init__(self, timeout=10, workers=5, column_index=0):
        self.timeout = timeout
        self.workers = workers
        self.column_index = column_index

    def read_excel_file(self, excel_file):
        """
        读取Excel文件，支持多种格式
        """
        try:
            if excel_file.endswith('.xls'):
                try:
                    return pd.read_excel(excel_file, engine='xlrd')
                except Exception as e:
                    try:
                        return pd.read_excel(excel_file)
                    except Exception as e:
                        raise Exception("无法读取.xls文件，请安装xlrd包：pip install xlrd>=2.0.1，或将文件转换为.xlsx格式")
            else:
                return pd.read_excel(excel_file)
        except Exception as e:
            raise Exception(f"读取Excel文件时出错: {str(e)}")

    def check_url(self, url_info):
        """
        检查URL是否可访问
        :param url_info: 元组 (行号, URL)
        :return: (行号, URL, 状态, 错误信息)
        """
        row_num, url = url_info
        
        if not isinstance(url, str):
            return row_num, url, False, "非URL格式"
        
        if not (url.startswith('http://') or url.startswith('https://')):
            return row_num, url, False, "URL格式错误（需要以http://或https://开头）"
            
        try:
            response = requests.head(
                url, 
                timeout=self.timeout, 
                verify=False, 
                allow_redirects=True
            )
            if response.status_code == 404:
                return row_num, url, False, "页面不存在 (404)"
            elif response.status_code >= 400:
                return row_num, url, False, f"错误状态码 ({response.status_code})"
            return row_num, url, True, "正常"
        except requests.exceptions.ConnectionError:
            return row_num, url, False, "连接错误"
        except requests.exceptions.Timeout:
            return row_num, url, False, f"连接超时 (超过{self.timeout}秒)"
        except Exception as e:
            return row_num, url, False, f"其他错误: {str(e)}"

    def process_file(self, excel_file):
        """
        处理单个Excel文件
        """
        print(f"\n正在处理文件: {excel_file}")
        try:
            # 读取Excel文件指定列
            df = self.read_excel_file(excel_file)
            
            if self.column_index >= len(df.columns):
                print(f"错误：文件只有{len(df.columns)}列，无法读取第{self.column_index + 1}列")
                return
                
            # 创建带行号的URL列表（行号从1开始以匹配Excel）
            urls = [(i+2, url) for i, url in enumerate(df.iloc[:, self.column_index].tolist())]
            print(f"从第{self.column_index + 1}列读取到 {len(urls)} 个URL，开始检查...")
            print(f"使用配置：超时时间={self.timeout}秒，并发线程数={self.workers}")
            
            # 使用线程池加速URL检查
            results = []
            with ThreadPoolExecutor(max_workers=self.workers) as executor:
                results = list(executor.map(self.check_url, urls))
            
            # 统计结果
            valid_count = sum(1 for _, _, status, _ in results if status)
            invalid_count = len(results) - valid_count
            
            print(f"\n检查完成:")
            print(f"- 有效链接: {valid_count}")
            print(f"- 无效链接: {invalid_count}")
            
            # 输出详细的无效链接信息
            if invalid_count > 0:
                print("\n无效链接详情:")
                for row_num, url, status, error in results:
                    if not status:
                        print(f"- 第{row_num}行: {url}")
                        print(f"  错误: {error}")
            
            # 创建结果Excel文件
            output_file = f"检查结果_{excel_file}"
            if output_file.endswith('.xls'):
                output_file = output_file.replace('.xls', '.xlsx')
            result_df = pd.DataFrame({
                '行号': [row_num for row_num, _, _, _ in results],
                'URL': [url for _, url, _, _ in results],
                '状态': ['有效' if status else '无效' for _, _, status, _ in results],
                '详细信息': [error for _, _, _, error in results]
            })
            result_df.to_excel(output_file, index=False)
            print(f"\n结果已保存至: {output_file}")
            
        except Exception as e:
            print(f"处理文件时出错: {str(e)}")
            print("如果是文件格式问题，请尝试将文件另存为.xlsx格式")

def main():
    print("Excel链接检查工具启动...")
    print("提示：推荐使用.xlsx格式的Excel文件，.xls格式可能需要安装额外的支持包")
    
    # 获取用户配置
    try:
        timeout = float(input("请输入超时时间（秒）[默认10]: ") or 10)
        workers = int(input("请输入并发线程数 [默认5]: ") or 5)
        column = int(input("请输入要检查的列号（从1开始）[默认1]: ") or 1) - 1
        
        # 创建检查器实例
        checker = URLChecker(timeout=timeout, workers=workers, column_index=column)
        
        # 获取当前目录下所有的xls和xlsx文件
        excel_files = [f for f in os.listdir('.') if f.endswith(('.xls', '.xlsx'))]
        
        if not excel_files:
            print("当前目录下没有找到Excel文件")
            return
            
        print(f"\n找到以下Excel文件：")
        for i, file in enumerate(excel_files, 1):
            print(f"{i}. {file}")
        
        # 处理每个Excel文件
        for excel_file in excel_files:
            checker.process_file(excel_file)
            
    except ValueError as e:
        print(f"输入错误：请确保输入正确的数字格式")
        return

if __name__ == "__main__":
    main()