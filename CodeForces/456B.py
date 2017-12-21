number = int(input())

number = number%4

values = {}

values[1] = [1,1,1,1]
values[2] = [1,2,4,3]
values[3] = [1,3,4,2]
values[4] = [1,4,1,4]

ans = 0

for i in range(1,5):
	ans = (ans + values[i][number])%5
	pass

print(ans)