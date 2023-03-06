N, M = [int(i) for i in input().split()]
C = input()

for i in range(N):
    for j in range(M - 1):
        print(C, end=' ')
    print(C)