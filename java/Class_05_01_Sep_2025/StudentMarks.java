import java.util.Scanner;

class Student {
	public static String Name = new String(""), Branch = new String("");
	public static int Age = 0;
	public static void getDetails (Scanner scanner) {
		System.out.print("Enter Student Name: ");
		Name = scanner.nextLine();
		System.out.print("Enter Student Branch: ");
		Branch = scanner.nextLine();
		System.out.print("Enter Student Age: ");
		Age = scanner.nextInt();
	}
}
class Marks extends Student {
	public static int Marks_Java = 0, Marks_Cpp = 0;
	public static void getMarks (Scanner scanner) {
		System.out.print("Enter Java Marks: ");
		Marks_Java = scanner.nextInt();
		System.out.print("Enter C++ Marks: ");
		Marks_Cpp = scanner.nextInt();
	}
}
class StudentMarks extends Marks {
	public static void main(String [] args) {
		Scanner scanner = new Scanner(System.in);
		getDetails (scanner);
		getMarks (scanner); int totalMarks = Marks_Java + Marks_Cpp;
		System.out.println("Student Name: " + Name);
		System.out.println("Student Branch: " + Branch);
		System.out.println("Student Age: " + Age);
		System.out.println("Total Marks: " + totalMarks);
	}
}
