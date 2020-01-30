inherit "room/room";
object monster;

int searched=0;

reset(arg) {
  if(!present("animal 2")) { 
    move_object(clone_object("/wizards/duncan/icecaves/monsters/animal.c"),
    this_object());
    move_object(clone_object("/wizards/duncan/icecaves/monsters/animal.c"),
    this_object());
}

  if(arg) return;

  add_exit("north", "/wizards/duncan/icecaves/tunnel1.c");

  short_desc = "A small ice-hall";
  long_desc = "A small hall has been formed in here by the ancient lava flow. It's separated\n"+ 
              "from the main tunnel. The walls, ground and ceiling are covered with thick ice\n"+
              "layer and snow. The hall is four meters wide and couple meters long and high,\n"+
              "lit up with shimmering blue light. The light is shimmering through the ice\n"+
              "layer on the walls. There are some icicles hanging from the ceiling. The\n"+
              "ground is rough and slippery, full of different sized and shaped pillars.\n"+
              "Cold air is floating around the hall. The main tunnel is in the north. In the\n"+
              "back corner of the hall is a frozen corpse lying on the ground, almost buried\n"+
              "in ice and snow.\n";

   set_not_out(1);
   set_light(3);

   items = allocate(6);
   items[0] = "icicles";
   items[1] = "The icicles are hanging from the ceiling. They are different sized and shaped. Some of them are swaying dangerously, like they would fall at any moment";
   items[2] = "pillars";
   items[3] = "The different sized and shaped pillars are rising from the ground. They are almost blocking the way to deeper underground";
   items[4] = "corpse";
   items[5] = "A frozen corpse of some ancient animal. It's well preserved, since it's almost buried in ice and snow. You can discern it's burnt body and fearful look in it's face.";

  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}

search_finished() {
if(searched) return 0;
searched++;

        if(!this_player()->query_quests("Find head of an ancient animal")) {
                write("You search the corpse and detach the head from it!\n");
                        say(this_player()->query_name()+ " detachs the head from the corpse.\n");
                        move_object(clone_object("/wizards/duncan/icecaves/object/head.c"), this_player());
                        this_player()->set_quest("Find head of an ancient animal");
                return 1;
        }
                write("You search the corpse and detach the head from it!\n");
                        say(this_player()->query_name()+ " detachs the head from the corpse.\n");
                        move_object(clone_object("/wizards/duncan/icecaves/object/head.c"), this_player());
}
