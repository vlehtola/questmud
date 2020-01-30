#include "/wizards/neophyte/city/misc/misc.h"
inherit "room/room";
object wolfleader,king;
reset(arg) {
               if(!wolfleader) {
                       wolfleader = clone_object(monspath+"wolfleader");
                       move_object(wolfleader, this_object());
               if(random(3) == 0) {
                                               king = clone_object(monspath+"king");
                                               move_object(king, this_object());
       }
   }
        add_exit("north","room4");
        short_desc = "Cave of wolfleader";
        long_desc = "The cave wall is decorated with ancient looking pictures and\n"+
                    "paintings of former wolfrider leaders. Back of the cave is a throne\n"+
                    "made from oak and hay. On the floor is piles of bones and couple\n"+
                    "pieces of meat. Oil lamp is hanging from the ceiling and giving light\n"+
                    "to this part of the caves.\n";
 set_not_out(1);
 set_light(3);
 items = allocate(4);
 items[0] = "throne";
 items[1] = "This throne looks very sturdy and it is also beautifully shaped";
 items[2] = "lamp";
 items[3] = "The oil lamp is made of silver and looks quite expensive";
}
