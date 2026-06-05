#include <iostream>
#include <cmath> 

using namespace std;


// номер 1 
/*
void printhello(){
cout << "Hello, world!" ; 
}
int main(){
printhello();
return 0; 
}
*/
//номер 2
  
/*
int sum(int a, int b) {
	
	int s;
	s = a + b;
	return s;
} 
int main()
{
	int x,y; 
	cin >> x >> y; 
	cout << sum(x, y); 
	return 0;

}
*/
// номер 3 

int maxoftwo(int a, int b){
if (a>b) return a; 
else return b; 
}

int main(){
	int x ,y;
	cin >> x >> y; 
	cout << maxoftwo(x, y) << endl; 
	return 0 ; 
}



//номер 4

/*
bool isEven(int number){
	if (number%2 == 0) return true;
	else return false;

} 
int main(){
int x; 
cin >> x; 
cout << isEven(x) << endl; 
return 0; 
}
*/ 
// номер 5 

/*
double square(double x) {
double fin;
fin = x*x; 
return fin;
}

int main(){
double x; 
cin >> x; 
cout << square(x) << endl; 
}
*/ 
// ---------МАССИВЫ--------------
// номер 6 

/*
int arraySum(int arr[], int size){
int summ=0; 
for (int i=0; i < size; i++){
	summ = summ + arr[i];}
	return summ; 
}
int main() 
{
	int massivv[] = {1,2,3,4};
	int size = 4;
	cout << arraySum(massivv, size);
	return 0;
}

*/ 

// номер 7 
/*
int arraySum(int arr[], int size){
int max=0; 
for (int i=0; i < size; i++){
	if (arr[i] > max){
		max = arr[i];
	}
}
	return max; 
}
int main() 
{
	int massivv[] = {1,2,3,46};
	int size = 4;
	cout << arraySum(massivv, size);
	return 0;
}	
*/ 
// номер 8 
/*
int charCount(const char* str, char ch){
int count = 0;
for (int i=0; str[i] !='\0'; i++){
	if (str[i] == ch) {
		count++;
	}
}

return count;
} 
int main(){
const char* mytext = "My name daniil and i am work in productioniii"; 
char target = 'i';
cout << charCount(mytext, target);

return 0;

}

*/ 
// номер 9 
/*
long long factorial(int n){
	long long result = 1;
	if (n == 0) result = 1;
	for(int i =1; i <=n; i++){
	result = result * i; 

}	
	return result;

}

int main(){
	int a;
	cin >> a;
	if (a!=0)
		cout << factorial(a);
		else if (a == 0)cout << 1;
		else cout << "число некорректное";
	
return 0;

}

*/ 

// номер 10 
/*
bool isPrime(int n){
	if (n < 2) return false;
	for (int i=2; i*i<=n; i++){
		if(n%i==0) return false;
	}
	return true; 
}
int main(){
	int a;
	cin >> a; 
	cout << isPrime(a);
}
*/ 

// номер 11
/*
int zxc(int x) {
	if (x<0) x=x*(-1);
	return x; 

}
double zxc (double z) {
	if (z<0) z=z*(-1);
return z;
}

int main(){
	double a;
	cin >> a;
	cout << zxc (a);
	return 0;
}
*/ 

// номер 12
/*
void print(int x){
	cout << "int: " << x << endl; 
} 
void print(double x) {
	cout << "double: " << x << endl; 
}
void print(const char* str){
	cout << "char: " << str << endl; 
}

int main(){
	print (4);
	print (5.55);
	print ("BogatovShow");
return 0;
}

*/ 


// номер 13
/*
double avg(int a, int b){
double count = 0; 
count = (a+b)/2.0;
return count;
}
double avg(int a, int b, int c){
int temp = 0; 
temp = (a+b+c)/3.0;
return temp; 
}
double avg(int arr[], int size){
int sum=0;
for (int i = 0; i<size; i++){
	sum=sum+arr[i];
}
double fin = sum/size;

return fin; 
}

int main() {
    int a = 10, b = 20, c = 5;
    int myArr[] = {1, 2, 3, 4, 5};

    cout  << avg(a, b) << endl;
    cout  << avg(a, b, c) << endl;
    cout  << avg(myArr, 5) << endl;

    return 0;
}
*/ 
 
 // номер 14

/*
void neswap(int &a, int &b){
	int temp = a;
	a=b;
	b=temp;
}
int main() {
	int z,x; 
	cin >> z >> x;
	neswap(z,x);
	cout << z  << " "<< x;
}
*/ 
// номер 15 

