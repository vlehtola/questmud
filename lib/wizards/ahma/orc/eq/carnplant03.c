inherit "obj/monster";
object root;

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3) + 23);
  set_name("plant");
  set_short("An angered carnivorous plant");
  set_long("Strange-looking green plant stands on the floor and swings furiously.\n" + 
           "Numerous small mouths full of sharp teeth grow from its trunk, in few\n" + 
           "mouths can be seen pieces of greenish Orc skin, like the plant would\n" + 
           "have tried to eat someone alive.\n");

  set_max_hp(query_hp() + 3000);
  set_hp(query_max_hp());
  set_str(query_str() * 2);
  set_animal();
  set_aggressive(1);

  if(!root) { move_object(clone_object("/wizards/ahma/orc/eq/root"), this_object()); }
}