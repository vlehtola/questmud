#include "room.h"
#undef EXTRA_RESET
#define EXTRA_RESET\
     extra_reset();
THREE_EXIT("wizards/daoloth/mansion/farm_house.c", "enter",
           "wizards/daoloth/mansion/farm_path.c", "southwest",
           "wizards/daoloth/mansion/path4.c", "east",
           "Yard",
           "You stand in the yard. The yard is surrounded by big forest.\n"
           "You see paths going east and southwest. You see a nice red\n"
           "painted house in north side of the yard. a Hen coop stand in\n"
           "northwest corner. Behind the house you see a big hill raising\n"
           "up to the sky. In middle of the yard you see a huge and old oak\n"
           "tree and a well under it.\n", 3)
extra_reset() {
items = allocate(20);
items[0] = "hill";
items[1] = "You have never seen that kind of hill in forests\n"
           "It's much larger than usually hills are forests";
items[2] = "tree";
items[3] = "This is the biggest oak what you have ever seen. You wonder\n"
           "if that strage sound could come from there";
items[4] = "coop";
items[5] = "The hen coop seems to be full of hens. Maybe you could even\n"
           "kill some of them";
items[6] = "house";
items[7] = "The house is really small. You're sure that there must be\n"
           "living only one or two persons. But anyway house is nice and\n"
           "cosy. It has red paint on walls and white on window frame.\n"
           "There is also a tiny chimney on the roof";
items[8] = "chimney";
items[9] = "It's very small and you see some smoke coming from it";
items[10] = "well";
items[11] = "It's ordinary round well builded from rocks. You see a small\n"
            "rope disappearing in darkness";
items[12] = "rope";
items[13] = "It's normal rope and it looks very sturdy";
}
init() {
::init();
add_action("enter_coop", "enter");
add_action("climb_well", "climb");
}
enter_coop(str) {
  if(str == "coop") {
    write("You crawl in the hen-coop from little hole in it\n");
    this_player()->move_player("north#wizards/daoloth/mansion/farm_coop.c");
    return 1;
  }
}
climb_well(str) {
  if(str == "rope") {
    write("You start climbing down..\n");
   this_player()->move_player("north#wizards/daoloth/mansion/mine_entrace.c");
    return 1;
  }
  if(str == "tree") {
    write("You start climbing to tree..\n");
   this_player()->move_player("north#wizards/daoloth/mansion/tree_entrace.c");
    return 1;
  }
}
