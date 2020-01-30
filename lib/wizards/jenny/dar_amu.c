#include <ansi.h>
inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("amulet");
    set_alias("medallion");
    set_short("Gold medallion won from bidding olympics <"+sprintf("%c",27)+"[1;1;30m"+"Foolish glow"+OFF+">");
    set_long("This is the best amulet!\n"+
             "Or is it?");
    set_ac(1);
    set_value(1);
    set_stats("int", -40);
    set_stats("wis", -40);
    set_stats("str", -40);
    set_stats("con", -40); 
    set_stats("dex", -40);
    set_slot("amulet");

}
