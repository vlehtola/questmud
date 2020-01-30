
inherit"obj/monster";

reset(arg) {
  object armour;
  object armour2;
  ::reset(arg);
  if(arg) { return; }
  set_name("elshwitch");
  set_gender(1);
  set_level(40);
  set_ep(5600);
  set_al(10);
  set_al_aggr(200);
  set_alias("wizard");
  set_race("human");
  set_short("Apprentice wizard Elshwitch");
  set_long("Wizard dressed in blue robe. His name is Elshwitch and he's a son of a witch\n"
         + "He is the most youngest member of the university. Elshwitch doesn't have beard\n"
         + "unlike nearly all other wizards. There is little thimble in his finger.\n");
  set_aggressive(0);
  set_spell_chance(90, "exs fla blt");
  set_dead_ob(0);
  set_skill("attack", 100);
  set_skill("stun", 40);
  set_skill("find weakness", 45);
  set_skill("cast essence", 90); 
  set_skill("cast fire", 90);  
  set_skill("cast bolt", 90);

    armour = clone_object("/wizards/siggy/area/unseen/elshrobe");
    move_object(armour, this_object());
    init_command("wear robe");

    armour2 = clone_object("/wizards/siggy/area/unseen/elshthimb");
    move_object(armour2, this_object());
    init_command("wear thimble");

}
