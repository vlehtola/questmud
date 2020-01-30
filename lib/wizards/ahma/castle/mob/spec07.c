inherit "obj/monster";

id(str) { return str == "spec"; }

catch_tell(str) {
  string tmp;
  if(sscanf(str,"Guard %s up.", tmp) == 1) {
  quest3();
  return;
  }
}

quest3() {
call_out("quest4", 3);
}

quest4() {
  say("You hear some distant sounds of battle.\n");
  call_out("quest5", 3);
}

quest5() {
  say("Suddenly, a bright blue light explodes in from upstairs and you hear\n" + 
      "a scream full of agony. Guard's head bounces down from stairs and stains\n" +
      "of blood splat on the wall one floor above you.\n");
  call_out("quest6", 3);
}

quest6() {
  say("You guess that's it. The guard is dead, R.I.P. And you lost your valuable\n" + 
      "weapon, too.\n");
  call_out("quest7", 3);
}

quest7() {
  call_other("/wizards/ahma/castle/rooms/area08", "quest_complete");
  destruct(this_object());
}