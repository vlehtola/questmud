inherit "room/room";

reset(arg)
{
if(arg) return;

add_exit("north","wizards/adrigon/cavenborough/cavendel/marketp2.c");
add_exit("south","wizards/adrigon/cavenborough/cavendel/road1.c");

short_desc = "Southern part of the main street";
long_desc =
"Loud clatter drifts from the marketplace. The opening of the lively\n" + 
"marketplace of Cavendel can be seen to the north. Houses look ordinary with\n" +
"the simple window frames. Traffic is very intense to in and out of the city.\n" +
"Broken cart in the middle of the street jams up the people. Impatient shouts\n" +
"and pushing increase the general confusion.\n";

items = allocate(2);
items[0] = "cart";
items[1] = "As you inspect the cart closer you see the other cartwheel missing\n" +
	   "and lying in the ground trampled and broken.\n";

}
