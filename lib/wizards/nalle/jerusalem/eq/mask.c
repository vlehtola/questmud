inherit "obj/armour";

start() {
    set_class(2);
    set_sub_type("helm");
    set_name("mask");
    set_short("A metal mask");
    set_long("A metal mask, with holes on it to make you able\n" +
                    "to breathe, see and hear.\n");
    set_stats("str", 1);
    set_stats("con", 1);
    set_stats("hpr", 3);
    set_slot("head");
}
