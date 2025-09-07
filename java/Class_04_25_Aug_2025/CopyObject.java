class CopyClass {
	public String text;
	CopyClass (String s) { text = s; }
	CopyClass (CopyClass o) { text = o.text; }
}
class CopyObject {
	public static void main (String [] args) {
		CopyClass objectA = new CopyClass (new String ("Text in Object A"));
		CopyClass objectB = new CopyClass (objectA);
		System.out.println("Object B: " + objectB.text);
	}
}
