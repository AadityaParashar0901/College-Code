import java.util.Scanner;

class BoxVolume {
	private static float getVolume (float s) {
		return s * s * s;
	}
	private static float getVolume (float s1, float s2, float s3) {
		return s1 * s2 * s3;
	}
	public static void main (String [] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter Cube Side: ");
		float cubeSide = scanner.nextFloat();
		System.out.print("Enter Cuboid Sides: ");
		float cuboidSide1 = scanner.nextFloat();
		float cuboidSide2 = scanner.nextFloat();
		float cuboidSide3 = scanner.nextFloat();
		System.out.println("Volume of Cube: " + getVolume(cubeSide));
		System.out.println("Volume of Cuboid: " +
			getVolume(cuboidSide1, cuboidSide2, cuboidSide3));
	}
}
