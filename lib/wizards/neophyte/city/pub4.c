inherit "room/room";
object ob;
reset(arg) {
if(arg) return;
if(!ob && !random(4)) {
        ob = clone_object("/wizards/neophyte/city/monst/kyriec");
        move_object(ob,this_object());
}


set_not_out(1);
set_light(3);

short_desc = "Private room of the inn";
long_desc =  "This room looks quite cosy and elegant. This regular bed-sitting-room\n"+
             "is spacious and has high ceiling. The wallpapers are white and painted\n"+
             "full of roses. A carpet made of finest cotton is covering the floor.\n"+
             "A large bed is placed in the center of the room, behind a mahongy\n"+
             "night table. The room is kept clean and fresh.\n";

   items = allocate(8);
   items[0] = "wallpaper";
   items[1] = "The white wallpaper is covering the walls. Roses are painted on it";
   items[2] = "carpet";
   items[3] = "The carpet is made of finest cotton";
   items[4] = "bed";
   items[5] = "The bed is huge made for two persons";
   items[6] = "table";
   items[7] = "The table is made of mahongy and placed in front of the bed";

add_exit("west","pub2");
}

