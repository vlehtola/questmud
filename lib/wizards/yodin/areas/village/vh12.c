inherit "room/room";
object fountain;
reset(arg)
{
if(arg) return;
if (!fountain) {
     fountain = clone_object("/wizards/yodin/areas/village/obj/fountain.c");
     move_object(fountain, this_object());
  }

short_desc = "Village of happiness.";
long_desc =
"This is the central square of the village. You can see many people\n" +
"walking by and some of them are just spending some time around the\n" +
"beautifully fountain. Some shops can be seen in distance.\n";

add_exit("west", "vh7.c");
add_exit("east", "vh9.c");
add_exit("north", "vh6.c");
add_exit("south", "vh8.c");

}
