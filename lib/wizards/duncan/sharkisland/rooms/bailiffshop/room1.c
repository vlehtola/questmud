inherit "room/room";

reset(arg) {
if(arg) return;

add_exit("west","/wizards/duncan/sharkisland/rooms/bailiffshop/bailiffshop.c");
add_exit("up","/wizards/duncan/sharkisland/rooms/bailiffshop/room2.c");

short_desc = "Living room inside a small house";
long_desc = "The living room is quite simple looking. It's really small and\n"+
            "there are only few furnitures. An old, leather sofa is next to\n"+
            "the north wall. Two wooden chairs are placed in the northwest\n"+
            "and northeast corners. A red rug is hanging on the south wall.\n"+
            "Wooden stairs are leading to the upstairs. The room is lit up\n"+
            "with torches.\n"; 
           
  
   set_not_out(1);
   set_light(3);

items = allocate(10);
items[0] = "sofa";
items[1] = "It's made of leather. Two people can sit on it at the same time.";
items[2] = "chair";
items[3] = "The chair is made of wood.";
items[4] = "rug";
items[5] = "The rug is red. It's hanging from the south wall.";
items[6] = "stairs";
items[7] = "The stairs are leading to the upstairs.";
items[8] = "torches";
items[9] = "The torches lit up the whole room.";

}
