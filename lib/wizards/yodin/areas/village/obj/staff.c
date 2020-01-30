#include "/sys/ansi.h"
inherit "obj/weapon";

start() {
    set_class(10);
    set_sub_type("staff");
    set_short(""+BOLD+WHITE_F+"Glimmering white staff of"+OFF+""+BOLD+RED_F+" '"+OFF+""+BOLD+BLUE_F+"frozen tears"+OFF+""+BOLD+RED_F+"'"+OFF+"");
    set_alias("staff");
    set_long("Et ole saamassa perkl.\n");
    set_stats("damage",80);
    set_stats("hit",50);
    set_stats("int", 20);
    set_stats("wis", 20);
    set_stats("spr", 20);
    set_stats("con", 20);
    set_stats("str", 20);
}
