#include "include/screen.h"
#include "include/kb.h"
#include "include/string.h"
#include "include/substr.h"
kmain()
{
       clearScreen();
	   
       print("Welcome to my operating system(1507014)!\n");
 A:    print("User login\n");
	   string username = "ankur";
	   string password = "123";
	   
	   string inp = 0;
	   string in = 0;
	   while (1) {
		   uint8 uOK = 0, pOK = 0;
		   
		   print("username: ");
		   inp = readStr();
		   if (strEql(inp, username)) uOK = 1;
		   
		   print("password: ");
		   inp = readStr();
		   if (strEql(inp, password)) pOK = 1;
		   
		   if (uOK && pOK) {
			   print("Login Done!\n");
			   break;
		   }
		   print("Wrong info. Try again\n");
	   }
	   
       while (1)
       {
			print("ankur> ");
			inp = readStr();
			if(strEql(inp,"cmd"))
			{
					print("You are already in cmd\n");
			}
			else if(strEql(inp,"clear"))
			{
					clearScreen();
			}
			else if(strEql(inp,"ankur"))
			{
					print("Username\n");
			}
			
			else if(strEql(inp,"substr"))
			{
				print("Enter string: ");
				inp = readStr();
				screen_substr(inp);
			}
			else if(strEql(inp,"logout"))
			{
					clearScreen();
					print("Successfully logout!\n");
					goto A;
					break;
			}
			else if(strEql(inp,"shut"))
			{
					print("Shutdown Successfully!\n");
					break;
			}
			else
			{
					print("Bad command!\n");
			}
       }
}
