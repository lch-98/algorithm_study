import numpy as np

def cross_entropy(y_true, pred):
    return -np.sum(y_true * np.log(pred))

def softmax(x):
    return np.exp(x) / np.sum(np.exp(x))

def relu(x):
    return np.maximum(0, x)

def forward_propagation():
    X = np.array([
        1,
        2
    ])
    W1 = np.array([
        [2, -1],
        [1, 3]
    ])
    b1 = np.array([
        1,
        0
    ])
    Z1 = np.dot(W1, X) + b1
    A1 = relu(Z1)
    
    W2 = np.array([
        [1, -2],
        [2, 1],
        [-1, 3]
    ])
    b2 = np.array([
        0,
        1,
        -1
    ])
    Z2 = np.dot(W2, A1) + b2
    pred = softmax(Z2)
    
    y_true = np.array([
        0,
        1,
        0
    ])
    loss = cross_entropy(y_true, pred)
    
    print(pred)
    print(loss)
    
def main():
    forward_propagation()
    
main()