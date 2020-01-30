inherit "room/room";
object monster01;

reset(arg) {
  if(arg) return;
    if (!monster01) {
      monster01 = clone_object("/wizards/ahma/castle/mob/mob24"); 
      move_object(monster01, this_object());
    }
    
  add_exit("up", "/wizards/ahma/castle/rooms/area52");
  short_desc = "Fifth floor of the tower";
  long_desc =  "On the sixth floor of the Demon Tower.\n" + 
               "The room looks shocking. Most of the killed guards have been dragged here.\n" + 
               "There is guards nailed on the walls, and those which are laying on the floor\n" + 
               "are waiting for their turn to be nailed up. Some of the guards laying on the\n" + 
               "floor are still alive and groaning in agony. No one can help these cursed souls\n" + 
               "anymore. There is human blood everywhere. The stench is unbelievably horrible.\n" + 
               "Room gets its illumination from the corpses on the walls. The glowing stones\n" + 
               "have been pierced through these poor guards. The captain of the guards has been\n" + 
               "separated from the normal castle guards. His stomach has been penetrated with a\n" + 
               "big-sized glowing stone, and his bowels have fallen on the rock, making the\n" + 
               "glow less bright. There is a hole in the ceiling in north.\n";
  items = allocate(8);
  items[0] = "hole";
  items[1] = "The hole seems to lead to the roof of this tower, and more light is coming in\n" + 
             "this room from there. The hole is too high for you to reach it from the ground";

  set_not_out(1);
}

props() {
  property = ({"no_kill", "no_skill", "no_spell", "no_summon"});
  return;
}