#ifndef CONIO_H_UNIX_HEADER
#define CONIO_H_UNIX_HEADER

#include <termios.h>
#include <stdio.h>

static int stricmp(const char * pStr1, const char *pStr2)
{
    char c1, c2;
    int  v;

    do {
        c1 = *pStr1++;
        c2 = *pStr2++;
        /* The casts are necessary when pStr1 is shorter & char is signed */
        v = (unsigned int) tolower(c1) - (unsigned int) tolower(c2);
    } while ((v == 0) && (c1 != '\0') && (c2 != '\0') );

    return v;
}

static struct termios _old, _new;

/* Initialize new terminal i/o settings */
static void initTermios(int echo) 
{
  tcgetattr(0, &_old); /* grab old terminal i/o settings */
  _new = _old; /* make new settings same as old settings */
  _new.c_lflag &= ~ICANON; /* disable buffered i/o */
  _new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &_new); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
static void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &_old);
}

/* Read 1 character - echo defines echo mode */
static char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
static char getch(void) 
{
  return getch_(0);
}

/* Read 1 character with echo */
static char getche(void) 
{
  return getch_(1);
}

#endif