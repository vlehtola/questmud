/* Bludgeons do damage mostly with weigth. */

inherit "obj/weapon";

reset(arg) {
    ::reset(arg);
    set_name("mace");
    set_long("This is a typical iron mace, that Duranghoms smithes produce.\n");
    set_weapon_type("bludgeon");
    set_wc(40);
    set_value(500);
    set_weight(5);
}
