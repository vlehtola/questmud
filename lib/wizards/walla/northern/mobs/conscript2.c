inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_level(21+random(4));
    set_name("dwarf");
    set_alias("conscript");
    set_short("An exhausted dwarven conscript");
    set_long("The short and sturdy dwarf is fully clad in his armour.\n"+
             "The dwarf does not seem to be in such a good shape, and seems\n"+
             "to have been out training all day, with little food and much to\n"+
             "learn. Yet, he looks quite skilled.\n");
    set_al(0);
    set_gender(1);
    set_race("dwarf");
    set_aggressive(1);               
  
}



