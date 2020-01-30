#include "room.h"
 
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset();
 
extra_reset() {
    if (!present("sign")) {
         move_object("wizards/walla/jericho/stuph/sign", this_object());
    }
    if (!items) {
        items = allocate(2);
        items[0] = "haystacks";
        items[1] = "Haystacks lie along the way, it seems asthough it has been harvesting season\n" +
                   "not long ago. The fresh hay still smells good.";
    }
}
FOUR_EXIT("wizards/walla/jericho/rooms/ujar4", "north",
         "wizards/walla/area/sgate", "south",
         "wizards/walla/jericho/rooms/htuos-1","west",
         "wizards/walla/jericho/rooms/htuos1","east",
         "At the crossing of Ujar street and Thuos street",
         "You area standing on Ujar street, which is one of the main roads of Jericho.\n" +
         "The road has been recently paved, and you can see some of the old cobblestones\n" +
         "still lying in piles, at the side of the road. In a east-west direction from\n" +
         "here lies Htuos street, which follows the southern town wall.\n", 3)
