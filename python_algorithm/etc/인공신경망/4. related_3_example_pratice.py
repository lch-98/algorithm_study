# X는 입력 [2, 3]
# W1은 가중치 [[1, 2], [3, 4]]
# b1은 [0 1]
# activation function ReLU
# W2는 가중치 [2, 3]
# b2는 1

import numpy as np

def ReLU(x):
    return np.maximum(0, x)

def neural_network_forward():
    X1 = np.array([
        2, 
        3
    ])
    W1 = np.array([
        [1, 2],
        [3, 4]
    ])
    b1 = np.array([
        0, 
        1
    ])
    Z1 = np.dot(W1, X1) + b1
    
    X2 = ReLU(Z1)
    W2 = np.array([
        2, 
        3
    ])
    b2 = np.array([1])
    Z2 = np.dot(W2, X2) + b2
    Y = Z2
    
    print(Y)

def main():
    neural_network_forward()
    
main()