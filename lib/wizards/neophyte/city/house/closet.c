inherit "room/room";

reset(arg) {
if(arg) return;

set_not_out(1);
set_light(1);

short_desc = "A closet";
long_desc =  "The closet full of different clothes. The clothes rack is full and almost\n"+
             "falling down. Walls are made from oak boards and they look quite hollow\n"+
             "but still sturdy enough to hold this closet up. On the floor is a couple\n"+
             "pair of boots, which look clean and shiny. Air smells here little fusty\n"+
             "and small bits of dust is floating in the air.\n" ;
add_exit("east", "house1");
  items = allocate(8);
  items[0] = "clothes";
  items[1] = "This place looks allmost full of clothes only leaving little space to move";
  items[2] = "rack";
  items[3] = "The rack is full of coats and looks like it might fall down any minute";
  items[4] = "walls";
  items[5] = "You haven't seen such a beautifully made boards that are used to made this closet";
  items[6] = "boots";
  items[7] = "A couple pairs of boots are organized on the floor";
}
