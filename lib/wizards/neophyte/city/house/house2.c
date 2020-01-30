inherit "room/room";

reset(arg) {
if(arg) return;

set_not_out(1);
set_light(2);

short_desc = "A living room";
long_desc =  "The living room of the lowie family, the room looks cosy and\n"+
             "relaxing. A nice fireplace is built on the north wall from\n"+
             "white bricks, but the bricks aren't still smutted. In front of the\n"+
             "fireplace is small holder of handlebars. Walls look skillfully made\n"+
             "from large logs and they are maintained correcly, because there are no\n"+
             "cracks or spiderwebs. Couple of stuffed hunting memories are placed\n"+
             "hanging on the walls, they seem to be elks and deer heads. The floor\n"+
             "is also made from sturdy logs, which is finished with care because you\n"+
             "can walk bare footed, without getting sticks on your foot. On\n"+
             "the floor is placed large hide of bear.\n";
  add_exit("west", "kitchen");
  add_exit("east", "bedroom");
  add_exit("south", "house1");
}


