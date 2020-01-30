inherit "room/room";

reset(arg)
{
if(arg) return;

add_exit ("north","wizards/adrigon/cavenborough/cavendel/mroad3.c");
add_exit ("south","wizards/adrigon/cavenborough/cavendel/mroad2.c");
add_exit ("west","wizards/adrigon/cavenborough/cavendel/marketp1.c");
add_exit ("east","wizards/adrigon/cavenborough/cavendel/marketp3.c");

short_desc = "Central part of the marketplace";
long_desc =
"Commotion and racket almost cover the loud shouts of desperative merchants\n" +
"selling their wares on the broad marketplace. Every kind of shops fill in\n" +
"the edges of the plaza. A big statue is on the center. It describes a proud\n" +
"human male. A decorative plate is on the base of the statue. Sparkling\n" +
"fountains circle the statue\n";

items = allocate(6);
items[0] = "shops";
items[1] = "As you glance the vendors in front of their booths. One special\n" +
	   "shop calls your attention. It has very exotic items from the \n" +
	   "distant lands. Pelts of the most intriguing animals, flavourished\n" +
	   "mats and rugs even incences with the most peculiar smells.";
items[2] = "statue"
items[3] = "Awe inspiring statue stands in the middle of diagonally placed\n" +
	   "fountains. Some weird alloy of stones is used in the making of the\n" +
	   "statue. It is polished and gleams fascinately.\n";
items[4] = "plate";
items[5] = "Behold the saviour and founder of majestical capitol of Cavenborough.\n" +
	   "Built for the everlasting honour of Lord Alexander Graydrake.\n";

}