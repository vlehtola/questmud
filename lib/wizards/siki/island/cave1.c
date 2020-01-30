inherit "room/room";
object monster;

reset(arg) {
     if(arg) return;
    if(!monster) {
        monster = clone_object("/wizards/siki/island/monsters/mineguard");
        move_object(monster, this_object());
        }
 

  add_exit("down","/wizards/siki/island/cave2");
  add_exit("east","/wizards/siki/island/v_map: 22 12");
  add_exit("southeast","/wizards/siki/island/v_map: 22 12");



  short_desc = "A cave inside the mountain";
  long_desc = "A deep, dark cave leading into the darkness. The entrance\n"+
              "is huge. The tunnel echoes quiet and regular sounds of\n"+
              "hammering.\n";
}
