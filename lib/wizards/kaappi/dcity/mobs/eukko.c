inherit "obj/monster";

reset(arg) {
  ::reset(arg);
   if(arg) { return; }
   set_level(20+random(10));
   set_name("dwarf");
   set_alias("woman");
   set_race("dwarf");
   set_gender(2);
   set_short("A dwarven woman, cooking here");
   set_long("An ugly looking dwarven woman. She is making\n"+
            "some food here. She has badly ragged clothes and\n"+
            "she smell awful.\n");
   set_al(40);
   set_aggressive(0);

}
