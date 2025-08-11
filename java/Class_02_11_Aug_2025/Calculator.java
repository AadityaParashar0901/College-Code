import java.util.Scanner;

class Calculator {
	public static void main (String [] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter Operation (+ - * /): ");
		String operation = scanner.nextLine();
		System.out.print("Enter Number A: ");
		float number_a = scanner.nextFloat();
		System.out.print("Enter Number B: ");
		float number_b = scanner.nextFloat();
		float result;
		switch (operation) {
			case "+": result = number_a + number_b; break;
			case "-": result = number_a - number_b; break;
			case "*": result = number_a * number_b; break;
			case "/": result = number_a / number_b; break;
			default: System.out.println("Not a valid operation");
				return;
		}
		System.out.println(number_a + " " + operation + " " + number_b + " = " + result);
	}
}
