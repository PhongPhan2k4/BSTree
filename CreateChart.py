import numpy as np
import matplotlib.pyplot as plt
import math

#Lấy dữ liệu
AVLTreeHeight = np.loadtxt("AVLTreeHeight.txt")
RBTreeHeight = np.loadtxt("RBTreeHeight.txt")
test = np.arange(1, 11, 1)
logN = np.full(10, math.log2(10**6))
__logN = 1.45 * logN 

# Vẽ biểu đồ
plt.title('Time Chart')
plt.ylabel('Height')
plt.xlabel('Test')
plt.plot(test, AVLTreeHeight, '-r', label = "AVL Tree")
plt.plot(test, RBTreeHeight, '-b', label = "Red Black Tree")
plt.plot(test, logN, '-g', label = "log2(10^6)")
plt.plot(test, __logN, '-y', label = "1.45log2(10^6)")
plt.legend(loc = "best")
plt.show()