inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("patch");
    set_alias("patch");
    set_short("The Eyepatch of the Captain");
set_long("This eyepatch is the most used on sailors. It seems to be slightly\n"+
                "different than the usual ones tho. It flows with magical aura..\n");
    set_ac(5);
    set_value(20004);
set_weight(100);
    set_stats("str", 3);
    set_stats("con", 4);
    set_stats("dex", 2);
    set_slot("head");
}  

