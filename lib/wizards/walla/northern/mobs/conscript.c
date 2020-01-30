inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_level(23+random(4));
    set_name("dwarf");
    set_alias("conscript");
    set_short("A dwarven conscript, guarding the barracks");
    set_long("The short and sturdy dwarf is fully clad in his armour.\n"+
             "He looks as though he is about to faint any time soon now,\n"+
             "because the immense heat and the position of attention he is\n"+
             "standing in.\n");
    set_al(0);
    set_gender(1);
    set_race("dwarf");
    set_aggressive(1);               
  
}
