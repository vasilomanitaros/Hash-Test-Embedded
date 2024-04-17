#include <stdio.h>
#include <string.h>

int hash(char* hash_string, int hash_table[]);
int unisum(int a);

int main(void) {
	int hash_table[]={10,42,12,21,7,5,67,48,69,2,36,3,19,1,14,51,71,8,26,54,75,15,6,59,13,25};
	char str[]="enter the input string";
	int a=hash(str,hash_table);
	int b=unisum(a);
	printf("The hash is %d\n", a);
	printf("the unisum of %d is %d\n",a,b);
	return 0;
}

int unisum(int i) {
	if (i<0) {i=-i;} //if negative make it positive
    int sum=i;
    while (sum>=10) { //while sum is not one digit
        sum=0; 
        while (i > 0) { //traverse the digits
            sum += i % 10; //add to result
            i /= 10; //cut the last one and move to the next
        }
        i=sum; //update the sum
    }
    //sum is calculated
    int result=0;
    while (sum>0) {
        result+=sum;
        sum--;
    }
    return result;
}

int hash (char* hash_string, int hash_table[]){
	int string_length=strlen(hash_string);
	printf("The string length is:%d\n", string_length);

	int number_start=48;
	int number_end=57;
	int char_upper_start=65;
	int char_upper_end=90;
	int char_lower_start=97;
	int char_lower_end=122;

	int hash=0;

	for(int i=0; i<=string_length; i++){
		if(hash_string[i]>=number_start && hash_string[i]<=number_end){
			hash+=hash_string[i]-48;//offset of numbers 
		}
		if(hash_string[i]>=char_upper_start && hash_string[i]<=char_upper_end){
			hash+=hash_table[hash_string[i]-65];//offset of upper case ASCII
		}
		if(hash_string[i]>=char_lower_start && hash_string[i]<=char_lower_end){
			hash-=hash_table[hash_string[i]-97];//offset of lower case ASCII
		}
		
	}
	return hash;
}