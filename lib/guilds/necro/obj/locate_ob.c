// This object is inside the controller of the horde and works as a aiding tool
// for summon horde spell.
// Object modified by Celtron 10.06.2002


object horde;
start(object ob) {
  horde = ob;
  return 1;
}

id(str) {
  return str == "horde_summon";

}

teleport_horde() {
  object attacker;
  if(!horde) {
    write("You dont have a horde.\n");
    destruct(this_object());
    return 1;
  }
  write("You summon your horde back.\n");
  move_object(horde, environment(this_player()));
  tell_room(environment(horde), "Horde arrives from somewhere.\n");
  this_player()->reduce_sp(this_player()->query_sp());
  return 1;

}

// Used in ambushes -N
teleport_horde_free() {
 if( horde && horde->query_follow() )
   call_out("teleport_horde_free_post_delay",3);
  return 1;
}

teleport_horde_free_post_delay() {
  object attacker;
  if(!horde) {
    write("You dont have a horde.\n");
    destruct(this_object());
    return 1;
  }
  write("You summon your horde back.\n");
  move_object(horde, environment(this_player()));
  tell_room(environment(horde), "Horde arrives from somewhere.\n");
  return 1;

}

drop() {
  return 1;
}

get() {
  return 0;
}

query_weight() {
  return 0;
}


