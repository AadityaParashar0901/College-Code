class Swap {
	public static void main(String [] args) {
		int a = 10, b = 20;
		int tmp = 0;
		System.out.println("Before swapping: a = " + a + ", b = " + b);
		// swap
		tmp = b; b = a; a = tmp;
		System.out.println("After swapping: a = " + a + ", b = " + b);
	}
}