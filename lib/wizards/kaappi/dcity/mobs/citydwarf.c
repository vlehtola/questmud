inherit "obj/monster";
string chat_str;

reset(arg) {
  ::reset(arg);
   if(arg) { return; }
   set_level(10+random(10));
   set_name("dwarf");
   set_race("dwarf");
   set_gender(1);
   set_short("A dwarf walking on the stree");
   set_long("An ugly looking dwarven woman. She is making\n"+
            "some food here. She has badly ragged clothes and\n"+
            "she smell awful.\n");
   set_al(40);
   set_aggressive(0);

}
