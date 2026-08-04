# 다중 입력 퍼셉트론
import numpy as np

def perceptron(x1, x2, w1, w2, b):
    y = w1*x1 + w2*x2 + b           # 즉, Y = W*X + b
    return y

def activation(y: int):
    if y > 0:
        return 1
    else:
        return 0

def main():
    output = perceptron(170, 70, 0.5, 0.8, -100)
    print(output)
    print(activation(output))

main()

"""
    만약 numpy를 쓸 수 있다면..
"""
x = np.array([170, 70])
w = np.array([0.5, 0.8])
b = -100

y = np.dot(w,x) + b
print(y)