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
        
         add_exit("inn","/world/city/inn");
         add_exit("cs","/world/city/cs");
         add_exit("dwarf","/wizards/kaappi/dcity/rooms/katu5.c");
          add_exit("tower","/wizards/nipa/areat/torni/huoneet/entrance.c");
 
           short_desc = "Nipa's causually furnitured workroom.";
           long_desc = " This is apprentice wizard Nipa's workroom. All int the room \n"+
                       " look very basic and common. No fancy thing exept one trophy stands \n"+
                       " on the big oak table with many unfinished blueprints. One big black \n"+
                       " leather chair stands beside the table. Also there seems to be only one \n"+
                       " spotlight pointed to light the table's content.\n";

        set_light(3);

items = allocate(4);
     items[0] = "blueprints";
     items[1] = "Some fuzzy and unfinished blueprints lay on the table.";
     items[2] = "trophy";
     items[3] = "Platinum achievment trophy of devoted player Ntg with text 'Game Cleared' on it";

}

long() {
        object *us;
        int i, lkm;
        string str,name,color,env;
        
         str = "----------------------------------------\n";
         str += "-�-  Aktiiviset  -�-\n";
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
