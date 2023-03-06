N = int(input())
A = [int(i) for i in input().split()]
B = [int(i) for i in input().split()]

print(sum([i * j for i, j in zip(A, B)]))