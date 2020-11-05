import numpy as np
import cv2
import matplotlib.pyplot as plt

my_img = np.zeros((400, 400, 3), dtype = "uint8")
pts0 = np.array([[100,100],[300,100],[300,300],[100,300]], np.int32)
# [[125,225],[175,225],[175,250],[125,250]]
pts0 = pts0.reshape((-1,1,2))
image0=cv2.polylines(my_img,[pts0],True,(255,0,0))

pts1 = np.array([[125,225],[175,225],[175,250],[125,250]], np.int32)
image1=cv2.polylines(my_img,[pts1],True,(255,0,0))

pts2 = np.array([[225,225],[275,225],[275,250],[225,250]], np.int32)
image2=cv2.polylines(my_img,[pts2],True,(255,0,0))

pts3 = np.array([[150,120],[250,120],[250,200],[150,200]], np.int32)
image3=cv2.polylines(my_img,[pts3],True,(255,0,0))

image = np.concatenate((image0,image1,image2,image3))

cv2.imwrite('robot.png', image)