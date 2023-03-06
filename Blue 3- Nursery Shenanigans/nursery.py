N = int(input())
prevSideLength = 0
totalArea = 0

for i in range(N):
    sidelength = int(input())
    totalArea += sidelength * 4 + 2 * sidelength ** 2 - 2 * min(sidelength, prevSideLength) ** 2
    prevSideLength = sidelength

print(totalArea)
