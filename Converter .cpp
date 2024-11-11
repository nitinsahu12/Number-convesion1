#include <iostream>
#include<string>
using namespace std;
string dec_to_binary(string);
string binary_to_dec(string);
string dec_to_hexa(string);
string hexa_binary(string);

string binary_to_dec(string n){
	int n1=stoi(n);
	int ans=0,pow=1;
	while(n1>0){
		int rem=n1%10;
		n1/=10;
		ans+=rem*pow;
		pow*=2;
	}
	string ans1=to_string(ans);
	return ans1;
}

string dec_to_hexa(string n) {
    string hex = "";
    int n1 = stoi(n);
    while (n1 != 0) {
        int rem = n1 % 16;
        if (rem < 10) {
            hex = char(48 + rem) + hex;
        } else {
            hex = char(55 + rem) + hex;
        }
        n1 /= 16;
    }
    return hex;
}


string hexa_binary(string n){
    string ans="";
    string send;
    int len=n.length();
    int array[len];
    for(int i=0;i<len;i++)
    {
        int b=int(n[i]);
        if(b>=48 and b<=57)
        {
            b=b-48;
        }
        else
        {
            b=b-55;
        }
        send=to_string(b);
        ans=ans+dec_to_binary(send);
    }
    return ans;   
}

string dec_to_binary(string n) {
    string binary = "";
    int n1=stoi(n);
    for (int i = 0; i < 4; ++i) {
        binary = to_string(n1 % 2) + binary;
        n1 /= 2;
    }
    return binary;
}


int main(){
char op;
string a;
string ans;
go:
cout<<"Your options are:"<<endl;
cout<<endl;
cout<<"A: Binary to Decimal "<<endl<<"B: Decimal to hexadecimal"<<endl;
cout<<"C: Hexadecimal to binary"<<endl<<"D: Binary to hexadecimal"<<endl<<"E: Decimal to binary"<<endl;
cout<<"F: Hexadecimal to decimal"<<endl;
cout<<endl;
cout<<"Chose The Option:"<<endl;
cin>>op;
switch(op){
	case 'A':
		//binary to decimal 
		cout<<"Enter a Binary number: "<<endl;
		cin>>a;
		cout<<"Your ans is: "<<binary_to_dec(a);
		break;
		
	case 'B':
		//decimal to hexadecimal
	    cout<<"Enter a Decimal number: "<<endl;
	    cin>>a;
	    cout<<"Your ans is: "<<dec_to_hexa(a);
	    //return 0;
		break;
		
	case 'C':
		//hexadecimal to binary
	    cout<<"Enter a Hexadecimal number: "<<endl;
	    cin>>a;
	    cout<<"Your ans is: "<<hexa_binary(a);
		break;
		
	case 'D':
		//binary to hexadecimal
	    cout<<"Enter a Binary number: "<<endl;
	    cin>>a;
	    ans=binary_to_dec(a);
	    cout<<"Your ans is: "<<dec_to_hexa(ans);
		
		break;
		
	case 'E':
		//decimal to binary 
	    cout<<"Enter a Decimal number: "<<endl;
	    cin>>a;
		cout<<"Your ans is: "<<dec_to_binary(a);
		break;
		
	case 'F':
		//hexadecimal to decimal
	    cout<<"Enter a Hexadecimal number: "<<endl;
	    cin>>a;
	    ans=hexa_binary(a);
	    cout<<"Your ans is: "<<binary_to_dec(ans);
		break;
		
	default:
		cout<<"You have choose wrong option "<<endl<<"Please choose right option"<<endl;
		goto go;
}
}