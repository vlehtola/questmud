inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("ring");
    set_alias("ring");
    set_short("Ring of chaos");
    set_long("This is a golden ring decorated with one black pearl. The pearl radiates with power and\n"
             "legends say the wearer of this ring gains extra abilities. The ring is engraved with\n"
             "runes impossible to understand. Ring of chaos glows in the darkness.");
    set_ac(5);
    set_value(5000);
    set_stats("int", 5);
    set_stats("wis", 10);
    set_stats("con", -10);
    set_stats("spr", 25);
set_slot("finger");

}
