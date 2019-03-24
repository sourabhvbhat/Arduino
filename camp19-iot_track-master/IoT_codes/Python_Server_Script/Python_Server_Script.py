import socket          


s = socket.socket()    

host = "192.168.43.227"
Change with your local ip address using 'ifconfig'
port = 12345   

s.bind((host, port))


//listen evry 40 mili secs
s.listen(40)



while True:

c, addr = s.accept() 
//the data in 1024 bits is received by the server
data =  c.recv(1024)
print data
  
c.send("Message Received")
   
c.close()
