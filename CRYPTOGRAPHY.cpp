#include<iostream>
#include<fstream>
#include<string.h>
#include<conio.h>
#define KEY 25 // Macro to store KEY for Encryption.
using namespace std;
int getFileSize(char*);
char* caesar(char*);
char* transposition(char*);
char* dcrcaesar(char*);
char* getPassword(char* );
char* maskPassword(char*);

int main() 
{
	char fname[80];
	char encfile[80];
	char pw[80], choice = 'Y';
	char* encstring;
	char* dcrstring;
	int srcsize;
	int ch,ch1;
	ifstream src,drc;
	ofstream enc;
	cout<<"\n Enter File name : "; 
	cin.getline(fname,80);
	do
	{
	 system("CLS");
	 strcpy(encfile,fname);
	 strcat(encfile,".enc");
	 src.open(fname);
	 if(!src.good())
	 { 
		cout<<"\n File does not exists";
	 }
	 else
	 {
		srcsize = getFileSize(fname);
		src.seekg(0,ios::beg);
		char* str = new char[srcsize];
		char* encstring = new char[srcsize];
		char* dcrstring = new char[srcsize];
		src.read((char*)str,srcsize);
		cout<<"\n 1. Encryption\n 2. Decryption\n 3. Exit";
		cout<<"\n Enter your choice : ";
		cin>>ch;
		char encmode;
		switch(ch)
		{
			case 1:
				cout<<"\n Enter password : ";
				cin.ignore();
				maskPassword(pw);
				cout<<"\n\n 1. Transposition\n 2. Caesar Cipher";
				cout<<"\n\n Enter your choice of encryption method : ";
				cin>>ch1;
				switch(ch1) //INNER SWITCH
				{
					case 1:
						encstring = transposition(str); //TRANSPOSITION
						encmode = 'T';
						break;
						case 2:
						encstring = caesar(str); //CAESAR CIPHER
						encmode = 'C';
						break;
						default : cout<<"\n Enter proper choice (1/2)";
						exit(1);
				}
				enc.open(encfile);
				enc.seekp(0,ios::beg);
				enc.write((char*)&encmode,1);
				enc.write((char*)"`",1);
				enc.write((char*)&pw,strlen(pw));
				enc.write((char*)"`",1);
				enc.write((char*)encstring,srcsize);
				enc.flush();
				cout<<"\n The encrypted version of your file is :\n\n "<<encstring;
				cout<<"\n\n "<<fname<<" encrypted successfully as "<<encfile;
				break;
				case 2: 
					cout<<"\n Enter password : ";
					cin.ignore();
					maskPassword(pw);
					cout<<"\n Enter file name to decrypt : ";
					gets(encfile);
					drc.open(encfile);
 					if(!drc.good())
					{ 
						cout<<"\n File does not exists";
					}
					else
					{
						srcsize = getFileSize(encfile);
						drc.seekg(0,ios::beg);
						char* str = new char[srcsize];
						char* encstring = new char[srcsize];
						char* dcrstring = new char[srcsize];
						drc.read((char*)str,srcsize);
						if(!strcmp(pw,getPassword(str)))
						{
							 int i,j;
							 for(i=(strlen(pw)+3),j=0; str[i]!='\0'; i++,j++)
						 	 {
								encstring[j] = str[i];
						 	 }
								encstring[j] = '\0';
					 	}
						else
						{
							cout<<"\n Wrong Password.";
							exit(1);
						}
						if(str[0] == 'T')
						{
							cout<<"\n The decrypted text is : "<<"\n"<<transposition(encstring)<<endl;
							//DECRYPTION FOR TRANSPOSITION
						}
						else if(str[0] == 'C')
						{
							cout<<"\n The decrypted text is :"<<"\n"<<dcrcaesar(encstring)<<endl;
							//DECRYPTION FOR CAESAR CIPHER
						}
					}
						cout<<"\n\n "<<encfile<<" has been decrypted successfully";
						drc.close();
						break;
						case 3 :
							cout<<" \n **** PROGRAM TERMINATED!! ****";
							exit(1);
							default : cout<<"\n Enter correct choice(1-3)";
							exit(1);
						}
		}
					cout<<"\n\n Do you want to continue (y/n) : ";
					cin>>choice;
					src.close();
					cin.ignore();
	}while(choice == 'y' || choice == 'Y');
return 0;
}

char* caesar(char* str) 			//CASEAR-CIPHER ENCRYPTION
{
	int i,encsize;
	encsize = strlen(str);
	char* enstr = new char[encsize];
	for(i=0;i<encsize;i++)
	{
		enstr[i] = (str[i] + KEY);
	}
	enstr[i] = '\0';
	return enstr;
}

char* transposition(char* str) 		//TRANSPOSITION ENCRYPTION AND DECRYPTION
{
	int i,j,encsize;
	char temp;
	encsize = strlen(str);
	char* enstr1 = new char[encsize];
	enstr1 = str;
	for(i=0,j=encsize-1;i<j;i++,j--)
	{
		temp = enstr1[i];
		enstr1[i] = enstr1[j];
		enstr1[j] = temp;
	}
	return enstr1;
}

char* dcrcaesar(char* encstring) 	//CASEAR-CIPHER DECRYPTION
{
	int var,i,dcrsize;
	dcrsize = strlen(encstring);
	char* dcrstr = new char[dcrsize];
	for(i=0;i<dcrsize;i++)
	{
		dcrstr[i] = (encstring[i] - KEY);
	}
	dcrstr[i] = '\0';
	return dcrstr;
}

int getFileSize(char* fname) 		//SIZE OF SOURCE FILE
{
	int filesize;
	ifstream src(fname);
	src.seekg(0,ios::end);
	filesize = src.tellg();
	return filesize;
}

char* getPassword(char* str) 		//GET PASSWORD
{
	int i,j;
	char* pw = new char[80];
	for(i=2,j=0;str[i]!='`';i++,j++)
	{
		pw[j] = str[i];
	}
	pw[j] = '\0';
	return pw;
}

char* maskPassword(char* pw) 		//HIDE PASSWORD
{
	int i=0; 
	char ch;
	do
	{
		ch = getch();
		if(ch == 13)
		break;
		cout<<"*";
		pw[i] = ch;
		i++;
	}while(ch != 13);
	return pw;
}

						

