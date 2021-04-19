//Problem - https://www.codechef.com/COOK128C/problems/CM164364

import java.lang.*;
import java.io.*;
import java.util.*;

class maxUniqueNumWindow {
	static int maxUniqueNum(int arr[], int M)
	{
		HashMap<Integer, Integer> hM = new HashMap<Integer, Integer>();

		int dist_count = 0;
		for (int i = 0; i < M; i++) {
			if (hM.get(arr[i]) == null) {
				hM.put(arr[i], 1);
				dist_count++;
			}
			else {
				int count = hM.get(arr[i]);
				hM.put(arr[i], count + 1);
			}
		}

		int res = dist_count;
		for (int i = M; i < arr.length; i++) {

			if (hM.get(arr[i - M]) == 1) {
				hM.remove(arr[i - M]);
				dist_count--;
			}

			else
			{
				int count = hM.get(arr[i - M]);
				hM.put(arr[i - M], count - 1);
			}

			if (hM.get(arr[i]) == null) {
				hM.put(arr[i], 1);
				dist_count++;
			}
			else
			{
				int count = hM.get(arr[i]);
				hM.put(arr[i], count + 1);
			}

			res = Math.max(res, dist_count);
		}

		return res;
	}


	public static void main(String arg[]) throws java.lang.Exception
	{   Reader.init(System.in);
		int T = Reader.nextInt();
		while(T-- > 0){
			int n=Reader.nextInt();
			int x=Reader.nextInt();
			int arr[] = new int[n];
			for(int i=0;i<n;i++)
				arr[i]=Reader.nextInt();
			int uni=maxUniqueNum(arr, n);
			while((n-uni)<x)
				uni--;
			System.out.println(uni);
		}
	}
}


class Reader {
	static BufferedReader reader;
	static StringTokenizer tokenizer;

    /** call this method to initialize reader for InputStream */
	static void init(InputStream input) {
		reader = new BufferedReader(
			new InputStreamReader(input) );
		tokenizer = new StringTokenizer("");
	}

    /** get next word */
	static String next() throws IOException {
		while ( ! tokenizer.hasMoreTokens() ) {
            //TODO add check for eof if necessary
			tokenizer = new StringTokenizer(
				reader.readLine() );
		}
		return tokenizer.nextToken();
	}

	static int nextInt() throws IOException {
		return Integer.parseInt( next() );
	}

	static double nextDouble() throws IOException {
		return Double.parseDouble( next() );
	}
}