class Fibonacci {
	public static void main(String [] args) {
		int alpha = 1;
		int current = 1;
		for (int i = 0; i < 10; i++) {
			System.out.println(current);
			int tmp = current;
			current = current + alpha;
			alpha = tmp;
		}
	}
}