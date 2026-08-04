"""
    실제 인공신경망은 여러 개의 퍼셉트론을 층(layer)으로 쌓음.
    
    Input Layer
        |
        v
    Hidden Layer (사람이 하는 중간 생각) > 입력을 보고 중간 특징(feature)을 만드는 층
        |
        v
    Output Layer
    
    ex) 가장 단순한 신경망
    x1, x2, x3: Input Layer
        |
        v
      h1, h2: Hidden Layer
        |
        v
        y: Output Layer
    
    아래 예시는 입력 3개 > 뉴런 2개 계산 > 결과 2개 생성
    원본 데이터 x1, x2, x3 (입력)
            |
            v
    Hidden Layer h1, h2
            |
            v
    Output Layer는 Hidden Layer를 보고 최종 판단
"""
import numpy as np

def relu(x):
    return np.maximum(0,x)

def forward(X):
    # Hidden Layer
    W1 = np.array([
        [0.1,0.2,0.3],
        [0.4,0.5,0.6]
    ])

    b1 = np.array([
        0.1,
        0.2
    ])

    Z1 = np.dot(W1,X) + b1  # 출력: [1.5 3.4]
    A1 = relu(Z1)           # 출력: [1.5 3.4] > 둘다 양수이기 때문

    # Output Layer
    W2 = np.array([
        0.5, 
        0.7
    ])

    b2 = 0.1

    Y = np.dot(W2,A1) + b2  # 출력: [3.23]
    return Y

X=np.array([
    1,
    2,
    3])

result = forward(X)

print(result)