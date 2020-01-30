inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("boots");
    set_alias("boots");
    set_short("Black Queen's boots");
    set_long("These black leather boots were worn by the black queen to intimidate all her\n" +
                      "opponents.\n");
    set_material(3);
    set_ac(10);
    set_stats("str", 3);
    set_stats("con", 2);
    set_stats("dex",1);
    set_stats("hpr",3);
   set_value(5000);
    set_weight(2);
    set_slot("feet");

}
