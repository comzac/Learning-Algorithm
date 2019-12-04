import cx_Oracle
import pandas as pd

conn = cx_Oracle.connect('scott', 'tiger', 'localhost:1521/XE')

# print(conn.version)
cursor = conn.cursor()

sql = """select empno, ename, sal
         from emp
         where deptno = 10"""

sql2 = """insert into dept(deptno, dname)
          values(90, 'TaskForce')"""

#cursor.execute(sql)
cursor.execute(sql2)
conn.commit()

# row = cursor.fetchall()
# column = ["empno", "ename", "sal"]
# index = [1,2,3]
# df = pd.DataFrame(row, columns = column, index = index)
# print(df)
# print(row)

conn.close()