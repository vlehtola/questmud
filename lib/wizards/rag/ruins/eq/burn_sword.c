inherit "obj/weapon";

start() {
  set_class(6);
  set_sub_type("broad sword");
  set_short("A flaming steel broad sword");
  set_long("The broad sword is used by strong warriors. It's strong blade is meant to\n"+
        "endure great force. The sword is the biggest and heaviest sword available.\n"+
        "It's of type blade. The blade if this sword is burning with a bright red\n"+
        "flame but the handle doesn't burn your hand.\n");

}

hit() {
  object target, room;
  int dama, p;
  if(!wielded_by || !wielded_by->query_attack()) return;

  room = environment(wielded_by);

  if(random(4) != 0) return;

  if(capitalize(wielded_by->query_name()) == "Bloodwind" && wielded_by->query_npc())
  {
        tell_room(room, "The flaming sword seems to burn brighter as Bloodwind chants dark spells!\n");
        dama = 600;
        p = 1;
  } else {
        dama = 240;
        p = 4;
  }

  if(random(p) != 0) return;

  target = wielded_by->query_attack();
  tell_room(room, "The flaming sword burns "+target->query_name()+" with unholy flames!\n");
  
  target->hit_with_spell(random(dama/2)+dama/2, "fire");
  return 1;
}
