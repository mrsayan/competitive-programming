//Problem - https://www.codechef.com/MAY21B/problems/MODEQ

for _ in range(int(input())):
	n,m = list(map(int,input().split()))
count = 0
mod = [1]*(n+1)
for i in range(2,n+1):
	x = m % i
count += mod[x]
for j in range(x,n+1,i):
	mod[j] += 1
print(count)