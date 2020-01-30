inherit "room/room";

reset(arg) {
if(arg) return;

add_exit("tunnel", "/wizards/duncan/icecaves/tunnel.c");
add_exit("jump", "/wizards/duncan/icecaves/entrance.c");

short_desc = "On a snow covered ledge";
long_desc = "A small ledge is sticking out from the mountainside. It's couple meters above\n"+ 
            "the ground. The ledge is covered with ice and snow feeling rough and slippery.\n"+
            "There is an opening on the mountainside leading to an ancient cave. A narrow\n"+
            "tunnel can be seen through the opening. The mountain wall is frozen and covered\n"+
            "with thick layer of ice and snow. A strange blue light is shimmering from the\n"+
            "opening, lighting the whole tunnel inside the mountain. You can feel the cold\n"+
            "air floating from the depths of mountain against your face and whole body.\n"+
            "The only way back to the ground is to jump down and hope for the best.\n";

   items = allocate(4);
   items[0] = "ledge";
   items[1] = "A small ledge is sticking out from the mountainside couple meters above the ground. The ledge is in front of the opening on the mountainside";
   items[2] = "opening";
   items[3] = "An opening on the mountainside is hiding a tunnel inside it. In the tunnel can be seen a strange blue light shimmering, lighting up the whole tunnel. Cold air is floating out from the tunnel";
}

init() {
   ::init();
   add_action("jump","jump");
}

jump() {
   int dama;
   write("You jump from the ledge!\n");
   write(".. and hit to the ground, ");
   this_player()->lited("OUCH");
   write("!\n");
   dama = random(20) + 10;
   this_player()->reduce_hp(dama);
}
