"""
@date(2025-02-17)
懒得下tree，不如自己写工具
"""
import os

def print_tree(startpath, level=9, prefix=""):
    for root, dirs, files in os.walk(startpath):
        level_now = root.replace(startpath, "").count(os.sep)
        if level_now >= level:
            continue
        indent = "│   " * level_now + "├── "
        print(indent + os.path.basename(root) + "/")
        subindent = "│   " * (level_now + 1) + "├── "
        for f in files:
            print(subindent + f)

if "__name__" == "__main__":
    print_tree(".")
