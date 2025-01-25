#include <curses.h>
#include "AK_RTTL.h"

int *max_min_where(int *where)
{
    if (*where < 0)
        *where = 0;
    if (*where > 2)
        *where = 2;
    return where;
}

void event_menu_poll(int car, int *i, int *where, int *live)
{
    switch (car) {
        case KEY_UP:
            *where = *where - 1;
            where = max_min_where(where);
            break;
        case KEY_DOWN:
            *where = *where + 1;
            where = max_min_where(where);
            break;
        case '\n':
            switch (*where) {
                case 2:
                    *live = 0;
                    break;
                case 1:
                    tutorial();
            }
    }
}
