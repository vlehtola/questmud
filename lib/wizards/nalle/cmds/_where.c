#include <ansi.h>
cmd_where(string str) 
{
  int i;
  object all;
  string *loc;
  string *loctmp;

  loc = ({});
  all = users();

  for(i=0;i<sizeof(all);i++) {
    if (capitalize(all[i]->query_name()) != "Logon") {
      loc += ({ sprintf("%s%s%s %s%s%s\n",BOLD,BLUE_F,capitalize(all[i]->query_name(1)), CYAN_F, file_name(environment(all[i])), OFF ) });
    }
  }

  loctmp = msort_arr(loc);
  loc = loctmp;  

  write(sprintf("\n%-15s %s\n\n","Player","Location"));

  for(i=0;i<sizeof(loc);i++) {
    write(loc[i]);
  }

  write("\n");
 return 1;
}

mixed msort_arr(string *arr) {
  int i,x,y;
  string ptmp, ltmp;
  string *player;
  string *loc;
  string *tmp;


  tmp = ({});
  player = ({});
  loc = ({});

  write("Debug: Received content;\n\n");
  for(i=0;i<sizeof(arr);i++) { 
    write(arr[i]);
  }
  
  write("\nEntering the 'splitting' section\n\n");

  for(i=0;i<sizeof(arr);i++) {
    tmp = explode(arr[i], " ");
    player += ({ tmp[0] });
    loc += ({ tmp[1] });
    write("Player "+i+": "+player[i]+" Loc: "+loc[i]);
  }  

  write("\nSorting section...\n\n");

  for(x=0;x<sizeof(loc);x++) {
    for(y=0;y<sizeof(loc);y++) {
      if(loc[x] < loc[y]) {
        ptmp = player[x];
        player[x] = player[y];
        player[y] = ptmp;
        ltmp = loc[x];
        loc[x] = loc[y];
        loc[y] = ltmp;
      }
    }
  }  

  write("Sorting results...\n\n");

  for(i=0;i<sizeof(loc);i++) {
    write(i+": "+player[i]+" "+loc[i]);
  }

  write("\nMerging the results...\n\n");
  
  tmp = ({});

  for(i=0;i<sizeof(loc);i++) {
    tmp += ({ sprintf("%-15s %s",player[i],loc[i]) });
  }

  write("\nReturning...\n\n");
  
  for(i=0;i<sizeof(tmp);i++) {
    write(tmp[i]+"\n");
  }
 
  return tmp;
}
