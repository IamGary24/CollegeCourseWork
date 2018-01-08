//just some testing of the homework4

import java.io.*;
import java.util.*;

public class hw4 {

	public static void main(String[] args)
	{	
		System.out.println(signum(12));
		System.out.println(signum(-11));
		System.out.println(signum(20.5));
		System.out.println(signum(0));
	}
	
	public static int signum(int x)
	{
		if(x > 0)
			return 1;
		else if (x == 0)
			return 0;
		else
			return -1;
	}
	
}