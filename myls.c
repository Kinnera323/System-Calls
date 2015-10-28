#define _GNU_SOURCE
#include <dirent.h>     /* Defines DT_* constants */
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#define handle_error(msg) \
	do { perror(msg); exit(EXIT_FAILURE); } while (0)
int flag1=0,flag2=0,flag3=0,flag4=0;
int hindex=0;
char b[100];int length=0;
char dir[100];
char argu[100];
#define ANSI_COLOR_RED "\x1b[31m" 
#define ANSI_COLOR_GREEN "\x1b[32m" 
#define ANSI_COLOR_YELLOW "\x1b[33m" 
#define ANSI_COLOR_BLUE "\x1b[34m" 
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m" 
#define ANSI_COLOR_RESET "\x1b[0m"
int own_strlen( char a[])
{ 
	int i=0;
	while(a[i] != '\0')
	{
		i = i + 1;
	}
	return i;
}
int stringcmp(char *s, char *t, int n) {
	int check = 0;
	while(n--) {
		if(*s != *t) {
			check = 1;
		}
		else {
			++s;
			++t;
		}
	}
	if(check==0)
	{
		return 0;
	}
	return -1;
	
}
void new_strcpy(char *sor,int x)
{
int i=0;
	if(x==1)
{
	while(1){
		dir[i]=sor[i];
		i++;
		if(sor[i]=='\0')
			break;
	}
}
	if(x==2){
	while(1){
		argu[i]=sor[i];
		i++;
	if(sor[i]=='\0')
		break;
}
}
}
struct linux_dirent {
           long           d_ino;
           off_t          d_off;
           unsigned short d_reclen;
           char           d_name[];
       };
