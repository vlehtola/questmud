inherit "obj/armour"; 
 
start() {
set_class(2);
  set_slot("finger");
    set_name("ring");
    set_alias("ring");
    set_short("Ring of Ice <Blue Glow>");
    set_long("The Ring of Ice seems to freeze your hand, but actually makes you feel better");
    set_value(5000);
    set_stats("int",2);
    set_stats("wis",2);
    set_stats("str",1);
    set_stats("spr",2);
    set_weight(0);
    set_resists(20,2);
}
