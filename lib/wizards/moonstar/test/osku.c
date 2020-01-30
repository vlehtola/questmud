
inherit "obj/monster";

reset(arg) {
    ::reset(arg);
    if (arg) { return; }
   set_level(150);
   set_name("rag");
    set_alias("animal");
   set_short("Xelfer Swinger the grey Elf TarNavHc");
    set_long("A fluffy looking brown bear is here eating some\n"
             "berries and growling at insects that fly around\n"+
             "it. The bear has sharp looking teeth and quite dangerous\n"+
             "claws.\n");

    set_al(1);
    set_animal(1);
    set_aggressive(0);
}

