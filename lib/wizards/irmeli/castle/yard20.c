inherit "room/room";
object monster;
reset(arg) {
if(!monster) { 
monster = clone_object("/wizards/irmeli/castle/monsters/wtowerguard.c");
move_object(monster, this_object());
}
if(arg) return;
add_exit("southeast","/wizards/irmeli/castle/yard19.c");


short_desc = "In front of the west tower";
long_desc = "Standing by the west tower. The tower is so high that you can't see its top\n"+
            "from here. The tower is made of solid rock and there are no windows. You\n"+
            "can't see any door or such in the tower. The tower is circular and painted\n"+  
            "with black paint. There are footprints on the ground, ending to the tower\n"+
            "wall. A door frame can be perceived on the wall, where the footprints ends.\n";

set_light(4); 

   items = allocate(6);
   items[0] = "tower";
   items[1] = "The west tower is high. It's made of solid rock and there are no windows in it.";
   items[2] = "footprints";
   items[3] = "Footprints have been left on the ground. They end to the tower wall.";
   items[4] = "door frame";
   items[5] = "A door frame can be seen on the tower wall. There's no way to open the door.";


  property = allocate(5);
  property[0] = "no_summon";
  property[1] = "no_tele";
  property[2] = "no_spell";
  property[3] = "no_skill";
  property[4] = "no_kill";
}
