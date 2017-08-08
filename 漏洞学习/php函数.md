- mysql_real_eascape_string()
  - 作用：转义sql语句中的特殊字符
  - 转换一下编码格式即可绕过该函数，比如url编码等


- addslashes
  - 对单引号，双引号，反斜线，NULL字符添加(\反斜线)

- stripslasher
  - 去除掉反斜线

- magic_quotes_gpc()
  - 对post,get,cookie等数据增加一个addslashes()函数，即为添加斜杠
