inherit "room/room";
object mercantilist;
reset(arg) {
  if(arg) return;
                  if(!mercantilist) {
                          mercantilist = clone_object("/wizards/neophyte/city/monst/mercantilist");
                          move_object(mercantilist, this_object());
                  }
  short_desc = "The general shop";
  long_desc = "The general shop is totally different than the weapon and armour shops. The\n"+
              "furnishings looks expensive, elegant and new. Everything is in good order,\n"+
              "paintings of ships are hanging on the walls and an expensive looking mat\n"+
              "is placed on the floor. There are big, wooden shelves around the shop standing\n"+
              "against the walls. A huge counter is dominating at the back of the room.\n";

  set_not_out(1);
  set_light(3);

   items = allocate(8);
   items[0] = "paintings";
   items[1] = "There are different sized ships painted on the paintings, which are hanging on the walls around the shop";
   items[2] = "mat";
   items[3] = "The mat is huge, expensive looking. It's covering the whole floor";
   items[4] = "shelves";
   items[5] = "The shelves are full of items, which you don't recognize";
   items[6] = "counter";
   items[7] = "The huge counter is placed at the back of the room";

  add_exit("south", "/wizards/neophyte/city/amber1");
}

