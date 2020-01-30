inherit "room/room";
object monster;

reset(arg) {
if(arg) return;
        if(!present("woman")) {
           move_object(clone_object("/wizards/jenny/mehta/mosut/woman.c"), this_object());
        }      

        add_exit("out","/wizards/jenny/mehta/huoneet/forest17.c");
        
  short_desc = "In a small hut";
  long_desc = "Cosy looking old hut, you can see a huge cauldron\n"+
              "in the middle of the hut. There are also some\n"+
              "mysterious looking potions on the shelves that are\n"+
              "hanging from the wall. The ground is pretty odd,\n"+
              "because it's only covered with reed and some\n"+
              "leaves.\n";

 
        items = allocate(8);
        items[0] = "cauldron";
        items[1] = "Someone has been cooking some odd liquid here.";
        items[2] = "potions";
        items[3] = "Potions of various colours and sizes.";
        items[4] = "shelves";
        items[5] = "Wooden shelves hanging on the wall.";
        items[6] = "ground";
        items[7] = "There are reed and leaves on the ground.";
}
