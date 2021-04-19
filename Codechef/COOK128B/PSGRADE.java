//Problem - https://www.codechef.com/COOK128B/problems/PSGRADE

import java.lang.*;
import java.io.*;
import java.util.*;

class PSGRADE
{
	public static void main (String[] args) throws java.lang.Exception
	{ Reader.init(System.in);
		int T = Reader.nextInt();
		while(T-- > 0){
			int Amin=Reader.nextInt();
			int Bmin=Reader.nextInt();
			int Cmin=Reader.nextInt();
			int Tmin=Reader.nextInt();
			int A=Reader.nextInt();
			int B=Reader.nextInt();
			int C=Reader.nextInt();
			
			
			if((A>=Amin&&B>=Bmin&&C>=Cmin)&&((A+B+C)>=Tmin))
				System.out.println("YES");
			else
				System.out.println("NO");

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