import pymysql
import pandas as pd

conn = pymysql.connect('localhost', 'root', '1234', 'census')
# print(conn)
cursor = conn.cursor()

sql = """select * from density """

cursor.execute(sql)
row = cursor.fetchall()


# df = pd.DataFrame(row)

# print(df)

print(row)

cursor.close()
conn.close()

