inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if(arg) { return; }
    set_level(5);
    set_name("woman");
    set_short("A thin older woman");
    set_long("This woman looks very old. Her eyes are red from crying and she looks\n" +
             "very miserable. She is wearing normal, plain clothes which look very worn.\n");
    set_al(10);
    set_aggressive(0);
}

