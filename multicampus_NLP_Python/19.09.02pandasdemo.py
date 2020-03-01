import pandas as pd
import cx_Oracle

conn = cx_Oracle.connect('scott', 'tiger', 'localhost:1521/XE')
cursor = conn.cursor()

sql = """SELECT empno, ename, job, sal, comm, deptno
         FROM emp"""
# sql = """SELECT empno, ename, job, sal, NVL(comm,0), deptno
#          FROM emp"""
                                # NVL(comm, 0) comm이 null이면 0으로 바꿔서 가져와라
cursor.execute(sql)

myemp = []


for empno, ename, job, sal, comm, deptno in cursor:
    #print( empno, ename, job, sal, com, deptno)
    mylist = []
    mylist.append(empno)
    mylist.append(ename)
    mylist.append(job)
    mylist.append(sal)
    mylist.append(comm)
    mylist.append(deptno)
    myemp.append(mylist)


column_label = ['empno', 'ename', 'job', 'sal', 'comm', 'deptno']
df = pd.DataFrame(data = myemp, columns = column_label)

#row = cursor.fetchall()
#print(row)

cursor.close()
conn.close()

#print(df)
#print(df.info())
# print(conn)

# irum = input('사원명: ')
# print(df.loc[df.ename == irum.upper()])

# df = df.dropna()
# print(df)

#print(df[df['comm'].notnull().values])
#print(df[df['comm'].isnull().values])


# df.drop(df.index[[0,1,2]], inplace = True) # 복수 행 삭제
# df.drop('ename', axis =1, inplace = True) # 열삭제
# df.drop(labels = ['empno', 'job', 'ename'], axis = 1, inplace = True) # 열삭제

#df['total'] = df['sal']*12+df['comm']
#df['total'] = (df['sal']+df['comm'])*12

#df.sort_values(by = ['total'],ascending = False, inplace = True)

# def cal(salary, monthnum):
#     return salary*monthnum

# df['total'] = df['sal'].apply(cal, monthnum = 12)

# df.sort_values(by = ['total'],ascending = False, inplace = True)

print(df.head())