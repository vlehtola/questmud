inherit "room/room";
object monster;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/cotd/mobs/carcass");
    move_object(monster, this_object());
  }

if(arg) return;

add_exit("southeast","/wizards/veron/areat/cotd/office.c");

  short_desc = "A dusty path";

  long_desc = "A dusty narrow path leading to the mountains. The iron mine\n"+
              "is to the north, but it's entrance has been blocked with large\n"+
	      "boulders. In the other end of the path is the mining office\n"+
              "building.\n";
              

  items = allocate(2);
  items[0] = "boulders";
  items[1] = "Huge boulders blocking the mine entrance";


 	
  }
