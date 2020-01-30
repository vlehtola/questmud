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
        if(ob->query_real_name() == "nalle") return 0;
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
        add_exit("post","/world/city/post");
        add_exit("lab","/wizards/proge/lab");
        add_exit("cs","/world/city/cs");
        short_desc = "Koti";
        long_desc = "";
        set_light(3);
        set_not_out(1);
}

long() {
        object *us;
        int i, lkm;
        string str,name,color,env;
        
        str = "\nUnidle:\n";
        str += sprintf("%4-s %15-s %s\n", "Lvl", "Name", "Location");
        str += "------------------------------------------------------------\n";
 
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
                str += sprintf("%4-i %28-s %s\n", us[i]->query_level(), BOLD+get_c(us[i])+capitalize(name)+OFF,
get_c(us[i])+env+OFF);
        }
        str += "------------------------------------------------------------\n";
        str += sprintf("Total of %d users, %d unidle\n", lkm, sizeof(us));
        str += "\n .----. .----. .-----. .-----. .-----. (R)";
        str += "\n |   || |   || |   | | |    _| |    _| ";
        str += "\n |    | |    | |     | |   | | |    _|  ";
        str += "\n |   |  |   || |     | |     | |     | ";
        str += "\n'''''''''''''''''''''''''''''''''''''''\n";


        write(str);
        ::long();
}

init() 
{
 ::init();
}