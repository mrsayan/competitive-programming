// Problem - https://www.codechef.com/MAY21B/problems/XOREQUAL

import java.util.*;
class XOREQUAL {

	final static long MOD = 1000000007L;

	public static void main (String[] args) {
		Scanner in=new Scanner(System.in);
		int t = in.nextInt();
		while (t-- > 0) {
			long n = in.nextLong();
			System.out.println(power(2L,(n-1)));
		}
	}

	static long power(long x, long y)
	{
		long res = 1L;
		x = x % MOD;
		if (x == 0)
			return 0;
		while (y > 0) {
			if ((y & 1) != 0)
				res = (res * x) % MOD;
			y = y >> 1;
			x = (x * x) % MOD;
		}
		return res;
	}
}