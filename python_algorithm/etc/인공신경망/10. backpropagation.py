import numpy as np

def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def relu(x):
    return np.maximum(0, x)

def bce(y, pred):
    return -(y*np.log(pred + 1e-10) + (1-y)*np.log(1-pred + 1e-10))

X = np.array([
    1, 
    2, 
    -1
])
y = 0

W1 = np.array([
    [1, -1,  2],
    [0,  1, -1]], dtype=float
)
b1 = np.array([1, -2], dtype=float)
W2 = np.array([2, -3], dtype=float)
b2 = 0.5
lr = 0.1

for epoch in range(200):
    Z1   = np.dot(W1, X) + b1        # 순전파
    A1   = relu(Z1)
    Z2   = np.dot(W2, A1) + b2
    pred = sigmoid(Z2)
    loss = bce(y, pred)

    dZ2 = pred - y                   # 역전파
    dW2 = dZ2 * A1
    db2 = dZ2
    dA1 = dZ2 * W2
    dZ1 = dA1 * (Z1 > 0)
    dW1 = np.outer(dZ1, X)
    db1 = dZ1

    W1 -= lr * dW1                   # 갱신
    b1 -= lr * db1
    W2 -= lr * dW2
    b2 -= lr * db2

    if epoch % 40 == 0:
        print(f"epoch {epoch:3d} | loss {loss:.6f} | pred {pred:.6f}")