import numpy as np
import cv2
import matplotlib.pyplot as plt

my_img = np.zeros((400, 400, 3), dtype = "uint8")
pts = np.array([[150,50],[30,300],[180,200],[250,100]], np.int32)
pts = pts.reshape((-1,1,2))
image=cv2.polylines(my_img,[pts],True,(255,255,255))

bigger = cv2.resize(image, (5000,5000),fx=int(input("FX=")), fy=int(input("FY="))) 

image_center = tuple(np.array(image.shape[1::-1]) / 2)
angle = int(input("Angle:"))
rot_mat = cv2.getRotationMatrix2D(image_center, angle, 1.0)
rotate = cv2.warpAffine(image, rot_mat, image.shape[1::-1], flags=cv2.INTER_LINEAR)

height, width = image.shape[:2] 
quarter_height, quarter_width = height / 4, width / 4
T = np.float32([[1, 0, quarter_width], [0, 1, quarter_height]]) 
img_translation = cv2.warpAffine(image, T, (width, height))

Titles =["Original",  "Bigger", "Rotate","Translate"] 
images =[my_img, bigger, rotate,img_translation] 
count = 4
  
for i in range(count): 
    plt.subplot(2, 2, i + 1) 
    plt.title(Titles[i]) 
    plt.imshow(images[i]) 
  
plt.show() 