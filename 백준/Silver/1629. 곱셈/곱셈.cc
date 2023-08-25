// BOJ 1629 분할정복
// 참고 : https://velog.io/@junttang/BOJ-1629-%EA%B3%B1%EC%85%88-%ED%95%B4%EA%B2%B0-%EC%A0%84%EB%9E%B5-C

#include <iostream>
long long power(long long A, long long B, long long C) {
	//영 제곱은 1
	if (B == 0)
		return 1;
	//일 제곱은 (원래 값 % C)
	if (B == 1)
		return A % C;

	long long tmp = power(A, B / 2, C) % C;

	//짝수 제곱이면 tmp(반으로 분할한 짝수 제곱) * tmp
	if (B % 2 == 0) 
		return tmp * tmp % C;
	//홀수 제곱이면 tmp * tmp * A
	return tmp * tmp % C * A % C;
}

int main(void) {
	long long A, B, C;
	std::cin >> A >> B >> C;
	std::cout << power(A, B, C);

	return 0;
}