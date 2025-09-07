import java.util.Scanner;

class Shape {
	public int length = 0, breadth = 0;
}
class TwoD extends Shape {
	public int getArea () { return length * breadth; }
	public int getPerimeter () { return 2 * (length + breadth); }
}
class ThreeD extends Shape {
	public int height = 0;
	public int getVolume () { return length * breadth * height; }
}
class TwoDimension {
	public static void main (String [] args) {
		TwoD shape2d = new TwoD();
		ThreeD shape3d = new ThreeD();
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter Length: ");
		shape3d.length = shape2d.length = scanner.nextInt();
		System.out.print("Enter Breadth: ");
		shape3d.breadth = shape3d.height = shape2d.breadth = scanner.nextInt();
		System.out.println("Perimeter: " + shape2d.getPerimeter());
		System.out.println("Area: " + shape2d.getArea());
		System.out.println("Volume: " + shape3d.getVolume());
	}
}
