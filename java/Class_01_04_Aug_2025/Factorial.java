class Factorial {
	public static void main(String [] args) {
		int n = 6;
		int f = 1;
		for (int i = 1; i <= n; i++) f *= i;
		System.out.println("Factorial of " + n + " is " + f);
	}
}