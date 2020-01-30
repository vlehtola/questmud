inherit "room/room";

reset(arg)
{
if(arg) return;

add_exit ("north","wizards/adrigon/cavenborough/cavendel/nwroad1.c");
add_exit ("south","wizards/adrigon/cavenborough/cavendel/swhouse2.c");
add_exit ("west","wizards/adrigon/cavenborough/cavendel/tcroad1.c");
add_exit ("east","wizards/adrigon/cavenborough/cavendel/tcroad3.c");

short_desc = "Western road";
long_desc =
"A crossing leads to north and west. Some merchant's house is to the south.\n" +
"The house is quite big and it must belong to some rich merchant. It is build\n" +
"from stone with brick roof. Balcony is on the front side of the house.\";

items = allocate(2);
items[0] = "balcony";
items[1] = "Big stone pillars support the covered balcony which offers excellent\n" +
	   "view over the events in the street.";
	   
}