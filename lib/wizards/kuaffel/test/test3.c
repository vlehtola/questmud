#include <ansi.h>
mixed cmd_where() {
  object *all;        
  string tmp;
  string *whoa; 
  int i,x;           

  all = users();                                          
  whoa = ({ "Players", "Location"});

  write("\nPlayers\t\tLocation\n\n");                     

  for (i=0;i<sizeof(all);i++) {                           
    whoa = insert_alist( (string) capitalize(all[i]->query_name()), (string) file_name(environment(all[i])), whoa);
  }                                             
  write ("Test: " + whoa[1][0] + " " + whoa[1][1]);
  /*
  for (i=0;i<sizeof(whoa);i++) {
    for (x=0;x<(sizeof(whoa)+1);x++) {
      if (whoa[x][1]>whoa[x+1][1]) {
        (string)tmp = (string)whoa[x+1][1];
        (string)whoa[x+1][1] = (string)whoa[x][1];
        (string)whoa[x][1] = (string)tmp;
      }
    }  
  }

  for (i=0;i<sizeof(whoa);i++) {
    write(sprintf("%s%s%-15s %s%s%s\n",BOLD,BLUE_F,whoa[i][0], CYAN_F, whoa[i][1], OFF ) );    
  }
  */
}
