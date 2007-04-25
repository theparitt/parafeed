/* $Id: clgetNIVal.c,v 2.0 1998/11/11 07:13:01 sanjay Exp $ */
#include <cllib.h>
#include <vector>

#ifdef __cplusplus
extern "C" {
#endif
/*---------------------------------------------------------------------------*/
/* Extract a m number of values associated with Key.  If *m is negative,     */
/* fatal error occurs.  If the return value is positive, it is the number of */
/* associated values that are returned in *Vals.  Vals should have enough    */
/* space to hold the returned values.                                        */
/*---------------------------------------------------------------------------*/
int clgetNIVal(char *Key, int *val, int *m)
{
  int i=1,n;
  double d;
  char tmp[8];
  Symbol *S;

HANDLE_EXCEPTIONS(
  if (*m <= 0) sprintf(tmp,"int[]");
  else sprintf(tmp,"int[%d]",*m);

  S = SearchQSymb(Key, tmp);
  i=1;
  while(i <= *m)
    if ((n=clparseVal(S,&i,&d))==FAIL) return n;
    else if (n==0) break;
    else {val[i-1] = (int)d;i++;}

  return i-1;
)
}

  int clgetNIValp(const string& Key, vector<int>& val, int& m)
  {
    int n;
    double d;
    char tmp[8];
    Symbol *S;
    
    HANDLE_EXCEPTIONS(
		      if (m <= 0) sprintf(tmp,"int[]");
		      else sprintf(tmp,"int[%d]",m);
		      
		      S = SearchQSymb((char *)Key.c_str(), tmp);
		      
		      int i=1;
		      while((n=clparseVal(S,&i,&d))!=FAIL)
			{
			  if (n==0) return i-1;
			  else 
			    {
			      val.resize(i);
			      val[i-1] = (int)d;
			      i++;
			    }
			}
		      return i-1;
		     );
  }
#ifdef __cplusplus
	   }
#endif