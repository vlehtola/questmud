#include <ansi.h>
inherit "room/room";

status sortting(object obj1, object obj2) {
        int i1,i2;
        i1=obj1->query_level();
        i2=obj2->query_level();
        return i1>i2;
}

status wiz(object obj1, object obj2) {
        int i1,i2;
        i1=obj1->query_wiz();
        i2=obj2->query_wiz();
        return i1>i2;
}

status unidle(object ob) {
        if(query_idle(ob) < 300) return 1;
        return 0;
}

status logon(object ob) {
        if(ob->query_level() > 0) return 1;
        return 0;
}

string get_c(object ob) {
        switch(ob->query_wiz()) {
        case 0 : return RED_F;
        case 1 : return CYAN_F;
        case 2 : return YELLOW_F;
        case 3 : return MAGENTA_F;
        case 4 : return BLUE_F;
        case 5 : return WHITE_F;
        return " Error ";
        }
}

reset(arg) {
  if(arg) return;
  add_exit("inn","/world/city/inn");
  add_exit("cs","/world/city/cs");
  add_exit("post","/world/city/post");
  
  short_desc = "Takke's Workshop";
  long_desc = "This is Takke's Workshop. There is a table in the center of the \n"+
              "room, a bed by the far wall, and bookshelves line the other three \n"+
              "walls. A pentagram covers the entire carpetless floor and light \n"+
              "is shed from an unseen source. You can hear some sort of music if \n"+
              "you listen very carefully. \n"; 
  
  set_light(3);
  
  property = allocate(4);
  property[0] = "no_summon";
    
  items = allocate(14);
  items[0] = "bed";
  items[1] = "The bed is rumpled and appears to have been used recently";
  items[2] = "table";
  items[3] = "This table has all sorts of alchemical supplies and tools \n"+        
             "on it. There is also a blue magicians hat with stars on it on the \n"+
             "table. The table is made of teak";
  items[4] = "pentagram";
  items[5] = "The pentagram is made of an unknown "+ RED_F +"red"+ OFF +" substance";
  items[6] = "substance";
  items[7] = "The substance is starting to peel off the floor";
  items[8] = "floor";
  items[9] = "The floor is made of granite and is cool to the touch";
  items[10] = "bookshelves";
  items[11] = "They are lined with books of all kind";
  items[12] = "walls";
  items[13] = "The walls are painted black with stars drawn on them";

}

init() {
  ::init(); /* don't forget this, if you use init() */
  add_action("listen", "listen");
}

/* when a player starts his command with "yeah", this func is called. */
/* str is the string (text) that the player possibly writes after "yeah" */
/* ex. "yeah this rocks" -> str == "this rocks" */

listen(str) {
  if(str == "music") {
    write("Classical music wafts out of nowhere.\n"); /* the "\n" changes the line :) */
    return 1; /* stop the execution */
  }
  /* "Blaah." will be writed, if the argument (str) is not "this rocks" */
  write("Classical music wafts out of nowhere.\n");
  return 1;
}

long() {
        object *us;
        int i, lkm;
        string str,name,color,env;
        
        str = "The Unidle\n";
        str += sprintf("%4-s %15-s %s\n", "Lvl", "Name", "Location");
        str += "----------------------------------------\n";

        us = users();
        lkm = sizeof(us);
        us = filter_array(us, "unidle");
        us = filter_array(us, "logon");
        us = sort_array(us, "sortting");
        us = sort_array(us, "wiz");
        
        for(i = sizeof(us)-1;i>-1;i--) {
                name = us[i]->query_name();
                if(environment(us[i])) { env = file_name(environment(us[i])); }
                else { env = ""; }
                str += sprintf("%4-i %28-s %s\n", us[i]->query_level(), BOLD+get_c(us[i])+capitalize(name)+OFF, get_c(us[i])+env+OFF);
        }
        str += "----------------------------------------\n";
        str += sprintf("Total of %d users, %d unidle\n", lkm, sizeof(us));

        write(str);
        ::long();
}
