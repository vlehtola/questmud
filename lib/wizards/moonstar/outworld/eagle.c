inherit "obj/monster";
object ob;

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+21);
  set_name("eagle");
  set_alias("animal");
  set_short("A great eagle");
  set_long("A brown-coloured great eagle is gently brushing its wings with its yellow\n" + 
           "beak. The feathers in eagle's neck are white, almost gray. Seeing an eagle\n" + 
           "in here is an extremely rare sight because they tend to live in forests\n" + 
           "far away from humanoid settlements. Being on the ground makes the eagle\n" + 
           "much more vulnerable to hostile attacks, than if it would sit on the branch\n" +
           "of a tree. Great eagles are known to be good hunters.\n");
  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Eagle flaps its huge wings.\n";
    chat_str[1] = "Eagle digs the ground with its beak.\n";
    chat_str[2] = "Eagle observes your moves suspiciously.\n";
  }
  load_chat(3, chat_str);
  
  set_animal();
  set_special(15);
  set_al(30);
}

special_move() {
  ob = this_object()->query_attack();
  tell_room(environment(this_object()), "Eagle flies high up in the sky.\n");
  move_object(this_object(), "/wizards/ahma/orc/void");
  call_out("spec2", (random(8)+3), ob);
  return 1;
}

spec2(ob) {
  move_object(this_object(), environment(ob));
  tell_room(environment(this_object()), "Eagle dives down from the sky and attacks.\n");
  attack_object(ob);
  return 1;
}
