import numpy as np

def Sigmoid(x):
    return 1 / (1 + np.exp(-x))

def ReLU(x):
    return np.maximum(0, x)

def ReLU_Sigmoid_Forward():
    X1 = np.array([
        1, 
        -2
    ])
    W1 = np.array([
        [2, 1],
        [-1, 3]        
    ])
    b1 = np.array([
        0,
        1
    ])
    Z1 = np.dot(W1, X1) + b1
    
    A1 = ReLU(Z1)
    W2 = np.array([
        1,
        -2
    ])
    b2 = 0.5
    Z2 = np.dot(W2, A1) + b2
    Y = Sigmoid(Z2)
    
    print(Y)

def main():
    ReLU_Sigmoid_Forward()

main()