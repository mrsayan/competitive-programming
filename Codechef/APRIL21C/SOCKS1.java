//Problem - https://www.codechef.com/APRIL21C/problems/SOCKS1

import java.lang.*;
import java.io.*;
import java.util.*;

class Codechef2
{
	public static void main (String[] args) throws java.lang.Exception
	{ 
		Reader.init(System.in);
		int A = Reader.nextInt();
		int B = Reader.nextInt();
		int C = Reader.nextInt();
		if(A==B||B==C|C==A) 
			System.out.println("Yes");
		else
			System.out.println("No");

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