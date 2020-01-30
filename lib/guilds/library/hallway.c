inherit "room/room";

object mob;

reset(arg) {
  if(!mob) mob = clone_object("/guilds/library/mathematician");
  move_object(mob, this_object());
if(arg) return;

set_not_out(1);
set_light(3);

add_exit("west","/world/city/diamond6");
add_exit("south","/guilds/library/mainhall.c");

short_desc = "A hallway leading to the library of Duranghom";
long_desc =
"A broad hallway, entrance to the library of Duranghom, is decorated with\n"+
"paintings and pictures, which are hanging on the granite walls. The library\n"+
"is old, but it was renovated and now it's re-opened again. Dust or dirt\n"+
"can't be seen even in the corners or floor. The floor is treated with wax,\n"+              
"and therefore it's slippery but clean. Burning torches are placed on the\n"+
"granite walls, on both sides of you, among the paintings and pictures.\n"+
"Towards south is a massive library mainhall, with shelves full of books\n"+
"and old scrolls.\n";

   items = allocate(6);
   items[0] = "torches";
   items[1] = "The torches are burning on both sides of you, on the walls of the hallway";
   items[2] = "paintings";
   items[3] = "The walls are full of expensive paintings and pictures";
   items[4] = "pictures";
   items[5] = "The walls are full of expensive paintings and pictures";

   property = allocate(4);
   property[0] = "no_kill";
   property[1] = "no_skill";
   property[2] = "no_spell";
   property[3] = "no_summon";

}
