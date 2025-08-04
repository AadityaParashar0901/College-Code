class BiggestNumber {
	public static void main (String [] args) {
		int a = 10, b = 12, c = 20;
		String msg = "";
		if (a > b) {
			if (a > c) msg = "Largest is a: " + a;
			if (a < c) msg = "Largest is c: " + c;
		} else {
			if (b > c) msg = "Largest is b: " + b;
			if (b < c) msg = "Largest is c: " + c;
		}
		System.out.println(msg);
	}
}