inherit "room/room";


object monster;
int taken;

reset(arg) {
  if(!monster) { 
    monster = clone_object("/wizards/veron/areat/golem/mobs/igolem");
    move_object(monster, this_object()); 
set_blocker("golem", "down");
set_not_out(1);

 }

add_exit("up","/wizards/veron/areat/golem/kellari3.c");
add_exit("down","/wizards/veron/areat/golem/kellari5.c");

  short_desc = "A stinking hole";

  long_desc = "It's freezing cold in here and the air stinks badly. You wonder \n"+
              "if there's some dead animal rotting here. Spiral stairs lead up and \n"+
              "down from here. There's a bucket with oily water in the corner. A torch\n"+
 		  "has been extinguished in it.\n";
	
		  
  items = allocate(2);
  items[0] = "bucket";
  items[1] = "A bucket made of sheet metal. It is full of water. There's a layer of.\n"+
             "oil floating on the surface. A torch has probably been put out in it.";

taken=0;
}
 init() {
  ::init();
  add_action("hep", "take");
  add_action("hep", "get");
}

hep(str) {
  if(str == "bucket") {
  if(!taken) {
    write("You take a sheet metal bucket.\n");
    say(this_player()->query_name() + " takes the bucket from the ground.\n");
    move_object(clone_object("/wizards/veron/areat/golem/items/bucket"), this_player());
long_desc = "It's freezing cold here and the air stinks badly. You wonder \n"+
              "if there's some animal rotting here. Spiral stairs lead up and \n"+
              "down here.\n";
items = allocate(0);


    taken = 1;
    return 1;
  }
  else {
    return;
  }
  }
  else {
    return;
  }

  }
