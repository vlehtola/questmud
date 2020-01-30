inherit "obj/armour";
 
reset(arg) {
    ::reset(arg);
    set_name("necklace");
    set_alias("necklace");
    set_short("Bone necklace of blood");
    set_long("This necklace has been made of human bones.\n",
             "It glows bloodred aura of rage.\n");
    set_ac(10);
    set_value(4000);
    set_weight(3);
    set_stats("str", 5);
    set_stats("dex", 8);
    set_slot("neck");
}
