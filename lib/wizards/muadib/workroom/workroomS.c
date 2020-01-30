inherit "room/room";
object monster;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/muadib/projects/katti");
    move_object(monster, this_object());
  }
  if(arg) return;

  add_exit("north","/wizards/muadib/workroom");
  short_desc = "A room";
  long_desc = "The monster room\n";
  set_light(3);


}
