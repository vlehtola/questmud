inherit "room/room";
object lasca;
reset (arg) {
    if(arg) return;
        short_desc = "In the endless void";
        long_desc = "You are walking in the endless void. The void continous almost everywhere but\n"+
                    "you can't make much sense of it. The walls are full of bones and heads of skeletons\n"+
                    "what have died tradigaly.\n";
   set_not_out(1);
   set_light(1);
   add_exit("out","/wizards/neophyte/city/lighthouse/corridor17");
}
