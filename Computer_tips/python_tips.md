## 1 pip安装路径的查看
**该问题出现在安装pygame时，明明安装好了，但import不出来，原因在于没有安装到对应项目的venv\Lib\site-packages里面，复制过来就好了。**
- win+R, cmd
- python -m site
- 其中USER_BASE和USER_SITE是pip的默认安装路径，不出意外都在C盘。
- 去到相应路径复制文件到你想要的位置

**不要看上面写的了，把pip安装的位置改一下，一劳永逸。**
## 2 新建pycharm项目
不要用虚拟环境，而用已有解释器，即previously configured interpreter, 这样site-packages中已有的模块可以直接使用，如pygame.
## 3 挂梯在导致pip更新失败
俺也不懂为啥，反正就不要挂梯子了。
## 4 python不要按到C盘了
现在的位置在\D:\python, 并且pip的安装位置也改过来了，C盘要放不下了。 