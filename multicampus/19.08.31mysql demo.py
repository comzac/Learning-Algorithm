import pymysql
import pandas as pd

conn = pymysql.connect('localhost', 'root', '1234', 'world')
# print(conn)
cursor = conn.cursor()
sql = """select id, name, countrycode, district, population 
        from city
        where countrycode = 'kor'"""

cursor.execute(sql)
row = cursor.fetchmany(5)
print(row)
column = ['id', 'name', 'countrycode', 'district', 'population']

# df = pd.DataFrame(row, columns=column)

# print(df)
print(list(row))
cursor.close()
conn.close()
