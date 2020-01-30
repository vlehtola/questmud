#include "/wizards/cendor/ansi.h"
#define THISYEAR to_int(ctime(time())[20..])
#define THISMONTH monthofyear(ctime(time())[4..6])
#define THISDAY dayofweek(ctime(time())[1..3])
#define TODAY to_int(ctime(time())[8..9])
#define TP this_player()
#define TO this_object()
#define FUDGE1  1               /* needed to make day of week come out right */
#define FUDGE2  6               /* for old style (Julian) calendar           */
#define isleap(y) (!((y)%4) && (((y)%100) || !((y)%400)))


void printmonth(int m, int y, string *mode);
int weekday(int m, int y);
int dayofweek(string day);
int monthofyear(string month);

static int *days, *mdays;
static int europe;
static string *months, *daynames;

int cmd_cal(string str) {
  int m, y;
  string *args, *mode;
  mode = ({ });
  days = ({ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 });
  mdays = ({ 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 });
  months = ({ "January ", "February ", "March ", "April ", "May ",
    "June ", "July ", "August ", "September ", "October ",
    "November ", "December ", });
  daynames = ({ "Sunday", "Monday", "Tuesday", "Wednesday",
     "Thursday", "Friday", "Saturday" });

  europe = 0;
  if(!str) {
    m = THISMONTH;
    y = THISYEAR;
  }
  else {
    args = explode(str, " ");
    str = "";
    while(sizeof(args)) {
      switch(args[0]) {
        case "-e": case "--european":
          mode += ({ "europe" });
          europe = 1;
          args[0] = 0; args -= ({ 0 });
          break;
        case "-j": case "--julian":
          mode += ({ "julian" });
          args[0] = 0; args -= ({ 0 });
          break;
        case "-w": case "--width":
          if(sizeof(args)<1) {
            write("Usage: cal " + args[0] + " [width]\n");
            return 1; break;
          }
          mode += ({ "width" + args[1] });
          args[0] = 0; args[1] = 0; args -= ({ 0 });
          break;
        case "-h": case "--nohilite":
          mode += ({ "nohilite" });
          args[0] = 0; args -= ({ 0 });
          break;
        default:
          str += args[0] + " ";
          args[0] = 0; args -= ({ 0 });
          break;
      }
    }
    if(!strlen(str)) str = THISMONTH + " " + THISYEAR;

    if(sscanf(str, "%d %d", m, y)!=2) {
      write("Usage: cal [-e] [-j] [-w width] [month year]\n");
      return 1;
    }
    if(m < 1 || m > 12) {
      write("cal: illegal month value: use 1-12\n");
      return 1;
    }
  }
  this_object()->fixtab(y);
  printmonth(m, y, mode);
  return 1;

}

/*============================================================================
 * fixtab() - correct for leapyears.
 *============================================================================*
/

void fixtab(int year) {
  int i;
  if(!(year % 4)) {
    if((year % 100) || !(year % 400) || (year < 1753)) {
      days[1] = 29;
      for(i=2;i<13;i++) mdays[i]++;
    }
  }
}

/*============================================================================
 * weekday() - return day-of-week for first day of month.
 *============================================================================*
/
int weekday(int m, int y) {
  y--;
  m--;
  if(y>1752-1 || (y == 1752-1 && m>8) )
    return (mdays[m]+y+y / 4-y / 100+y / 400 + FUDGE1 - europe) % 7;
  else
    return (mdays[m] + y + y / 4 + FUDGE2 - europe) % 7;
}

/*===========================================================================
 * This prints the month with given modes
 *===========================================================================*/

void printmonth(int m, int y, string *mode) {
  string str, dateline, day;
  int dow, index;
  int i, j, k, width;
  int julian;

  width = 3;
  dateline = " ";

  if(member(mode, "julian")!=-1) {
    julian = 1;
    width = 4;
  }
  for(i=0;i<sizeof(mode);i++) {
    // ({ "width5" })
    if(mode[i][0..4] == "width") width = to_int(mode[i][5..]);
    if(width>10) width = 10;
    if(width<3) width = 3;
  }

  // Let's write the dateline as wanted
  dateline = "";
  if(member(mode, "europe")!=-1) {
    // From Monday to Saturday and then Sunday
    for(i=1;i<sizeof(daynames);i++) {
      dateline += daynames[i][0..(width-2)]+" ";
    }
    dateline += daynames[0][0..(width-2)];
  }
  else {
    for(i=0;i<sizeof(daynames);i++) {
      dateline += sprintf("%-"+width+"s", daynames[i][0..(width-2)]);
    }
  }
  dateline += "\n";


  // Few spaces to the beginning
  str = months[m-1] + to_string(y) + "\n";
  for(i=0;i<(((7*width+1)-strlen(str))/2)+1;i++)
    str = " " + str;

  write(str);
  write(dateline);


  index = dow = this_object()->weekday(m, y);
  str = "";
  // Write empty slots until we are in correct position
  for(i=0;i<width;i++) str += " ";
  for(i=0;i<dow;i++) write(str);

  // Let's write the days
  for(i=1;i<=days[m-1];i++) {
    if(julian)
      j = mdays[m-1] + i;
    else
      j = i;

    if(i==TODAY && y==THISYEAR&& m==THISMONTH&& member(mode,"nohilite")==-1) {
      if(this_player()->query_term() == "ansi") {
        day = BOLD + to_string(j) + OFF;
        for(k=0;k<width-strlen(to_string(j));k++) day += " ";
      }
      else
        day = "("+to_string(j)+")";
    }
    else day = to_string(j);

    write(sprintf("%-"+width+"s", day));
    index++;
    if(index>=7) { write("\n"); index = 0; }
  }
  write("\n");
}

int dayofweek(string day) {
  switch(capitalize(day[0..0])) {
    case "S":
      if(lower_case(day[1..1]) == "u") return europe ? 7 : 1;
      else return 7 - europe;
    case "M": return 2 - europe;
    case "T":
      if(lower_case(day[1..1]) == "u") return 3 - europe;
      else return 5 - europe;
    case "W": return 4 - europe;
    case "F": return 6 - europe;
    default: return 0;
  }
}

int monthofyear(string month) {
  switch(month) {
    case "Jan": return 1;
    case "Feb": return 2;
    case "Mar": return 3;
    case "Apr": return 4;
    case "May": return 5;
    case "Jun": return 6;
    case "Jul": return 7;
    case "Aug": return 8;
    case "Sep": return 9;
    case "Oct": return 10;
    case "Nov": return 11;
    case "Dec": return 12;
  }
}



