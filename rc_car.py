import BlynkLib
from machine import Pin
import network 



ssid = "SPY"
password = "120hzpoco"

sta = network.WLAN(network.STA_IF)
sta.active(True) 

if not sta.isconnected(): 
  print('connecting to network...') 
  sta.active(True)  
  sta.connect(ssid, password) 
  while not sta.isconnected(): 
    pass 
print('network config:', sta.ifconfig())

blynk=BlynkLib.Blynk("6-tzkivRbsKCvInFiLISQHKZmIIlR76m")


i1=Pin(19,Pin.OUT)
i2=Pin(21,Pin.OUT)
i3=Pin(22,Pin.OUT)
i4=Pin(23,Pin.OUT)


@blynk.on("V*")
def blynk_handle_vpins(pin, value):
    if(pin=='1'):
        if(value[0]=='1'):
            print("Forward")
            forward()
        else:
            print("Stop")
            stop()
    elif(pin=='2'):
        if(value[0]=='1'):
            print("Backward")
            backward()
        else:
            print("Stop")
            stop()
    elif(pin=='3'):
        if(value[0]=='1'):
            print("Left")
            left()
        else:
            print("Stop")
            stop()
    elif(pin=='4'):
        if(value[0]=='1'):
            print("Right")
            right()
        else:
            print("Stop")
            stop()

@blynk.on("connected")
def blynk_connected():
    print("Updating V1,V2,V3 values from the server...")
    blynk.sync_virtual(1,2,3,4)


def forward():
    i1.value(1)
    i2.value(0)
    i3.value(1)
    i4.value(0)
def backward():
    i1.value(0)
    i2.value(1)
    i3.value(0)
    i4.value(1)
def left():
    i1.value(0)
    i2.value(1)
    i3.value(1)
    i4.value(0)
def right():
    i1.value(1)
    i2.value(0)
    i3.value(0)
    i4.value(1)
def stop():
    i1.value(0)
    i2.value(0)
    i3.value(0)
    i4.value(0)


while True:
    blynk.run()
