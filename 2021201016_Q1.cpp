#include<iostream>
using namespace std;


template <class T >
struct node{
	T data;
	node<T> *next;
};

template <class T >
class Stack{
	public :
	int size=0;
	node<T> *Top;
	void push(T x){
	    size++;
		node<T> *tmp;
		tmp=new node<T>;
		tmp->data=x;
		tmp->next==NULL;
		if(Top==NULL){
			Top=tmp;
		}	
		else{
			tmp->next=Top;
			Top=tmp;
		}
	}

	T pop(){
		T res;
		node<T> *tmp;
		if(Top){
		    size--;
			tmp=Top;
			res=Top->data;
			if(Top->next){
				Top=Top->next;
			}
			else{
				Top=NULL;
			}
			delete(tmp);
			return res;
		}
		return -1;
	}
	T top(){
		if(Top)
			return Top->data;
		else
			return -1;
	}
};


void trim(string& s){  
    string temp;
    for(int i=0;i<s.size();i++)
    {
       if(((s[i]-'0')>=0)&&((s[i]-'0')<=9))
       {
           while(i<s.size() && ((s[i]-'0')>=0)&&((s[i]-'0')<=9))
           {
               temp+=s[i];
               i++;
           }
           i--;
           temp+='|';
       }
       else
       temp+=s[i];
    }
    s=temp;
}


int precedence(char c){
    if(c=='x')
    return 2;
    if(c=='+' || c=='-')
    return 1;
    return 0;
}


long long int calculate(long long int a,long long int b,char c){
    if(c=='+'){
        return (a+b);
    }else if(c=='-'){
        return (a-b);
    }else if(c=='x'){
        return (a*b);
    }
    return -1;
}
long long int change(string& t){
    long long int ans=0;
    int p=10;
    for(int i=0;i<t.size();i++){
        ans=ans*p+(t[i]-'0');
    }
    return ans;
}

long long int calculator(string& s)
{
    trim(s);
     char op;
     long long int op1,op2,ans;
    Stack<char> operator_stack;
    Stack<long long int> operand_stack;
    operator_stack.push('#');
    for(int i=0;i<s.size();i++)
    {
       
        
        if(s[i]=='+' || s[i]=='-' || s[i] =='x')
        {
            
            while (operator_stack.size && precedence(operator_stack.top()) >= precedence(s[i]))

            {
                op  = operator_stack.top();
                operator_stack.pop();
                op2 = operand_stack.top();
                operand_stack.pop();
                op1 = operand_stack.top();
                operand_stack.pop();
                ans = calculate(op1,op2,op);
               
                operand_stack.push(ans);
            }
            operator_stack.push(s[i]);
        }
        else
        {   string temp="";
       
            while(s[i]!='|')
            {
                temp+=s[i];
                i++;
            }
            ans = change(temp);
          
            operand_stack.push(ans);
        }
        
        
    }
     while (operator_stack.size>1)
            {
                op  = operator_stack.top();
                operator_stack.pop();
                op2 = operand_stack.top();
                operand_stack.pop();
                op1 = operand_stack.top();
                operand_stack.pop();
                ans = calculate(op1,op2,op);
                operand_stack.push(ans);
            }
    operator_stack.pop();
    return (operand_stack.top());
    
}

void factorial(int num){
    int fact[3000];
    fact[0]=1;
    for(int i=1;i<3000;i++){
        fact[i]=0;
    }
    int digit=1;   //it will store length of answer 
    for(int i=2;i<=num;i++){
        int carry=0;
        int product;
        for(int j=0;j<digit;j++){
            product=(fact[j]*i)+carry;
            fact[j]=product%10;
            carry=product/10;
        }
        while(carry>0){
            fact[digit]=carry%10;
            digit++;
            carry=carry/10;
        }
    }
    if(digit<3001){
    for(int i=digit-1;i>=0;i--){
        cout<<fact[i];
    }
    }else{
        cout<<"output has more than 3000 digits";
    }
}

string multiply(string a, string b){
	
	int arr[3001]={0};

        for(int i=a.size()-1; i>=0 ; i--)
        {
            int product,sum;
            for(int j = b.size()-1; j>=0; j--)
            {
                product = (a[i]-'0') * (b[j]-'0');
                sum  = arr[i+j+1] + product;
                arr[i+j+1] = sum % 10;
                arr[i+j] += sum / 10; 
            }
        }

        string ans;
        int t=a.size()+b.size(); 
        for(int i=0;i<t;i++)
        {
            if(ans.size() != 0)
            { 
                ans += char(arr[i]+'0');
            }
            else if(arr[i] != 0) {
                ans += char(arr[i]+'0'); 
            }
        }
        
        if(ans.size() == 0) return "0";

        return ans;
	
}

string power(string base, int exponent){
	if(exponent==0)
		return "1";
	if(exponent==1)
		return base;
	string res=power(base,exponent/2);
	if(exponent % 2){
        res = multiply(res,res);
		return multiply(base,res);
	}
	else{
		res = multiply(res,res);
		return res;
	}
}

long long int gcd(long long int a,long long int b){
    if(a==0 & b==0){
        return 0;
    }
    if(a==0 && b!=0){
        return b;
    }
    if(a!=0 && b==0){
        return a;
    }
    if(a==b){
        return a;
    }
    
    if(a%2==0 && b%2==0){
        return (2*gcd(a/2,b/2));
    }else if(a%2==0 && b%2==0){
        return gcd(a/2,b);
    }else if(a%2!=0 && b%2!=0){
        return gcd(a/2,b);
    }else if(a%2!=0 && b%2!=0){
        if(a>=b){
            return gcd((a-b)/2,b);
        }else{
            return  gcd((b-a)/2,a);
        }
    }


}

int main(){

  int n;
  cin>>n;
  if(n==1){
      int exp;
      string b;
      cin>>b>>exp;
      string ans1=power(b,exp);
  }else if(n==2){
      long long int a,b;
      cin>>a>>b;
      cout<<gcd(a,b);
      
  }else if(n==3){
      int f;
      cin>>f;
      cout<<factorial(f);
      
  }else if(n==4){
      string s;
      cin>>s;
      cout<<calculator(s);
  }
  return 0;
}