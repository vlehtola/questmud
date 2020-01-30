inherit "room/room";

object monster;

reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/ozmala/areat/wine-cellar/mobs/mob");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("south","wizards/ozmala/areat/wine-cellar/rooms/room2");
  short_desc = "Wine cellar";
  long_desc =
"You are standing in a large wine cellar, there are several torches on\n" +
"the wall's lighting up the place. There is a sour odor in here, it must\n" +
"be coming out of those several oaken barrels all around the room. Poorly\n" +
"builded wall's surround you, you can see some loosened tiles here and there.\n"; 
  items = allocate(6);                
  items[0] = "barrel";
  items[1] = "Old oaken barrel full of old vintage wine";
  items[2] = "torch"; 
  items[3] = "A torch burning with a frail light";
  items[4] = "wall";
  items[5] = "These walls were build many years ago, they are obviously made by some weak race" +
"because of their lousy condition. There are many loosened tiles hear and there.";
  property = allocate(1);
  property[0] = "no_summon";
  set_light(3);
}
