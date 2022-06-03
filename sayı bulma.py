# -*- coding: utf-8 -*-
"""
Created on Thu Feb 24 17:21:58 2022

@author: Bedirhan Sen
"""

num=int(input("sayı girin: "))

def Perfect(num):
    counter=0
    for i in range(1,int(num/2)+1):
        if(num%i==0):
            counter=counter+i
    if (counter == num):
        print("Bu sayı mükemmel sayı tanımına uygundur.")
    if(counter == 0):
        print("Bu sayı asal bir sayıdır")

def fib():
    sequence = [0, 1]
    for k in range(2,100):
        sequence.insert(k,sequence[k-1] + sequence[k-2])
        if (num==sequence[k]):
            print("Bu sayı fibonnacci dizisinin bir elemanıdır")

            
def Prime(num):
    counter=0
    for i in range(1,int(num/2)+1):
        if(num%i==0):
           counter=counter+1
    if(counter!=0):
        print("Bu sayı asal bir sayıdır.")

def CiftTek(num):
    if(num%2==0):
        print("Bu sayi cift bir sayıdır")
    else:
        print("Bu sayi tek bir sayıdır")
#palindrom
while(1):
    num=int(input("sayı girin: "))
    Perfect(num)
    fib()
    Prime(num)
    CiftTek(num)