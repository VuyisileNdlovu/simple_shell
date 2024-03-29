#include"shell.h"

/**
*_erratoi-convertsastringtoaninteger
*@s:thestringtobeconverted
*Return:0ifnonumbersinstring,convertednumberotherwise
*-1onerror
*/
int_erratoi(char*s)
{
inti=0;
unsignedlongintresult=0;

if(*s=='+')
s++;
for(i=0;s[i]!='\0';i++)
{
if(s[i]>='0'&&s[i]<='9')
{
result*=10;
result+=(s[i]-'0');
if(result>INT_MAX)
return(-1);
}
else
return(-1);
}
return(result);
}

/**
*print_error-printsanerrormessage
*@info:theparameter&returninfostruct
*@estr:stringcontainingspecifiederrortype
*Return:0ifnonumbersinstring,convertednumberotherwise
*-1onerror
*/
voidprint_error(info_t*info,char*estr)
{
_eputs(info->fname);
_eputs(":");
print_d(info->line_count,STDERR_FILENO);
_eputs(":");
_eputs(info->argv[0]);
_eputs(":");
_eputs(estr);
}

/**
*print_d-functionprintsadecimal(integer)number(base10)
*@input:theinput
*@fd:thefiledescriptortowriteto
*
*Return:numberofcharactersprinted
*/
intprint_d(intinput,intfd)
{
int(*__putchar)(char)=_putchar;
inti,count=0;
unsignedint_abs_,current;

if(fd==STDERR_FILENO)
__putchar=_eputchar;
if(input<0)
{
_abs_=-input;
__putchar('-');
count++;
}
else
_abs_=input;
current=_abs_;
for(i=1000000000;i>1;i/=10)
{
if(_abs_/i)
{
__putchar('0'+current/i);
count++;
}
current%=i;
}
__putchar('0'+current);
count++;

return(count);
}

/**
*convert_number-converterfunction,acloneofitoa
*@num:number
*@base:base
*@flags:argumentflags
*
*Return:string
*/
char*convert_number(longintnum,intbase,intflags)
{
staticchar*array;
staticcharbuffer[50];
charsign=0;
char*ptr;
unsignedlongn=num;

if(!(flags&CONVERT_UNSIGNED)&&num<0)
{
n=-num;
sign='-';

}
array=flags&CONVERT_LOWERCASE?"0123456789abcdef":"0123456789ABCDEF";
ptr=&buffer[49];
*ptr='\0';

do{
*--ptr=array[n%base];
n/=base;
}while(n!=0);

if(sign)
*--ptr=sign;
return(ptr);
}

/**
*remove_comments-functionreplacesfirstinstanceof'#'with'\0'
*@buf:addressofthestringtomodify
*
*Return:Always0;
*/
voidremove_comments(char*buf)
{
inti;

for(i=0;buf[i]!='\0';i++)
if(buf[i]=='#'&&(!i||buf[i-1]==''))
{
buf[i]='\0';
break;
}
}
