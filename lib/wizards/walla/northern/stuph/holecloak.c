inherit "obj/armour";

start() {
    set_class(9);
    set_slot("cloak");
    set_name("cloak");
    set_alias("hoovee");
    set_short("The cloak of castle North Face <ripped>");
    set_long("This is the cloak of castle North Face. In the\n"+
             "middle of the cloak is a huge hole, from where the symbol\n"+
             "was removed. It still seems to protect you from the cold\n"+
             "as well as before, and now it looks even cooler.\n");
    set_resists("cold", 33);
    set_stats("str",8);
    set_stats("con",8);
    set_stats("hpr",10);
    set_weight(5);
    set_value(5000);

}
