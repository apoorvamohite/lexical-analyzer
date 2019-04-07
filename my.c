/*#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isKeyword(char* str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||
        !strcmp(str, "break") ||
         !strcmp(str, "continue") || !strcmp(str, "int")
        || !strcmp(str, "double") || !strcmp(str, "float")
        || !strcmp(str, "return") || !strcmp(str, "char")
        || !strcmp(str, "case") || !strcmp(str, "char")
        || !strcmp(str, "sizeof") || !strcmp(str, "long")
        || !strcmp(str, "short") || !strcmp(str, "typedef")
        || !strcmp(str, "switch") || !strcmp(str, "unsigned")
        || !strcmp(str, "void") || !strcmp(str, "static")
        || !strcmp(str, "struct") || !strcmp(str, "goto"))
        return (true);
    return (false);
}

char* substring(char *destination, const char *source, int beg, int n)
{
	while (n > 0)
	{
		*destination = *(source + beg);
		destination++;
		source++;
		n--;
	}
	*destination = '\0';
	return destination;
}

// Comments
// Literal strings
// printf, scanf

int main()
{
    int i=0,x=0;
    char str[1000], ch, c;

    // File Read
    FILE *fp;
    fp = fopen("C:\\Users\\kiran\\Documents\\Projects\\cd\\program.txt", "rw");
    while((ch = fgetc(fp)) != EOF)
      str[x++]=ch;
    str[x]='\0';
    x=0;

    char subs[50];
    char num[50];
    int state=-1, slen=0, nlen=0;
    while(1)
    {
        c = str[i];
        switch(state)
        {
            case -1:
                switch(c)
                {
                    case 'a':
                    case 'b':
                    case 'c':
                    case 'd':
                    case 'e':
                    case 'f':
                    case 'g':
                    case 'h':
                    case 'i':
                    case 'j':
                    case 'k':
                    case 'l':
                    case 'm':
                    case 'n':
                    case 'o':
                    case 'p':
                    case 'q':
                    case 'r':
                    case 's':
                    case 't':
                    case 'u':
                    case 'v':
                    case 'w':
                    case 'x':
                    case 'y':
                    case 'z':
                        state=9;
                        i--;
                        break;

                    // state 0
                    case '>':
                        state=6;
                        break;
                    case '<':
                        state=1;
                        break;
                    case '=':
                        state=5;
                        break;

                    // state 12
                    case '0':
                    case '1':
                    case '2':
                    case '3':
                    case '4':
                    case '5':
                    case '6':
                    case '7':
                    case '8':
                    case '9':
                        state = 12;
                        i--;
                        break;

                    case '+':
                        if(str[i+1]=='+')
                        {
                            printf("++ <OPERATOR, INC>\n");
                            i++;
                        }
                        else
                        {
                            printf("+ <OPERATOR, ADD>\n");
                        }
                        break;
                    case '-':
                        if(str[i+1]=='-')
                        {
                            printf("-- <OPERATOR, DEC>\n");
                            i++;
                        }
                        else
                        {
                            printf("- <OPERATOR, SUB>\n");
                        }
                        break;
                    case '*':
                        printf("* <OPERATOR, MUL>\n");
                        break;
                    case '/':
                        printf("/ <OPERATOR, DIV>\n");
                        break;
                    case '%':
                        printf("%% <OPERATOR, MOD>\n");
                        break;

                    case '!':
                        printf("! <OPERATOR, NOT>\n");
                        break;
                    case '&':
                        if(str[i+1]=='&')
                        {
                            printf("&& <OPERATOR, AND>\n");
                            i++;
                        }
                        else
                        {
                            printf("& <OPERATOR, AMP>\n");
                        }
                        break;
                    case '|':
                        if(str[i+1]=='|')
                        {
                            printf("|| <OPERATOR, OR>\n");
                            i++;
                        }
                        else
                        {
                            printf("| <OPERATOR, VERT>\n");
                        }
                        break;
                    case '(':
                        printf("( <OPERATOR, LPAR>\n");
                        break;
                    case ')':
                        printf(") <OPERATOR, RPAR>\n");
                        break;
                    case ',':
                        printf(", <OPERATOR, COMMA>\n");
                        break;
                    case '.':
                        printf(". <OPERATOR, DOT>\n");
                        break;
                    case ':':
                        printf(": <OPERATOR, COL>\n");
                        break;
                    case ';':
                        printf("; <OPERATOR, SEMICOL>\n");
                        break;
                    case '?':
                        printf("? <OPERATOR, TER>\n");
                        break;
                    case '[':
                        printf("[ <OPERATOR, LBRACKET>\n");
                        break;
                    case ']':
                        printf("] <OPERATOR, RBRACKET>\n");
                        break;
                    case '\\':
                        printf("\\ <OPERATOR, ESC>\n");
                        break;
                    case '^':
                        printf("^ <OPERATOR, CARET>\n");
                        break;
                    case '{':
                        printf("{ <OPERATOR, LBRACE>\n");
                        break;
                    case '}':
                        printf("} <OPERATOR, RBRACE>\n");
                        break;


                    case ' ':
                    case '\b':
                    case '\t':
                    case '\n':
                        state=-1;
                        break;

                    case '\0':
                        return 0;
                }
                break;
            case 1:
                if(c=='=')
                {
                    state=2;
                }
                else if(c=='>')
                {
                    state=3;
                }
                else
                {
                    state=4;
                }
                break;
            case 2:
                printf("<= <RELOP, LE>\n");
                state=-1;
                break;
            case 3:
                printf("<> <RELOP, NE>\n");
                state=-1;
                break;
            case 4:
                printf("< <RELOP, LT>\n");
                i--;
                state=-1;
                break;
            case 5:
                printf("= <RELOP, EQ>\n");
                state=-1;
                break;
            case 6:
                if(c=='=')
                {
                    state=7;
                }
                else
                {
                    state=8;
                }
                break;
            case 7:
                printf(">= <RELOP, GE>\n");
                state=-1;
                break;
            case 8:
                printf("> <RELOP, GT>\n");
                i--;
                state=-1;
                break;
            case 9:
                if((c>=97 && c<=122) || (c>=65 && c<=90))
                {
                    state=10;
                    slen++;
                }
                break;
            case 10:
                if((c>=97 && c<=122) || (c>=65 && c<=90) || (c>=48 && c<=57))
                {
                    state=10;
                    slen++;
                }
                else
                {
                    state=11;
                    i--;
                }
                break;
            case 11:
                substring(subs, str, i-slen,slen);
                for(x=0; x<strlen(subs); x++)
                    printf("%c", subs[x]);
                slen=0;
                printf(" ");
                if(isKeyword(subs))
                {
                    printf("<KEYWORD>\n");
                    i--;
                    subs[0]='\0';
                    state=-1;
                }
                else
                {
                    printf("<IDENTIFIER>\n");
                    i--;
                    subs[0]='\0';
                    state=-1;
                }
                break;
            case 12:
                if(c>=48 && c<=57)
                {
                    state=13;
                    nlen++;
                }
                break;
            case 13:
                if(c>=48 && c<=57)
                {
                    state=13;
                    nlen++;
                }
                else if(c=='.')
                {
                    state=14;
                    nlen++;
                }
                else if(c=='E')
                {
                    state=16;
                    nlen++;
                }
                else
                {
                    state=20;
                    i--;
                }
                break;
            case 14:
                if(c>=48 && c<=57)
                {
                    state=15;
                    nlen++;
                }
                break;
            case 15:
                if(c>=48 && c<=57)
                {
                    state=15;
                    nlen++;
                }
                else if(c=='E')
                {
                    state=16;
                    nlen++;
                }
                else
                {
                    state=21;
                    i--;
                }
                break;
            case 16:
                if(c=='+' || c=='-')
                {
                    state=17;
                    nlen++;
                }
                else if(c>=48 && c<=57)
                {
                    state=18;
                    nlen++;
                }
                break;
            case 17:
                if(c>=48 && c<=57)
                {
                    state=18;
                    nlen++;
                }
                break;
            case 18:
                if(c>=48 && c<=57)
                {
                    state=18;
                    nlen++;
                }
                else
                {
                    state=19;
                    i--;
                }
                break;
            case 19:
                if(c==' ')
                {
                    substring(num, str, i-nlen,nlen);
                    for(x=0; x<strlen(num); x++)
                        printf("%c", num[x]);
                    nlen=0;
                    printf(" ");
                    printf("<NUMBER>\n");
                    i--;
                    subs[0]='\0';
                    state=-1;
                }
                else
                {
                    printf("ERROR");
                    state=-1;
                }
                break;
            case 20:
                if(c==' ')
                {
                    substring(num, str, i-nlen,nlen);
                    for(x=0; x<strlen(num); x++)
                        printf("%c", num[x]);
                    nlen=0;
                    printf(" ");
                    printf("<NUMBER>\n");
                    i--;
                    subs[0]='\0';
                    state=-1;
                }
                else
                {
                    printf("ERROR\n");
                    state=-1;
                }
                break;
            case 21:
                if(c==' ')
                {
                    substring(num, str, i-nlen,nlen);
                    for(x=0; x<strlen(num); x++)
                        printf("%c", num[x]);
                    nlen=0;
                    printf(" ");
                    printf("<NUMBER>\n");
                    i--;
                    subs[0]='\0';
                    state=-1;
                }
                else
                {
                    printf("ERROR");
                    state=-1;
                }
                break;
        }
        i++;
    }
    return 0;
}*/
