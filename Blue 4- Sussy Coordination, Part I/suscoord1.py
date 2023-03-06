N, M, K = [int(i) for i in input().split()]

remain = N - (M * (K - 1) + K)

top = 1
bot = 1

for i in range(K):
    top *= (remain + K - i)
    bot *= (i + 1)

print(int(top / bot) % 1000000007)