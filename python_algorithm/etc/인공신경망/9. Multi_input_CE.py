import numpy as np

def cross_entropy(y, pred):
    return -np.sum(y*np.log(pred + 1e-10))

def softmax(x):
    x = x - np.max(x)
    return np.exp(x) / np.sum(np.exp(x))

def relu(x):
    return np.maximum(0, x)

def forward():
    X = np.array([
        [1, 0],
        [0, 2],
        [-1, -1]
    ])
    
    answer = [[], [], []]
    answer2 = [[], [], []]
    answer3 = [[], [], []]
    answer4 = []
    average = 0
    
    array = [np.array([0, 1, 0]), np.array([1, 0, 0]), np.array([0, 0, 1])]
    for idx, input in enumerate(X):
        W1 = np.array([
            [1, 1],
            [-1, 2],
            [0, -3]
        ])
        b1 = np.array([0, 1, 2])
        
        Z1 = np.dot(W1,input) + b1
        A1 = relu(Z1)
        
        W2 = np.array([
            [1, 0, -1],
            [2, 1, 0],
            [0, -1, 1]
        ])
        b2 = np.array([
            0,
            1,
            -1
        ])
        y = array[idx]
        
        Z2 = np.dot(W2, A1) + b2

        pred = softmax(Z2)
        loss = cross_entropy(y, pred)
        
        answer[idx] = A1.tolist()        
        answer2[idx] = Z2.tolist()
        answer3[idx] = pred.tolist()
        answer4.append(loss)
        
        average += loss
        
        print("pred:", pred, "| 합:", np.sum(pred))
        print("loss:", loss)

    print(answer)                   # A1
    print(answer2)                  # Z2
    print(answer3)                  # pred
    print(answer4)                  # loss
    print(average / len(answer4))   # average loss
    
forward()