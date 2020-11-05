import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import cv2
if __name__ == "__main__":
    image = cv2.imread('Lena.jpg')
    y=0
    x=0
    h=300
    w=510
    crop_image = image[x:w, y:h]
    Titles =["Original",  "Cropped image"] 
    images =[image, crop_image] 
    count = 2
    for i in range(count): 
        plt.subplot(2, 2, i + 1) 
        plt.title(Titles[i]) 
        plt.imshow(images[i]) 
    plt.show()


    # plt.imshow(crop_image)
    # plt.title("Cropped image")
    # plt.show()