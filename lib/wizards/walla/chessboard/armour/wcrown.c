inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("crown");
    set_alias("crown");
    set_short("White King's crown");
    set_long("The white crown glows white like the snow and seems to be pulsating a magical aura\n" +
                      "around you.\n");
    set_material(5);
    set_ac(10);
    set_stats("int", 5);
    set_stats("wis", 4);
    set_stats("dex",3);
    set_stats("spr",6);     
   set_value(10000);
    set_weight(3);
    set_slot("head");

}
