import numpy as np
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import cv2

def rgb2gray(I):
    return np.dot(I[:,:,:], [0.2989, 0.5870, 0.1140])

def binthresh(I,thresh):
    return I>thresh
if __name__ == "__main__":
    img = cv2.imread('Lena.jpg')  
    # img_gray_mode = cv2.imread('Lena.jpg', cv2.IMREAD_GRAYSCALE) 
    plt.imshow(img)
    plt.show() 
    # I = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
    I_GreyScale = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
    I_GreyScale_Func = rgb2gray(img)
    bi=binthresh(I_GreyScale_Func,127)
    # I_app = np.concatenate((I_GreyScale, I_GreyScale_Func), axis =1) 
    # cv2.imshow("I_APP", I_app)
    # cv2.waitKey()
    # plt.imshow(I_GreyScale_Func, "gray")
    # plt.show()
    # plt.imshow(bi*255, "gray")
    # plt.show()
    I_app = np.concatenate((I_GreyScale_Func, bi*255), axis =1)

    Height = I_GreyScale_Func.shape[0]
    Width = I_GreyScale_Func.shape[1]

    for y in range(0, int(Height)):
        for x in range(0, int(Width)):

            old_value = I_GreyScale_Func[y, x]
            new_value = 0
            if (old_value > 128) :
                new_value = 255

            I_GreyScale_Func[y, x] = new_value

            Error = old_value - new_value

            if (x<Width-1):
                NewNumber = I_GreyScale_Func[y, x+1] + Error * 7 / 16
                if (NewNumber>255) : NewNumber=255
                elif (NewNumber<0) : NewNumber=0
                I_GreyScale_Func[y, x+1] = NewNumber

            if (x>0 and y<Height-1):
                NewNumber = I_GreyScale_Func[y+1, x-1] + Error * 3 / 16
                if (NewNumber>255) : NewNumber=255
                elif (NewNumber<0) : NewNumber=0
                I_GreyScale_Func[y+1, x-1] = NewNumber

            if (y<Height-1):
                NewNumber= I_GreyScale_Func[y+1, x] + Error * 5 / 16
                if (NewNumber>255) : NewNumber=255
                elif (NewNumber<0) : NewNumber=0
                I_GreyScale_Func[y+1, x] = NewNumber

            if (y<Height-1 and x<Width-1):
                NewNumber = I_GreyScale_Func[y+1, x+1] + Error * 1 / 16
                if (NewNumber>255) : NewNumber=255
                elif (NewNumber<0) : NewNumber=0
                I_GreyScale_Func[y+1, x+1] = NewNumber
    I_appf = np.concatenate((I_GreyScale_Func,I_app), axis =1)
    plt.imshow(I_appf, "gray")
    plt.show()
            