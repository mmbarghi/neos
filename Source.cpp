#include<stdio.h>
#include"Header.h"
#include"dirent.h"
//#include"unistd.h"
#include<stdlib.h>
#include<direct.h>
#include<string.h>
#include <stdlib.h>
#include<conio.h>
#include<time.h>
#include <iostream>
#include <windows.h>
#define widtheditorshow 50
#define higheditorshow 30

/////////////////////////////&&&&&&&&& def &&&&&&&&&&&&&&
//////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////********************     GLOBAL   ***********************************
typedef struct users
{
	char name[200];
	char username[200];
	char password[200];
	int passstrength;
	int access;
	int wrongcommand;
	int timeaccess[3] ;
	int tuser;
	int shareuser[50];
}stusr;
typedef struct filess
{
	char name[200];
	char filemaker[200];
	int timeaccess[6];
	int tfile;
	int fileaccess[50];
}stfl;
///////////////////////////////////////////////////////////////////// *********************** FUNCTIONS *********************

//////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////// ********************** INT MAIN   **************************
int main(void)
{
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	stusr user[50];
	stfl myflies[50];
	stfl emfile = {};
	char usercheck[200];
	char passcheck[200];
	char currentuser[200];
	char currentpath[150];
	int currentid;
	int currentaccess;
	char badcommand[300];
	char command[50];
	char seccommand[50];
	char thcommand[50];
	char focommand[50];
	char ficommand[50];
	char sicommand[50];
	char sevcommand[50];
	char eightcommand[50];
	int fuserpass = 0;
	int howmanyfolderforward = 1;
	int finpass = 0;
	int ftime = 0;
	////////////////////
	char newusername[200];
	char newuserusername[200];
	char newuserpassword[200];
	char newuserpasswordrepeat[200];
	char chpass[200];
	char chpassrep[200];
	char ynnewadmin[10];
	char filepath[2000];
	char cdfilepath[2000] = { "cd " };
	char filedriver[3];
	char cwd[2000];
	char wherewanttogo[2000];
	int tbachslash=0;
	int newuserpassstrength;
	int newuseraccess;
	int newusertimeaccess;
	int frepeat = 0;
	int fw = 0;
	int tu;
	int tf;


	starshow();
	startfolder();
	////////////////////////////////////////////////////////////////////start user
	FILE *fptr;
	fptr = fopen("users.bin", "rb");
	if (fptr == NULL)
	{

		fptr = fopen("users.bin", "ab");

		user[0] = { "admin", "admin", "admin",100,1,0,{9999,99,99},1,{0} };
		fwrite(&user, sizeof(stusr), 1, fptr);
		fclose(fptr);
		chdir("admin");
		FILE *fpf;
		fpf = fopen("files.bin", "wb");
		fclose(fpf);
		chdir("..");
	}
	
	//////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////users load
	//fptr = fopen("users.bin", "rb");
	
	else
	{
		fread(&user, sizeof(stusr), 1, fptr);
		tu = user[0].tuser;
		fclose(fptr);
		fptr = fopen("users.bin", "rb");
		fread(&user, sizeof(stusr), tu, fptr);
		tu = user[0].tuser;
		fclose(fptr);
		getcwd(filepath, sizeof(filepath));
		strcat(cdfilepath, filepath);
		filedriver[0] = filepath[0];
		filedriver[1] = filepath[1];
		filedriver[2] = '\0';
		//for (int i = 0; i <= tu - 1; i++)
		//{
			//fread(&user, sizeof(stusr), 1, fptr);
			//printf("%s\n%s\n%s\n%d\n%d\n%d\n%d\n", user[i].name, user[i].username, user[i].password, user[i].passstrength, user[i].access, user[i].wrongcommend, user[i].timeaccess);
		//}

	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////########  login page  ################
	
	while (1)
	{


		timenow();
		if (ftime)
		{
			setTextColor(stdout, TC_RED);
			printf("Your premission is expire!\n");
			setTextColor(stdout, TC_LIGHTGRAY);
			fuserpass = 0;
			finpass = 0;
			ftime = 0;
		}
		 else if (finpass)
		{
			setTextColor(stdout, TC_RED);
			printf("the username or password is incorrect\n");
			setTextColor(stdout, TC_LIGHTGRAY);
			finpass = 0;
		}
		setTextColor(stdout, TC_LIGHTBLUE);
		printf("User Name:");
		setTextColor(stdout, TC_LIGHTGRAY);
		gets_s(usercheck);
		//getchar();
		//scanf("%s", usercheck);
		printf("\n");
		setTextColor(stdout, TC_LIGHTBLUE);
		printf("Password:");
		setTextColor(stdout, TC_LIGHTGRAY);
		//getchar();
		setTextColor(stdout, TC_BLACK);
		gets_s(passcheck);
		setTextColor(stdout, TC_LIGHTGRAY);

		for (int i = 0; i <= (user[0].tuser) - 1; i++)
		{

			if (!(strcmp(usercheck, user[i].username)) && !(strcmp(passcheck, user[i].password)))
			{
				if ((user[i].timeaccess[0] < tm.tm_year + 1900))
				{
					ftime = 1;
				}
				if ((user[i].timeaccess[0] == tm.tm_year + 1900))
				{
					if ((user[i].timeaccess[1] < tm.tm_mon + 1))
					{
						ftime = 1;
					}
					if ((user[i].timeaccess[1] == tm.tm_mon + 1))
					{
						if ((user[i].timeaccess[2] < tm.tm_mday))
						{
							ftime = 1;
						}
					}
					

				}
				
				
					strcpy(currentuser, user[i].username);
					fuserpass = 1;
					currentid = i;
					currentaccess = user[i].access;
					break;
			}
		}
		if (ftime)
		{
			system("cls");

			continue;
		}
		if (fuserpass)
		{
			system("cls");
			printf("Welcome %s\n", currentuser);
			fuserpass = 0;
			finpass = 0;
			//mkdir(currentuser);
			chdir(currentuser);
			

		}
		else//error of wrong password
		{
			system("cls");
			finpass = 1;
			continue;
		}

		//system("echo %cd%");
		//////////////////////////////////////////////////////////////////////////############# command page ###################
		
		while (1)
		{
			tbachslash = 0;
			getcwd(cwd, sizeof(cwd));
			for (int i = 0; cwd[i] != '\0'; i++)
			{
				if (cwd[i] == '\\')
				{
					tbachslash++;
				}
			}
			for (int i = 0,c=0,t=0; i<=strlen(cwd); i++)
			{
				if (cwd[i] == '\\')
				{
					t++;
				}
				if (t > tbachslash - 3)
				{
					currentpath[c] = cwd[i];
					c++;
				}
				
			}
			//system("echo %cd%");
			if (currentaccess)
			{
				setTextColor(stdout, TC_GREEN);
				printf("[ %s @ %s ]:  ", currentuser, currentpath);
				setTextColor(stdout, TC_LIGHTGRAY);
			}
			else
			{
				setTextColor(stdout, TC_CYAN);
				printf("[ %s @ %s ]:  ", currentuser, currentpath);
				setTextColor(stdout, TC_LIGHTGRAY);
			}
			strcpy(seccommand, "");
			strcpy(thcommand, "");
			strcpy(focommand, "");
			strcpy(ficommand, "");
			strcpy(sicommand, "");
			strcpy(sevcommand, "");
			strcpy(eightcommand, "");

			gets_s(badcommand);
			if (!(strcmp(badcommand, "\0")))
			{
				continue;
			}
			else
			{
				sscanf(badcommand, "%s%s%s%s%s%s%s%s", command, seccommand,thcommand,focommand,ficommand,sicommand,sevcommand,eightcommand);
			}
			for (int i = 0; i <= strlen(badcommand); i++)
			{
				if (badcommand[i] == '>')
				{
					if (badcommand[i + 1] == '>')
					{
						strcpy(seccommand, ">>");
						for (int j = 0, co = 0; j <= i - 2; j++, co++)
						{
							command[co] = badcommand[j];
						}
						command[i - 1] = '\0';
						int co = 0;
						for (int j = i + 3; j <= strlen(badcommand); j++, co++)
						{
							thcommand[co] = badcommand[j];
						}
						thcommand[co] = '\0';
						break;
					}
					else
					{
						strcpy(seccommand, ">");
						for (int j = 0, co = 0; j <= i - 2; j++, co++)
						{
							command[co] = badcommand[j];
						}
						command[i - 1] = '\0';
						int co = 0;
						for (int j = i + 2; j <= strlen(badcommand); j++, co++)
						{
							thcommand[co] = badcommand[j];
						}
						thcommand[co] = '\0';
						break;
					}
			
				}
				
			}
			if (!(strcmp(command, "exit")))
			{
				return 0;
			}
			else if (!(strcmp(command, "cls")))
			{
				system("cls");
				continue;
			}

			else if (!(strcmp(command, "lock")))
			{
				system("cls");
				SetCurrentDirectory(filepath);
				//system("cd %s",filepath);
				//system(filedriver);
				//system(cdfilepath);
				//printf("%s\n", filedriver);
				break;

			}
			else if (!(strcmp(command, "su")))
			{
				if (!(strcmp(seccommand, "")))
				{
					setTextColor(stdout, TC_RED);
					printf("Please enter user!\n");
					setTextColor(stdout, TC_LIGHTGRAY);
					continue;
				}

				if (currentaccess)
				{
					for (int i = 0; i <= (user[0].tuser) - 1; i++)
					{
						
						if (!(strcmp(seccommand, user[i].username)))
						{
							strcpy(currentuser, user[i].username);
							fuserpass = 1;
							currentid = i;
							currentaccess = user[i].access;
							SetCurrentDirectory(filepath);
							chdir(currentuser);
							continue;
						}
					}
					///////////////
					if (fuserpass)
					{
						fuserpass = 0;

					}
					else//error of wrong username
					{
						setTextColor(stdout, TC_RED);
						printf("Username Not found!\n");
						setTextColor(stdout, TC_LIGHTGRAY);


						strcpy(badcommand, "\0");
						continue;
					}



				}
				else
				{
					int fuu = 0;
					for (int i = 0; i <= (user[0].tuser) - 1; i++)
					{
						if (!(strcmp(seccommand, user[i].username)))
						{
							fuu = 1;
						}
					}
					if (!fuu)
					{
						setTextColor(stdout, TC_RED);
						printf("I can't find user!\n");
						setTextColor(stdout, TC_LIGHTGRAY);
						continue;
					}
					
						printf("\nPassword:");
						//getchar();
						setTextColor(stdout, TC_BLACK);
						gets_s(passcheck);
						setTextColor(stdout, TC_LIGHTGRAY);

						for (int i = 0; i <= (user[0].tuser) - 1; i++)
						{

							if (!(strcmp(seccommand, user[i].username)) && !(strcmp(passcheck, user[i].password)))
							{
								strcpy(currentuser, user[i].username);
								fuserpass = 1;
								currentid = i;
								currentaccess = user[i].access;
								SetCurrentDirectory(filepath);
								chdir(currentuser);
								continue;
							}

						}
						if (!fuserpass)
						{
							setTextColor(stdout, TC_RED);
							printf("Password is wrong!\n");
							setTextColor(stdout, TC_LIGHTGRAY);
							continue;
						}

					
				}

			}


			else if (!(strcmp(command, "pwd")))
			{
				if (!(strcmp(seccommand, "-l")))
				{
					printf("%s\n", currentpath);
				}
				else {
					system("echo %cd%");

				}
				continue;
			}

			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else if (!(strcmp(command, "create")))
			{
				if (currentaccess)
				{
					printf("please choose a name for new user:\n");
					gets_s(user[user[0].tuser].name);
					strcpy(newusername, user[user[0].tuser].name);
					printf("and please choose a username for %s:\n", newusername);
					gets_s(user[user[0].tuser].username);
					strcpy(newuserusername, user[user[0].tuser].username);
					while (1)
					{
						if (frepeat==2)
						{
							setTextColor(stdout, TC_RED);
							printf("Password is too weak!.\n");
							setTextColor(stdout, TC_LIGHTGRAY);
							frepeat = 0;
						}
						else if (frepeat)
						{
							setTextColor(stdout, TC_RED);
							printf("passwords are not match.\n");
							setTextColor(stdout, TC_LIGHTGRAY);
							frepeat = 0;
						}
						printf("so what is the password of %s account\n", newuserusername);
						setTextColor(stdout, TC_BLACK);
						gets_s(user[user[0].tuser].password);
						strcpy(newuserpassword, user[user[0].tuser].password);
						if ((passsterngth(newuserpassword)) < 33)
						{
							frepeat = 2;
							continue;
						}
						setTextColor(stdout, TC_LIGHTGRAY);

						printf("to ensure please enter password again:\n");
						setTextColor(stdout, TC_BLACK);
						gets_s(newuserpasswordrepeat);
						setTextColor(stdout, TC_LIGHTGRAY);
						if ((strcmp(newuserpasswordrepeat, newuserpassword)))
						{
							frepeat = 1;
							continue;
						}
						else
						{
							strcpy(user[user[0].tuser].password, newuserpassword);
						}
						break;
					}
					user[user[0].tuser].passstrength = passsterngth(newuserpassword);
					printf("is this user admin of system? (Y/n)\n");
					gets_s(ynnewadmin);
					if (!(strcmp(ynnewadmin, "n")))
					{
						user[user[0].tuser].access = 0;
					}
					else
					{
						user[user[0].tuser].access = 1;
					}

					printf("up to what date user has access to sysytem? (YYYY MM DD)\n");
					scanf("%d%d%d", &user[user[0].tuser].timeaccess[0], &user[user[0].tuser].timeaccess[1], &user[user[0].tuser].timeaccess[2]);
					getchar();
					//user[user[0].tuser].tuser = (user[0].tuser)++;
					user[user[0].tuser].wrongcommand = 0;
					user[user[0].tuser].tuser = user[0].tuser+1;
					user[user[0].tuser].shareuser[0] =0 ;
					///////////////
					SetCurrentDirectory(filepath);

					////////////////////////////////making new user folder /////////////////
					mkdir(newuserusername);
					chdir(newuserusername);
					FILE *fpf;
					fpf = fopen("files.bin", "wb");
					fclose(fpf);
					chdir("..");
					////////////////////////////////////////////////////////////////////******** writing new user to file **********
					user[0].tuser++;
					tu++;
					fptr = fopen("users.bin", "wb");
					//for (int i = 0; i <= tu; i++)
					//{
						fwrite(&user, sizeof(stusr), tu+1, fptr);

//					}
					fclose(fptr);
					//////////////////////
					SetCurrentDirectory(cwd);
					setTextColor(stdout, TC_GREEN);
					printf("creating new user is done!\n");
					setTextColor(stdout, TC_LIGHTGRAY);


				}

				else
				{
					setTextColor(stdout, TC_RED);
					printf("I'm Sorry you do Not have access to do that\n");
					setTextColor(stdout, TC_LIGHTGRAY);
					strcpy(badcommand, "\n");
				}
				strcpy(badcommand, "^");

			}

			///////////////////////////////////////////////////////////////////////////////////
			else if (!(strcmp(command, "passwd")))
			{
				if (currentaccess)//admin
				{
					if (!(strcmp(seccommand, "-l")))
					{
						if (!(strcmp(sicommand, "")))
						{
							setTextColor(stdout, TC_RED);
							printf("you forget to enter username, try again!\n");
							setTextColor(stdout, TC_LIGHTGRAY);
							continue;
						}
						else
						{



							for (int i = 0; i <= (user[0].tuser) - 1; i++)
							{

								if (!(strcmp(sicommand, user[i].username)))
								{
									user[i].timeaccess[0] = atoi(thcommand);
									user[i].timeaccess[1] = atoi(focommand);
									user[i].timeaccess[2] = atoi(ficommand);
									fuserpass = 1;
									break;
								}
							}
							///////////////
							if (fuserpass)
							{
								SetCurrentDirectory(filepath);
								fptr = fopen("users.bin", "wb");
								fwrite(&user, sizeof(stusr), user[0].tuser + 1, fptr);
								fclose(fptr);
								fuserpass = 0;
								SetCurrentDirectory(cwd);
							}
							else//error of wrong username
							{
								setTextColor(stdout, TC_RED);
								printf("Username Not found!\n");
								setTextColor(stdout, TC_LIGHTGRAY);
								continue;
								
							}














						}
					}
					else if (!(strcmp(seccommand, "")))//pass admin
					{

						while (1)
						{
							if (frepeat==2)
							{
								setTextColor(stdout, TC_RED);
								printf("Password is too weak!\n");
								setTextColor(stdout, TC_LIGHTGRAY);
								frepeat = 0;
							}
							else if (frepeat)
							{
								setTextColor(stdout, TC_RED);
								printf("Passwords are not match.\n");
								setTextColor(stdout, TC_LIGHTGRAY);
								frepeat = 0;
							}
							printf("So lets change your password what is your new password:\n");
							setTextColor(stdout, TC_BLACK);
							gets_s(chpass);
							setTextColor(stdout, TC_LIGHTGRAY);
							if ((passsterngth(chpass)) < 33)
							{
								frepeat = 2;
								continue;
							}
							printf("to ensure please enter new password again:\n");
							setTextColor(stdout, TC_BLACK);
							gets_s(chpassrep);
							setTextColor(stdout, TC_LIGHTGRAY);
							if ((strcmp(chpass, chpassrep)))
							{
								frepeat = 1;
								continue;
							}
							else
							{
								strcpy(user[currentid].password, chpass);
								user[currentid].passstrength = passsterngth(chpass);
								SetCurrentDirectory(filepath);
								fptr = fopen("users.bin", "wb");
								fwrite(&user, sizeof(stusr), user[0].tuser+1 , fptr);
								fclose(fptr);
								SetCurrentDirectory(cwd);
							}
							break;
						}
					}
					else//admin change other user pass
					{
						int k = 0;
						/////////////////////////////////////////////////////////////////////
						for (int i = 0; i <= (user[0].tuser) - 1; i++)
						{

							if (!(strcmp(seccommand, user[i].username)))
							{
								fuserpass = 1;
								k = i;
								continue;
							}
						}
						///////////////
						if (fuserpass)
						{
							fuserpass = 0;
							//////////////////////////////////////
							while (1)
							{
								if (frepeat == 2)
								{
									setTextColor(stdout, TC_RED);
									printf("Password is too weak!\n");
									setTextColor(stdout, TC_LIGHTGRAY);
									frepeat = 0;
								}
								else if (frepeat)
								{
									setTextColor(stdout, TC_RED);
									printf("Passwords are not match.\n");
									setTextColor(stdout, TC_LIGHTGRAY);
									frepeat = 0;
								}
								printf("So lets change %s password what is your new password:\n", user[k].username);
								setTextColor(stdout, TC_BLACK);
								gets_s(chpass);
								setTextColor(stdout, TC_LIGHTGRAY);
								if ((passsterngth(chpass)) < 33)
								{
									frepeat = 2;
									continue;
								}
								printf("to ensure please enter new password again:\n");
								setTextColor(stdout, TC_BLACK);
								gets_s(chpassrep);
								setTextColor(stdout, TC_LIGHTGRAY);
								if ((strcmp(chpass, chpassrep)))
								{
									frepeat = 1;
									continue;
								}
								else
								{
									strcpy(user[k].password, chpass);
									user[currentid].passstrength = passsterngth(chpass);
									SetCurrentDirectory(filepath);
									fptr = fopen("users.bin", "wb");
									fwrite(&user, sizeof(stusr), user[0].tuser+1, fptr);
									fclose(fptr);
									SetCurrentDirectory(cwd);
								}
								break;
							}
							////////////////////////////////////////////
						}
						else//error of wrong username
						{
							setTextColor(stdout, TC_RED);
							printf("Username Not found!\n");
							setTextColor(stdout, TC_LIGHTGRAY);
							strcpy(badcommand, "\0");
							continue;
						}

						//////////////////////////////////////////////////////////////////////
					}
				}
				else//user
				{
					if (!(strcmp(seccommand, "")))//pass user
					{
						while (1)
						{
							if (frepeat == 2)
							{
								setTextColor(stdout, TC_RED);
								printf("Password is too weak!\n");
								setTextColor(stdout, TC_LIGHTGRAY);
								frepeat = 0;
							}
							else if (frepeat)
							{
								setTextColor(stdout, TC_RED);
								printf("Passwords are not match.\n");
								setTextColor(stdout, TC_LIGHTGRAY);
								frepeat = 0;
							}
							printf("So lets change your password what is your new password:\n");
							setTextColor(stdout, TC_BLACK);
							gets_s(chpass);
							setTextColor(stdout, TC_LIGHTGRAY);
							if ((passsterngth(chpass)) < 33)
							{
								frepeat = 2;
								continue;
							}
							printf("to ensure please enter new password again:\n");
							setTextColor(stdout, TC_BLACK);
							gets_s(chpassrep);
							setTextColor(stdout, TC_LIGHTGRAY);
							if ((strcmp(chpass, chpassrep)))
							{
								frepeat = 1;
								continue;
							}
							else
							{
								strcpy(user[currentid].password, chpass);
								user[currentid].passstrength = passsterngth(chpass);
								SetCurrentDirectory(filepath);
								fptr = fopen("users.bin", "wb");
								fwrite(&user, sizeof(stusr), user[0].tuser+1, fptr);
								fclose(fptr);
								SetCurrentDirectory(cwd);
							}
							break;
						}
					}
					
					else if(!(strcmp(seccommand, user[currentid].username)))//pass user by username
					{
						while (1)
						{
							if (frepeat == 2)
							{
								setTextColor(stdout, TC_RED);
								printf("Password is too weak!\n");
								setTextColor(stdout, TC_LIGHTGRAY);
								frepeat = 0;
							}
							else if (frepeat)
							{
								setTextColor(stdout, TC_RED);
								printf("Passwords are not match.\n");
								setTextColor(stdout, TC_LIGHTGRAY);
								frepeat = 0;
							}
							printf("So lets change your password what is your new password:\n");
							setTextColor(stdout, TC_BLACK);
							gets_s(chpass);
							setTextColor(stdout, TC_LIGHTGRAY);
							if ((passsterngth(chpass)) < 33)
							{
								frepeat = 2;
								continue;
							}
							printf("to ensure please enter new password again:\n");
							setTextColor(stdout, TC_BLACK);
							gets_s(chpassrep);
							setTextColor(stdout, TC_LIGHTGRAY);
							if ((strcmp(chpass, chpassrep)))
							{
								frepeat = 1;
								continue;
							}
							else
							{
								strcpy(user[currentid].password, chpass);
								user[currentid].passstrength = passsterngth(chpass);
								SetCurrentDirectory(filepath);
								fptr = fopen("users.bin", "wb");
								fwrite(&user, sizeof(stusr), user[0].tuser+1, fptr);
								fclose(fptr);
								SetCurrentDirectory(cwd);
							}
							break;
						}
					}
					else//user change other pass
					{
						setTextColor(stdout, TC_RED);
						printf("sorry, You do'nt have permission to do that!\n");
						setTextColor(stdout, TC_LIGHTGRAY);
					}
				}
				continue;
			}
			/////////////////////////////////////////////////////////////////////////////////////
			else if (!(strcmp(command, "chgr")))
			{
				int fchgr = 0;
				int fchgru = 0;
				int k;
				if (currentaccess)
				{
					
					if (!(strcmp(seccommand, "")))
					{
						setTextColor(stdout, TC_RED);
						printf("Please enter user!\n");
						setTextColor(stdout, TC_LIGHTGRAY);
						continue;
					}



					for (int i = 0; i <= (user[0].tuser) - 1; i++)
					{

						if (!(strcmp(seccommand, user[i].username)))
						{
							k = i;
							
							if (user[i].access == 1)
							{
								fchgr = 1;
							}
							else if (user[i].passstrength < 75)
							{
								fchgr = 2;
							}
							else if (user[i].wrongcommand > 10)
							{
								fchgr = 3;
							}
							else
							{
								user[i].access = 1;
								fchgru = 1;
								SetCurrentDirectory(filepath);
								fptr = fopen("users.bin", "wb");
								fwrite(&user, sizeof(stusr), user[0].tuser + 1, fptr);
								fclose(fptr);
								SetCurrentDirectory(cwd);
							}
							break;
						}
					}
					///////////////
					if (fchgru)
					{
						fuserpass = 0;
						setTextColor(stdout, TC_GREEN);
						printf("Changing access of %s is done!\n",user[k].username);
						setTextColor(stdout, TC_LIGHTGRAY);


					}
					if (fchgr==1)
					{
						setTextColor(stdout, TC_RED);
						printf("sorry, %s was admin!\n",user[k].username);
						setTextColor(stdout, TC_LIGHTGRAY);
					}
					else if (fchgr == 2)
					{
						setTextColor(stdout, TC_RED);
						printf("sorry, %s password is too weak! (it must be upper that 75%) \n", user[k].username);
						setTextColor(stdout, TC_LIGHTGRAY);
					}
					else if (fchgr == 3)
					{
						setTextColor(stdout, TC_RED);
						printf("sorry, %s has more than 10 wrong commands!\n", user[k].username);
						setTextColor(stdout, TC_LIGHTGRAY);
					}
					else if (fchgru==0)//error of wrong username
					{
						setTextColor(stdout, TC_RED);
						printf("Username Not found!\n");
						setTextColor(stdout, TC_LIGHTGRAY);
						continue;
					}




				}







				else//user access eror
				{
					setTextColor(stdout, TC_RED);
					printf("sorry, You do'nt have permission to do that!\n");
					setTextColor(stdout, TC_LIGHTGRAY);
				}



				continue;
			}

			/////////////////////////////////////////////////////////////////////////////////////
			else if (!(strcmp(command, "mkdir")))
			{
				for (int i = 6, co = 0; i<=strlen(badcommand); i++, co++)
				{
					seccommand[co] = badcommand[i];
				}
				mkdir(seccommand);
				chdir(seccommand);
				FILE *fpf;
				fpf = fopen("files.bin", "wb");
				fclose(fpf);

				chdir("..");
				strcpy(myflies[0].name, seccommand);
				myflies[0].tfile = 1;
				strcpy(myflies[0].filemaker,currentuser);
				myflies[0].timeaccess[0] = tm.tm_year + 1900;
				myflies[0].timeaccess[1] = tm.tm_mon + 1;
				myflies[0].timeaccess[2] = tm.tm_mday;
				myflies[0].timeaccess[3] = tm.tm_hour;
				myflies[0].timeaccess[4] = tm.tm_min;
				fpf = fopen("files.bin", "ab");
				fwrite(&myflies[0], sizeof(stfl), 1, fpf);
				fclose(fpf);
				continue;
			}
			/////////////////////////////////////////////////////////////////////////////////////
			else if (!(strcmp(command, "cd")))
			{
				for (int i = 3, co = 0; i <= strlen(badcommand); i++, co++)
				{
					seccommand[co] = badcommand[i];
				}
				SetCurrentDirectory(seccommand);
				if(!currentaccess)
				{
					getcwd(wherewanttogo, sizeof(wherewanttogo));
					if (!(strstr(wherewanttogo, currentuser)))
					{
						setTextColor(stdout, TC_RED);
						printf("sorry, You do'nt have permission to do that!\n");
						setTextColor(stdout, TC_LIGHTGRAY);
						SetCurrentDirectory(cwd);
					}
						
					
						

				}
				/*int fchf = 0;
				if (!(strcmp(seccommand, "..")))
				{
					chdir("..");
					howmanyfolderforward--;
					int co = 0;
					for (int i = 0; currentpath[i] != '\0'; i++)
					{
						if (currentpath[i] == '/')
						{
							co++;
						}
						if (co > howmanyfolderforward)
						{
							currentpath[i + 1] = '\0';
						}
					}

				}
				else
				{
					//opendir(seccommand);
					fchf=chdir(seccommand);
					if (fchf == 0)
					{
						howmanyfolderforward++;
						strcat(currentpath, seccommand);
						strcat(currentpath, "/");

					}
					else
					{
						setTextColor(stdout, TC_RED);
						printf("sorry, %s does Not exit!\n",seccommand);
						setTextColor(stdout, TC_LIGHTGRAY);
					}
				}
				continue;*/
			}
			/////////////////////////////////////////////////////////////////////////////////////
			else if (!(strcmp(command, "back")))
			{
				if (currentaccess)
				{
					SetCurrentDirectory(filepath);
				}
				else 
				{
					setTextColor(stdout, TC_RED);
					printf("sorry, You do'nt have permission to do that!\n");
					setTextColor(stdout, TC_LIGHTGRAY);
				}
			}
			/////////////////////////////////////////////////////////////////////////////////////
			else if (!(strcmp(command, "ls")))
			{
				if (!(strcmp(seccommand, "")))
				{
					/*DIR *d;
					struct dirent *dir;
					d = opendir(".");
					if (d) {
						int i = 0;
						while ((dir = readdir(d)) != NULL) {
							if (i < 2)
							{
								i++;
								continue;
							}
							printf("%s\n", dir->d_name);
						}
						closedir(d);
					}*/
					system("dir /b");
				}
				else if (!(strcmp(seccommand, "-hide")))
				{
					system("dir /b /a");
				}
				continue;
				
			}
			/////////////////////////////////////////////////////////////////////////////////////
			else if (!(strcmp(command, "exif")))
			{
				for (int i = 5, co = 0; i <= strlen(badcommand); i++, co++)
				{
					seccommand[co] = badcommand[i];
				}
				char com[100];
				char f = 0;
				strcpy(com, seccommand);
				strcat(com, ".txt");

					
					//printf("\n");
					FILE *fpf;
					fpf = fopen("files.bin", "rb");
					while (!feof(fpf))
					{
						fread(&myflies[0], sizeof(stfl), 1, fpf);
						if (!(strcmp(myflies[0].name, com)) || !(strcmp(myflies[0].name, seccommand)))
						{
							if (myflies[0].tfile == -1)
							{
								continue;
							}
							f = 1;
							break;
						}
					}
					if(f)
					{
						setTextColor(stdout, TC_YELLOW);
						printf("file location is:\n");
						system("echo %cd%");
						setTextColor(stdout, TC_LIGHTGRAY);

						printf("%-30s%-30s%s", "file name", "user", "data modified\n");
						printf("%-30s%-30s%d/%d/%d  %d:%d", myflies[0].name, myflies[0].filemaker, myflies[0].timeaccess[0], myflies[0].timeaccess[1], myflies[0].timeaccess[2], myflies[0].timeaccess[3], myflies[0].timeaccess[4]);
						printf("\n");
					
					}
					else
					{
						setTextColor(stdout, TC_RED);
						printf("file not found!\n");
						setTextColor(stdout, TC_LIGHTGRAY);
					}

				
				continue;
			}
			/////////////////////////////////////////////////////////////////////////////////////
			
			else if (!(strcmp(seccommand, ">")))
			{
				
				FILE *fp;
				char filechecker[200];
				strcpy(filechecker, command);
				strcat(filechecker, ".txt");
				char complitefilename[200];
				strcpy(complitefilename, thcommand);
				strcat(complitefilename, ".txt");
				fptr = fopen(filechecker, "r");
				
				if (fptr == NULL)//if first command is'nt file
				{
					
					fp = fopen(complitefilename, "w");
					fprintf(fp, "%s", command);
					fclose(fp);



					FILE *fpf;
					strcpy(myflies[0].name, complitefilename);
					myflies[0].tfile = 1;
					strcpy(myflies[0].filemaker, currentuser);
					myflies[0].timeaccess[0] = tm.tm_year + 1900;
					myflies[0].timeaccess[1] = tm.tm_mon + 1;
					myflies[0].timeaccess[2] = tm.tm_mday;
					myflies[0].timeaccess[3] = tm.tm_hour;
					myflies[0].timeaccess[4] = tm.tm_min;
					fpf = fopen("files.bin", "ab");
					fwrite(&myflies[0], sizeof(stfl), 1, fpf);
					fclose(fpf);



				}
				else//if first command is file
				{
					fclose(fptr);
					fptr = fopen(filechecker, "r");
					char alpha;
					fp = fopen(complitefilename, "w");

					while (!(feof(fptr)))
					{
						alpha = fgetc(fptr);
						if (alpha == -1)
						{
							continue;
						}
						fprintf(fp, "%c", alpha);
					}
					fclose(fp);
					fclose(fptr);
					///////////////////////////////////////////
					FILE *fpf;
					strcpy(myflies[0].name, complitefilename);
					myflies[0].tfile = 1;
					strcpy(myflies[0].filemaker, currentuser);
					myflies[0].timeaccess[0] = tm.tm_year + 1900;
					myflies[0].timeaccess[1] = tm.tm_mon + 1;
					myflies[0].timeaccess[2] = tm.tm_mday;
					myflies[0].timeaccess[3] = tm.tm_hour;
					myflies[0].timeaccess[4] = tm.tm_min;
					fpf = fopen("files.bin", "ab");
					fwrite(&myflies[0], sizeof(stfl), 1, fpf);
					fclose(fpf);
				}
				continue;
			}
			/////////////////////////////////////////////////////////////////////////////////////
			else if (!(strcmp(seccommand, ">>")))
			{
				FILE *fp;
				char filechecker[200];
				strcpy(filechecker, command);
				strcat(filechecker, ".txt");
				char complitefilename[200];
				strcpy(complitefilename, thcommand);
				strcat(complitefilename, ".txt");
				fptr = fopen(filechecker, "r");

				if (fptr == NULL)//if first command is'nt file
				{

					fp = fopen(complitefilename, "a");
					fprintf(fp, "%s", command);
					fclose(fp);



					FILE *fpf;
					
					strcpy(myflies[0].name, complitefilename);
					myflies[0].tfile = 1;
					strcpy(myflies[0].filemaker, currentuser);
					myflies[0].timeaccess[0] = tm.tm_year + 1900;
					myflies[0].timeaccess[1] = tm.tm_mon + 1;
					myflies[0].timeaccess[2] = tm.tm_mday;
					myflies[0].timeaccess[3] = tm.tm_hour;
					myflies[0].timeaccess[4] = tm.tm_min;
					fpf = fopen("files.bin", "ab");
					fwrite(&myflies[0], sizeof(stfl), 1, fpf);
					fclose(fpf);



				}
				else//if first command is file
				{
					fclose(fptr);
					fptr = fopen(filechecker, "r");
					char alpha;
					fp = fopen(complitefilename, "a");

					while (!(feof(fptr)))
					{
						alpha = fgetc(fptr);
						if (alpha == -1)
						{
							continue;
						}
						fprintf(fp, "%c", alpha);
					}
					fclose(fp);
					fclose(fptr);
					///////////////////////////////////////////
					FILE *fpf;
					strcpy(myflies[0].name, complitefilename);
					myflies[0].tfile = 1;
					strcpy(myflies[0].filemaker, currentuser);
					myflies[0].timeaccess[0] = tm.tm_year + 1900;
					myflies[0].timeaccess[1] = tm.tm_mon + 1;
					myflies[0].timeaccess[2] = tm.tm_mday;
					myflies[0].timeaccess[3] = tm.tm_hour;
					myflies[0].timeaccess[4] = tm.tm_min;
					fpf = fopen("files.bin", "ab");
					fwrite(&myflies[0], sizeof(stfl), 1, fpf);
					fclose(fpf);
				}
				continue;
			}
			/////////////////////////////////////////////////////////////////////////////////////
			else if (!(strcmp(command, "cat")))
			{
				for (int i = 4, co = 0; i <= strlen(badcommand); i++, co++)
				{
					seccommand[co] = badcommand[i];
				}
				char complitefilename[200];
				strcpy(complitefilename, seccommand);
				strcat(complitefilename, ".txt");

				char alpha;
				fptr = fopen(complitefilename, "r");
				if (fptr == NULL) {
					setTextColor(stdout, TC_RED);
					printf("%s does Not exit!\n", complitefilename);
					setTextColor(stdout, TC_LIGHTGRAY);
				}
				else
				{
					while (!(feof(fptr)))
					{
						alpha = fgetc(fptr);
						printf("%c", alpha);
					}

					printf("\n");
					fclose(fptr);
				}
			}
			////////////////////////////////////////////////////////////////////////////////////////
			else if (!(strcmp(command, "rm")))
			{
				
				if (!(strcmp(seccommand, "-r")))
				{
					char rempath[200];
					strcpy(rempath, "rmdir /S "); 
					for (int i = 6, co = 0; i <= strlen(badcommand); i++, co++)
					{
						thcommand[co] = badcommand[i];
					}
					strcat(rempath, thcommand);
					system(rempath);
					
					FILE *fpf;
					fpf = fopen("files.bin", "rb");
					fread(&myflies, sizeof(stfl), 20, fpf);
					fclose(fpf);
					for (int i = 0; i < 20; i++)
						{
							if (!(strcmp(myflies[i].name, thcommand)))
							{
								myflies[i].tfile = -1;
								break;
							}
						}
					fpf = fopen("files.bin", "wb");
					fread(&myflies, sizeof(stfl), 20, fpf);
					fclose(fpf);
						
					
				}
				else 
				{
					for (int i = 3, co = 0; i <= strlen(badcommand); i++, co++)
					{
						seccommand[co] = badcommand[i];
					}
					if (remove(seccommand) == 0)
					{
						setTextColor(stdout, TC_GREEN);
						printf("Deleted successfully!\n");
						setTextColor(stdout, TC_LIGHTGRAY);
						FILE *fpf;
						fpf = fopen("files.bin", "rb");
						fread(&myflies, sizeof(stfl), 20, fpf);
						fclose(fpf);
						for (int i = 0; i < 20; i++)
						{
							if (!(strcmp(myflies[i].name, thcommand)))
							{
								myflies[i].tfile = -1;
							}
						}
						fpf = fopen("files.bin", "wb");
						fread(&myflies, sizeof(stfl), 20, fpf);
						fclose(fpf);
					}

					else
					{
						setTextColor(stdout, TC_RED);
						printf("Unable to delete the file!\n");
						setTextColor(stdout, TC_LIGHTGRAY);
					}
				}
				continue;
			}
			////////////////////////////////////////////////////////////////////////////////////////
			else if (!(strcmp(command, "cp")))
			{
				char cppath[500]="copy ";
				int co = 5;
				for (int i = 3; i <= strlen(badcommand); i++, co++)
				{
					cppath[co] = badcommand[i];
				
				}
				system(cppath);
				continue;
			}
			////////////////////////////////////////////////////////////////////////////////////////
			else if (!(strcmp(command, "mv")))
			{
				char mvpath[500] = "move ";
				int co = 5;
				for (int i = 3; i <= strlen(badcommand); i++, co++)
				{
					mvpath[co] = badcommand[i];

				}
				system(mvpath);
				continue;
			}

			//////////////////////////////%%%%%%%%%%%%  my text editor  %%%%%%%%%%%%%%%%%%//////////////////////////////////////////////////////////
			else if (!(strcmp(command, "myeditor")))
			{
				char openingname[100];
				int cerx = 0;
				int cery = 1;
				int mood = 1;
				char filename[100];
				int startofshow = 0;
				char editorshow [higheditorshow][widtheditorshow];
				char editor[higheditorshow*3][widtheditorshow];
				char alpha=0;
				/*for (int i = 0; i < higheditorshow; i++)
				{
					for (int j = 0; j < widtheditorshow; j++)
					{
						editorshow[i][j] = 32;
					}
					editor[i][widtheditorshow - 1] = '\n';
				}
				for (int i = 0; i < higheditorshow*3; i++)
				{
					for (int j = 0; j < widtheditorshow; j++)
					{
						editor[i][j] = 32;
					}
					editor[i][widtheditorshow - 1] = '\n';
				}*/
				for (int i = 9, co = 0; i <= strlen(badcommand); i++, co++)
				{
					seccommand[co] = badcommand[i];
				}


			openinglabel:

				if (!(strcmp(seccommand, "")))
				{
					strcpy(filename, "Newtext.txt");
					for (int i = 0; i < higheditorshow * 3; i++)
					{
						for (int j = 0; j < widtheditorshow - 1; j++)
						{
							editor[i][j] = 0;
						}
						editor[i][widtheditorshow - 1] = '\n';

					}
				}

				else
				{
					char sectxt[100];
					strcpy(sectxt, seccommand);
					strcat(sectxt, ".txt");
					fptr = fopen(sectxt, "r");
					if (fptr == NULL)
					{
						strcpy(filename, seccommand);
						strcat(filename, ".txt");
						for (int i = 0; i < higheditorshow * 3; i++)
						{
							for (int j = 0; j < widtheditorshow - 1; j++)
							{
								editor[i][j] = 0;
							}
							editor[i][widtheditorshow - 1] = '\n';
						}

					}

					else
					{
						strcpy(filename, sectxt);
						for (int i = 0; i < higheditorshow * 3; i++)
						{
							for (int j = 0; j < widtheditorshow; j++)
							{
								editor[i][j] = 0;
							}
							editor[i][widtheditorshow - 1] = '\n';
						}

						int i = 0;
						while (i<(higheditorshow*3-1))
						{

							//for (int i = 0; i < higheditorshow * 3; i++)
							//{
								//for (int j = 0; j < widtheditorshow - 1; j++)
								//{
									//alpha = fgetc(fptr);
							int j = 0;
							alpha = 0;
							while (alpha != '\n')
							{
								alpha = fgetc(fptr);
								editor[i][j] = alpha;
								j++;
								if (j > widtheditorshow - 1)
								{
									break;
								}
							}


							//}
							editor[i][widtheditorshow - 1] = '\n';
							i++;
						}



						fclose(fptr);
					}
				}
				
				////////////////////////////////////////////////////show page
				

				while (1)
				{
					system("cls");
					setTextColor(stdout, TC_LIGHTBLUE);
					printf("%s               MYeditor\n", filename);
					setTextColor(stdout, TC_LIGHTGRAY);
					////////////////////////////////////////////////////////////////////////////////
					for (int i = 0,x=startofshow;i<higheditorshow; i++,x++)
					{
						int j = 0;
						for (;editor[x][j]!='\n'; j++)
						{
							editorshow[i][j] = editor[x][j];
						}
						editorshow[x][j] = '\n';
					}
					/////////////////////////////////////////
					for (int i = 0; i < higheditorshow; i++)
					{
						for (int j = 0; editorshow[i][j] != '\n'; j++)
						{
							printf("%c", editorshow[i][j]);
						}
						printf("\n");
					}
					//////////toll box
					setTextColor(stdout, TC_LIGHTMAGENTA);
					
					

					printf("______________________________________________\n");
					if (mood == 1)
					{
						printf(" ctrl+R: open file      ctrl+S: save file     ctrl+E: exit    ctrl+F: search\n");
						printf(" select text & press enter: copy text               righ click: paste text  \n");
						setTextColor(stdout, TC_CYAN);
						printf(" to turn on select mode in your consol please right click on the top of \n your consol and go to \"propertise\" and enable \"Quick Edit Mode\". \n");
						setTextColor(stdout, TC_LIGHTMAGENTA);
					}
					else if (mood == 2)
					{
						mood = 1;
						cerx = 0;
						cery = 1;
						printf("enter name of file:");
						gets_s(openingname);
						strcpy(seccommand, openingname);
						goto openinglabel;

					}
					else if (mood == 3)
					{
						printf("enter name of file:");
						gets_s(filename);
						strcat(filename, ".txt");
						fptr = fopen(filename, "w");
						for (int i = 0; i < (3 * higheditorshow) - 1; i++)
						{
							for (int j = 0; editor[i][j] != '\n'; j++)
							{
								fprintf(fptr, "%c", editor[i][j]);

							}
							fprintf(fptr, "\n");

						}
						fclose(fptr);
						FILE *fpf;

						strcpy(myflies[0].name, filename);
						myflies[0].tfile = 1;
						strcpy(myflies[0].filemaker, currentuser);
						myflies[0].timeaccess[0] = tm.tm_year + 1900;
						myflies[0].timeaccess[1] = tm.tm_mon + 1;
						myflies[0].timeaccess[2] = tm.tm_mday;
						myflies[0].timeaccess[3] = tm.tm_hour;
						myflies[0].timeaccess[4] = tm.tm_min;
						fpf = fopen("files.bin", "ab");
						fwrite(&myflies[0], sizeof(stfl), 1, fpf);
						fclose(fpf);

						setTextColor(stdout, TC_LIGHTGREEN);
						printf("file save successfully!");
						mood = 1;
						cerx = 0;
						cery = 1;
					}
					else if (mood == 4)
					{
						fptr = fopen(filename, "w");
						for (int i = 0; i < (3 * higheditorshow) - 1; i++)
						{
							for (int j = 0; editor[i][j] != '\n'; j++)
							{
								fprintf(fptr, "%c", editor[i][j]);

							}
							fprintf(fptr, "\n");

						}
						fclose(fptr);
						FILE *fpf;

						strcpy(myflies[0].name, filename);
						myflies[0].tfile = 1;
						strcpy(myflies[0].filemaker, currentuser);
						myflies[0].timeaccess[0] = tm.tm_year + 1900;
						myflies[0].timeaccess[1] = tm.tm_mon + 1;
						myflies[0].timeaccess[2] = tm.tm_mday;
						myflies[0].timeaccess[3] = tm.tm_hour;
						myflies[0].timeaccess[4] = tm.tm_min;
						fpf = fopen("files.bin", "ab");
						fwrite(&myflies[0], sizeof(stfl), 1, fpf);
						fclose(fpf);

						setTextColor(stdout, TC_LIGHTGREEN);
						printf("file save successfully!");
						mood = 1;
						cerx = 0;
						cery = 1;
					}
					else if (mood == 5)
					{
						char yn;
						mood = 1;
						printf("Are you sure you want to exit? (Y/n)");
						scanf("%c", &yn);
						if (yn == 'n')
						{
							getchar();
							continue;
						}
						else
						{
							printf("do you want to save the file? (Y/n)");
							scanf("%c", &yn);
							if (yn == 'n')
							{
								getchar();
								break;
							}
							else
							{
								getchar();
								if (filename[0] == 'N'&&filename[1] == 'e')
								{
									getchar();
									printf("enter name of file:");
									gets_s(filename);
									strcat(filename, ".txt");
									fptr = fopen(filename, "w");
									for (int i = 0; i < (3 * higheditorshow) - 1; i++)
									{
										for (int j = 0; editor[i][j] != '\n'; j++)
										{
											fprintf(fptr, "%c", editor[i][j]);

										}
										fprintf(fptr, "\n");

									}
									fclose(fptr);
									FILE *fpf;

									strcpy(myflies[0].name, filename);
									myflies[0].tfile = 1;
									strcpy(myflies[0].filemaker, currentuser);
									myflies[0].timeaccess[0] = tm.tm_year + 1900;
									myflies[0].timeaccess[1] = tm.tm_mon + 1;
									myflies[0].timeaccess[2] = tm.tm_mday;
									myflies[0].timeaccess[3] = tm.tm_hour;
									myflies[0].timeaccess[4] = tm.tm_min;
									fpf = fopen("files.bin", "ab");
									fwrite(&myflies[0], sizeof(stfl), 1, fpf);
									fclose(fpf);


								}
								else
								{
									getchar();
									fptr = fopen(filename, "w");
									for (int i = 0; i < (3 * higheditorshow) - 1; i++)
									{
										for (int j = 0; editor[i][j] != '\n'; j++)
										{
											fprintf(fptr, "%c", editor[i][j]);

										}
										fprintf(fptr, "\n");

									}
									fclose(fptr);
									FILE *fpf;

									strcpy(myflies[0].name, filename);
									myflies[0].tfile = 1;
									strcpy(myflies[0].filemaker, currentuser);
									myflies[0].timeaccess[0] = tm.tm_year + 1900;
									myflies[0].timeaccess[1] = tm.tm_mon + 1;
									myflies[0].timeaccess[2] = tm.tm_mday;
									myflies[0].timeaccess[3] = tm.tm_hour;
									myflies[0].timeaccess[4] = tm.tm_min;
									fpf = fopen("files.bin", "ab");
									fwrite(&myflies[0], sizeof(stfl), 1, fpf);
									fclose(fpf);

								}
								system("cls");
								break;
							}
						}
					}
					else if (mood == 6)
					{
						mood = 1;
						char searchstr[100];
						char *spt;
						int fsearch = 0;
						printf("searching:");
						gets_s(searchstr);
						for (int i = 0; i < (higheditorshow * 3) - 1; i++)
						{
							spt= strstr(editor[i], searchstr);
							if (spt)
							{
								printf("what you searched found in line :%d", i + 1);
								fsearch = 1;
								cerx = 0;
								cery = i+1;
							}
						}
						if (!fsearch)
						{
							setTextColor(stdout, TC_RED);
							printf("No results found!!");
							cerx = 0;
							cery = 1;
						}
					}
					setTextColor(stdout, TC_LIGHTGRAY);
					//////////////////get command
					
					gotoxy(cerx, cery);
		
					char fun = getch();
					////////////cursor movement
					if (fun == -32)
					{
						fun = getch();
						if (fun == 77) //(right press)
						{
							cerx++;
							if (cerx > widtheditorshow-2)
							{
								cerx = 0;
								fun=80;
							}
						}


						if (fun == 75) //(left press)
						{
							cerx--;
							if (cerx < 0)
							{
								cerx = widtheditorshow-2;
								fun = 72;
							}
						}
						
						
						
						if (fun == 72) ////(up press)
						{
							cery--;
							if (cery < 1)
							{
								startofshow--;
								if (startofshow < 0)
								{
									startofshow++;
									cery++;
								}
							}
							
						}



						if (fun == 80) ////(down press)
						{
							cery++;
							if (cery > higheditorshow)
							{
								startofshow++;
								cery--;
							}
						}
						
					}//end of cursor movement
					else if (fun == 18)////ctrl + R ( open file)
					{
						gotoxy(19, 51);
						mood = 2;
					}


					else if (fun == 19)////ctrl + S ( save file)
					{
						if (filename[0] == 'N'&&filename[1] == 'e')
						{
							gotoxy(18, 51);
							mood = 3;
						}
						else
						{
							gotoxy(0, 51);
							mood = 4;
						}
					}
					else if (fun == 5)////ctrl + E ( exit)
					{
						gotoxy(36, 51);
						mood = 5;
					}
					else if (fun == 6)////ctrl + F ( search)
					{
						gotoxy(10, 51);
						mood = 6;
					}
					else if (fun == 3)////ctrl + C ( copy )
					{

					}
					else if (fun == 22)////ctrl + V ( paste)
					{

					}
					else if (fun == 8)//backspace *
					{
						cerx--;
						editor[cery + startofshow - 1][cerx] = 32;


					}
					else if (fun == 13)//enter *
					{
						editor[cery + startofshow - 1][cerx] = '\n';
						cerx = 0;
						cery++;


					}

					else if (fun >= 32 && fun <= 127)
					{
						editorshow[cery - 1][cerx] = fun;
						editor[cery + startofshow - 1][cerx] = fun;
						cerx++;
						if (cerx > widtheditorshow - 2)
						{
							cerx = 0;
							cery++;
							if (cery > higheditorshow)
							{
								startofshow++;
								cery--;
							}
						}
					}


				}
				continue;
			}
			////////////////////////////////////////////////////////////////////////////////////////

			else if (!(strcmp(command, "help")))
			{
				/*for (int i = 5, co = 0; i <= strlen(badcommand); i++, co++)
				{
					seccommand[co] = badcommand[i];
				}*/
				setTextColor(stdout, TC_LIGHTGREEN);
				if (!(strcmp(seccommand, "")))
				{
					setTextColor(stdout, TC_LIGHTCYAN);
					printf("                    NEOS CONSOL\n");
					setTextColor(stdout, TC_LIGHTGREEN);
					printf("-LOGIN :for login you need to have username and password \n");
					printf("\t #there is a defualt user on system with username:admin\n");
					printf("\t #every user has time access to system which set by admin of system\n");
					printf("\t #we have two type of users 1.administirators of system \n\t& 2.user of system \n");
					printf("\t #admins have green color in system with * befor they name . \n");
					printf("\t #users have blue color in system. \n");
					printf("\n");
					printf("\n");
					printf("-su (su \"username\"):this command used to change user of system\n");
					printf("\t #admnis don't need to enter password for login other users accounts.\n");
					printf("\n"); 
					printf("\n");
					printf("-passwd :you can use this command to change your password.\n");
					printf("\t #admnis can change all users password.(passwd \"username\")\n");
					printf("\t #all user must have a password stronger than 33\% \n");
					printf("\t\t in password:\n");
					printf("\t\t lowercase add: 2\% to password strong\n");
					printf("\t\t uppercase add: 4\% to password strong\n");
					printf("\t\t numbers add: 3\% to password strong\n");
					printf("\t\t puncats add: 8\% to password strong\n");
					printf("\t\t space add: 1\% to password strong\n");
					printf("\t #admnis can change time access of users with \n\t(passwd -l \"year\" \"month\" \"day\" \"username\") command\n");
					printf("\n");
					printf("\n");
					printf("-create user: this command use to create ne user in your consol.\n");
					printf("\t #just admins can use this command\n");
					printf("\n");
					printf("\n");
					printf("-chgr: this command can use to change users access (user -> admin ).\n");
					printf("\t #just admins can use this command\n");
					printf("\t #for changin access of user user must: \n");
					printf("\t\t *have password stronger than %75 \n");
					printf("\t\t *be user \"admins are admin!!  :) \" \n");
					printf("\t\t *wrong command of user must be lower than 10 \n");
					printf("\n");
					printf("\n");
					printf("-cd : it uses to change directory.\n");
					printf("\t #use \" cd .. \" to pervious directory,\n");
					printf("\t #the adress of directory could be absolute or relative \n");
					printf("\n");
					printf("\n");
					printf("-pwd :it shows you current working directory.\n");
					printf("\t #(\"pwd -l \") can be use to show you short form of \n\t current working directory.\n");
					printf("\n");
					printf("\n");
					printf("-mkdir :this command use to make a new directory.(\"mkdir [name of new folder] \")\n");
					printf("\n");
					printf("\n");
					printf("- > \"first > secend\" : you can write \"first\" in \"secend\" file.\n \t (don't need .txt at the end of file)\n");
					printf("\t #\"first\" could be a file name and > rewrite \n \t \"first file \" in \"secend file\"\n");
					printf("\n");
					printf("\n");
					printf("- >> \"first >> secend\" : you can append \n \t \"first\" in \"secend\" file.\n \t(don't need .txt at the end of file)\n");
					printf("\t #\"first\" could be a file name and >> append \"first file \" in \"secend file\"\n");
					printf("\n");
					printf("\n");
					printf("-cat (cat filename):this command read the file for you (don't need .txt at the end of file) \n");
					printf("\n\n");
					printf("-rm (rm filename) :use it when you want to remove a file.\n");
					printf("\t #for removing directories please use (rm -r dirname) .\n");
					printf("\n\n");
					printf("-cp (cp \"file1\" \"file2\") :use this command to copy file \n \t from \"file1\" to \"file2\".\n");
					printf("\t #\"file1\" & \"file2\" could be address of file.\n");
					printf("\n\n");
					printf("-mv (mv \"file1\" \"file2\") :use this command to move file \n \t from \"file1\" to \"file2\".\n");
					printf("\t #\"file1\" & \"file2\" could be address of file.\n");
					printf("\n\n");
					printf("-ls : it list files & directories for you.\n");
					printf("\t #use (ls -hide) to show hide files too.\n");

					printf("\n\n");
					printf("-exif (exif filename): show information of file : creator of file ,path and\n \t when it make.\n");
					printf("\n\n");
					printf("-myeditor:just a simple & useful text editor will be open.\n");
					printf("\n\n");
					printf("-wc (wc filename):show number of lines and letters of your file \n \t (don't need .txt in your file name).\n");
					printf("\n\n");
					printf("-diff (diff file1 file2): show you two file are diffrent or they are similar \n \t (don't need .txt in your file name).\n");
					printf("\n\n");
					printf("-search (search filename or dirname): looking for a file this \n \t command find it for you and show the path.\n");
					printf("\n\n");
					printf("-hide (hide filename) : use it for hiding files.\n \t (don't need .txt in your file name)\n");
					printf("\t #make your file visible with (hide -off filename)");
					printf("\n\n");
					printf("-help :need a help this command will help you.\n");
					printf("\t #you can see help for each command with (help \"command\").\n");
					printf("\n");
					printf("**************  developed by : Mohammad Mahdi Barghi  **************");
					printf("\n\n");
				}
				else if (!(strcmp(seccommand, "login")))
				{
					printf("-LOGIN :for login you need to have username and password \n");
					printf("\t #there is a defualt user on system with username:admin\n");
					printf("\t #every user has time access to system which set by admin of system\n");
					printf("\t #we have two type of users 1.administirators of system \n\t& 2.user of system \n");
					printf("\t #admins have green color in system with * befor they name . \n");
					printf("\t #users have blue color in system. \n");
				}
				else if (!(strcmp(seccommand, "su")))
				{
					printf("-su (su \"username\"):this command used to change user of system\n");
					printf("\t #admnis don't need to enter password for login other users accounts.\n");
					
					
				}
				else if (!(strcmp(seccommand, "passwd")))
				{
					printf("-passwd :you can use this command to change your password.\n");
					printf("\t #admnis can change all users password.(passwd \"username\")\n");
					printf("\t #all user must have a password stronger than 33\% \n");
					printf("\t\t in password:\n");
					printf("\t\t lowercase add: 2\% to password strong\n");
					printf("\t\t uppercase add: 4\% to password strong\n");
					printf("\t\t numbers add: 3\% to password strong\n");
					printf("\t\t puncats add: 8\% to password strong\n");
					printf("\t\t space add: 1\% to password strong\n");
					printf("\t #admnis can change time access of users with \n\t(passwd -l \"year\" \"month\" \"day\" \"username\") command\n");

				}
				else if (!(strcmp(seccommand, "create user")))
				{
					printf("-create user: this command use to create ne user in your consol.\n");
					printf("\t #just admins can use this command\n");
					
					
				}
				else if (!(strcmp(seccommand, "chgr")))
				{
					printf("-chgr: this command can use to change users access (user -> admin ).\n");
					printf("\t #just admins can use this command\n");
					printf("\t #for changin access of user user must: \n");
					printf("\t\t *have password stronger than %75 \n");
					printf("\t\t *be user \"admins are admin!!  :) \" \n");
					printf("\t\t *wrong command of user must be lower than 10 \n");
				}
				else if (!(strcmp(seccommand, "cd")))
				{
					printf("-cd : it uses to change directory.\n");
					printf("\t #use \" cd .. \" to pervious directory,\n");
					printf("\t #the adress of directory could be absolute or relative \n");
					
					
				}
				else if (!(strcmp(seccommand, "pwd")))
				{
					printf("-pwd :it shows you current working directory.\n");
					printf("\t #(\"pwd -l \") can be use to show you short form of \n\t current working directory.\n");
					
					
					
				}
				else if (!(strcmp(seccommand, "mkdir")))
				{
					printf("-mkdir :this command use to make a new directory.(\"mkdir [name of new folder] \")\n");

				}
				else if (!(strcmp(seccommand, ">")))
				{
					printf("- > \"first > secend\" : you can write \"first\" in \"secend\" file.\n \t (don't need .txt at the end of file)\n");
					printf("\t #\"first\" could be a file name and > rewrite \n \t \"first file \" in \"secend file\"\n");

				}
				else if (!(strcmp(seccommand, ">>")))
				{
					printf("- >> \"first >> secend\" : you can append \n \t \"first\" in \"secend\" file.\n \t(don't need .txt at the end of file)\n");
					printf("\t #\"first\" could be a file name and >> append \"first file \" in \"secend file\"\n");
					
					
				}
				else if (!(strcmp(seccommand, "cat")))
				{
					printf("-cat (cat filename):this command read the file for you (don't need .txt at the end of file) \n");
					
				}
				else if (!(strcmp(seccommand, "rm")))
				{
					printf("-rm (rm filename) :use it when you want to remove a file.\n");
					printf("\t #for removing directories please use (rm -r dirname) .\n");

					
				}
				else if (!(strcmp(seccommand, "cp")))
				{
					printf("-cp (cp \"file1\" \"file2\") :use this command to copy file \n \t from \"file1\" to \"file2\".\n");
					printf("\t #\"file1\" & \"file2\" could be address of file.\n");
					
					
				}
				else if (!(strcmp(seccommand, "mv")))
				{
					printf("-mv (mv \"file1\" \"file2\") :use this command to move file \n \t from \"file1\" to \"file2\".\n");
					printf("\t #\"file1\" & \"file2\" could be address of file.\n");
					
					
				}
				else if (!(strcmp(seccommand, "ls")))
				{
					printf("-ls : it list files & directories for you.\n");
					printf("\t #use (ls -hide) to show hide files too.\n");

					
				}
				else if (!(strcmp(seccommand, "exif")))
				{
					printf("-exif (exif filename): show information of file : creator of file ,path and\n \t when it make.\n");
					
					
				}
				else if (!(strcmp(seccommand, "myeditor")))
				{
					printf("-myeditor:just a simple & useful text editor will be open.\n");
					
					
				}
				else if (!(strcmp(seccommand, "hide")))
				{
					printf("-hide (hide filename) : use it for hiding files.\n \t (don't need .txt in your file name)\n");
					printf("\t #make your file visible with (hide -off filename)");


				}
				
				else if (!(strcmp(seccommand, "wc")))
				{
					printf("-wc (wc filename):show number of lines and letters of your file \n \t (don't need .txt in your file name).\n");
					
				}
				else if (!(strcmp(seccommand, "diff")))
				{
					printf("-diff : show you two file are diffrent or they are similar \n \t (don't need .txt in your file name).\n");
					
					
					
				}
				else if (!(strcmp(seccommand, "help")))
				{
					printf("-help :need a help this command will help you.\n");
					printf("\t #you can see help for each command with (help \"command\").\n");

				}
				else if (!(strcmp(seccommand, "search")))
				{
					printf("-search : looking for a file in your account this command find it for you ).\n");

				}
				setTextColor(stdout, TC_LIGHTGRAY);
				continue;
			}

			//////////////////////////////////////////////////////////////////////////////////////
			else if (!(strcmp(command, "wc")))
			{
				int tl = 0;
				int tk = 0;
				char alpha = 0;
				char editor[higheditorshow * 3][widtheditorshow];
				for (int i = 3, co = 0; i <= strlen(badcommand); i++, co++)
				{ 
					seccommand[co] = badcommand[i];
				}







				char sectxt[100];
				strcpy(sectxt, seccommand);
				strcat(sectxt, ".txt");
				fptr = fopen(sectxt, "r");
				if (fptr == NULL)
				{
					setTextColor(stdout, TC_RED);
					printf("file not found!\n");
					setTextColor(stdout, TC_LIGHTGRAY);

				}

				else
				{
					

					int i = 0;
					while (i<(higheditorshow * 3) - 1)
					{

						//for (int i = 0; i < higheditorshow * 3; i++)
						//{
						//for (int j = 0; j < widtheditorshow - 1; j++)
						//{
						//alpha = fgetc(fptr);
						int j = 0;
						alpha = 0;
						while (alpha != '\n')
						{
							alpha = fgetc(fptr);
							editor[i][j] = alpha;
							if (alpha >= 33 && alpha <= 126)
							{
								tk++;
								tl = i + 1;
							}
							j++;
							if (j > widtheditorshow - 1)
							{
								break;
							}
						}


						//}
						editor[i][widtheditorshow - 1] = '\n';
						i++;
					}



					fclose(fptr);
				}







				setTextColor(stdout, TC_YELLOW);
				printf("nuber of lines:%d\n",tl);
				printf("nuber of letters:%d\n", tk);
				setTextColor(stdout, TC_LIGHTGRAY);





				continue;
			}
			//////////////////////////////////////////////////////////////////////////////
			else if (!(strcmp(command, "hide")))
			{
				char hidecom[300] = "attrib +h ";
				char showcom[300] = "attrib -h ";
				
				if (!(strcmp(seccommand, "-off")))
				{


					for (int i = 10, co = 0; i <= strlen(badcommand); i++, co++)
					{
						thcommand[co] = badcommand[i];
					}
					strcat(showcom, thcommand);
					strcat(showcom, ".txt");
					system(showcom);

				}
				
				else
				{
					for (int i = 5, co = 0; i <= strlen(badcommand); i++, co++)
					{
						seccommand[co] = badcommand[i];
					}
					strcat(hidecom, seccommand);
					strcat(hidecom, ".txt");
					system(hidecom);
				}
				continue;
			}

			//////////////////////////////////////////////////////////////////////////////////////
			else if (!(strcmp(command, "search")))
			{
				for (int i = 7, co = 0; i <= strlen(badcommand); i++, co++)
				{
					seccommand[co] = badcommand[i];
				}
				char com[300] = "dir /s /b ";
				strcat(com, seccommand);
				system(com);
				continue;
			}
			//////////////////////////////////////////////////////////////////////////////////////
			else if (!(strcmp(command, "diff")))
			{
				int fnotfound = 0;
				char alpha = 0;
				char balpha = 0;
				char editor[higheditorshow * 3][widtheditorshow];
				char neditor[higheditorshow * 3][widtheditorshow];

				char sectxt[100];
				strcpy(sectxt, seccommand);
				strcat(sectxt, ".txt");
				char thtxt[100];
				strcpy(thtxt, thcommand);
				strcat(thtxt, ".txt");
				fptr = fopen(sectxt, "r");
				if (fptr == NULL)
				{
					setTextColor(stdout, TC_RED);
					printf("%s not found!\n",sectxt);
					setTextColor(stdout, TC_LIGHTGRAY);
					continue;
				}

				else
				{
					for (int i = 0; i < widtheditorshow; i++)
					{
						for (int j = 0; j < higheditorshow * 3; j++)
						{
							alpha = fgetc(fptr);
							editor[i][j] = alpha;
						}
					}
					fclose(fptr);
				}
				/////////////////////////////////////////////////////////////////////////////
				fptr = fopen(thtxt, "r");
				if (fptr == NULL)
				{
					setTextColor(stdout, TC_RED);
					printf("%s not found!\n",thtxt);
					setTextColor(stdout, TC_LIGHTGRAY);
					continue;
				}

				else
				{
					for (int i = 0; i < widtheditorshow; i++)
					{
						for (int j = 0; j < higheditorshow * 3; j++)
						{
							alpha = fgetc(fptr);
							neditor[i][j] = alpha;
						}
					}
					fclose(fptr);
				}
			///////////////////////////////////////////////////
				int i = 0;
				for (; i < widtheditorshow; i++)
				{
					for (int j = 0; j < higheditorshow * 3; j++)
					{
						if (editor[i][j] == neditor[i][j])
						{
							continue;
						}
						else
						{
							if (!((editor[i][j] == '\n' && neditor[i][j] == '\n')|| (editor[i][j] == '\n' && neditor[i][j] == 0)|| (editor[i][j] == 0 && neditor[i][j] == 0)|| (editor[i][j] == 0 && neditor[i][j] == '\n')))
							{
								fnotfound = 1;
								break;
							}
						}
					}
					if (fnotfound)
					{
						break;
					}
				}
				if (fnotfound)
				{
					setTextColor(stdout, TC_RED);
					printf("files are different!(first difference is in line %d)\n",i+1);
					setTextColor(stdout, TC_LIGHTGRAY);
				}
				else
				{
					setTextColor(stdout, TC_GREEN);
					printf("files are complitly like each other!\n");
					setTextColor(stdout, TC_LIGHTGRAY);
				}
				continue;
			}
			//////////////////////////////////////////////////////////////////////////////////////
			/*else if (!(strcmp(command, "cda")))
			{
				sscanf(system("echo %cd%") , "%s",currentpath);
				continue;
			}*/
			/////////////////////////////////////////////////////////////////////////////////////
			else {
			
			setTextColor(stdout, TC_RED);
			printf("command not found!\n");
			setTextColor(stdout, TC_LIGHTGRAY);
			user[currentid].wrongcommand++;
			fptr = fopen("users.bin", "wb");
			fwrite(&user, sizeof(stusr), user[0].tuser+1, fptr);
			fclose(fptr);
			}
			continue;
		}//command
		///////////////////////////////////////////////////////////////////////////////////////////////////end of create user


	}///login
	fclose(fptr);
	return 0;
}//end of main