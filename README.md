# Face-Detection
基于OpenCV的人脸检测

该代码运行需要在VS上配置OpenCV的环境
1.修改环境变量步骤如下：右键“我的电脑”->”属性”->”高级系统设置”->”环境变量”->”系统变量Path”，添加“D:\opencv\build\x64\vc14\bin”（以自己下载路劲为准），添加成功后关闭界面。
2.在VS2017上新建一个空项目并新建源文件。
3.点击“视图”进入到属性管理器
4.在这里以64位为例，双击debug x64进入如下的界面，首先修改包含目录，添加以下三个目录地址：
D:\opencv\build\include 
D:\opencv\build\include\opencv 
D:\opencv\build\include\opencv2
然后修改工程库目录，添加库目录：D:\opencv\build\x64\vc15\lib
5.修改链接库，连接器--输入--附加依赖项 将opencv中的lib库添加进去，
 例如opencv_world400d.lib（以实际安装版本为准）
