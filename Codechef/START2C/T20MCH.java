//Problem - https://www.codechef.com/START2C/problems/T20MCH

import java.util.*;

class T20MCH
{
    public static void main (String[] args)
    { Scanner in =new Scanner(System.in);
        int R = in.nextInt();
        int O = in.nextInt();
        int C = in.nextInt();
        if(((20-O)*36+C)>R) 
            System.out.println("Yes");
        else
            System.out.println("No");

    }
}