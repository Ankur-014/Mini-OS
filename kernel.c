#include "include/screen.h"
#include "include/kb.h"
#include "include/string.h"
#include "include/substr.h"
#include "include/strint.h"

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
			else if(strEql(inp,"len"))
			{
				print("Enter string: ");
				inp = readStr();
				print("The length of string is: ");
				printnum(strlength(inp));
				print("\n");
			}
			else if(strEql(inp,"cll"))
			{
					clearLine(0,1);
			}
			else if(strEql(inp,"cline"))
			{
				print("Enter line no: ");
				inp = readStr();
				uint8 lineno = (uint8) strToInt(inp, 999);
				if (lineno < 1 || lineno > cursorY) {
					print("Line no is out of screen\n");
					continue;
				}
				clearLine(lineno-1, lineno);
				uint8 i,j;
				string vidmem = (string)0xb8000; 
				for (i = lineno-1 +1; i<=cursorY; i++) {
					for (j = 0; j<sw; j++) {
						vidmem[((i-1)*sw+j)*2] = vidmem[(i*sw+j)*2];
						vidmem[((i-1)*sw+j)*2+1] = vidmem[(i*sw+j)*2+1];
					}
				}
				cursorY--;
				updateCursor();
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
