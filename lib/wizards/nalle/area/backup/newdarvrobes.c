inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_name("Robes");
    set_alias("robes");
    set_short("Robes of Final Darkness");
    set_long("As you lift your gaze upon the robes, your eyes lose focus\n" +
                    "and you see images of plague, death and blood. You \n" +
                    "suddenly regain your correct vision of the world as\n" +
                    "you faintly hear echos of roaring laughter\n");
    set_ac(42);
    set_value(11000);
    set_weight(3);
    set_stats("wis", 13);
    set_stats("int", 13);
    set_stats("spr", 13);
    set_slot("cloak");
}
