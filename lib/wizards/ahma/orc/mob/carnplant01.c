inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3) + 30);
  set_name("plant");
  set_short("An angered carnivorous plant");
  set_long("Strange-looking green plant stands on the floor and swings furiously.\n" + 
           "Numerous small mouths full of sharp teeth grow from its trunk. In few\n" + 
           "mouths can be seen pieces of greenish Orc skin, like the plant would\n" + 
           "have tried to eat someone alive.\n");

  set_max_hp(query_hp() + 4000);
  set_hp(query_max_hp());
  set_aggressive(1);
  set_str(query_str() * 2);
  set_animal();
  set_dead_ob(this_object());
  set_al(-30);
}

monster_died() {
  tell_room(environment(this_object()), "As the carnivorous plant scatters into pieces, two more plants jump down from their pots and attack.\n");
  move_object(clone_object("/wizards/ahma/orc/mob/carnplant02"), environment(this_object()));
  move_object(clone_object("/wizards/ahma/orc/mob/carnplant03"), environment(this_object()));
  return 0;
}
