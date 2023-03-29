#include <stdio.h>
#include <stdlib.h>

int get_length_from_str(char* str) {
	int result = 0;
	for(int i = 0; str[i] != '\0'; i++) {
		result++;
	}
	return result;
}

void print_str(char* str, int length) {
	for(int i = 0; i < length; i++) {
		printf("%c", str[i]);
	}
	printf(" finieshed\n");
}

char* norm(char* str, int length) {
	int index = 0;
	int l = get_length_from_str(str);
	int rest = length - l;
	char* result = calloc(length, sizeof(char));
	
	for(int i = 0; i < length; i++) {
		if(rest <= i) {
			result[i] = str[index];
			index++;
		} else {
			result[i] = '0';
		}
	}
	return result;
}

char* rotate_str(char* str, int length) {
	
	char* erg = calloc(length, sizeof(char));
	int l = length;
	
	for(int i = 0; i <= length; i++) {
		erg[i] = str[l];
		l--;
	}
	return erg;
}

char* add_binary(char* a, char* b) {	
	////////////////////////////////////////////
	int length_a = get_length_from_str(a);
	int length_b = get_length_from_str(b);
	int l = 0;
	
	if(length_a >= length_b) {
		l = length_a;
	} else {
		l = length_b;
	}
	
	l ++;
	
	char* a_new =  norm(a, l);
	char* b_new =  norm(b, l);
	////////////////////////////////////////////
	char subtotal = '0';
	char* result = calloc(l, sizeof(char));
	////////////////////////////////////////////
	for(int i = l - 1; i >= 0; i--) {
		if(a_new[i] == '0' && b_new[i] == '0') {
			if(subtotal == '1') {
				result[i] = '1';
				subtotal = '0';
			} else {
				result[i] = '0';
			}
		} else if(a_new[i] == '1' && b_new[i] == '1') {
			if(subtotal == '1') {
				result[i] = '1';
			} else {
				result[i] = '0';
			}
			subtotal = '1';
		} else {
			if(subtotal == '1') {
				result[i] = '0';
				subtotal = '1';
			} else {
				result[i] = '1';
			}
		}
	}
	////////////////////////////////////////////
	return result;
}

void test_equals_char(char* result, char* actual, int line) {
	int length = 0;
	for(int i = 0; result[i] != '\0'; i++) {
		if(result[i] != actual[i]){
			printf("expected [%s] differs from [%s] in Line %d.\n", actual, result, line);
			break;
		}
		length ++;
	}
	
	if(actual[length] == '\0') {
		printf("Test pass in Line %d.\n", line);
	}
}

void main(){
	char a[] = "11";	
	char b[] = "1";
	char actual[] = "100";
	test_equals_char(add_binary(a, b), actual, __LINE__);
	
	char c[] = "1010";	
	char d[] = "1011";
	char actual_01[] = "10101";
	test_equals_char(add_binary(c, d), actual_01, __LINE__);
	
	char e[] = "1010";	
	char f[] = "1011";
	char actual_02[] = "10101";
	test_equals_char(add_binary(e, f), actual_02, __LINE__);
}
