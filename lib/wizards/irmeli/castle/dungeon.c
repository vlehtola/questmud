inherit "room/room";
inherit "room/door";
object monster;
reset(arg) {

if(arg) return;

if(!monster) {
monster = clone_object("/wizards/irmeli/castle/monsters/masterknight.c");
move_object(monster, this_object());

}

short_desc = "Dungeon of the castle Asgroth";
long_desc = "A dungeon has been carved in rock, deep inside the earth. The ground is damp\n"+ 
            "and muddy. The walls of the dungeon are covered with moss. The dungeon is a\n"+
            "creepy place to be held. You can see chains hanging from the walls and ceiling.\n"+
            "Pieces of different sized bones are lying among the mud. The dungeon is cold\n"+
            "gloomy.\n";
  
   items = allocate(4);
   items[0] = "chains";
   items[1] = "There are more than ten rusty chains hanging from the walls and from the ceiling.";
   items[2] = "bones";
   items[3] = "Pieces of different sized bones are lying among the mud.";



  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";


  door_reset();
  set_door_label("Dungeon door", 1);
  set_door_dir("south", "/wizards/irmeli/castle/well.c", 1);
  set_door_link("/wizards/irmeli/castle/well.c", 1);
  set_door_code("447", 1);
  set_locked(1, 1);
}


init() {
  ::init();
  door_init();
}
