
inherit "obj/monster";
  int helping_small_ones = 0;

reset(arg) {
  object armour;
  ::reset (arg);
  if(arg) { return; }
  set_level(82);
   set_spell_chance(15, "exs sol blt");
   set_skill("cast essence", 50);
   set_skill("cast earth", 50);
   set_skill("cast bolt", 50);
   set_skill("mana control", 85);
  set_name("crab");
  set_race("crab");
  set_short("Huge, ancient crab");
  set_long("This crab has lived here for ages. It looks ancient and has\n"+
           "a thick natural bone armour. It's huge size fills almost the whole cave and\n"+
           "the long, strong pincers can hit anyone in this room.\n");
  set_al(-2);
  set_log();
  set_aggressive(1);
  set_al_aggr(200);
  set_animal();
  set_extra(1);

   armour = clone_object("/wizards/torspo/areat/ogre/monsters/eq/bracelet01.c");
   move_object(armour, this_object());
   armour = clone_object("/wizards/torspo/areat/ogre/monsters/eq/belt01.c");
   move_object(armour, this_object());
}

extra() {
  if (!attacker_ob) {
   return;
  }
    if (helping_small_ones <10) {
    move_object(clone_object("/wizards/torspo/areat/ogre/monsters/small_crab"), environment(this_object()));
   say("Huge crab draws some ancient runes in the air and a small crab appears from the dark\n"+
       "portal to aid it's master.\n");
    helping_small_ones++;
  }
}
