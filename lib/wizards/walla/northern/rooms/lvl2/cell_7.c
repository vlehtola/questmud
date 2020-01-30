inherit "room/room";
 
object monster;
 
reset(arg) {
  if(!monster) {
    monster = clone_object("/wizards/walla/northern/mobs/conscript");
    move_object(monster, this_object());
  }
  if(arg) return;
  add_exit("west","court_15");
  short_desc = "In the barracks";
  long_desc =
  long_desc =
"You are standing inside a small barracks room. Ten piles of hay are on the floor, which\n" +
"serve as beds for the weary soldiers when they return from their duties. Some chests are\n" +
"on the floor, which contain the soldiers items. A small hole in one corner serves as the\n" +
"sanitary part of the room, and the smell that it creates is not of the best ones.\n";
 
}
