inherit "obj/armour";

start() {
    set_class(1);
    set_sub_type("necklace");
    set_name("necklace");
    set_short("A broken necklace");
    set_long("This is an old necklace. It seems to have had somekind\n" +
                 "of stone in the middle. It is broken.\n");
    set_stats("spr", 1);
    set_slot("neck");
}
