#include "include/screen.h"
#include "include/kb.h"
#include "include/string.h"
#include "include/substr.h"
kmain()
{
       clearScreen();
	   
       print("Welcome to my operating system(1507014)!\nUser login\n");
	   string username = "ankur";
	   string password = "1507014";
	   
	   string inp = 0;
	   //string in = 0;
	   while (1) {
		   uint8 uOK = 0, pOK = 0;
		   
		   print("username: ");
		   inp = readStr();
		   if (strEql(inp, username)) uOK = 1;
		   
		   print("password: ");
		   inp = readStr();
		   if (strEql(inp, password)) pOK = 1;
		   
		   if (uOK && pOK) {
			   print("Logged in as ankur!\n");
			   break;
		   }
		   print("Wrong information. Try again\n");
	   }
	   
       while (1)
       {
			print("ankur> ");
			inp = readStr();
			if(strEql(inp,"cmd"))
			{
					print("You are already in cmd\n");
			}
			else if(strEql(inp,"cls"))
			{
					clearScreen();
			}
			else if(strEql(inp,"cll"))
			{
					clearLine(0,1);
			}
			else if(strEql(inp,"scr"))
			{
					scrollUp(2);
			}
			else if(strEql(inp,"tb"))
			{
					printch(0x09);
			}
			else if(strEql(inp,"bc"))
			{
					printch(0x08);
			}
			else if(strEql(inp,"new"))
			{
					newLineCheck();
			}
			else if(strEql(inp,"upc"))
			{
					cursorX=10;
					cursorY=10;
					updateCursor();
			}
			else if(strEql(inp,"ankur"))
			{
					print("Username\n");
			}
			else if(strEql(inp,"os"))
			{
					print("CSE 3202\n");
			}
			
			else if(strEql(inp,"sub"))
			{
				print("Enter string: ");
				inp = readStr();
				screen_substr(inp);
			}
			else if(strEql(inp,"logout"))
			{
					print("Successfully logout!\n");
					break;
			}
			else
			{
					print("Bad command!\n");
			}
       }
}
