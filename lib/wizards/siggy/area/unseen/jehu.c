inherit"obj/monster";
int number_of_guards;
object armour;
object weapon; 

reset(arg) {
  :: reset(arg);
  number_of_guards = 0;
  if(arg) { return; }
  set_name("jehu");
  set_level(65);
  set_ep(8000);
  set_al(10);
  set_al_aggr(200);
  set_alias("wizard");
  set_race("human");
  set_short("A leader of the Unseen University 'Jehu'");
  set_long("Small man with long beard. He sits behind his desk. Beard is grey and thick.\n"
           + "He looks very nice and he won't harm you unless you try to harm him. He has a\n"
           + "thoughtful looks on his face. He surely has a problem to work out.\n");
  set_extra(1); 
  set_aggressive(0);
  set_spell_chance(100, "exs brr blt");
  set_dead_ob(0);
  set_skill("cast essence", 100);
  set_skill("cast cold", 100);
  set_skill("cast bolt", 100);
  set_skill("attack", 100);
  set_skill("stun", 70);
  set_skill("critical", 70);
  set_skill("find weakness", 80);
  set_skill("pound", 60);
  set_skill("bludgeons", 60);

    armour = clone_object("/wizards/siggy/area/unseen/jehurobe");
    move_object(armour, this_object());
    init_command("wear robe");

    weapon = clone_object("/wizards/siggy/area/unseen/jehustaff");
    move_object(weapon, this_object());
    init_command("wield staff");

}
extra() {
    object guard;
    if (!attacker_ob) {
         return;
    }
    if(random(number_of_guards + 1) == number_of_guards) {
        guard = clone_object("/wizards/siggy/area/unseen/jehuguard");
        move_object(guard, environment(this_object()));
        say("After the wild whistle, a tough looking guards runs in.\n");
        number_of_guards += 1;
 }
}

reduce_number() {
    number_of_guards -= 1;
}
