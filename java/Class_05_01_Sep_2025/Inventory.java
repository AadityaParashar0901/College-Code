import java.util.Scanner;
class DepartmentalStore {
	String [] inventory_name = new String[0];
	int [] inventory_price = new int[0];
	int [] inventory_quantity = new int[0];
	int totalItems = 0;
	public void input_inventory (Scanner scanner) {
		System.out.print("Enter the number of Items: ");
		totalItems = scanner.nextInt();
		inventory_name = new String[totalItems];
		inventory_price = new int[totalItems];
		inventory_quantity = new int[totalItems];
		System.out.println("Enter Items' Name, Price, Quantity:");
		for (int i = 0; i < totalItems; i++) {
			inventory_name[i] = scanner.next();
			inventory_price[i] = scanner.nextInt();
			inventory_quantity[i] = scanner.nextInt();
		}
	}
}
class Inventory extends DepartmentalStore {
	public static void main (String [] args) {
		Scanner scanner = new Scanner (System.in);
		Inventory store1 = new Inventory();
		store1.input_inventory (scanner);
		int totalPrice = 0;
		for (int i = 0; i < store1.totalItems; i++) {
			System.out.println("Item " + i +
				": Name: " + store1.inventory_name[i] +
				": Price: " + store1.inventory_price[i] +
				": Quantity: " + store1.inventory_quantity[i]);
			totalPrice += store1.inventory_price[i] * store1.inventory_quantity[i];
		}
		System.out.println("Total Price: " + totalPrice);
	}
}
