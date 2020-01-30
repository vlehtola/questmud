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
  add_exit("shifters","/wizards/moonstar/shifters/testguild.c");
  add_exit("south","/wizards/moonstar/areas/asgroth/rooms/nbridge");
  add_exit("cs","/world/city/cs");
add_exit("guild","/wizards/moonstar/artists/base_guild.c");
short_desc = "Moonstar's workroom";
  long_desc =
"This is Moonstar's huge workroom full of different kind of bookshelves.\n" +
"Only wizards are allowed to be here. Here Moonstar does his dirty work\n" +
"and testings.\n";
  set_light(3);
}
long() {
        object *us;
        int i, lkm;
        string str,name,color,env;
       str = "The plaque of unidle players\n";
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

   property = allocate(1);
   property[0] = "no_summon";
}

status unidle(object ob) 
{
  if(ob->query_real_name()[0 .. 1] == "na") return 0;
  if(query_idle(ob) < 300) return 1;
  return 0;
}


