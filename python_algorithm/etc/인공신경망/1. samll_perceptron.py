# 가장 작은 인공신경망
# 입력과 출력 사이에 weight(가중치)가 존재
# 1) y = wx

# 하지만, 1)번과 같은 수식은 직선이 위로 움직였을 때, 따라갈 수 없음 따라서 bias가 생김
# 따라서 2) y = wx + b

# 이 2)번 수식을 통해 아래와 같은 flow가 생성
# x: 입력 > weight > b: bias > Activation: 활성함수 > y: 출력

# Activation은 왜 중요하냐?
# 사람의 뇌는 무조건 반응하지 않음 보통 어느정도 자극이 와야 반응 그래서 "Activation Function"이 생김
# ex)
#     if (y>0):
#         res = 1
#     else:
#         res = 0
def perceptron(x, w, b):
    y = w*x + b
    return y
    
def activation(y: int):
    if y > 0:
        return 1
    else:
        return 0

def main():
    print(perceptron(2, 4, 1))
    
    output = perceptron(2, 3, -3)    # 3 출력
    print(activation(output))
    
    output2 = perceptron(2, 3, -11)  # -5 출력
    print(activation(output2))
    
main()