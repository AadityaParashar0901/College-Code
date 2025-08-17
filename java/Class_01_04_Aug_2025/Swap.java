class Swap {
	public static void main(String [] args) {
		int a = 10, b = 20;
		int tmp = 0;
		System.out.println("Before swapping: a = " + a + ", b = " + b);
		tmp = b; b = a; a = tmp; // swap
		System.out.println("After swapping: a = " + a + ", b = " + b);
	}
}
