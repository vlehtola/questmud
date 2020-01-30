inherit "room/room";
object monster01, spec, ob;
int h;

reset(arg) {
  add_exit("north", "/wizards/ahma/castle/rooms/area07");
  add_exit("up", "/wizards/ahma/castle/rooms/area09a");
  short_desc = "Stairway entrance";
  long_desc = "A dark and dusty room: Entrance to watch tower.\n" + 
              "There is very little light in this room. The walls are made of\n" + 
              "the same stone as the corridor leading to this post. The room is\n" + 
              "untidy and the stench of rotting corpses from the room behind is\n" + 
              "mixed with a smell of sweat. The stairway which leads to the\n" + 
              "actual tower is lit with torches.\n";
  property = ({"no_summon"});


/*  if(!spec) {
    if(!h) {
    spec = clone_object("/wizards/ahma/castle/mob/spec07");
    move_object(spec, this_object());
    }
  }*/

  if(!monster01) {
    if(!h) {
    monster01 = clone_object("/wizards/ahma/castle/mob/mob19");
    move_object(monster01, this_object());
    }
  }
}

quest_complete() {
  add_exit("north", "/wizards/ahma/castle/rooms/area07");
  add_exit("up", "/wizards/ahma/castle/rooms/area09a");
  h++;
}

quest3() {
  destruct(present("guard", this_object()));
  call_out("quest4", 2);
}


quest4() {
  tell_room(this_object(), "\nYou hear some distant sounds of battle.\n");
  call_out("quest5", 3);
}

quest5() {
  tell_room(this_object(), "\nSuddenly, a bright blue light explodes in from upstairs and you hear\n" + 
      "a scream full of agony. Guard's head bounces down from stairs and stains\n" +
      "of blood splat on the wall one floor above you.\n");
  call_out("quest6", 3);
}

quest6() {
  tell_object(this_player(), "\nYou guess that's it. The guard is dead, R.I.P. And you lost your valuable\n" + 
      "weapon, too.\n");
  call_out("quest_complete", 2);
}