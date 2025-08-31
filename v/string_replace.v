import os

fn main() {
	input_string := os.input("Enter a String: ")
	find_string := os.input("Enter String to Find: ")
	replace_string := os.input("Enter String to Replace: ")
	mut output_string := ""
	mut i := 0
	for i <= input_string.len - find_string.len {
		if input_string[i .. i+find_string.len] == find_string {
			output_string += replace_string
			i += find_string.len
		} else {
			output_string += input_string[i].ascii_str()
			i++
		}
	}
	if i < input_string.len {
		output_string += input_string[i..]
	}
	println("Output String: ${output_string}")
}
