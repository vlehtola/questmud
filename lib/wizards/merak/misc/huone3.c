inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/merak/misc/monsu2");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("east","wizards/merak/misc/huone2");
  short_desc = "A good way up on the stairs";
  long_desc =
"You are a good way up on the stirs. The grounds below you start\n" +
"to disappear, although ahead of you, mountains still stand very\n" +
"high above you. A frisk mountain breeze has caught up with you,\n" +
"and blows gently in your hair. The low hanging clouds are ever \n" +
"closer to you.\n";

}