
public class StaticMethodClass_Fowler
{
	 //static method with the formula for an area of a circle, accepts radius r
	public static double areaOfCircle_Fowler(double r)
	{
		if (r <= 0) //check to see if radius is less than 0
		{
			System.out.println("Area can not be less than 0."); //error message
			return 0;
		}
		else
		{	
			double area = Math.PI * r * r; //formula using the radius r, and multiplying by pi to determine area
			return area; //return the area	
		}
	}
	
	//static method to determine area of rectangle, accepts length l and width w
	public static double areaOfRectangle_Fowler(double l, double w) 
	{
		if (l <= 0) //check that the length is not negative
		{
			System.out.println("Area can not be less than 0."); //error message
			return 0;
		}
		else if(w <= 0) //check that the length is not negative
		{
			System.out.println("Area can not be less than 0."); //error message
			return 0;
		}
		else
		{
			double area = l * w; //formula to calculate area
			return area; //return area
		}
	}
	
	//static method to determine area of a square, accepts side of square, s
	public static double areaOfSquare_Fowler(double s)
	{
		if (s <= 0) //check to make sure sides are not less than 0
		{
			System.out.println("Area can not be less than 0."); //error message
			return 0;
		}
		else
		{
			double area = s * s; //formula to calculate area
			return area; //return area
		}
	}
	
	//static method to determine area of a triangle, accepts base b, and height h
	public static double areaOfTriangle_Fowler(double b, double h)
	{
		if (b <= 0) //make sure base is above 0
		{
			System.out.println("Area can not be less than 0."); //error message
			return 0;
		}
		else if (h <= 0) //make sure height is above 0
		{
			System.out.println("Area can not be less than 0."); //error message
			return 0;
		}
		else
		{
		double area = b * h * .5; //formula to calculate area
		return area; //return area
		}
	}
}
