inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    set_slot("neck");
    set_name("collar");
    set_short("Collar of the Lost Souls >>Corrupted<<");
    set_long("The sparkling white collar is ringed with a single, red line. The soft\n"+
             "touch of the collar can be only felt by wearing it. A text is written\n"+
             "in the collar by neat handwriting. It symbols the signature of the maker\n"+
             "of this collar");
    set_value(3000);
    set_weight(200);
    set_stats("int", 5);
    set_stats("spr", 7);
    set_stats("wis", 4);
    set_stats("con", 1);
}
