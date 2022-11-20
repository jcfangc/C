### 假定宏 M 有如下定义：
***
#define M 10<br>
下面哪些测试会失败？<br>
（a）#if M<br>
（b）#ifdef M<br>
（c）#ifndef M<br>
（d）#if defined(M)<br>
（e）#if !defined(M)
***

<br>

参考答案：
|题号|回答|
|:-|:-|
|（a）|成功|
|（b）|成功|
|（c）|失败|
|（d）|成功|
|（e）|失败|

<br>

原书作者答案：<br>
(c) and (e) will fail, since M is defined.<br>
（ 源自：http://knking.com/books/c2/answers/c14.html ）