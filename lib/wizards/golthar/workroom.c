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
 
  short_desc = "Golthar's Sweet Home";
  long_desc = "";
  add_exit("druid","/wizards/grizzt/druids/outer1");
  add_exit("inn","/world/city/inn");
  add_exit("cs","/world/city/cs");
  add_exit("post","/world/city/post");
  add_exit("jail","/wizards/golthar/rako");
  add_exit("north","/wizards/golthar/rooms/panik");

  set_light(1);
  set_not_out(1);
  property = allocate(1);
  property[0] = "no_summon";
  
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
        write("Current time is: "+ctime(time())[11..15]+"\n");
	  str += "----------------------------------------\n";
        ::long();
}


init()
{
 if(    this_player()->query_name() == "Jenny"

    )
   {
    move_object(this_player(),"/world/objects/trashcan");
    tell_object(this_player(),"I have to clean up the trashes.\n");
   }
 ::init();
}