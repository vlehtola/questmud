inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("shoes");
    set_alias("shoes");
    set_short("White Queen's transparent shoes");
    set_long("These shoes are transparent, and you can see your foot through it.\n" +
                      "They are not very comfortable.\n");
    set_material(3);
    set_ac(10);
    set_stats("wis", 3);
    set_stats("int", 2);
    set_stats("dex",1);
    set_stats("spr",3);
   set_value(5000);
    set_weight(2);
    set_slot("feet");

}
