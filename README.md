# 广播聊天室程序(Qt5 实现)

程序主要包含聊天和文件传输两个功能：

1. 聊天：用户登录、退出和发送消息时都使用UDP广播来告知所有用户，系统所有用户的地位都是平等的，每个用户聊天窗进程视为一个端点。共有五中消息类型： Msg（常规信息）,UsrEnter（用户进入）,UsrLeft（用户离开）,FileName（传输文件）,Refuse（拒绝接收），将采用不同的槽函数进行处理。消息都是用UDP进行传送。

2. 文件传输：采用TCP实现，采用C/S方式。用户聊天窗进程视不同角色分别扮演服务器和客户端。客户端是接收端，服务器是发送方。服务器发送文件前先用UDP发送文件名，客户端再用UDP返回响应。若客户端同意接受文件，则服务器利用TCP连接传输文件。
点击“发送”按钮后将服务器设置为监听状态，并发送sndFileName()信号，主界面Widget类将关联该信号并使用UDP广播将文件名发送给接收端。广播信息包含接收端的IP地址，所有用户客户端收到广播之后会和自己的IP地址对比，如果匹配则弹出文件接收提示框。若同意接收，则建立TCP客户端并建立TCP连接传输文件。拒绝则使用UDP广播将拒绝消息返回发送端（同样需要匹配），一旦发送端收到该拒绝消息就取消文件的传输。

每个用户聊天窗既可做服务器也能作为客户端，P2P系统。

## 一、登录界面

![Image text](https://raw.githubusercontent.com/Taurus-Chao/ChatRoom_Qt5/master/imgstorage/login.png)

采用Splash窗口呈现登录界面，根据登录输入状况确定启动主窗口或终止程序运行。目前设定的用户信息：
* 用户名:root 密码:0000，是测试用户，会启动一个所有用户列表，单击某个图标即以该用户身份信息进入聊天室。
* 用户名:user1-user4 密码：12345，会以用户1-用户4的身份进入聊天室。

## 二、主界面

root用户的用户列表界面：

![Image text](https://raw.githubusercontent.com/Taurus-Chao/ChatRoom_Qt5/master/imgstorage/rootWidget.png)

从用户列表中单击进入，或普通用户的主界面：

![Image text](https://raw.githubusercontent.com/Taurus-Chao/ChatRoom_Qt5/master/imgstorage/Widget.png)

## 三、发送文件

![Image text](https://raw.githubusercontent.com/Taurus-Chao/ChatRoom_Qt5/master/imgstorage/send.png)

## 四、接收文件

![Image text](https://raw.githubusercontent.com/Taurus-Chao/ChatRoom_Qt5/master/imgstorage/receive1.png)

## 五、保存聊天记录

![Image text](https://raw.githubusercontent.com/Taurus-Chao/ChatRoom_Qt5/master/imgstorage/Widget2.png)

可以选择路径保存聊天记录为纯文本的记事本格式。

