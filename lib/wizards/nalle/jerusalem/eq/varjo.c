object aijys,risti;
int still;
start(ob) {
  aijys = ob;
  shadow(aijys, 1);
  call_out("normal", 125);
  move_object(this_player(),"/wizards/nalle/jerusalem/golpath");
  risti = clone_object("/wizards/nalle/jerusalem/eq/risti"); 
  move_object(risti, this_player());
  call_out("goto_loop", 5);
  call_out("antiloop", 13);
  return 1;
}

goto_loop() {
write("The citizens seem satisfied with their new victim and aim their rocks at you.\n");
write("You grunt in pain as sharp rocks hit your body.\n");
this_player()->reduce_hp(random(100)+100);
call_out("indefinate_loop", 15);
return 1;
}

indefinate_loop() {
  if (still != 21) {
  write("You grunt in pain as sharp rocks hit your body.\n");
  say(call_other(this_player(), "query_name", 0) + " roars in pain as rocks hit him.\n");  
  this_player()->reduce_hp(random(130)+120);
  call_out("indefinate_loop",random(15)+5); 
  } else { return; }
  return 1;
}

antiloop() {
  if (still != 21) {
  write("Prodded by the soldiers you move along the path.\n");
  say(call_other(this_player(), "query_name", 0) + " moves along.\n");
  call_out("antiloop",random(20)+25);
  } else { return; }
  return 1;
}

normal() {
  object puuh;
  still = 21;
  puuh = allocate(1);
  puuh[0] = aijys;
  tell_object(aijys, "The soldiers start mounting the cross.\n");
  call_out("eppunormal", 13);
  return 1;
}

eppunormal() {
  write("The crucifix is now in place. The soldiers start attaching you to it.\n");
  call_out("sluut", 6);
}

sluut() {
  object puuh;
  puuh = allocate(1);
  puuh[0] = aijys;
  tell_object(aijys, "After 3 strokes of a hammer you pass out and choke to death.\n");
  tell_room(environment(aijys), aijys->query_name()+" is crucified.\n",puuh);
  if (!aijys->query_quests("Help the wounded man"))  {
    tell_object(aijys, "You complete the 'Help the wounded man' quest.\n");
    call_other(aijys, "set_quest", "Help the wounded man");
  } else {
    write("You have already completed this quest.\n");
  }
  this_player()->reduce_hp(50000);
  if(risti) destruct(risti);
  if (this_object()) { destruct(this_object()); }
  return 1;
}  

death(arg) {
  if (still != 21) { 
  write("Death overcomes.\n"); 
  destruct(risti);
  } 
  aijys->death(arg);
  destruct(this_object());
  return;
}

