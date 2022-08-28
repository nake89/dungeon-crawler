#include <ncurses.h>
#include <unistd.h>

#define DELAY 30000

int kbhit(void);
int main(int argc, char *argv[]) {
 int x = 0, y = 0;
 int max_y = 0, max_x = 0;
 int next_x = 0;
 int next_y = 0;
 int direction = 1;
 int dir_y = 1;

 initscr();
 noecho();
 curs_set(FALSE);

 // Global var `stdscr` is created by the call to `initscr()`
 getmaxyx(stdscr, max_y, max_x);

 while(1) {
   clear();
   mvprintw(y, x, "o");
   refresh();
   if (kbhit()) {
            printw("Key pressed! It was: %d\n", getch());
            refresh();
        }
   usleep(DELAY);

   next_x = x + direction;
   next_y = y + dir_y;

   if (next_x >= max_x || next_x < 0) {
     direction*= -1;
   } else {
     x+= direction;
   }

   if (next_y >= max_y || next_y < 0) {
     dir_y*= -1;
   } else {
     y+= dir_y;
   }
 }

 endwin();
}

int kbhit(void)
{
    int ch = getch();

    if (ch != ERR) {
        ungetch(ch);
        return 1;
    } else {
        return 0;
    }
}
