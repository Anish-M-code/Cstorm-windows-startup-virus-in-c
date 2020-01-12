
// Cstorm Remover
// Copyright (C) 2018-2019 M.Anish <aneesh25861@gmail.com>

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
//(at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

/* Cstorm Remover was developed independantly by M.Anish For Educational purpose only!
    USE AT YOUR OWN RISK. DEVELOPER NOT RESPONSIBLE FOR ANY DAMAGES THROUGH USE OF THIS SOFTWARE.	*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//Function to get Current User in Windows who is logged in.
void tunnel()
{
    system("echo %USERPROFILE%>user");
}

//Function to detect and remove chrome.bat in startup folder in windows.
void tscan()
{
    FILE *f;
    char s[300],tmp[350],tmp2[350],ch; int i=0;
    f=fopen("user","r");
    if(f==NULL)
    {
        exit(0);
    }
    while(feof(f)==0)
    {
        fscanf(f,"%c",&ch);
        if(ch=='\n')
            break;
        s[i]=ch;
        i++;
    }
    s[i]='\0';
    fclose(f);
    strcat(s,"\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\chrome.bat");
	strcpy(tmp,"del \"");
	strcat(tmp,s);
	strcat(tmp,"\"");
    f=fopen(s,"r");
    if(f!=NULL)
    {
        printf("\nCstorm Infection Detected!:%s",s);
        printf("\nAttempting Repairs!\n");
        fclose(f);
        system(tmp);
    }
    else
    fclose(f);
    f=fopen("C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp\\chrome.bat","r");
    if(f!=NULL)
    {
       printf("\nCstorm Infection Detected!");
       printf("\nAttempting Repairs!\n");
	   strcpy(tmp2,"del \"");
	   strcat(tmp2,"C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp\\chrome.bat");
	   strcat(tmp2,"\"");
	   fclose(f);
       system(tmp2);
    }
    else
    fclose(f);
}

//Perform cleaning of temporary files generated .
void ok()
{
    remove("user");
}

//Load all reqired functions.
void run()
{
    tunnel();
    tscan();
}

//Function to pause the program.
void pause()
{
    printf("\n");
    system("pause");
}

int main()
{
    system("title Cstorm Remover ");
    run();
    ok();
    printf("All operations completed...\n");
    pause();
}
