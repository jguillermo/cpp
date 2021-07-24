#include<conio.h>
#include<iostream.h>
#include<math.h>
#include<stdlib.h>

main()
{randomize();
 int a[100],rep,j,c;
 a[0]=random(100)+1;
 cout<<a[0]<<",";
 for(c=0;c<=99;)
 {a[c]=random(100)+1;
  rep=1;
  for(j=0;j<c;j++)
  	{if(a[c]==a[j])
  	 	{rep=0; break;
      }
  	}
  if(rep==1)
  	{cout<<a[c]<<",";
    c++;
    }
  }
 getch();
}