/*
void myfindMinMax(int arr[], int size, int &min, int &max){
	for (int i=0; i < size; i++){
	if (arr[i] > max) max = arr[i];
	if (arr[i] < min) min = arr [i];
}
}
int main(){
int newsize = 0; 
cin >> newsize; 
int newarr[newsize];
for (int i; i < newsize; i++){
	cin >> newarr[i];
}
cin >> newarr[newsize]; 
int postmin= newarr[1], postmax= newarr[1];
myfindMinMax(newarr, newsize, postmin, postmax);
cout << "MIN " << postmin << endl << "MAX " << postmax; 
}

*/ 

//номер 16

/*
bool solveQuadratic(double a, double b, double c, double &x1, double &x2){

double D=b*b-4*a*c;
if (D>0){
x1= (-b+sqrt(D))/(2*a);
x2= (-b-sqrt(D))/(2*a);
return true;
}

else if (D==0){
	x1=(-b+sqrt(D))/(2*a);
	x2=x1;
	return true;
}
	else return false;
}

int main(){
	double a,b,c,x1,x2;
	bool result = 0;
	cin >> a >> b >> c;
result = solveQuadratic(a,b,c,x1,x2);

if (result ==1) cout << "TRUE" << " " << x1 << " " << x2;
else cout << "FALSE" ; 
return 0; 
}

*/ 

// номер 17	
/*
long long factorialRec(int n){
	if (n<=1) return 1;
	long long t=1;
	for (int i=n; i>0; i--){
	t=n; 
	t = t * (n-1);}
return t; 
}

int main(){
	long long k;
	long long result; 
	cin >> k; 
	result = factorialRec(k);
cout << result; 
return 0; 
}

*/ 

// номер 18 
/*
int fibonacci(int n){
if (n<=0) return 0;
if (n==0) return 1;
int count=0;
count = (n-1)+(n-2);
return count; 
}
int main(){
int k;
cin >> k;
int temp = fibonacci(k);
cout << temp; 
}

*/ 


//номер 19 
/* 
double power(double base, int exp){
	if (exp<0) return 0; 
	if (exp==0) return 1;
	if (exp%2==0)  return  power(base*base, exp/2);
	else return base * power(base, exp-1); 
}

int main(){
	double k,j; 
	cin >> k >> j;
	double t;
	t = power(k,j); 
	cout << t; 

}

*/ 

//номер 20

/* 
int sumOfDigits(int n) {
    n = abs(n); 
    if (n == 0) return 0;
    return (n % 10) + sumOfDigits(n / 10);
}

int main(){

	int z;
	cin >> z;
	int x=sumOfDigits(z);
	cout << x;
	return 0;
}
*/ 
/*
// номер 21 
void caesarCipher(char str[], int shift) {
    for (int i = 0; str[i] != '\0'; i++) {
        char &c = str[i];

        if (c >= 'A' && c <= 'Z') {
            c = (c - 'A' + shift) % 26 + 'A';
        } 

        else if (c >= 'a' && c <= 'z') {
            c = (c - 'a' + shift) % 26 + 'a';
        }
    }
}


*/
/*
// номер 22
void transpose(int matrix[][3], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {

            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
}
*/ 


// номер 23
// void mergeSortedArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
//     int i = 0, j = 0, k = 0;

//     while (i < size1 && j < size2) {
//         if (arr1[i] < arr2[j]) result[k++] = arr1[i++];
//         else result[k++] = arr2[j++];
//     }

//     while (i < size1) result[k++] = arr1[i++];
//     while (j < size2) result[k++] = arr2[j++];
// }

// номер 24

// int increment(int n) { return n + 1; }
// int squareFunc(int n) { return n * n; }
// int negateFunc(int n) { return -n; }

// void processArray(int arr[], int size, int (*func)(int)) {
//     for (int i = 0; i < size; i++) {
//         cout << func(arr[i]) << " ";
//     }
//     cout << endl;
//}
 
// номер 25 
/*
const int STACK_SIZE = 100;
int stackArr[STACK_SIZE];
int topIndex = -1;

void push(int value) {
    if (topIndex < STACK_SIZE - 1) {
        stackArr[++topIndex] = value;
    } else {
        cout << "Stack Overflow!" << endl;
    }
}

bool isEmpty() {
    return topIndex == -1;
}

int pop() {
    if (!isEmpty()) {
        return stackArr[topIndex--];
    }
    cout << "Stack is empty!" << endl;
    return -1;
}
*/ 







































