# -*- coding: utf-8 -*-
"""
Created on Thu Feb 24 17:57:19 2022

@author: acer
"""
from PIL import Image                                                                                

import random
#Kenar uzunlugu 2 olan kare alanı 4, yarıcapı 2 olan cemberin alanı 4pi
# içlerine düşen noktaların oranı pi olmalı


#cemberin merkezi orijin olsun en sağdaki noktası 2,0 en soldaki noktası -2,0 en üstteki noktası 0,2
# cemberin icinde olabilmesi iiçin a^2+b^2 4 dan küçük eşit olmalı
print("Bu programın amacı bir düzlemde yukarıdan aşağı atılan topların \ndüzlemdeki bir kare ve bir çemberin içine düşme olasılıklarının \nkare ve çemberin alanlarıyla orantılı olduğunu göstermektir. ")
print("Deneyde gözlemlenmeye çalışan şey ise yukarıdan aşağıya attığımız\ntoplardan yarıçapı a olan bir çemberin içine düşenlerin sayısının\nkenar uzunluğu a olan bir karenin içine düşenlerin sayısının pi katı olmasıdır")

img = Image.open('figure.png')
img.show() 

print("özet üretmek için q tuşlayın")
#kare x: 2,6 y: 0,4
counter_circle = 0
counter_square = 0
a_array=[]
b_array=[]
mem_arr=[]
mem_itt_arr=[]
def sorFirst(val):
    return val[0] 
def inside_circle(a,b,counter_circle):

    if(a>=-2 and a<=2 and b<=2 and b>=-2 and (pow(a,2)+pow(b,2) <= 4)):
        counter_circle=counter_circle+1
    return counter_circle
  
def inside_square(a,b,counter_square):
    if(a>=4 and a<=6 and b<=1 and b>=-1):
        counter_square=counter_square+1
    return counter_square
while(1):
    try:
        itera=input("Atılacak top sayısını girin ")
        if(itera!="qq"):
            iteration=int(itera)
            for i in range(iteration):
               a_array.append(random.uniform(-3,7))
               b_array.append(random.uniform(-3,7))
               a=a_array[i]
               b=b_array[i]
               counter_circle=inside_circle(a, b, counter_circle)
               counter_square=inside_square(a, b, counter_square)
               
            print("Çemberin içine düşen noktaların karenin içine düşen noktalara oranı: ")
            q=(iteration,counter_circle/counter_square)
            mem_arr.append(q)
            print(counter_circle/counter_square)
        else:
            mem_arr.sort(key=sorFirst)
            for k in range(len(mem_arr)):
                print("Top sayisi: " , mem_arr[k][0], "Cemberin icine dusen topların karenin icine düsenlere orani", mem_arr[k][1])

                #print("Oran: "+mem_arr[k]+"Top Sayisi: " +mem_arr[k])
            print("Top sayısı artırıldıkça oran pi sayısına yaklaşıyor")
            
    except:
        print("Lutfen bir pozitif tam sayı giriniz")
        

