inherit "obj/armour"; 
 
reset(arg) {
    ::reset(arg);
    set_name("leggings");
    set_alias("pants");
    set_short("Twisted leggings of rulership");
    set_long("These, darkbrown leggings are not normal. They are abstract in somekind of way.\n");
    set_value(50000);
    set_stats("con", 5);
    set_stats("str",10);
    set_stats("hpr",13);
    set_weight(100);
    set_slot("legs");
}
