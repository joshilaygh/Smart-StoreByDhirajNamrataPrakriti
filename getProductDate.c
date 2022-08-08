#include <time.h>

void getDate(struct product *p)
{
    time_t s, val = 1;
    struct tm *t;
    s = time(NULL);
    t = localtime(&s);
    
	p->d= t->tm_mday;
    p->m= (t->tm_mon + 1);
    p->y= (t->tm_year + 1900);
}
