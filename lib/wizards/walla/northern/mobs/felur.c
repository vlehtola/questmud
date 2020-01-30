inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_level(10);
    set_name("dwarf");
    set_alias("felur");
    set_short("Felur, a female dwarf");
    set_long("Female dwarves are rarely seen, and they look quite peculiar.\n"+
             "They look pretty much the same as males, apart from the beard.\n"+
             "Instead they have long sideburns and and some single strands of\n"+
             "hair on their chins.\n");
    set_al(0);
    set_gender(2);
    set_race("dwarf");
 
 
}
