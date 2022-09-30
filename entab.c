#include<stdio.h>


#define TAB 4 //number of spaces to make a tab

int main(void)
{
    int numberOfSpaces,c,pos,reachedLetter,numberOfTabs;
    numberOfSpaces = 0;
    reachedLetter = 0;
    pos=0;
    numberOfTabs=0;



    while((c=getchar())!=EOF) {
        ++pos;
        if (c == ' '&&!reachedLetter)
        {
            if((pos%TAB)!=0)
            {
                numberOfSpaces++;
                //putchar(numberOfSpaces);
            }
            else
            {
                //putchar(numberOfSpaces);
                numberOfSpaces=0;
                numberOfTabs++;
            }

            continue;
        }
        else if(c=='\t' && !reachedLetter)
        {
            numberOfTabs++;
            numberOfSpaces=0;
            pos = pos + (TAB - (pos%TAB));
            continue;
        }
        else
        {

            while(numberOfTabs>0&&!reachedLetter)
            {
                putchar('\t');
                --numberOfTabs;
            }

            if(numberOfSpaces%TAB!=0&&!reachedLetter) {
                putchar('\t');
                numberOfSpaces = 0;
            }
            reachedLetter=1;
            putchar(c);
           // pos++;
            if(c=='\n')
            {
                reachedLetter=0;
                pos=0;
            }

        }






        /*else //reached non-white so just keep spitting
        {
            reachedLetter = 1;
            putchar(c);
            if(c=='\n')
            {
                numberOfSpaces=0;
                pos=0;
                reachedLetter=0;
                //prep=0;
                //putchar(numberOfSpaces);
            }
            else if( c=='\t')
            {
                pos = pos + (TAB - (pos-1)%TAB)-1;
            }
*/
        }
    return 0;
}