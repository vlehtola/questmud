inherit "obj/monster";
 
reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_level(25+random(4));
    set_name("dwarf");
    set_alias("sergeant");
    set_short("A dwarven sergeant, training the conscripts");
    set_long("The short and sturdy dwarf is fully clad in his armour.\n"+
             "He is constantly yelling at everyone, because they no one\n"+
             "seems to be concentrating in training, but rather looking \n"+
             "at you.\n");
    set_al(0);
    set_gender(1);
    set_race("dwarf");
    set_aggressive(1);               
  
}









