#include "room.h" 
 
#undef EXTRA_RESET
#define EXTRA_RESET\
    extra_reset();
 
object monster,monster2,monster3;
 
extra_reset() {
    items = allocate(2);
    items[0] = "poster";
    items[1] = "If your cash is hard, you're welcome";
    if (!monster) {
        monster = clone_object("/wizards/walla/ravenloft/citys/Barovia/monsters/barman");
        move_object(monster, this_object());
    }
    if (!monster2) {
        monster2 = clone_object("/wizards/walla/ravenloft/citys/Barovia/monsters/drunkman");
        move_object(monster2, this_object());
    }
if (!monster3) {
        monster3 = clone_object("/wizards/walla/ravenloft/citys/Barovia/monsters/innman2");
        move_object(monster3, this_object());
    }
}
 
TWO_EXIT("wizards/walla/ravenloft/citys/Barovia/kartov5","west",
"wizards/walla/ravenloft/citys/Barovia/innbackroom","backroom",
"This is the bar of the city of Barovia",
"As you enter the lightened inn of Barovia, you start to smell the tobacco, and the wine, which\n" +
"is very present. Behind the desk stands Igor, the Barkeeper, and at the tables people sit and\n" +
"discuss their problems over a glass of tuika. Behind the desk is a poster of somesort, and you think\n" +
"you can notice a red curtain at the back of the bar.\n", 3)

