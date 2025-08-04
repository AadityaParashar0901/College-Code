class PrimeNumbers {
	public static int isPrime(int n) {
		for (int i = 2; i < (n >> 1); i++) {
			if ((n % i) == 0) return 0;
		}
		return 1;
	}
	public static void main(String [] args) {
		for (int i = 2; i <= 150; i++) {
			if (isPrime(i) > 0) System.out.println(i + " is Prime.");
		}
	}
}