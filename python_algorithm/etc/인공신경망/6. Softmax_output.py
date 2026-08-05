import numpy as np

def Softmax(x):
    x = x - np.max(x)
    exp_x = np.exp(x)
    return exp_x / np.sum(exp_x)

def ReLU(x):
    return np.maximum(0, x)

def neural_network_forward():
    X = np.array([
        2,
        1
    ])
    W1 = np.array([
        [1, 2],
        [-1, 1]
    ])
    b1 = np.array([
        0,
        0
    ])
    
    Z1 = np.dot(W1, X) + b1
    A1 = ReLU(Z1)
    

    W2 = np.array([
        [1,2],
        [2,1],
        [3,4]
    ])

    b2 = np.array([
        0,
        0,
        0
    ])
    Z2 = np.dot(W2, A1) + b2
    Y = Softmax(Z2)
    
    print(Y, "| 배열 합(1이어야 함)=>", np.sum(Y))

def main():
    neural_network_forward()
    
main()