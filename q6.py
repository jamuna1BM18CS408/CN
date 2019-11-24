Client
from socket import *
serverName = '127.0.0.1'
serverPort = 12000
clientSocket = socket(AF_INET,SOCK_DGRAM)
sentence = input("Enter a word : ")
clientSocket.sendto(bytes(sentence,"utf-8"),(serverName,serverPort))
filecontents,aerverAddress = clientSocket.recvfrom(2048)
print("from server : ",filecontents.decode('utf-8'))
clientSocket.close()
Server
from socket import *
st = ""
serverPort = 12000
serverSocket = socket(AF_INET,SOCK_DGRAM)
serverSocket.bind(("127.0.0.1",serverPort))
files = ['file1.txt','file2.txt','file3.txt','file4.txt','file5.txt']
print("server is ready to receive")
while 1:
sentence,clientAddress = serverSocket.recvfrom(2048)
for i in files:
fil = open(i,"r")
y = fil.read().replace("."," ").replace(","," ")
x = y.strip().split()
p = sentence.decode('utf-8')
if p in x:
st = st+str(i)+" "
fil.close()
if(len(st)!=0):
serverSocket.sendto(bytes(st,"utf-8"),clientAddress)
else:
serverSocket.sendto(bytes("Not found","utf-8"),clientAddress)
print("sent")
break
