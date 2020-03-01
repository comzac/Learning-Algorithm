import pymongo
from pymongo import MongoClient


client = MongoClient('localhost', 27017, maxPoolSize = 50) # 머신을 연결
#print(client)

db = client.test # test data를 연결
emp = db['Employee'] # table이 아닌 collection임
cursor = emp.find({}, {'_id' : False})

# for i, docu in enumerate(cursor,1):
#     print(i, docu)

for i, docu in enumerate(cursor):  
    rowcont = ''
    keycont = ''
    for key, val in docu.items():
        keycont = keycont + '\t' + str(key)
        rowcont = rowcont + '\t' + str(val)

    if i == 0:
        print(keycont)
        print(rowcont)
    else:
        print(rowcont)
    #i+=1 넣을 필요없음

    


