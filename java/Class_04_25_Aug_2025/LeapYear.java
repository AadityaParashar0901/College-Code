import java.util.Scanner;

class Year {
	int checkLeapYear (int year) {
		if ((year % 400) == 0 || ((year % 4) == 0 && (year % 100) != 0)) return 1;
		return 0;
	}
}
class LeapYear {
	public static void main (String [] args) {
		Year leapYear = new Year();
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter a Year: ");
		int year = scanner.nextInt();
		if (leapYear.checkLeapYear(year) == 1) System.out.println(year + " is a leap year.");
		else System.out.println(year + " is not a leap year.");
	}
}
