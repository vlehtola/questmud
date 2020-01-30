inherit "room/room";
int h = random(3), open;
object mob;

reset(arg) {
  add_exit("north", "/wizards/ahma/orc/forest/sub09");
  add_exit("south", "/wizards/ahma/orc/forest/sub03");
  add_exit("east", "/wizards/ahma/orc/forest/sub05");
  short_desc = "Entrance to an underground opening";
  long_desc = read_file("/wizards/ahma/orc/forest/subdesc") + 
              "A hole is leading up from here.\n";
  
  items = allocate(2);
  items[0] = "hole";
  if(!open) {
  items[1] = "The hole seems to be blocked from up by a pile of rocks. You cannot\n" + 
             "remove the rocks from here because they would fall over you if you\n" + 
             "would even try to touch them";
  }
  if(!mob) {
    if(h==0) { move_object(mob = clone_object("/wizards/ahma/orc/mob/elemental01"), this_object()); }
    if(h==1) { move_object(mob = clone_object("/wizards/ahma/orc/mob/elemental02"), this_object()); }
    if(h==2) { move_object(mob = clone_object("/wizards/ahma/orc/mob/elemental03"), this_object()); }
  }
}

exit_open() {
  items[1] = "A soft light is illuminating in from the hole which is leading upwards";
  open = 1;
}

exit_closed() {
  items[1] = "The hole seems to be blocked from up by a pile of rocks. You cannot\n" + 
             "remove the rocks from here because they would fall over you if you\n" + 
             "would even try to touch them";
  open = 0;
}