import java.util.Scanner;

class Alphabet {
	private int checkCharInString(String s, char c) {
		for (int i = 0; i < s.length(); i++) if (c == s.charAt(i)) return 1;
		return 0;
	}
	public int isVowel(char c) { String vowels = new String("aeiou");
		return checkCharInString(vowels, Character.toLowerCase(c));
	}
	public int isConsonant(char c) { String consonants = new String("bcdfghjklmnpqrstvwxyz");
		return checkCharInString(consonants, Character.toLowerCase(c));
	}
}
class CheckVowels {
	public static void main (String [] args) {
		Alphabet alphabets = new Alphabet();
		Scanner scanner = new Scanner(System.in);
		System.out.print("Enter a Character: ");
		char c = scanner.nextLine().charAt(0);
		if (alphabets.isVowel(c) == 1) System.out.println(c + " is a Vowel.");
		else System.out.println(c + " is not a Vowel.");
		if (alphabets.isConsonant(c) == 1) System.out.println(c + " is a Character.");
		else System.out.println(c + " is not a Character.");
	}
}
