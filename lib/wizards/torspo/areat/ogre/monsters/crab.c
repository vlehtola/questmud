
inherit "obj/monster";
  int helping_small_ones = 0;

reset(arg) {
  object armour;
  ::reset (arg);
  if(arg) { return; }
  set_level(80);
   set_spell_chance(20, "exs brr blt");
   set_spell_chance(10, "kyo brr rhj");
   set_skill("cast ice", 85);
   set_skill("cast bolt", 80);
   set_skill("mana control", 95);
   set_skill("abjuration", 75);
   set_skill ("cast vulnerability", 85);
   set_skill ("cast abjuration", 75);
   set_skill ("shielding mastery", 75);
   set_skill("stun", 100);

  set_name("crab");
  set_race("crab");
  set_short("Huge, ancient crab");
  set_long("This crab has lived here for ages. It looks ancient and has\n"+
           "a thick natural bone armour. It's huge size fills almost the whole cave and\n"+
           "the long, strong pincers can hit anyone in this room.\n");
  set_al(-2);
  set_log();
  set_aggressive(1);
  set_str(query_str() + 125);
  set_animal();
  set_extra(1);
  set_special(10);

  set_skill("deceived attack", 85);

   armour = clone_object("/wizards/torspo/areat/ogre/monsters/eq/bracelet01.c");
   move_object(armour, this_object());
   armour = clone_object("/wizards/torspo/areat/ogre/monsters/eq/belt01.c");
   move_object(armour, this_object());
}

special_move() {
  object ob;
  ob = this_player() -> query_attack();
  tell_object(ob, "Crab reaches you with his pincer and cuts deep into your flesh.\n");
  say("Crab cuts "+ob->query_name()+" with its pincer.\n", ob);
  ob->hit_with_spell(150, "physical");
}

extra() {
  if (!attacker_ob) {
   return;
  }
   if(random(12) == 0) {
    if (helping_small_ones <20) {
    move_object(clone_object("/wizards/torspo/areat/ogre/monsters/small_crab"), environment(this_object()));
   say("Huge crab draws some ancient runes in the air and a small crab appears from the dark\n"+
       "portal to aid it's master.\n");
    helping_small_ones++;
   }
  }
}
