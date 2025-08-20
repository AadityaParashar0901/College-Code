import java.util.Scanner;

class Max_Min {
	private static int max (int a, int b) {
		if (a > b) return a;
		return b;
	}
	private static int min (int a, int b) {
		if (a < b) return a;
		return b;
	}
	public static void main (String [] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter Number A: ");
		int number_a = scanner.nextInt();
		System.out.print("Enter Number B: ");
		int number_b = scanner.nextInt();
		System.out.println("Max: " + max(number_a, number_b));
		System.out.println("Min: " + min(number_a, number_b));
	}
}
