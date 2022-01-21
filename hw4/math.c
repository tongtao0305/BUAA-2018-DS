#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
int top=-1,ans=0,o=-1;
char stack[10000];
int numb[1000];
int nu=-1;
char op[10000]; 

int main()
{int i,j,k;
 char s[1000];
 gets(s);
 int l=strlen(s);
 for(i=0;i<l;i++)
    {if(s[i]>='0'&&s[i]<='9')
       {while(s[i]>='0'&&s[i]<='9')
          {o++;
		   op[o]=s[i];
		   i++;
		  }
	    i--;
	    o++;
		op[o]='#';
	   }
	 else
	   {if(s[i]=='(')
	      {top++;
		   stack[top]=s[i];
		  }
	    else if(s[i]==')')
	      {while(stack[top]!='(')
             {o++;
              op[o]=stack[top];
              top--;
		     }
	       top--;
		  }
	    else if(s[i]=='*'||s[i]=='/')
	      {while(stack[top]=='*'||stack[top]=='/')
            {o++;
             op[o]=stack[top];
		     top--;
		    }
		   top++;//printf("!");
           stack[top]=s[i];
		  }
		else if(s[i]=='+'||s[i]=='-')
	      {while(top!=-1&&stack[top]!='(')
            {o++;
             op[o]=stack[top];
		     top--;
		    }
		   top++;
		   stack[top]=s[i];
		  }
	   }
	}
 while(top!=-1)
   {o++;
    op[o]=stack[top];
    top--;
   }
 o++;
 op[o]='=';  
 //printf("%d ",o);
 /*while(o!=-1) 
   {printf("%c",op[o]);
    o--;
   }*/
 i=0;
 top=-1;
 while(op[i]!='=')
   {if(op[i]=='#') 
      {i++;
	   continue;
	  }
    if(op[i]>='0'&&op[i]<='9')
      {int data=0;
       while(op[i]>='0'&&op[i]<='9')
         {data=data*10+op[i]-'0';
          i++;//printf("!%d!",i);
		 }
	   nu++;//printf("%d\n",data);
	   numb[nu]=data;
	  }
    else if(op[i]=='+') 
      {numb[nu-1]=numb[nu-1]+numb[nu];//printf("%d",stack[top-1]);
       nu--;
	  }
    else if(op[i]=='-') 
      {numb[nu-1]=numb[nu-1]-numb[nu];
       nu--;
	  }
    else if(op[i]=='*') 
      {numb[nu-1]=numb[nu-1]*numb[nu];
       nu--;
	  }
	else if(op[i]=='/') 
      {numb[nu-1]=numb[nu-1]/numb[nu];
       nu--;
	  }
    i++;
   }
 ans=numb[nu];
 printf("%d",ans);
 	
}

