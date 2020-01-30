inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_level(21+random(4));
    set_name("scavenger");
    set_alias("beast");
    set_short("A scavenger beast");
    set_long("The creature bears no resemblance to anything you've\n"+
             "seen before. The beast is about the size of a large cat\n"+
             "but has a tail of a beaver. Its face looks that of a\n"+
             "rat's, with two huge incisors, used to bite into rotten\n"+
             "flesh.\n");
    set_al(-42);
    set_animal();



}

