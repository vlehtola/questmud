inherit "room/room";

reset(arg)
{
if(arg) return;

add_exit ("south","wizards/adrigon/cavenborough/cavendel/tailor.c");
add_exit ("west","wizards/adrigon/cavenborough/cavendel/tcroad3.c");
add_exit ("east","wizards/adrigon/cavenborough/cavendel/marketp2.c");

short_desc = "Western part of the marketplace";
long_desc =
"Western part the marketplace isn't so loud and crowded as the center. Tailors,\n" +
"shoemakers and other more ordinary people are selling merchandise here. To the\n" +
"south can be seen a sign describing a needle hanging in its holder above the\n" +
"door. Metallic clanking drifts through wall from north but the entry must be\n" +
"on the other side of the house. Some large building looms in west at some\n" +
"distance and road leads to it.\n";

items = allocate (2);
items[0] = "sign";
items[1] = "A large metallic needle hangs above the tailor shop";

}