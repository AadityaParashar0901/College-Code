import java.util.Scanner;

class StudentDetails {
	public static void main (String [] args) {
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter Student Name: ");
		String student_name = scanner.nextLine();
		System.out.print("Enter Student Branch: ");
		String student_branch = scanner.nextLine();
		System.out.print("Enter Student Roll Number: ");
		String student_roll_number = scanner.nextLine();
		System.out.print("Enter Student Contact: ");
		String student_contact = scanner.nextLine();
		System.out.println("Student Name: " + student_name);
		System.out.println("Student Branch: " + student_branch);
		System.out.println("Student Roll Number: " + student_roll_number);
		System.out.println("Student Contact: " + student_contact);
	}
}
