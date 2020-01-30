inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("crown");
    set_alias("crown");
    set_short("Black King's crown");
    set_long("The black crown of death is usually worn by the Black king, but fits your head like\n" +
                      "a glove.\n");
    set_material(5);
    set_ac(10);
    set_stats("str", 4);
    set_stats("con", 4);
    set_stats("hpr",6);     
   set_value(10000);
    set_weight(3);
    set_slot("head");

}
