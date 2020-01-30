inherit "room/room";

reset(arg)
{
if(arg) return;

add_exit ("south","wizards/adrigon/cavenborough/cavendel/herb.c");
add_exit ("west","wizards/adrigon/cavenborough/cavendel/tcroad2.c");
add_exit ("east","wizards/adrigon/cavenborough/cavendel/marketp1.c");

short_desc = "Western road";
long_desc =
"Paved road leads west from the marketplace. Green painted wooden house is to\n" +
"south. Many jugs and pots full of different flowers and plants are on the\n" +
"front side. Flowered vines climb the walls.\n";

items = allocate(4);
items[0] = "jugs";
items[1] = "About feet tall clay jugs are scattered on street side of the house.\n" +
	   "Some of the plants are common and easy recognisable, as most of\n" +
	   "them aren't.\n";
items[2] = "vines";
items[3] = "Flowers on the full bloom cover the vines and the wall seems to be\n" +
	   "alive in the myriad of colours. Different types of vines crawl on the\n" +
	   "wall hiding it completely.\n";

}