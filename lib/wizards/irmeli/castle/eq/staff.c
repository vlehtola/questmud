inherit "obj/weapon";

start() {
    set_class(8);
    set_sub_type("morningstar");
    set_name("staff");
    set_short("Silver staff");
    set_long("The silver staff is beautiful. It's quite old and it feels magical.\n"+
             "It's decorated with blue crystals. The handle of the staff is\n"+
             "reinforced with titanium.\n");
    set_stats("damage",2);
    set_stats("hit",2);
    set_stats("spr",10);
}

