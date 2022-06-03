def fun():
	a,b = map(int, input().split())
	atb = 500-a*2+1000-(a+b)*4
	bta = 1000-b*4+500-(a+b)*2
	print(max(atb,bta))

if __name__ == '__main__':
	t = int(input())
	while t:
		fun()
		t-=1