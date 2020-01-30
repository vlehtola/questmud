inherit "room/room";



object monster,monster2,monster3;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/cotd/mobs/pigeon");
    move_object(monster, this_object());
  }
  if(!monster2) {
    monster2 = clone_object("/wizards/veron/areat/cotd/mobs/pigeon");
    move_object(monster2, this_object());
}
 if(!monster3) {
    monster3 = clone_object("/wizards/veron/areat/cotd/mobs/pigeon");
    move_object(monster3, this_object());
}


add_exit("south","/wizards/veron/areat/cotd/street3.c");
add_exit("north","/wizards/veron/areat/cotd/mayor1.c");
add_exit("northwest","/wizards/veron/areat/cotd/office.c");
add_exit("northeast","/wizards/veron/areat/cotd/ceme1.c");
add_exit("west","/wizards/veron/areat/cotd/park1.c");
add_exit("east","/wizards/veron/areat/cotd/store.c");

  short_desc = "cs";

  long_desc = "The central square of the town must have been quite nice. There's\n"+
	      "even a small fountain in the middle of it. Now that the town is \n"+
              "abandoned, the fountain has dried and it's full of sand. The ground\n"+
              "is covered with stone tiles, now cracked and dusty. To the west\n"+
              "there's a lot of trees and bushes, maybe a park. A large building\n"+
              "in the east has a battered sign in it's wall, reading 'The general\n"+
              "store.\n";
              

  items = allocate(6);
  items[0] = "fountain";
  items[1] = "A small dried fountain full of sand";
  items[2] = "tiles";
  items[3] = "Small stone tiles covering the ground. Some of the tiles are missing and\n"+
             "cracked";
  items[4] = "sign";
  items[5] = "The sign says 'General store', in decorative letters";

 	
  }
