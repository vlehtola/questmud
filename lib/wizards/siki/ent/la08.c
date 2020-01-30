inherit "room/room";
object guard,guard2;

reset(arg) {
    if(!guard) {
        guard = clone_object("/wizards/siki/ent/monsters/skeguard");
        move_object(guard, this_object());
       }
    if(!guard2) {
        guard2 = clone_object("/wizards/siki/ent/monsters/skeguard");
        move_object(guard2, this_object());

       }
   add_exit("west","/wizards/siki/ent/la07");
   short_desc = "A dead end.";
   long_desc = "Another dead end in this infinite maze. It seems that there is no\n"+
               "way out from this hell. There is a dead human body on the floor and\n"+
               "it is still bleeding. The blood runs down to the west.\n";

items = allocate(6);
items[0] = "body";
items[1] = "Dead body of an adult human. It is still warm and it is loosing blood";
items[2] = "stream";
items[3] = "The stream is small, but it runs quite fast";
items[4] = "blood";
items[5] = "Dark red blood all over the room in different forms";
   property = allocate(1);
   property[0] = "no_summon";

   set_not_out(1);




}

