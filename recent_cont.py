def fun():
	n = int(input())
	s = input()
	a = 0
	for i in s:
		if i=='S':
			a+=1
	print(a,n-a)

if __name__ == '__main__':
	t = int(input())
	while t:
		fun()
		t-=1