void convert(long int x,int y)
{
	char a[100];
	a[0]='\0';
	b[0]='\0';
	length=0;
	if(y==1)
	{
		if(hindex==1)
		{
			x=x/1000;
		}
	}
	while(x>0)
	{
		a[length]=(x%10)+48;
		x=x/10;
		length++;
	}
	a[length]='\0';
	int i;
	for(i=0;i<length;i++)
	{
		b[i]=a[length-i-1];
	}
	b[length]='\0';
	if(y!=2)
	{
		write(1,b,length);
	}	
}
void conversion(long int k)
{
	char link[20],b[2];
        b[1] = '\0';
        long int rev;
        int q = 0,m;
        if(k == 0){write(1,"0",1);}
        else{
        while(k!= 0)
	{
 		rev = k%10;
		k = k/10;
                link[q] = rev + 48;
		q = q+1;
	}
        for(m = q-1;m >= 0;m--)
        {
        	b[0] = link[m];
                write(1,b,1);
 	}}
}
void get_name(long int x,int y)
{
	char c[100],c1[100];
	
	c[0]='\0';
	c1[0]='\0';
	char buff[1],ch;
	int fd,i,cnt=0,cnt1=0,flag=0,r,l=0,fl;
	if(y==0)
	{
		fd=open("/etc/passwd",O_RDONLY);
	}
	else
	{
		fd=open("/etc/group",O_RDONLY);
	}
	convert(x,2);
	while((r=read(fd,buff,1))!=0)
	{
		buff[1]='\0';
		ch=buff[0];
		if(flag==1)
		{
			break;
		}
		if(ch==':')
		{
			cnt1+=1;
		}
		if(cnt1==0)
		{
			c[cnt]=ch;
			cnt++;
		}
		if(cnt1==2 && ch!=':')
		{
			c1[l]=ch;
			l++;
		}
		if(ch=='\n')
		{
			c[cnt]='\0';
			c1[l]='\0';
			cnt=0;
			fl=0;cnt1=0;
			if(l==length)
			{
				for(i=0;i<cnt;i++)
				{
					if(c1[i]!=b[i])
					{
						fl=1;
						break;
					}
				}
				if(fl==0)
				{
					flag=1;
				}
			}
			l=0;
		}
	}
	while(c[cnt]!='\0')
	{
		cnt++;
	}
	write(1,c,cnt);
	write(1," ",1);
}
long int days_in(long int year)
{
	if((year%4 == 0) && (year%100!=0)){ return 366; }
        else if(year%400 == 0){ return 366; }
        else{ return 365;}
}
long int no_days(long int month,long int year)
{
 	if(month == 1 || month == 3 || month == 5 || month == 7 || month ==8 || month == 10 || month == 12) {return 31;}
	if(month == 2 && days_in(year) == 366){return 29;} 
        if(month == 2 && days_in(year) == 365) {return 28;}
 	return 30;
}
void monthname(int month){
	if( month == 1){ write(1,"Jan ",4);}
        else if( month == 2){ write(1,"Feb ",4);}
	else if( month == 3){ write(1,"Mar ",4);}
	else if( month == 4){ write(1,"Apr ",4);}
	else if( month == 5){ write(1,"May ",4);}
	else if( month == 6){ write(1,"Jun ",4);}
	else if( month == 7){ write(1,"Jul ",4);}
	else if( month == 8){ write(1,"Aug ",4);}
	else if( month == 9){ write(1,"Sep ",4);}
	else if( month == 10){ write(1,"Oct ",4);}
	else if( month == 11){ write(1,"Nov ",4);}
	else if( month == 12){ write(1,"Dec ",4);}
}
#define BUF_SIZE 1024
char g[2];
void details(char *dir)
{
	struct stat sb;
	time_t time;
	//if (stat(dir, &sb) == -1) 
	{
//		perror("stat");
	}
	lstat(dir,&sb);
	g[1]='\0';
	if(S_ISLNK(sb.st_mode)){g[0]='l';}
	else if(S_ISDIR(sb.st_mode)){g[0]='d';}
	else{ g[0] = '-' ;}
	write(1,g,1);
	//write(1, (S_ISDIR(sb.st_mode)) ? "d" : "-",1);
	write(1, (sb.st_mode & S_IRUSR) ? "r" : "-",1);
	write(1,(sb.st_mode & S_IWUSR) ? "w" : "-",1);
	write(1, (sb.st_mode & S_IXUSR) ? "x" : "-",1);
	write(1, (sb.st_mode & S_IRGRP) ? "r" : "-",1);
	write(1, (sb.st_mode & S_IWGRP) ? "w" : "-",1);
	write( 1,(sb.st_mode & S_IXGRP) ? "x" : "-",1);
	write( 1,(sb.st_mode & S_IROTH) ? "r" : "-",1);
	write( 1,(sb.st_mode & S_IWOTH) ? "w" : "-",1);
	write( 1,(sb.st_mode & S_IXOTH) ? "x" : "-",1);
	write(1," ",1);
	convert(sb.st_nlink,0);
	write(1," ",1);
	get_name(sb.st_uid,0);
	get_name(sb.st_gid,1);
	if(hindex)
	{
		convert(sb.st_size,1);
		write(1,"K ",2);
	}
	else
	{
		convert(sb.st_size,1);
		write(1," ",1);
	}
	//write(1,ctime(&sb.st_atime),strlen(ctime(&sb.st_atime)));
	time = sb.st_mtime;
	time = time + 19800 ;
	long int time_of_day = time % 86400; 
 	long int day = time / 86400;
 	long int min = (time_of_day % 3600) / 60; 
	long int hour = time_of_day / 3600; 
 	long int year = 1970;
        long int month = 1;
        while(day >= days_in(year))
	{ 
		day= day - days_in(year);
		year++; }  
	while(day >= no_days(month,year)) 
	{ 
		day = day - no_days(month,year); 
		month++; 
	}
        monthname(month);
	conversion(day+1);
        write(1," ",1);
        conversion(hour);
        write(1,":",1);
        conversion(min);
	write(1," ",1);
	return;

}
int main(int argc, char *argv[])
{
	int fd, nread;
	char buf[BUF_SIZE];
	struct linux_dirent *d;
	int bpos;
	char d_type;
	int flag=0;
	dir[0]='\0';
	argu[0]='\0';
	if(argc==1)
	{
		fd=open(".",O_RDONLY);
		flag4=1;
	}
	else if(argc==2)
	{
		if(argv[1][0]=='-')
		{
			fd=open(".",O_RDONLY | O_DIRECTORY);
			if(argv[1][1]=='l')
				flag2=1;
			if(argv[1][1]=='a')
				flag3=1;
			if(argv[1][1]=='h')
			{
				flag4=1;
				hindex=1;
			}
		}
		else
		{
			fd=open(argv[1],O_RDONLY | O_DIRECTORY);
			flag4=1;
			if(fd == -1)
			{
				int exist;
				exist=access(argv[1],F_OK);
				if(exist==0)
				{
					write(1,argv[1],own_strlen(argv[1]));
					write(1,"\n",1);
				}
				else if(exist == -1)
				{
					write(1,"File or Dir doesnt exist\n",25);
				}
				exit (1); 
			}
		}
	}
	
	
	if(argc==3)
	{
		if(argv[1][0]=='-')
		{
			flag=own_strlen(argv[1]);
			new_strcpy(argv[2],1);
			new_strcpy(argv[1],2);
//			printf("%d\n",flag);
	//		printf("%s",argu);
		}
		if(argv[2][0]=='-')
		{
			flag=own_strlen(argv[2]);
			new_strcpy(argv[1],1);
			new_strcpy(argv[2],2);
		}
		if (flag==2)
		{
	//		printf("*1\n");
			if(argu[1]=='l')
				flag2=1;
			else if(argu[1]=='a')
				flag3=1;
			else if(argu[1]=='h')
			{
				flag4=1;
				hindex=1;
			}
		}
		 if(flag==3)
		{
			if(stringcmp(argu,"-lh",3)==0 || stringcmp(argu,"-hl",3)==0)
			{
				flag2=1;
				hindex=1;
			}
			else if(stringcmp(argu,"-ah",3)==0 || stringcmp(argu,"-ha",3)==0)
			{
				flag3=1;
				hindex=1;
			}
			else if(stringcmp(argu,"-la",3)==0 || stringcmp(argu,"-al",3)==0)
				flag1=1;
		}
		if(flag==4)
		{
			flag1=1;
			hindex=1;
		}
		fd=open(dir,O_RDONLY | O_DIRECTORY);
	}
	for ( ; ; ) {
		fchdir(fd);
		nread = syscall(SYS_getdents, fd, buf, BUF_SIZE);
		if (nread == -1)
			handle_error("getdents");

		if (nread == 0)
			break;

		for (bpos = 0; bpos < nread;) {
		d = (struct linux_dirent *) (buf + bpos);
		struct stat sb;
		if (stat(d->d_name, &sb) == -1) 
		{
		//		perror("stat");
		}
		if (flag4)
		{
			if(d->d_name[0]!='.')
			{
			if(S_ISLNK(sb.st_mode))
				write(1,ANSI_COLOR_CYAN,sizeof(ANSI_COLOR_CYAN));
			if(S_ISDIR(sb.st_mode))
				write(1,ANSI_COLOR_BLUE,sizeof(ANSI_COLOR_BLUE));
			write(1,d->d_name,own_strlen(d->d_name));
			write(1,ANSI_COLOR_RESET,sizeof(ANSI_COLOR_RESET));
			}
			write(1,"\n",1);
		}
		if (flag3)
		{
			if(S_ISLNK(sb.st_mode))
				write(1,ANSI_COLOR_CYAN,sizeof(ANSI_COLOR_CYAN));
			if(S_ISDIR(sb.st_mode))
				write(1,ANSI_COLOR_BLUE,sizeof(ANSI_COLOR_BLUE));
			write(1,d->d_name,own_strlen(d->d_name));
			write(1,ANSI_COLOR_RESET,sizeof(ANSI_COLOR_RESET));
			write(1,"\t",1);
		}
		if (flag1)
		{
			details(d->d_name);
			if(g[0]=='l')
				write(1,ANSI_COLOR_CYAN,sizeof(ANSI_COLOR_CYAN));
			else if(g[0]=='d')
				write(1,ANSI_COLOR_BLUE,sizeof(ANSI_COLOR_BLUE));
			write(1,d->d_name,own_strlen(d->d_name));
			write(1,ANSI_COLOR_RESET,sizeof(ANSI_COLOR_RESET));
			//printf("%s\t",d->d_name);
			if(g[0]=='l'){
				char f[1000];
				readlink(d->d_name,f,1000);
	                	write(1," -> ",4);
	                	write(1,f,own_strlen(f));
			}
			write(1,"\n",1);
		}
		if (flag2)
		{
			if(d->d_name[0]!='.')
			{
				details(d->d_name);
			if(g[0]=='l')
				write(1,ANSI_COLOR_CYAN,sizeof(ANSI_COLOR_CYAN));
			else if(g[0]=='d')
				write(1,ANSI_COLOR_BLUE,sizeof(ANSI_COLOR_BLUE));
				write(1,d->d_name,own_strlen(d->d_name));
				write(1,ANSI_COLOR_RESET,sizeof(ANSI_COLOR_RESET));
			if(g[0]=='l'){
			char f[1000];
			readlink(d->d_name,f,1000);
                	write(1," -> ",4);
			struct stat n;
			stat(f,&n);
			if(S_ISDIR(n.st_mode))
				write(1,ANSI_COLOR_BLUE,sizeof(ANSI_COLOR_BLUE));
                	write(1,f,own_strlen(f));
				write(1,ANSI_COLOR_RESET,sizeof(ANSI_COLOR_RESET));
			}
				write(1,"\n",1);
			}
		}
		bpos += d->d_reclen;
		}
	}
	write(1,"\n",1);
	exit(EXIT_SUCCESS);
}

