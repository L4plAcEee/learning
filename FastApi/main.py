from typing import Union
from fastapi import FastAPI
from pydantic import BaseModel
from typing import Optional
from typing import Any
from decimal import Decimal
import random


class Donation(BaseModel):
    id: int
    signature: str
    donation_amount: Decimal
    # 在 Python 类型提示（Type Hints）中，Optional 是一个特殊类型注解，
    # 用于表示某个值可以是指定类型，也可以是 None。它来自 typing 模块，是 Python 3.5+ 引入的类型系统的重要组成。
    description: Optional[str] = None 
    

class APIResponse(BaseModel):
    code: int
    msg: Optional[str] = None
    # typing.Any允许任何类型，类似动态类型，比Optional[Object]方案更适合
    data: Optional[Any] = None

data: list[Donation] = []
def init_data(num_records: int = 10):
    """ 初始化随机 Donation 记录 """
    global data
    data.clear()
    
    for i in range(1, num_records + 1):
        donation = Donation(
            id=i,
            signature=f"Donor_{random.randint(1000, 9999)}",
            donation_amount=Decimal(random.uniform(10, 1000)).quantize(Decimal("0.01")),
            description=random.choice(["芙兰朵露", "十六夜咲夜", "红美玲", ""])
        )
        data.append(donation)

app = FastAPI()
init_data()

@app.get("/")
def say_hello():
    """
    from fastapi import FastAPI： 这行代码从 fastapi 模块中导入了 FastAPI 类。FastAPI 类是 FastAPI 框架的核心，用于创建 FastAPI 应用程序实例。

    app = FastAPI()：这行代码创建了一个 FastAPI 应用实例。与 Flask 不同，FastAPI 不需要传递 __name__ 参数，因为它默认使用当前模块。

    @app.get("/")： 这是一个装饰器，用于告诉 FastAPI 哪个 URL 应该触发下面的函数，并且指定了 HTTP 方法为 GET。在这个例子中，它指定了根 URL（即网站的主页）。

    def say_hello():： 这是定义了一个名为 say_hello 的函数，它将被调用当用户使用 GET 方法访问根 URL 时。

    return {"Hello": "reimu"}： 这行代码是 say_hello 函数的返回值。当用户使用 GET 方法访问根 URL 时，这个 JSON 对象将被发送回用户的浏览器或 API 客户端。
    """
    return APIResponse(code=10001, msg="OK", data={"hello": "reimu"})

@app.get("/donation/{id}")
def reimu_get(id: int, q: str):
    """
    FastAPI会自动捕获"/{id}?q='xxx'"中的查询参数并解析成python可直接处理的数据格式
    """
    for it in data:
        if it.id == id or it.signature == q:
            return APIResponse(code=10001, msg="OK", data=it)
    return APIResponse(code=10404, msg="donation record not found")
@app.post("/donation/")
def reimu_post(donation: Donation):
    """
    使用 Pydantic 模型 定义了一个请求体，包含多个字段，其中一些有默认值
    FastAPI会自动处理参数并包装成对应Pydantic模型

    针对Post的特性，应当创建新数据时使用post
    """
    for it in data:
        if it.id == donation.id:
            return APIResponse(code=205, msg="Reset Content")
    data.append(donation)
    return APIResponse(code=10001, msg="OK")
@app.put("/donation/")
def reimu_put(donation: Donation):
    """
    相同的，FastAPI会自动处理参数并包装成对应Pydantic模型
    不过针对put方法的特性，应当完全更新数据时使用put
    """
    for index, it in enumerate(data): # enumerate()返回一个由索引和对象构成的二元组
        if it.id == donation.id:
            data[index] = donation
            return APIResponse(code=10001, msg="OK")
    data.append(donation)
    return APIResponse(code=10001, msg="OK")

@app.patch("/donation/")
def reimu_patch(donation: Donation):
    """
    相同的，FastAPI会自动处理参数并包装成对应Pydantic模型
    不过针对patch方法的特性，应当更新部分字段，而不是整个资源时使用patch
    """
    for index, it in enumerate(data):
        if it.id == donation.id:
            data[index] = donation
            return APIResponse(code=10001, msg="OK")
    return APIResponse(code=10404, msg="not found")
@app.delete("/donation/{id}")
def reimu_delete(id: int):
    """
    相同的，FastAPI会自动处理参数并包装成对应Pydantic模型
    不过针对delete方法的特性，删除资源时使用delete
    """
    for it in data:
        if it.id == id:
            data.remove(it)
            return APIResponse(code=10001, msg="OK")
    return APIResponse(code=10404, msg="not found")
@app.options("/donation/")
def func_option():
    return APIResponse(code=10001, msg='OK', data={"qwq": "qaq"})