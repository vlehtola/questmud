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
         property = ({ "no_summon", });
         add_exit("west","wizards/walla/w2");
         add_exit("jericho","wizards/walla/jericho/rooms/cs");
         add_exit("pepe","wizards/walla/peepseye/1");
         add_exit("test","wizards/walla/void");
         add_exit("shaolin","wizards/walla/area2/rooms/entrance");
         add_exit("inn","world/city/inn");
         add_exit("sban","wizards/shadow/shortban");
         add_exit("nface","wizards/walla/northern/rooms/entrance");
         short_desc = "Walla's Hall of Divine Justice";
         long_desc =" \n";
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
                str += sprintf("%4-i %28-s %s\n", us[i]->query_level(),
    BOLD+get_c(us[i])+capitalize(name)+OFF, get_c(us[i])+env+OFF);
        }
        str += "----------------------------------------\n";
        str += sprintf("Total of %d users, %d unidle\n", lkm, sizeof(us));

        write(str);
        ::long();
}
