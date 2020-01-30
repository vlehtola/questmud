inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_slot("head");
    set_name("golden crown");
    set_alias("crown");
    set_short("A golden crown");
    set_long("This is the golden crown of the King. The only thing you can\n"+
             "seem to find out about this crown is that it must hurt if you wear it.\n");
    set_ac(5);
    set_value(1);
    set_weight(100);
    set_stats("hpr", -30);
}
