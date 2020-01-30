inherit "obj/weapon";

start() {
    set_class(8);
    set_sub_type("long sword");
    set_short("Silver long-sword of Chivalry");
    set_long("The long-sword is made of silver. Its titanium handle is decorated\n"+
             "with gold carvings. The edge of the sword is long, broad and it shines\n"+
             "like just made. The sword belongs to the master knight.\n");
    set_stats("damage",5);
    set_stats("hit",8);
    set_stats("str",5);
}

