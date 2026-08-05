import numpy as np

def binary_cross_entropy(y, pred):
    return -(y*np.log(pred) + (1-y)*np.log(1-pred))

def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def ReLU(x):
    return np.maximum(0, x)

def neural_network_forward():
    X = np.array([
        2,
        -1
    ])
    W1 = np.array([
        [1, 2],
        [-2, 1]
    ])
    b1 = np.array([
        0,
        1
    ])
    Z1 = np.dot(W1, X) + b1
    A1 = ReLU(Z1)
    
    W2 = np.array([
        2,
        -1
    ])
    b2 = 0.5
    
    Z2 = np.dot(W2, A1) + b2
    pred = sigmoid(Z2)
    
    loss=binary_cross_entropy(1,pred)

    print(pred)
    print(loss)

def main():
    neural_network_forward()
    
main()