#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
	string F;
	int i = 0;
	while(!feof(iostream)) {
	    cin >> F ;
	    int n = 0;
	    int R = 0;
		for( ; i < F.length();i++){
			if (n<0) {
				R = 1;
				break;
			}
			if (F[i]=='(') {
				n++;
			}
			if (F[i]==')') {
				n--;
			}
			if (F[i]=='\n') {
				break;
			}
		}
		if(n>0 || R == 1) {
			cout << "incorrect" << '\n';
		}
		if(n=0 || R == 0) {
			cout << "correct" << '\n';
		}
		
	} 
	cout << F;

	return 0;
}
