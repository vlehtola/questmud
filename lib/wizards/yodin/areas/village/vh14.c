inherit "room/room";

reset(arg)
{
if(arg) return;


short_desc = "Village of happines.";
long_desc =
"This is very small and cosy hut. There are some floursacks\n" +
"on the floor. Small window let the sun shine in here. You see \n" +
"few chairs and small desk in front of you. There are a lot of bread\n" +
"and hams in wooden shelves.\n";

add_exit("west", "vh13.c");
add_exit("north", "vh25.c");
items = allocate (2);
items[0] = "shelves";
items[1] = "there are many breads on the shelf.\n";
move_object(clone_object("/wizards/yodin/areas/village/monsters/baker.c"), this_object());
}
