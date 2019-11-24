client.py
from socket import*
serverName=gethostname()
serverPort=12000
clientSocket=socket(AF_INET,SOCK_STREAM)
clientSocket.connect((serverName,serverPort))
file1=input("Enter file name and the word : ")
clientSocket.send(file1.encode())
wordcount=clientSocket.recv(1024).decode('utf8')
print(wordcount)
clientSocket.close()
server.py
from socket import*
serverName=gethostname()
serverPort=12000
serverSocket=socket(AF_INET,SOCK_STREAM)
serverSocket.bind((serverName,serverPort))
serverSocket.listen(1)
print("The Server is ready to recieve")
while(1):
count=0
conn,addr=serverSocket.accept()
file2=conn.recv(1024).decode()
list1=[]
list1=file2.split(" ")
file=open(list1[0],"r")
words=file.read(1024)
list2=[]
list2=words.split(" ")
for i in list2:
if(list1[1]==i):
count+=1
print(count)
conn.send(str(count).encode('utf8'))
file.close()
conn.close()
