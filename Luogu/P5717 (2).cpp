#include<iostream> 
using namespace std;
int main(){
	float a, b, c, d, e, f;
	cin>>a>>b>>c; 
	if(a>b){
        if(b>c){
            d = c,e = b,f = a;
        }
        else if(a>=c){
            d = b,e = c,f = a;
        }
        else if(c>a){
            d = b,e = a,f = c;
        }
    }
    else if(a<=b){
        if(c>=b){
            d = a,e = b,f = c;
        }
        else if(a>=c){
            d = c,e = a,f = b;
        }
        else if(c>a){
            d = a,e = c,f = b;
        }
    }
	if(d+e<f){
		cout<<"Not triangle"<<endl;
	}
	else{
		if(d*d+e*e==f*f){
			cout<<"Right triangle"<<endl;
		}
		else if(d*d+e*e<f*f){
			cout<<"Obtuse triangle"<<endl;
		}
		else if(d*d+e*e>f*f){
			cout<<"Acute triangle"<<endl;
		}
		
		if(d == e||d == f||f == e){
			cout<<"Isosceles triangle"<<endl;
			if(a ==b&&b==c){
				cout<<"Equilateral triangle"<<endl;
			}
		}
	}
	return 0;
}
