inherit "obj/monster";
object lappu;

reset(arg) {
  ::reset(arg);
   if(arg) { return; }
  set_level(40+random(5));
   set_name("guard");
   set_alias("guard");
   set_race("dwarf");
   set_gender(1);
   set_short("An evil looking guard");
   set_long("An evil looking city guard. He is sitting on the\n"+
            "chest, rubbing his hands together. There is something\n"+
            "in his pocket.\n");
   set_al(-80);
   set_aggressive(0);

lappu = clone_object("/wizards/kaappi/dcity/items/paper.c");
move_object(lappu, this_object());
}
