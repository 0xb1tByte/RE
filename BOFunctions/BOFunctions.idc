#include <idc.idc> 

static list_callers(bad_func)
{
 // auto is used to define local variables 
 auto vulnFuncAddress, address, xref, source,counter;
 // LocByName is used to find the address of a given function by its name 
vulnFuncAddress = LocByName(bad_func);
	if (vulnFuncAddress == BADADDR) // Function name is not found
    {
       Message("Sorry, %s not found in database \n", bad_func);
    } // end if 
    else   
    {
	  counter= 0;
      
	  for (address = RfirstB(vulnFuncAddress) ; address != BADADDR; address = RnextB(vulnFuncAddress, address) ) 
          {
	    xref = XrefType();
		if (xref == fl_CN || xref == fl_CF) 
            {
		  source = GetFunctionName(address);
        Message("%s is called from 0x%x in %s\n", bad_func, address, source);
		 counter = counter + 1;
		} // end if 
	  } // end for 
	  Message("[+] %s is called %d times ---\n",bad_func,counter);
	} // end else 
} // end list_callers
static main() 
{
// open the file that contains functions name 
auto functionNameFile,functionName,length,String;
functionNameFile =  fopen("BOFunctionsList.txt","r"); // r ==> open the file for reading 
  if (functionNameFile == 0) {
    Message("[!] Error in opening the file!\n");
	return;
  }
  while ((functionName = readstr(functionNameFile) ) != -1 )
  {
      length = strlen(functionName);
      String = substr(functionName,0,length-1);
      list_callers(String);
  } // end while
} // end main 


